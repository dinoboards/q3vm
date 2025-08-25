#ifndef __OPCODES
#define __OPCODES

#include <stdint.h>

/** Enum for the virtual machine op codes */
typedef enum {
  OP_UNDEF,      /*   0  Error: VM halt */
  OP_IGNORE,     /*   1  No operation */
  OP_BREAK,      /*   2  vm->breakCount++ */
  OP_ADD3,       /*   3  */
  OP_ADD4,       /*   4  Add integers (two's complement). */
  OP_ADDF4,      /*   5  Add floats */
  OP_ARG3,       /*   6  Marshal argument */
  OP_ARG4,       /*   7  */
  OP_BAND3,      /*   8  */
  OP_BAND4,      /*   9  Bitwise AND */
  OP_BCOM3,      /*  10  */
  OP_BCOM4,      /*  11  Bitwise COMplement */
  OP_BLOCK_COPY, /*  12  memcpy */
  OP_BOR3,       /*  13  */
  OP_BOR4,       /*  14  Bitwise OR */
  OP_BXOR3,      /*  15  */
  OP_BXOR4,      /*  16  Bitwise eXclusive-OR */
  OP_CALL,       /*  17  Call subroutine. */
  OP_CF4I4,      /*  18  Convert to float from integer */
  OP_CI1I3,      /*  19  */
  OP_CI2I3,      /*  20  */
  OP_CI3F4,      /*  21  */
  OP_CI3s4,      /*  22  */
  OP_CI4F4,      /*  23  Convert to integer from float */
  OP_CONSTGP3,   /*  24  push address pointer to stack. */
  OP_CONSTP3,    /*  25  */
  OP_CONSTs1,    /*  26  */
  OP_CONSTs2,    /*  27  */
  OP_CONSTs3,    /*  28  */
  OP_CONSTs4,    /*  29  */
  OP_CU1I3,      /*  30  */
  OP_CU2I3,      /*  31  */
  OP_CU3U2,      /*  32  */
  OP_CU3U4,      /*  33  */
  OP_CU4I3,      /*  34  */
  OP_CU4U3,      /*  35  */
  OP_CVFI3,      /*  36  */
  OP_CVIU3,      /*  37  */
  OP_CVUI3,      /*  38  */
  OP_DIVF4,      /*  39  Divide floats */
  OP_DIVI,       /*  40  Divide signed integers. */
  OP_DIVI3,      /*  41  */
  OP_DIVU,       /*  42  Divide unsigned integers. */
  OP_DIVU3,      /*  43  */
  OP_ENTER,      /*  44  Begin subroutine. */
  OP_EQ3,        /*  45  */
  OP_EQ4,        /*  46  Compare integers, jump if equal. */
  OP_EQF4,       /*  47  Compare floats, jump if equal */
  OP_EQU3,       /*  48  */
  OP_GEF4,       /*  49  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  50  */
  OP_GEI4,       /*  51  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  52  */
  OP_GEU4,       /*  53  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  54  Compare floats, jump if greater-than */
  OP_GTI3,       /*  55  */
  OP_GTI4,       /*  56  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  57  */
  OP_GTU4,       /*  58  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  59  Unconditional jump. */
  OP_LEAVE,      /*  60  End subroutine. */
  OP_LEF4,       /*  61  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  62  */
  OP_LEI4,       /*  63  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  64  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  65  */
  OP_LOAD1,      /*  66  Load 1-byte from memory */
  OP_LOAD2,      /*  67  Load 2-bytes from memory */
  OP_LOAD3,      /*  68  Load 3-bytes from memory */
  OP_LOAD4,      /*  69  Load 4-bytes from memory */
  OP_LOADF4,     /*  70  Load 4 byte float from memory */
  OP_LOCAL,      /*  71  Get local variable. */
  OP_LSH3,       /*  72  */
  OP_LSH4,       /*  73  Left-shift */
  OP_LTF,        /*  74  Compare floats, jump if less-than */
  OP_LTI3,       /*  75  */
  OP_LTI4,       /*  76  Compare integers, jump if less-than. */
  OP_LTU,        /*  77  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  78  */
  OP_MODI3,      /*  79  */
  OP_MODI4,      /*  80  Modulus (signed). */
  OP_MODU3,      /*  81  */
  OP_MODU4,      /*  82  Modulus (unsigned). */
  OP_MULF4,      /*  83  Multiply floats */
  OP_MULI3,      /*  84  */
  OP_MULI4,      /*  85  Multiply signed integers. */
  OP_MULU3,      /*  86  */
  OP_MULU4,      /*  87  Multiply unsigned integers. */
  OP_NE3,        /*  88  */
  OP_NE4,        /*  89  Compare integers, jump if not equal. */
  OP_NEF,        /*  90  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  91  Negate float */
  OP_NEGI3,      /*  92  */
  OP_NEGI4,      /*  93  Negate integer. */
  OP_POP,        /*  94  Discard top-of-stack. */
  OP_PUSH,       /*  95  Push to stack. */
  OP_RSHI3,      /*  96  */
  OP_RSHI4,      /*  97  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /*  98  */
  OP_RSHU4,      /*  99  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 100  Store 1-byte to memory */
  OP_STORE2,     /* 101  Store 2-byte to memory */
  OP_STORE3,     /* 102  */
  OP_STORE4,     /* 103  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 104  */
  OP_SUB4,       /* 105  Subtract integers (two's complement). */
  OP_SUBF4,      /* 106  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
