#ifndef __OPCODES
#define __OPCODES

#include <stdint.h>

/** Enum for the virtual machine op codes */
typedef enum {
  OP_UNDEF,      /*   0  Error: VM halt */
  OP_IGNORE,     /*   1  No operation */
  OP_BREAK,      /*   2  vm->breakCount++ */
  OP_ADD,        /*   3  Add integers (two's complement). */
  OP_ADD3,       /*   4  */
  OP_ADDF,       /*   5  Add floats */
  OP_ARG,        /*   6  Marshal argument */
  OP_ARG4,       /*   7  */
  OP_ARGF,       /*   8  */
  OP_BAND,       /*   9  Bitwise AND */
  OP_BAND3,      /*  10  */
  OP_BCOM,       /*  11  Bitwise COMplement */
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
  OP_CU4U3,      /*  44  */
  OP_CVFI,       /*  45  Convert to float from integer */
  OP_CVFI3,      /*  46  */
  OP_CVIF,       /*  47  Convert to integer from float */
  OP_CVIU3,      /*  48  */
  OP_CVUI3,      /*  49  */
  OP_DIVF,       /*  50  Divide floats */
  OP_DIVI,       /*  51  Divide signed integers. */
  OP_DIVI3,      /*  52  */
  OP_DIVU,       /*  53  Divide unsigned integers. */
  OP_DIVU3,      /*  54  */
  OP_ENTER,      /*  55  Begin subroutine. */
  OP_EQ,         /*  56  Compare integers, jump if equal. */
  OP_EQ3,        /*  57  */
  OP_EQF,        /*  58  Compare floats, jump if equal */
  OP_EQU3,       /*  59  */
  OP_GEF,        /*  60  Compare floats, jump if greater-than-or-equal */
  OP_GEI,        /*  61  Compare integers, jump if greater-than-or-equal. */
  OP_GEI3,       /*  62  */
  OP_GEU,        /*  63  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GEU3,       /*  64  */
  OP_GTF,        /*  65  Compare floats, jump if greater-than */
  OP_GTI,        /*  66  Compare integers, jump if greater-than. */
  OP_GTI3,       /*  67  */
  OP_GTU,        /*  68  Compare unsigned integers, jump if greater-than */
  OP_GTU3,       /*  69  */
  OP_JUMP,       /*  70  Unconditional jump. */
  OP_LEAVE,      /*  71  End subroutine. */
  OP_LEF,        /*  72  Compare floats, jump if less-than-or-equal */
  OP_LEI,        /*  73  Compare integers, jump if less-than-or-equal. */
  OP_LEI3,       /*  74  */
  OP_LEU,        /*  75  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  76  */
  OP_LOAD1,      /*  77  Load 1-byte from memory */
  OP_LOAD2,      /*  78  Load 2-bytes from memory */
  OP_LOAD3,      /*  79  Load 3-bytes from memory */
  OP_LOAD4,      /*  80  Load 4-bytes from memory */
  OP_LOADF4,     /*  81  Load 4 byte float from memory */
  OP_LOCAL,      /*  82  Get local variable. */
  OP_LSH,        /*  83  Left-shift */
  OP_LSH3,       /*  84  */
  OP_LTF,        /*  85  Compare floats, jump if less-than */
  OP_LTI,        /*  86  Compare integers, jump if less-than. */
  OP_LTI3,       /*  87  */
  OP_LTU,        /*  88  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  89  */
  OP_MODI,       /*  90  Modulus (signed). */
  OP_MODI3,      /*  91  */
  OP_MODU,       /*  92  Modulus (unsigned). */
  OP_MODU3,      /*  93  */
  OP_MULF,       /*  94  Multiply floats */
  OP_MULI,       /*  95  Multiply signed integers. */
  OP_MULI3,      /*  96  */
  OP_MULU,       /*  97  Multiply unsigned integers. */
  OP_MULU3,      /*  98  */
  OP_NE,         /*  99  Compare integers, jump if not equal. */
  OP_NE3,        /* 100  */
  OP_NEF,        /* 101  Compare floats, jump if not-equal */
  OP_NEGF,       /* 102  Negate float */
  OP_NEGI,       /* 103  Negate integer. */
  OP_NEGI3,      /* 104  */
  OP_POP,        /* 105  Discard top-of-stack. */
  OP_PUSH,       /* 106  Push to stack. */
  OP_RSHI,       /* 107  Right-shift (algebraic; preserve sign) */
  OP_RSHI3,      /* 108  */
  OP_RSHU,       /* 109  Right-shift (bitwise; ignore sign) */
  OP_RSHU3,      /* 110  */
  OP_SEX24,      /* 111  */
  OP_SEX8_3,     /* 112  */
  OP_STORE1,     /* 113  Store 1-byte to memory */
  OP_STORE2,     /* 114  Store 2-byte to memory */
  OP_STORE3,     /* 115  */
  OP_STORE4,     /* 116  *(stack[top-1]) = stack[top] */
  OP_STOREF4,    /* 117  *(stack[top-1]) = stack[top] */
  OP_SUB,        /* 118  Subtract integers (two's complement). */
  OP_SUB3,       /* 119  */
  OP_SUBF,       /* 120  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
