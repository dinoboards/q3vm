#ifndef __OPCODES
#define __OPCODES

#include <stdint.h>

/** Enum for the virtual machine op codes */
typedef enum {
  OP_UNDEF,      /*   0  Error: VM halt */
  OP_IGNORE,     /*   1  No operation */
  OP_BREAK,      /*   2  vm->breakCount++ */
  OP_ADD3,       /*   3  Add int24 (two's complement) */
  OP_ADD4,       /*   4  Add int32 (two's complement) */
  OP_ADDF4,      /*   5  Add floats */
  OP_ARG3,       /*   6  Marshal 3 byte argument */
  OP_ARG4,       /*   7  Marshal 4 byte argument */
  OP_BAND3,      /*   8  Bitwise AND int24 */
  OP_BAND4,      /*   9  Bitwise AND int32 */
  OP_BCOM3,      /*  10  Bitwise Complement int24 */
  OP_BCOM4,      /*  11  Bitwise COMplement int32 */
  OP_BLOCK_COPY, /*  12  memcpy */
  OP_BOR3,       /*  13  Bitwise OR int24 */
  OP_BOR4,       /*  14  Bitwise OR int32 */
  OP_BXOR3,      /*  15  Bitwise eXclusive-OR int24 */
  OP_BXOR4,      /*  16  Bitwise eXclusive-OR int32 */
  OP_CALL,       /*  17  Call subroutine. */
  OP_CF4I3,      /*  18  Convert float to int24 */
  OP_CF4I4,      /*  19  Convert float to int32 */
  OP_CI1I3,      /*  20  Convert int8 to int24 */
  OP_CI2I3,      /*  21  Convert int16 to int24 */
  OP_CI3F4,      /*  22  Convert int24 to float */
  OP_CI3s4,      /*  23  Convert int24 to (u)int32 */
  OP_CI4F4,      /*  24  Convert int32 to float */
  OP_CONSTGP3,   /*  25  Push address pointer to stack (duplicate?) */
  OP_CONSTP3,    /*  26  Push address pointer to stack */
  OP_CONSTs1,    /*  27  Push 1 byte constant */
  OP_CONSTs2,    /*  28  Push 2 byte constant */
  OP_CONSTs3,    /*  29  Push 3 byte constant */
  OP_CONSTs4,    /*  30  Push 4 byte constant */
  OP_CU1I3,      /*  31  Convert uint8 to int24 */
  OP_CU2I3,      /*  32  Convert uint16 to int24 */
  OP_CU3U4,      /*  33  Convert uint24 to uint32 */
  OP_DIVF4,      /*  34  Divide floats */
  OP_DIVI3,      /*  35  Divide int24 */
  OP_DIVI4,      /*  36  Divide int32 */
  OP_DIVU3,      /*  37  Divide uint24 */
  OP_DIVU4,      /*  38  Divide uint32 */
  OP_ENTER,      /*  39  Begin subroutine */
  OP_EQ3,        /*  40  Compare (u)int24, jump if == */
  OP_EQ4,        /*  41  Compare (u)int32, jump if == */
  OP_EQF4,       /*  42  Compare floats, jump if == */
  OP_GEF4,       /*  43  Compare floats, jump if >= */
  OP_GEI3,       /*  44  Compare int24, jump if > */
  OP_GEI4,       /*  45  Compare int32, jump if >= */
  OP_GEU3,       /*  46  Compare uint24, jump if >= */
  OP_GEU4,       /*  47  Compare uint24, jump if >= */
  OP_GTF4,       /*  48  Compare floats, jump if > */
  OP_GTI3,       /*  49  Compare int24, jump if > */
  OP_GTI4,       /*  50  Compare int32, jump if > */
  OP_GTU3,       /*  51  Compare uint24, jump if > */
  OP_GTU4,       /*  52  Compare uint32, jump if > */
  OP_JUMP,       /*  53  Unconditional jump */
  OP_LEAVE,      /*  54  End subroutine */
  OP_LEF4,       /*  55  Compare floats, jump if <= */
  OP_LEI3,       /*  56  Compare int24, jump if <= */
  OP_LEI4,       /*  57  Compare int32, jump if <= */
  OP_LEU3,       /*  58  Compare uint24, jump if <= */
  OP_LEU4,       /*  59  Compare uint32, jump if <= */
  OP_LOAD1,      /*  60  Load 1-byte from memory */
  OP_LOAD2,      /*  61  Load 2-bytes from memory */
  OP_LOAD3,      /*  62  Load 3-bytes from memory */
  OP_LOAD4,      /*  63  Load 4-bytes from memory */
  OP_LOCAL,      /*  64  Get local variable */
  OP_LSH3,       /*  65  left shift (u)int24 */
  OP_LSH4,       /*  66  Left-shift (u)int32 */
  OP_LTF4,       /*  67  Compare floats, jump if < */
  OP_LTI3,       /*  68  Compare int24, jump if < */
  OP_LTI4,       /*  69  Compare int32, jump if < */
  OP_LTU3,       /*  70  Compare uint24, jump if < */
  OP_LTU4,       /*  71  Compare uint32, jump if < */
  OP_MODI3,      /*  72  Modulus int24 */
  OP_MODI4,      /*  73  Modulus int32 */
  OP_MODU3,      /*  74  Modulus uint24 */
  OP_MODU4,      /*  75  Modulus uint32 */
  OP_MULF4,      /*  76  Multiply floats */
  OP_MULI3,      /*  77  Multiple int24 */
  OP_MULI4,      /*  78  Multiply int32 */
  OP_MULU3,      /*  79  Multiply uint24 */
  OP_MULU4,      /*  80  Multiply uint32 */
  OP_NE3,        /*  81  Compare (u)int24, jump if != */
  OP_NE4,        /*  82  Compare integers, jump if != */
  OP_NEF4,       /*  83  Compare floats, jump if != */
  OP_NEGF4,      /*  84  Negate float */
  OP_NEGI3,      /*  85  Negate int24 */
  OP_NEGI4,      /*  86  Negate int32 */
  OP_POP,        /*  87  Discard top-of-stack */
  OP_PUSH,       /*  88  Push no-value to stack */
  OP_RSHI3,      /*  89  Right-shift int24 (preserve sign) */
  OP_RSHI4,      /*  90  Right-shift int32 (preserve sign) */
  OP_RSHU3,      /*  91  Right-shift uint24 */
  OP_RSHU4,      /*  92  Right-shift uint32 */
  OP_STORE1,     /*  93  Store 1-byte to memory */
  OP_STORE2,     /*  94  Store 2-byte to memory */
  OP_STORE3,     /*  95  Store 3-byte to memory */
  OP_STORE4,     /*  96  Store 4-byte to memory */
  OP_SUB3,       /*  97  Subtract (u)int24 (two's complement). */
  OP_SUB4,       /*  98  Subtract (u)int32 (two's complement). */
  OP_SUBF4,      /*  99  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
