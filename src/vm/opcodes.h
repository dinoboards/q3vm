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
  OP_CI1I3,      /*  19  */
  OP_CI1I4,      /*  20  Sign-Extend 8-bit */
  OP_CI2I3,      /*  21  */
  OP_CI2I4,      /*  22  Sign-Extend 16-bit */
  OP_CI3I1,      /*  23  */
  OP_CI3I2,      /*  24  */
  OP_CI3I4,      /*  25  */
  OP_CI3U4,      /*  26  */
  OP_CI4I3,      /*  27  */
  OP_CI4U3,      /*  28  */
  OP_CONSTF4,    /*  29  */
  OP_CONSTGP3,   /*  30  */
  OP_CONSTGP4,   /*  31  Load constant to stack. */
  OP_CONSTI1,    /*  32  */
  OP_CONSTI2,    /*  33  */
  OP_CONSTI3,    /*  34  */
  OP_CONSTI4,    /*  35  */
  OP_CONSTP3,    /*  36  */
  OP_CONSTP4,    /*  37  */
  OP_CONSTU1,    /*  38  */
  OP_CONSTU2,    /*  39  */
  OP_CONSTU3,    /*  40  */
  OP_CONSTU4,    /*  41  */
  OP_CU2I3,      /*  42  */
  OP_CU3U2,      /*  43  */
  OP_CU3U4,      /*  44  */
  OP_CU4I3,      /*  45  */
  OP_CU4U3,      /*  46  */
  OP_CVFI,       /*  47  Convert to float from integer */
  OP_CVFI3,      /*  48  */
  OP_CVIF,       /*  49  Convert to integer from float */
  OP_CVIU3,      /*  50  */
  OP_CVUI3,      /*  51  */
  OP_DIVF,       /*  52  Divide floats */
  OP_DIVI,       /*  53  Divide signed integers. */
  OP_DIVI3,      /*  54  */
  OP_DIVU,       /*  55  Divide unsigned integers. */
  OP_DIVU3,      /*  56  */
  OP_ENTER,      /*  57  Begin subroutine. */
  OP_EQ,         /*  58  Compare integers, jump if equal. */
  OP_EQ3,        /*  59  */
  OP_EQF,        /*  60  Compare floats, jump if equal */
  OP_EQU3,       /*  61  */
  OP_GEF,        /*  62  Compare floats, jump if greater-than-or-equal */
  OP_GEI,        /*  63  Compare integers, jump if greater-than-or-equal. */
  OP_GEI3,       /*  64  */
  OP_GEU,        /*  65  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GEU3,       /*  66  */
  OP_GTF,        /*  67  Compare floats, jump if greater-than */
  OP_GTI,        /*  68  Compare integers, jump if greater-than. */
  OP_GTI3,       /*  69  */
  OP_GTU,        /*  70  Compare unsigned integers, jump if greater-than */
  OP_GTU3,       /*  71  */
  OP_JUMP,       /*  72  Unconditional jump. */
  OP_LEAVE,      /*  73  End subroutine. */
  OP_LEF,        /*  74  Compare floats, jump if less-than-or-equal */
  OP_LEI,        /*  75  Compare integers, jump if less-than-or-equal. */
  OP_LEI3,       /*  76  */
  OP_LEU,        /*  77  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  78  */
  OP_LOAD1,      /*  79  Load 1-byte from memory */
  OP_LOAD2,      /*  80  Load 2-bytes from memory */
  OP_LOAD3,      /*  81  Load 3-bytes from memory */
  OP_LOAD4,      /*  82  Load 4-bytes from memory */
  OP_LOADF4,     /*  83  Load 4 byte float from memory */
  OP_LOCAL,      /*  84  Get local variable. */
  OP_LSH,        /*  85  Left-shift */
  OP_LSH3,       /*  86  */
  OP_LTF,        /*  87  Compare floats, jump if less-than */
  OP_LTI,        /*  88  Compare integers, jump if less-than. */
  OP_LTI3,       /*  89  */
  OP_LTU,        /*  90  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  91  */
  OP_MODI,       /*  92  Modulus (signed). */
  OP_MODI3,      /*  93  */
  OP_MODU,       /*  94  Modulus (unsigned). */
  OP_MODU3,      /*  95  */
  OP_MULF,       /*  96  Multiply floats */
  OP_MULI,       /*  97  Multiply signed integers. */
  OP_MULI3,      /*  98  */
  OP_MULU,       /*  99  Multiply unsigned integers. */
  OP_MULU3,      /* 100  */
  OP_NE,         /* 101  Compare integers, jump if not equal. */
  OP_NE3,        /* 102  */
  OP_NEF,        /* 103  Compare floats, jump if not-equal */
  OP_NEGF,       /* 104  Negate float */
  OP_NEGI,       /* 105  Negate integer. */
  OP_NEGI3,      /* 106  */
  OP_POP,        /* 107  Discard top-of-stack. */
  OP_PUSH,       /* 108  Push to stack. */
  OP_RSHI,       /* 109  Right-shift (algebraic; preserve sign) */
  OP_RSHI3,      /* 110  */
  OP_RSHU,       /* 111  Right-shift (bitwise; ignore sign) */
  OP_RSHU3,      /* 112  */
  OP_SEX24,      /* 113  */
  OP_SEX8_3,     /* 114  */
  OP_STORE1,     /* 115  Store 1-byte to memory */
  OP_STORE2,     /* 116  Store 2-byte to memory */
  OP_STORE3,     /* 117  */
  OP_STORE4,     /* 118  *(stack[top-1]) = stack[top] */
  OP_SUB,        /* 119  Subtract integers (two's complement). */
  OP_SUB3,       /* 120  */
  OP_SUBF,       /* 121  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
