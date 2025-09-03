/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#include "../src/vm/opcodes.c.h"
#include "../src/vm/vm.h"

#include "cmdlib.h"
#include "q_platform.h"
#include <inttypes.h>

/* 19079 total symbols in FI, 2002 Jan 23 */
#define DEFAULT_HASHTABLE_SIZE 2048

/* 4 MB MAX POTENTIAL SIZE */

#define VM_MAX_IMAGE_SIZE 0x400000

char outputFilename[MAX_OS_PATH];

typedef enum {
  CODESEG,
  DATASEG, // initialized 32 bit data, will be byte swapped
  LITSEG,  // strings
  BSSSEG,  // 0 filled
  NUM_SEGMENTS
} segmentName_t;

typedef struct {
  byte        image[VM_MAX_IMAGE_SIZE];
  int         imageUsed;
  int         segmentBase;   // only valid on second pass
  int         segmentLength; // valid on 2nd pass
  const char *name;
  int         index;
} segment_t;

typedef struct symbol_s {
  struct symbol_s *next;
  int              hash;
  segment_t       *segment;
  char            *name;
  int              value;
} symbol_t;

typedef struct hashchain_s {
  void               *data;
  struct hashchain_s *next;
} hashchain_t;

typedef struct hashtable_s {
  int           buckets;
  hashchain_t **table;
} hashtable_t;

int          symtablelen = DEFAULT_HASHTABLE_SIZE;
hashtable_t *symtable;
hashtable_t *optable;

segment_t  segment[NUM_SEGMENTS];
segment_t *currentSegment;

int passNumber;
int jump_optimisation_crc;
int numSymbols;
int errorCount;

typedef struct options_s {
  qboolean verbose;
  qboolean writeMapFile;
  qboolean writeListFile;
} options_t;

options_t options = {0};

symbol_t *symbols;
symbol_t *lastSymbol = 0; /* Most recent symbol defined. */

#define MAX_ASM_FILES 256
int   numAsmFiles;
char *asmFiles[MAX_ASM_FILES];
char *asmFileNames[MAX_ASM_FILES];

int   currentFileIndex;
char *currentFileName;
int   currentFileLine;

// we need to convert arg and ret instructions to
// stores to the local stack frame, so we need to track the
// characteristics of the current functions stack frame
int currentLocals;    // bytes of locals needed by this function
int currentArgs;      // bytes of largest argument list called from this function
int currentArgOffset; // byte offset in currentArgs to store next arg, reset
                      // each call

#define MAX_LINE_LENGTH 1024
char lineBuffer[MAX_LINE_LENGTH];
char infoBuffer[MAX_LINE_LENGTH];
int  lineParseOffset;
char token[MAX_LINE_LENGTH];

static const uint32_t crc_32_tab[] =
    {/* CRC polynomial 0xedb88320 */
     0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4,
     0xe0d5e91e, 0x97d2d988, 0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
     0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7, 0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
     0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172, 0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
     0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59, 0x26d930ac, 0x51de003a,
     0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
     0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f,
     0x9fbfe4a5, 0xe8b8d433, 0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
     0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e, 0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
     0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65, 0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
     0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0, 0x44042d73, 0x33031de5,
     0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
     0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6,
     0x03b6e20c, 0x74b1d29a, 0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
     0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1, 0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
     0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc, 0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
     0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b, 0xd80d2bda, 0xaf0a1b4c,
     0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
     0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31,
     0x2cd99e8b, 0x5bdeae1d, 0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
     0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38, 0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
     0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777, 0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
     0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2, 0xa7672661, 0xd06016f7,
     0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
     0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8,
     0x5d681b02, 0x2a6f2b94, 0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d};

#define UPDC32(octet, crc) (crc_32_tab[((crc) ^ (octet)) & 0xff] ^ ((crc) >> 8))

void crc24(const uint8_t data) {
  jump_optimisation_crc = UPDC32(data, jump_optimisation_crc);
  jump_optimisation_crc = jump_optimisation_crc ^ 0xFFFFFFFF;
}

static int vreport(const char *fmt, va_list vp) {
  if (options.verbose != qtrue)
    return 0;
  return vprintf(fmt, vp);
}

static int report(const char *fmt, ...) {
  va_list va;
  int     retval;

  va_start(va, fmt);
  retval = vreport(fmt, va);
  va_end(va);
  return retval;
}

/* The chain-and-bucket hash table.  -PH */

static void hashtable_init(hashtable_t *H, int buckets) {
  H->buckets = buckets;
  H->table   = calloc(H->buckets, sizeof(*(H->table)));
}

static hashtable_t *hashtable_new(int buckets) {
  hashtable_t *H;

  H = malloc(sizeof(hashtable_t));
  hashtable_init(H, buckets);
  return H;
}

/* No destroy/destructor.  No need. */

