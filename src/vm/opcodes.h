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
  OP_ARGF4,      /*   8  */
  OP_BAND3,      /*   9  */
  OP_BAND4,      /*  10  Bitwise AND */
  OP_BCOM3,      /*  11  */
  OP_BCOM4,      /*  12  Bitwise COMplement */
  OP_BLOCK_COPY, /*  13  memcpy */
  OP_BOR3,       /*  14  */
  OP_BOR4,       /*  15  Bitwise OR */
  OP_BXOR3,      /*  16  */
  OP_BXOR4,      /*  17  Bitwise eXclusive-OR */
  OP_CALL,       /*  18  Call subroutine. */
  OP_CF4I4,      /*  19  Convert to float from integer */
  OP_CI1I3,      /*  20  */
  OP_CI1I4,      /*  21  Sign-Extend 8-bit */
  OP_CI2I3,      /*  22  */
  OP_CI2I4,      /*  23  Sign-Extend 16-bit */
  OP_CI3I1,      /*  24  */
  OP_CI3I2,      /*  25  */
  OP_CI3I4,      /*  26  */
  OP_CI3U4,      /*  27  */
  OP_CI4F4,      /*  28  Convert to integer from float */
  OP_CI4I3,      /*  29  */
  OP_CI4U3,      /*  30  */
  OP_CONSTGP3,   /*  31  push address pointer to stack. */
  OP_CONSTI1,    /*  32  */
  OP_CONSTI2,    /*  33  */
  OP_CONSTI3,    /*  34  */
  OP_CONSTI4,    /*  35  */
  OP_CONSTP3,    /*  36  */
  OP_CONSTU1,    /*  37  */
  OP_CONSTU2,    /*  38  */
  OP_CONSTU3,    /*  39  */
  OP_CONSTU4,    /*  40  */
  OP_CU1I3,      /*  41  */
  OP_CU2I3,      /*  42  */
  OP_CU3U2,      /*  43  */
  OP_CU3U4,      /*  44  */
  OP_CU4I3,      /*  45  */
  OP_CU4U3,      /*  46  */
  OP_CVFI3,      /*  47  */
  OP_CVIU3,      /*  48  */
  OP_CVUI3,      /*  49  */
  OP_DIVF4,      /*  50  Divide floats */
  OP_DIVI,       /*  51  Divide signed integers. */
  OP_DIVI3,      /*  52  */
  OP_DIVU,       /*  53  Divide unsigned integers. */
  OP_DIVU3,      /*  54  */
  OP_ENTER,      /*  55  Begin subroutine. */
  OP_EQ3,        /*  56  */
  OP_EQ4,        /*  57  Compare integers, jump if equal. */
  OP_EQF4,       /*  58  Compare floats, jump if equal */
  OP_EQU3,       /*  59  */
  OP_GEF4,       /*  60  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  61  */
  OP_GEI4,       /*  62  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  63  */
  OP_GEU4,       /*  64  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  65  Compare floats, jump if greater-than */
  OP_GTI3,       /*  66  */
  OP_GTI4,       /*  67  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  68  */
  OP_GTU4,       /*  69  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  70  Unconditional jump. */
  OP_LEAVE,      /*  71  End subroutine. */
  OP_LEF,        /*  72  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  73  */
  OP_LEI4,       /*  74  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  75  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  76  */
  OP_LOAD1,      /*  77  Load 1-byte from memory */
  OP_LOAD2,      /*  78  Load 2-bytes from memory */
  OP_LOAD3,      /*  79  Load 3-bytes from memory */
  OP_LOAD4,      /*  80  Load 4-bytes from memory */
  OP_LOADF4,     /*  81  Load 4 byte float from memory */
  OP_LOCAL,      /*  82  Get local variable. */
  OP_LSH3,       /*  83  */
  OP_LSH4,       /*  84  Left-shift */
  OP_LTF,        /*  85  Compare floats, jump if less-than */
  OP_LTI3,       /*  86  */
  OP_LTI4,       /*  87  Compare integers, jump if less-than. */
  OP_LTU,        /*  88  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  89  */
  OP_MODI3,      /*  90  */
  OP_MODI4,      /*  91  Modulus (signed). */
  OP_MODU3,      /*  92  */
  OP_MODU4,      /*  93  Modulus (unsigned). */
  OP_MULF4,      /*  94  Multiply floats */
  OP_MULI3,      /*  95  */
  OP_MULI4,      /*  96  Multiply signed integers. */
  OP_MULU3,      /*  97  */
  OP_MULU4,      /*  98  Multiply unsigned integers. */
  OP_NE3,        /*  99  */
  OP_NE4,        /* 100  Compare integers, jump if not equal. */
  OP_NEF,        /* 101  Compare floats, jump if not-equal */
  OP_NEGF4,      /* 102  Negate float */
  OP_NEGI3,      /* 103  */
  OP_NEGI4,      /* 104  Negate integer. */
  OP_POP,        /* 105  Discard top-of-stack. */
  OP_PUSH,       /* 106  Push to stack. */
  OP_RSHI3,      /* 107  */
  OP_RSHI4,      /* 108  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 109  */
  OP_RSHU4,      /* 110  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 111  Store 1-byte to memory */
  OP_STORE2,     /* 112  Store 2-byte to memory */
  OP_STORE3,     /* 113  */
  OP_STORE4,     /* 114  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 115  */
  OP_SUB4,       /* 116  Subtract integers (two's complement). */
  OP_SUBF4,      /* 117  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
