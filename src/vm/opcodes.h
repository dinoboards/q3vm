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
  OP_BCOM4,      /*  11  Bitwise COMplement */
  OP_BCOM3,      /*  12  */
  OP_BLOCK_COPY, /*  13  memcpy */
  OP_BOR,        /*  14  Bitwise OR */
  OP_BOR3,       /*  15  */
  OP_BXOR,       /*  16  Bitwise eXclusive-OR */
  OP_BXOR3,      /*  17  */
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
  OP_CONSTF4,    /*  28  */
  OP_CONSTGP3,   /*  29  */
  OP_CONSTGP4,   /*  30  Load constant to stack. */
  OP_CONSTI1,    /*  31  */
  OP_CONSTI2,    /*  32  */
  OP_CONSTI3,    /*  33  */
  OP_CONSTI4,    /*  34  */
  OP_CONSTP3,    /*  35  */
  OP_CONSTP4,    /*  36  */
  OP_CONSTU1,    /*  37  */
  OP_CONSTU2,    /*  38  */
  OP_CONSTU3,    /*  39  */
  OP_CONSTU4,    /*  40  */
  OP_CU2I3,      /*  41  */
  OP_CU3U2,      /*  42  */
  OP_CU3U4,      /*  43  */
  OP_CU4I3,      /*  44  */
  OP_CU4U3,      /*  45  */
  OP_CVFI,       /*  46  Convert to float from integer */
  OP_CVFI3,      /*  47  */
  OP_CVIF,       /*  48  Convert to integer from float */
  OP_CVIU3,      /*  49  */
  OP_CVUI3,      /*  50  */
  OP_DIVF,       /*  51  Divide floats */
  OP_DIVI,       /*  52  Divide signed integers. */
  OP_DIVI3,      /*  53  */
  OP_DIVU,       /*  54  Divide unsigned integers. */
  OP_DIVU3,      /*  55  */
  OP_ENTER,      /*  56  Begin subroutine. */
  OP_EQ,         /*  57  Compare integers, jump if equal. */
  OP_EQ3,        /*  58  */
  OP_EQF,        /*  59  Compare floats, jump if equal */
  OP_EQU3,       /*  60  */
  OP_GEF,        /*  61  Compare floats, jump if greater-than-or-equal */
  OP_GEI,        /*  62  Compare integers, jump if greater-than-or-equal. */
  OP_GEI3,       /*  63  */
  OP_GEU,        /*  64  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GEU3,       /*  65  */
  OP_GTF,        /*  66  Compare floats, jump if greater-than */
  OP_GTI,        /*  67  Compare integers, jump if greater-than. */
  OP_GTI3,       /*  68  */
  OP_GTU,        /*  69  Compare unsigned integers, jump if greater-than */
  OP_GTU3,       /*  70  */
  OP_JUMP,       /*  71  Unconditional jump. */
  OP_LEAVE,      /*  72  End subroutine. */
  OP_LEF,        /*  73  Compare floats, jump if less-than-or-equal */
  OP_LEI,        /*  74  Compare integers, jump if less-than-or-equal. */
  OP_LEI3,       /*  75  */
  OP_LEU,        /*  76  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  77  */
  OP_LOAD1,      /*  78  Load 1-byte from memory */
  OP_LOAD2,      /*  79  Load 2-bytes from memory */
  OP_LOAD3,      /*  80  Load 3-bytes from memory */
  OP_LOAD4,      /*  81  Load 4-bytes from memory */
  OP_LOADF4,     /*  82  Load 4 byte float from memory */
  OP_LOCAL,      /*  83  Get local variable. */
  OP_LSH,        /*  84  Left-shift */
  OP_LSH3,       /*  85  */
  OP_LTF,        /*  86  Compare floats, jump if less-than */
  OP_LTI,        /*  87  Compare integers, jump if less-than. */
  OP_LTI3,       /*  88  */
  OP_LTU,        /*  89  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  90  */
  OP_MODI,       /*  91  Modulus (signed). */
  OP_MODI3,      /*  92  */
  OP_MODU,       /*  93  Modulus (unsigned). */
  OP_MODU3,      /*  94  */
  OP_MULF,       /*  95  Multiply floats */
  OP_MULI,       /*  96  Multiply signed integers. */
  OP_MULI3,      /*  97  */
  OP_MULU,       /*  98  Multiply unsigned integers. */
  OP_MULU3,      /*  99  */
  OP_NE,         /* 100  Compare integers, jump if not equal. */
  OP_NE3,        /* 101  */
  OP_NEF,        /* 102  Compare floats, jump if not-equal */
  OP_NEGF,       /* 103  Negate float */
  OP_NEGI,       /* 104  Negate integer. */
  OP_NEGI3,      /* 105  */
  OP_POP,        /* 106  Discard top-of-stack. */
  OP_PUSH,       /* 107  Push to stack. */
  OP_RSHI,       /* 108  Right-shift (algebraic; preserve sign) */
  OP_RSHI3,      /* 109  */
  OP_RSHU,       /* 110  Right-shift (bitwise; ignore sign) */
  OP_RSHU3,      /* 111  */
  OP_SEX24,      /* 112  */
  OP_SEX8_3,     /* 113  */
  OP_STORE1,     /* 114  Store 1-byte to memory */
  OP_STORE2,     /* 115  Store 2-byte to memory */
  OP_STORE3,     /* 116  */
  OP_STORE4,     /* 117  *(stack[top-1]) = stack[top] */
  OP_SUB,        /* 118  Subtract integers (two's complement). */
  OP_SUB3,       /* 119  */
  OP_SUBF,       /* 120  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