static void hashtable_add(hashtable_t *H, int hashvalue, void *datum) {
  hashchain_t *hc, **hb;

  hashvalue = (abs(hashvalue) % H->buckets);
  hb        = &(H->table[hashvalue]);
  if (*hb == 0) {
    /* Empty bucket.  Create new one. */
    *hb = calloc(1, sizeof(**hb));
    hc  = *hb;
  } else {
    /* Get hc to point to last node in chain. */
    for (hc = *hb; hc && hc->next; hc = hc->next)
      ;
    if (hc) {
      hc->next = calloc(1, sizeof(*hc));
      hc       = hc->next;
    }
  }
  if (hc) {
    hc->data = datum;
    hc->next = 0;
  }
}

static hashchain_t *hashtable_get(hashtable_t *H, int hashvalue) {
  hashvalue = (abs(hashvalue) % H->buckets);
  return (H->table[hashvalue]);
}

static void hashtable_stats(hashtable_t *H) {
  int          len, empties, longest, nodes;
  int          i;
  float        meanlen;
  hashchain_t *hc;

  report("Stats for hashtable %08" PRIXPTR, (uintptr_t)H);
  empties = 0;
  longest = 0;
  nodes   = 0;
  for (i = 0; i < H->buckets; i++) {
    if (H->table[i] == 0) {
      empties++;
      continue;
    }
    for (hc = H->table[i], len = 0; hc; hc = hc->next, len++)
      ;
    if (len > longest) {
      longest = len;
    }
    nodes += len;
  }
  meanlen = (float)(nodes) / (H->buckets - empties);
#if 0
/* Long stats display */
  report(" Total buckets: %d\n", H->buckets);
  report(" Total stored nodes: %d\n", nodes);
  report(" Longest chain: %d\n", longest);
  report(" Empty chains: %d\n", empties);
  report(" Mean non-empty chain length: %f\n", meanlen);
#else // 0
  /* Short stats display */
  report(", %d buckets, %d nodes", H->buckets, nodes);
  report("\n");
  report(" Longest chain: %d, empty chains: %d, mean non-empty: %f", longest, empties, meanlen);
#endif // 0
  report("\n");
}

/* Kludge. */
/* Check if symbol already exists. */
/* Returns 0 if symbol does NOT already exist, non-zero otherwise. */
static int hashtable_symbol_exists(hashtable_t *H, int hash, char *sym, symbol_t **found) {
  hashchain_t *hc;
  symbol_t    *s;

  hash = (abs(hash) % H->buckets);
  hc   = H->table[hash];
  if (hc == 0) {
    /* Empty chain means this symbol has not yet been defined. */
    return 0;
  }
  for (; hc; hc = hc->next) {
    s = (symbol_t *)hc->data;
    //      if ((hash == s->hash) && (strcmp(sym, s->name) == 0))
    /* We _already_ know the hash is the same.  That's why we're probing! */
    if (strcmp(sym, s->name) == 0) {
      /* Symbol collisions -- symbol already exists. */
      *found = s;
      return 1;
    }
  }
  return 0; /* Can't find collision. */
}

/* Comparator function for quicksorting. */
static int symlist_cmp(const void *e1, const void *e2) {
  const symbol_t *a, *b;

  a = *(const symbol_t **)e1;
  b = *(const symbol_t **)e2;
  // crumb("Symbol comparison (1) %d  to  (2) %d\n", a->value, b->value);
  return (a->value - b->value);
}

/*
  Sort the symbols list by using QuickSort (qsort()).
  This may take a LOT of memory (a few megabytes?), but memory is cheap these
 days.
  However, qsort(3) already exists, and I'm really lazy.
 -PH
*/
static void sort_symbols() {
  int        i, elems;
  symbol_t  *s;
  symbol_t **symlist;

  if (!symbols)
    return;

  // crumb("sort_symbols: Constructing symlist array\n");
  for (elems = 0, s = symbols; s; s = s->next, elems++) /* nop */
    ;

  symlist = malloc(elems * sizeof(symbol_t *));
  for (i = 0, s = symbols; s; s = s->next, i++) {
    symlist[i] = s;
  }
  // crumbf("sort_symbols: Quick-sorting %d symbols\n", elems);
  qsort(symlist, elems, sizeof(symbol_t *), symlist_cmp);
  // crumbf("sort_symbols: Reconstructing symbols list\n");
  s = symbols = symlist[0];
  for (i = 1; i < elems; i++) {
    s->next = symlist[i];
    s       = s->next;
  }
  lastSymbol = s;
  s->next    = 0;
  // crumbf("sort_symbols: verifying..."); fflush(stdout);
  for (i = 0, s = symbols; s; s = s->next, i++) /*nop*/
    ;
  // crumbf(" %d elements\n", i);
  free(symlist); /* d'oh.  no gc. */
}

#ifdef _MSC_VER
#define INT64  __int64
#define atoi64 _atoi64
#else
#define INT64  long long int
#define atoi64 atoll
#endif

/*
 Problem:
    BYTE values are specified as signed decimal string.  A properly functional
    atoip() will cap large signed values at 0x7FFFFFFF.  Negative word values
 are
    often specified as very large decimal values by lcc.  Therefore, values that
    should be between 0x7FFFFFFF and 0xFFFFFFFF come out as 0x7FFFFFFF when
 using
    atoi().  Bad.

 This function is one big evil hack to work around this problem.
*/
static int atoiNoCap(const char *s) {
  INT64 l;
  union {
    unsigned int u;
    signed int   i;
  } retval;

  l = strtoul(s, NULL, 0);
  /* Now smash to signed 32 bits accordingly. */
  if (l < 0) {
    retval.i = (int)l;
  } else {
    retval.u = (unsigned int)l;
  }

  return retval.i; /* <- union hackage.  I feel dirty with this.  -PH */
}

/*
=============
HashString
=============
*/
/* Default hash function of Kazlib 1.19, slightly modified. */
static unsigned int HashString(const char *key) {
  static unsigned long randbox[] = {
      0x49848f1bU, 0xe6255dbaU, 0x36da5bdcU, 0x47bf94e9U, 0x8cbcce22U, 0x559fc06aU, 0xd268f536U, 0xe10af79aU,
      0xc1af4d69U, 0x1d2917b5U, 0xec4c304dU, 0x9ee5016cU, 0x69232f74U, 0xfead7bb3U, 0xe9089ab6U, 0xf012f6aeU,
  };

  const char  *str = key;
  unsigned int acc = 0;

  while (*str) {
    acc ^= randbox[(*str + acc) & 0xf];
    acc = (acc << 1) | (acc >> 31);
    acc &= 0xffffffffU;
    acc ^= randbox[((*str++ >> 4) + acc) & 0xf];
    acc = (acc << 2) | (acc >> 30);
    acc &= 0xffffffffU;
  }
  return acc;
}

/*
============
CodeError
============
*/
static void CodeError(char *fmt, ...) {
  va_list argptr;

  errorCount++;

  fprintf(stderr, "%s:%i ", currentFileName, currentFileLine);

  va_start(argptr, fmt);
  vfprintf(stderr, fmt, argptr);
  va_end(argptr);
}

static int   dis_columnpos = 0;
static FILE *fListFile;

#define COLWIDTH_1 8                 /* PC */
#define COLWIDTH_2 (COLWIDTH_1 + 9)  /* Label */
#define COLWIDTH_3 (COLWIDTH_2 + 13) /* Opcode */
#define COLWIDTH_4 (COLWIDTH_3 + 24) /* Value */

static int WriteString(const char *str) {
  if (passNumber == 2 && options.writeListFile) {
    return fprintf(fListFile, "%s", str);
  }

  return 0;
}

static int WriteChar(const char ch) {
  if (passNumber == 2 && options.writeListFile) {
    return fprintf(fListFile, "%c", ch);
  }

  return 0;
}
static void WritePC() {
  if (passNumber == 2 && options.writeListFile) {
    int v = 0;
    switch (currentSegment->index) {

    case DATASEG:
      v = currentSegment->imageUsed + segment[LITSEG].segmentLength;
      break;

    case BSSSEG:
      v = currentSegment->imageUsed + segment[LITSEG].segmentLength + segment[DATASEG].segmentLength;
      break;

    default:
      v = currentSegment->imageUsed;
    }

    dis_columnpos = fprintf(fListFile, "%06X", v);
  }
}

static void WriteSymbol(const char *const token) {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_1 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%s:", token);
  }
}

static void WriteOpcode(const uint8_t v) {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_2 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%s", opnames[v]);
  }
}

static void WriteDirective(const char *directive) {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_2 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%s", directive);
  }
}

static void WriteValue(const char *str) {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_3 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%s", str);
  }
}

static void WriteInt8(const int v) {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_3 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%%%02X", (uint32_t)v & 0xFF);
  }
}

static void WriteInt16(const int v) {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_3 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%%%04X", (uint32_t)v & 0xFFFF);
  }
}

static void WriteInt24(const int v) {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_3 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%%%06X", (uint32_t)v & 0xFFFFFF);
  }
}

static void WriteInt32(const int v) {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_3 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%%%08X", (uint32_t)v);
  }
}

static void WriteNumber(const int v) {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_3 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%d", (uint32_t)v);
  }
}

static void WriteFloat(int v) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
  const float as_float = *((float *)&v);
#pragma GCC diagnostic pop
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_3 - dis_columnpos, "");
    dis_columnpos += fprintf(fListFile, "%f", as_float);
  }
}

static void WriteComment() {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_4 - dis_columnpos, "");
    fprintf(fListFile, "; %s\n", lineBuffer);
    dis_columnpos = 0;
  }
}

static void WriteInfo() {
  if (passNumber == 2 && options.writeListFile) {
    dis_columnpos += fprintf(fListFile, "%*s", COLWIDTH_4 - dis_columnpos, "");
    fprintf(fListFile, "; %s\n", infoBuffer);
    dis_columnpos = 0;
  }
}

static void WriteNewLine() {
  if (passNumber == 2 && options.writeListFile) {
    fprintf(fListFile, "\n");
    dis_columnpos = 0;
  }
}

static void WriteInt32Code(const uint8_t opcode, const uint32_t v) {
  WritePC();
  WriteOpcode(opcode);
  WriteInt32(v);
  WriteComment();
}

static void WriteInt24Code(const uint8_t opcode, const uint32_t v) {
  WritePC();
  WriteOpcode(opcode);
  WriteInt24(v);
  WriteComment();
}

static void WriteInt16Code(const uint8_t opcode, const uint32_t v) {
  WritePC();
  WriteOpcode(opcode);
  WriteInt16(v);
  WriteComment();
}

static void WriteInt8Code(const uint8_t opcode, const uint32_t v) {
  WritePC();
  WriteOpcode(opcode);
  WriteInt8(v);
  WriteComment();
}

static void WriteFloatCode(const uint8_t opcode, const uint32_t v) {
  WritePC();
  WriteOpcode(opcode);
  WriteFloat(v);
  WriteComment();
}

static void WriteCode(const uint8_t opcode) {
  WritePC();
  WriteOpcode(opcode);
  WriteComment();
}

static void WriteDirectiveD8(const uint8_t v) {
  WritePC();
  WriteDirective("DATA8");
  WriteInt8(v);

  if (isprint(v)) {
    dis_columnpos += WriteString(" ;'");
    dis_columnpos += WriteChar(v);
    dis_columnpos += WriteString("' ");
  }

  WriteComment();
}

static void WriteDirectiveD24(const uint32_t v) {
  WritePC();
  WriteDirective("DATA24");
  WriteInt24(v);
  WriteComment();
}

static void WriteDirectiveSegment(uint8_t segmentIndex) {
  WriteString("\n");
  WriteDirective("SEGMENT");
  WriteValue(segment[segmentIndex].name);
  WriteComment();
  WriteString("\n");
}

static void WriteDirectiveEQU(const char *label, const uint32_t v) {
  dis_columnpos = WriteString(label);
  dis_columnpos += WriteString(":");
  WriteDirective("SEGMENT");
  WriteInt24(v);
  WriteComment();
}

static void EmitByte(segment_t *seg, uint8_t v) {
  if (seg->imageUsed >= VM_MAX_IMAGE_SIZE) {
    Error("VM_MAX_IMAGE_SIZE");
  }

  seg->image[seg->imageUsed] = v;
  crc24(v);
  seg->imageUsed++;
}

static void EmitInt16(segment_t *seg, int16_t v) {
  if (seg->imageUsed >= VM_MAX_IMAGE_SIZE - 4) {
    Error("VM_MAX_IMAGE_SIZE");
  }
  seg->image[seg->imageUsed] = v & 255;
  crc24(v & 255);
  seg->image[seg->imageUsed + 1] = (v >> 8) & 255;
  crc24((v >> 8) & 255);
  seg->imageUsed += 2;
}

static void EmitInt24(segment_t *seg, int v) {
  if (seg->imageUsed >= VM_MAX_IMAGE_SIZE - 4) {
    Error("VM_MAX_IMAGE_SIZE");
  }
  seg->image[seg->imageUsed] = v & 255;
  crc24(v & 255);
  seg->image[seg->imageUsed + 1] = (v >> 8) & 255;
  crc24((v >> 8) & 255);
  seg->image[seg->imageUsed + 2] = (v >> 16) & 255;
  crc24((v >> 16) & 255);
  seg->imageUsed += 3;
}

static void EmitInt32(segment_t *seg, int32_t v) {
  if (seg->imageUsed >= VM_MAX_IMAGE_SIZE - 4) {
    Error("VM_MAX_IMAGE_SIZE");
  }
  seg->image[seg->imageUsed] = v & 255;
  crc24(v & 255);
  seg->image[seg->imageUsed + 1] = (v >> 8) & 255;
  crc24((v >> 8) & 255);
  seg->image[seg->imageUsed + 2] = (v >> 16) & 255;
  crc24((v >> 16) & 255);
  seg->image[seg->imageUsed + 3] = (v >> 24) & 255;
  crc24((v >> 24) & 255);
  seg->imageUsed += 4;
}

/*
============
DefineSymbol

Symbols can only be defined on pass 0
============
*/
static void DefineSymbol(char *sym, int value) {
  /* Hand optimization by PhaethonH */
  symbol_t *s;
  char      expanded[MAX_LINE_LENGTH * 2];
  int       hash;

  // add the file prefix to local symbols to guarantee unique
  if (sym[0] == '$') {
    sprintf(expanded, "%s_%i", sym, currentFileIndex);
    sym = expanded;
  }

  hash = HashString(sym);

  if (hashtable_symbol_exists(symtable, hash, sym, &s)) {

    if (passNumber == 0) {
      CodeError("Multiple definitions for %s\n", sym);
      return;
    }
    // if (s->value != value )
    //   printf("%d: Updating %s from %04X to %04X\n", passNumber, sym, s->value, value);
    s->value = value;
    return;
  }

  s          = malloc(sizeof(*s));
  s->next    = NULL;
  s->name    = copystring(sym);
  s->hash    = hash;
  s->value   = value;
  s->segment = currentSegment;

  hashtable_add(symtable, hash, s);

  /*
    Hash table lookup already speeds up symbol lookup enormously.
    We postpone sorting until end of pass 0.
    Since we're not doing the insertion sort, lastSymbol should always
     wind up pointing to the end of list.
    This allows constant time for adding to the list.
   -PH
  */
  if (symbols == 0) {
    lastSymbol = symbols = s;
  } else {
    lastSymbol->next = s;
    lastSymbol       = s;
  }
}

/*
============
LookupSymbol

Symbols can only be evaluated on pass 1
============
*/
static int LookupSymbol(char *sym, symbol_t **found) {
  symbol_t    *s;
  char         expanded[MAX_LINE_LENGTH + 16];
  int          hash;
  hashchain_t *hc;

  if (passNumber == 0) {
    return 0;
  }

  // add the file prefix to local symbols to guarantee unique
  if (sym[0] == '$') {
    sprintf(expanded, "%s_%i", sym, currentFileIndex);
    sym = expanded;
  }

  hash = HashString(sym);

  /*
    Hand optimization by PhaethonH

    Using a hash table with chain/bucket for lookups alone sped up q3asm by
   almost 3x for me.
   -PH
  */
  for (hc = hashtable_get(symtable, hash); hc; hc = hc->next) {
    s = (symbol_t *)hc->data; /* ugly typecasting, but it's fast! */
    if ((hash == s->hash) && !strcmp(sym, s->name)) {
      if (found)
        *found = s;
      return s->segment->segmentBase + s->value;
    }
  }

  CodeError("error: symbol '%s' undefined\n", sym);
  int pn     = passNumber;
  passNumber = 0;
  DefineSymbol(sym, 0); // so more errors aren't printed
  passNumber = pn;
  return 0;
}

/*
==============
ExtractLine

Extracts the next line from the given text block.
If a full line isn't parsed, returns NULL
Otherwise returns the updated parse pointer
===============
*/
static char *ExtractLine(char *data) {
  /* Goal:
       Given a string `data', extract one text line into buffer `lineBuffer'
   that
       is no longer than MAX_LINE_LENGTH characters long.  Return value is
       remainder of `data' that isn't part of `lineBuffer'.
   -PH
  */
  /* Hand-optimized by PhaethonH */
  char *p, *q;

  currentFileLine++;

  lineParseOffset = 0;
  token[0]        = 0;
  *lineBuffer     = 0;

  p = q = data;
  if (!*q) {
    return NULL;
  }

  for (; !((*p == 0) || (*p == '\n')); p++) /* nop */
    ;

  if ((p - q) >= MAX_LINE_LENGTH) {
    CodeError("MAX_LINE_LENGTH");
    return data;
  }

  memcpy(lineBuffer, data, (p - data));
  lineBuffer[(p - data)] = 0;
  p += (*p == '\n') ? 1 : 0; /* Skip over final newline. */
  return p;
}

/*
==============
Parse

Parse a token out of linebuffer
==============
*/
static qboolean Parse(void) {
  /* Hand-optimized by PhaethonH */
  const char *p, *q;

  /* Because lineParseOffset is only updated just before exit, this makes this
   * code version somewhat harder to debug under a symbolic debugger. */

  *token = 0; /* Clear token. */

  // skip whitespace
  for (p = lineBuffer + lineParseOffset; *p && (*p <= ' '); p++) /* nop */
    ;

  // skip ; comments
  /* die on end-of-string */
  if ((*p == ';') || (*p == 0)) {
    lineParseOffset = p - lineBuffer;
    return qfalse;
  }

  q = p; /* Mark the start of token. */
  /* Find separator first. */
  for (; *p > 32; p++) /* nop */
    ;                  /* XXX: unsafe assumptions. */
  /* *p now sits on separator.  Mangle other values accordingly. */
  strncpy(token, q, p - q);
  token[p - q] = 0;

  lineParseOffset = p - lineBuffer;

  return qtrue;
}

/*
==============
ParseValue
==============
*/
static int ParseValue(void) {
  Parse();
  return atoiNoCap(token);
}

/*
==============
ParseExpression
==============
*/
static int ParseExpression2(symbol_t **s) {
  /* Hand optimization, PhaethonH */
  int  i, j;
  char sym[MAX_LINE_LENGTH + 1];
  int  v;

  /* Skip over a leading minus. */
  for (i = ((token[0] == '-') ? 1 : 0); i < MAX_LINE_LENGTH; i++) {
    if (token[i] == '+' || token[i] == '-' || token[i] == 0) {
      break;
    }
  }

  memcpy(sym, token, i);
  sym[i] = 0;

  switch (*sym) { /* Resolve depending on first character. */
  /* Optimizing compilers can convert cases into "calculated jumps".  I think
   * these are faster.  -PH */
  case '-':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    v = atoiNoCap(sym);
    break;
  default:
    v = LookupSymbol(sym, s);
    break;
  }

  // parse add / subtract offsets
  while (token[i] != 0) {
    for (j = i + 1; j < MAX_LINE_LENGTH; j++) {
      if (token[j] == '+' || token[j] == '-' || token[j] == 0) {
        break;
      }
    }

    memcpy(sym, token + i + 1, j - i - 1);
    sym[j - i - 1] = 0;

    switch (token[i]) {
    case '+':
      v += atoiNoCap(sym);
      break;
    case '-':
      v -= atoiNoCap(sym);
      break;
    }

    i = j;
  }

  return v;
}

static int ParseExpression(void) { return ParseExpression2(NULL); }

#define assfn(a) TryNewAssemble_##a

#include "assemblers.c"
#include "assemblers.h"

// #define STAT(L) report(L "\n");
#define STAT(L)
#define ASM(O) int TryAssemble##O()

/* START OLD ASSEMBLY PATTERN */

/*
==============
AssembleLine

==============
*/

static void AssembleLine(void) {
  int i;

  Parse();

  if (!token[0]) {
    WriteComment();
    return;
  }

  for (i = 0; i < (int)(sizeof(assemblers) / sizeof(assemblers_t)); i++) {
    const assemblers_t a = assemblers[i];

    if (strncasecmp(a.prefix, token, strlen(a.prefix)) == 0) {
      a.emit(a);
      return;
    }
  }

  CodeError("Unknown token: %s\n", token);
}

/*
==============
InitTables
==============
*/
void InitTables(void) {

  symtable = hashtable_new(symtablelen);
  optable  = hashtable_new(100); /* There's hardly 100 opcodes anyway. */
}

static void writeMapFileForSegment(FILE *f, int seg) {
  symbol_t *s;

  for (s = symbols; s; s = s->next) {
    if (s->name[0] == '$') {
      continue; // skip locals
    }
    if (&segment[seg] != s->segment) {
      continue;
    }
    fprintf(f, "%i %8x %s\n", seg, s->segment->segmentBase + s->value, s->name);
  }
}

static void writeFunctionsHeader(FILE *f) {
  symbol_t *s;

  for (s = symbols; s; s = s->next) {
    if (s->name[0] == '$')
      continue; // skip locals

    if (s->segment->index != CODESEG)
      continue;

    if (s->value < 0)
    continue;

    strupr(s->name);
    fprintf(f, "#define Q3VM_FN_%-40s (0x%06X)\n", s->name, s->segment->segmentBase + s->value);
  }
}

static void writeGlobalsHeader(FILE *f) {
  symbol_t *s;

  for (s = symbols; s; s = s->next) {
    if (s->name[0] == '$')
      continue; // skip locals

    if (s->segment->index == CODESEG)
      continue;

    if (s->value < 0)
    continue;

    strupr(s->name);
    fprintf(f, "#define Q3VM_DATA_%-38s (0x%06X)\n", s->name, s->segment->segmentBase + s->value);
  }
}

/*
==============
WriteMapFile
==============
*/
static void WriteMapFile(void) {
  FILE *f;
  char  imageName[MAX_OS_PATH];

  strcpy(imageName, outputFilename);
  StripExtension(imageName);
  strcat(imageName, ".map");

  report("Writing %s...\n", imageName);

  f = SafeOpenWrite(imageName);
  writeMapFileForSegment(f, CODESEG);
  writeMapFileForSegment(f, LITSEG);
  writeMapFileForSegment(f, DATASEG);
  writeMapFileForSegment(f, BSSSEG);

  fclose(f);

  imageName[0] = 0;
  strcpy(imageName, outputFilename);
  StripExtension(imageName);
  strcat(imageName, ".h");

  report("Writing %s...\n", imageName);

  f = SafeOpenWrite(imageName);

  fprintf(f, "#ifndef __NOTQ3VM_SYMBOLS__\n");
  fprintf(f, "#define __NOTQ3VM_SYMBOLS__\n\n");

  writeFunctionsHeader(f);
  fprintf(f, "\n");
  writeGlobalsHeader(f);

  fprintf(f, "\n#endif\n");


  fclose(f);

}

/*
===============
WriteVmFile
===============
*/
static void WriteVmFile(void) {
  char       imageName[MAX_OS_PATH];
  vmHeader_t header;
  FILE      *f;
  int        headerSize;

  report("%i total errors\n", errorCount);

  strcpy(imageName, outputFilename);
  StripExtension(imageName);
  strcat(imageName, ".qvm");

  remove(imageName);

  report("code segment: %7i\n", segment[CODESEG].imageUsed);
  report("data segment: %7i\n", segment[DATASEG].imageUsed);
  report("lit  segment: %7i\n", segment[LITSEG].imageUsed);
  report("bss  segment: %7i\n", segment[BSSSEG].imageUsed);

  if (errorCount != 0) {
    report("Not writing a file due to errors\n");
    return;
  }

  header.vmMagic = VM_MAGIC;

  // Don't write the VM_MAGIC_VER2 bits when maintaining 1.32b compatibility.
  // (I know this isn't strictly correct due to padding, but then platforms
  // that pad wouldn't be able to write a correct header anyway).  Note: if
  // vmHeader_t changes, this needs to be adjusted too.
  headerSize = sizeof(header);

  header.codeLength = to_uint24(segment[CODESEG].imageUsed);
  header.litLength  = to_uint24(segment[LITSEG].imageUsed);
  header.dataLength = to_uint24(segment[DATASEG].imageUsed);
  header.bssLength  = to_uint24(segment[BSSSEG].imageUsed);

  report("Writing to %s\n", imageName);

#ifdef Q3_BIG_ENDIAN
  {
    int i;

    // byte swap the header
    for (i = 0; i < sizeof(vmHeader_t) / 4; i++) {
      ((int *)&header)[i] = LittleLong(((int *)&header)[i]);
    }
  }
#endif

  CreatePath(imageName);
  f = SafeOpenWrite(imageName);
  SafeWrite(f, &header, headerSize);
  SafeWrite(f, &segment[CODESEG].image, segment[CODESEG].imageUsed);
  SafeWrite(f, &segment[LITSEG].image, segment[LITSEG].imageUsed);
  SafeWrite(f, &segment[DATASEG].image, segment[DATASEG].imageUsed);

  fclose(f);
}

/*
===============
Assemble
===============
*/
static void Assemble(void) {
  int   i;
  char  filename[MAX_OS_PATH];
  char *ptr;

  report("outputFilename: %s\n", outputFilename);

  for (i = 0; i < numAsmFiles; i++) {
    strcpy(filename, asmFileNames[i]);
    DefaultExtension(filename, ".asm");
    LoadFile(filename, (void **)&asmFiles[i]);
  }

  segment[CODESEG].name = "CODE";
  segment[DATASEG].name = "DATA";
  segment[BSSSEG].name  = "BSS";
  segment[LITSEG].name  = "LIT";

  segment[CODESEG].index = CODESEG;
  segment[DATASEG].index = DATASEG;
  segment[BSSSEG].index  = BSSSEG;
  segment[LITSEG].index  = LITSEG;

  // assemble
  jump_optimisation_crc              = 0xFFFFFFFF;
  int previous_jump_optimisation_crc = 0;
  for (passNumber = 0; passNumber < 3; passNumber++) {
    segment[LITSEG].segmentBase  = 0;
    segment[DATASEG].segmentBase = segment[LITSEG].imageUsed;
    segment[BSSSEG].segmentBase  = segment[DATASEG].segmentBase + segment[DATASEG].imageUsed;

    for (i = 0; i < NUM_SEGMENTS; i++) {
      segment[i].segmentLength = segment[i].imageUsed;
      segment[i].imageUsed     = 0;
    }
    segment[LITSEG].imageUsed = 1; // skip the 0 byte, so NULL pointers are fixed up properly

    for (i = 0; i < numAsmFiles; i++) {
      currentFileIndex = i;
      currentFileName  = asmFileNames[i];
      currentFileLine  = 0;
      report("pass %i: %s\n", passNumber, currentFileName);

      if (passNumber == 2 && options.writeListFile) {
        strcpy(filename, currentFileName);
        StripExtension(filename);
        strcat(filename, ".lst");
        fListFile = SafeOpenWrite(filename);
      }

      fflush(NULL);

      ptr = asmFiles[i];
      while (ptr) {
        ptr = ExtractLine(ptr);
        AssembleLine();
      }

      if (passNumber == 2 && options.writeListFile) {
        fclose(fListFile);
      }
    }

    if (passNumber == 0) {
      sort_symbols();
    }

    if (passNumber == 1 && jump_optimisation_crc != previous_jump_optimisation_crc) {
      passNumber = 0;
    }
    previous_jump_optimisation_crc = jump_optimisation_crc;
    jump_optimisation_crc          = 0xFFFFFFFF;
  }

  // reserve the stack in bss
  currentSegment = &segment[BSSSEG];
  DefineSymbol("_stackBottom", segment[BSSSEG].imageUsed);
  // write the image
  WriteVmFile();

  // write the map file even if there were errors
  if (options.writeMapFile) {
    WriteMapFile();
  }
}

/*
=============
ParseOptionFile

=============
*/
static void ParseOptionFile(const char *filename) {
  char  expanded[MAX_OS_PATH];
  char *text, *text_p;

  strcpy(expanded, filename);
  DefaultExtension(expanded, ".q3asm");
  LoadFile(expanded, (void **)&text);
  if (!text) {
    return;
  }

  text_p = text;

  while ((text_p = COM_Parse(text_p)) != 0) {
    if (!strcmp(com_token, "-o")) {
      // allow output override in option file
      text_p = COM_Parse(text_p);
      if (text_p) {
        strcpy(outputFilename, com_token);
      }
      continue;
    }

    asmFileNames[numAsmFiles] = copystring(com_token);
    numAsmFiles++;
  }
}

static void ShowHelp(char *argv0) {
  Error("Usage: %s [OPTION]... [FILES]...\n\
Assemble LCC bytecode assembly to Q3VM bytecode.\n\
\n\
  -o OUTPUT      Write assembled output to file OUTPUT.qvm\n\
  -f LISTFILE    Read options and list of files to assemble from LISTFILE.q3asm\n\
  -b BUCKETS     Set symbol hash table to BUCKETS buckets\n\
  -m             Generate a mapfile for each OUTPUT.qvm\n\
  -l             Generate listing for each OUTPUT.qvm\n\
  -v             Verbose compilation report\n\
  -h --help -?   Show this help\n\
",
        argv0);
}

/*
==============
main
==============
*/
int main(int argc, char **argv) {
  int    i;
  double start, end;

  //  _chdir( "/quake3/jccode/cgame/lccout" );    // hack for vc profiler

  if (argc < 2) {
    ShowHelp(argv[0]);
  }

  start = I_FloatTime();

  // default filename is "q3asm"
  strcpy(outputFilename, "q3asm");
  numAsmFiles = 0;

  for (i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      break;
    }
    if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help") || !strcmp(argv[i], "-?")) {
      ShowHelp(argv[0]);
    }

    if (!strcmp(argv[i], "-o")) {
      if (i == argc - 1) {
        Error("-o must precede a filename");
      }
      /* Timbo of Tremulous pointed out -o not working; stock ID q3asm
       * folded in the change. Yay. */
      strcpy(outputFilename, argv[i + 1]);
      i++;
      continue;
    }

    if (!strcmp(argv[i], "-f")) {
      if (i == argc - 1) {
        Error("-f must precede a filename");
      }
      ParseOptionFile(argv[i + 1]);
      i++;
      continue;
    }

    if (!strcmp(argv[i], "-b")) {
      if (i == argc - 1) {
        Error("-b requires an argument");
      }
      i++;
      symtablelen = atoiNoCap(argv[i]);
      continue;
    }

    if (!strcmp(argv[i], "-v")) {
      /* Verbosity option added by Timbo, 2002.09.14.
      By default (no -v option), q3asm remains silent except for critical
      errors.
      Verbosity turns on all messages, error or not.
      Motivation: not wanting to scrollback for pages to find asm error.
      */
      options.verbose = qtrue;
      continue;
    }

    if (!strcmp(argv[i], "-m")) {
      options.writeMapFile = qtrue;
      continue;
    }

    if (!strcmp(argv[i], "-l")) {
      options.writeListFile = qtrue;
      continue;
    }

    Error("Unknown option: %s", argv[i]);
  }

  // the rest of the command line args are asm files
  for (; i < argc; i++) {
    asmFileNames[numAsmFiles] = copystring(argv[i]);
    numAsmFiles++;
  }
  // In some case it Segfault without this check
  if (numAsmFiles == 0) {
    Error("No file to assemble");
  }

  InitTables();
  Assemble();

  {
    symbol_t *s;

    for (i = 0, s = symbols; s; s = s->next, i++) /* nop */
      ;

    if (options.verbose) {
      report("%d symbols defined\n", i);
      hashtable_stats(symtable);
      hashtable_stats(optable);
    }
  }

  end = I_FloatTime();
  report("%5.0f seconds elapsed\n", end - start);

  return errorCount;
}
