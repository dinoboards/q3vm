#ifndef __OPCODES
#define __OPCODES

#include <stdint.h>

/** Enum for the virtual machine op codes */
typedef enum {
  OP_UNDEF,      /*   1  Error: VM halt */
  OP_IGNORE,     /*   2  No operation */
  OP_BREAK,      /*   3  vm->breakCount++ */
  OP_ADD,        /*   4  Add integers (two's complement). */
  OP_ADD3,       /*   5  */
  OP_ADDF,       /*   6  Add floats */
  OP_ARG,        /*   7  Marshal argument */
  OP_ARG4,       /*   8  */
  OP_ARGF,       /*   9  */
  OP_BAND,       /*  10  Bitwise AND */
  OP_BAND3,      /*  11  */
  OP_BCOM,       /*  12  Bitwise COMplement */
  OP_BCOM3,      /*  13  */
  OP_BLOCK_COPY, /*  14  memcpy */
  OP_BOR,        /*  15  Bitwise OR */
  OP_BOR3,       /*  16  */
  OP_BXOR,       /*  17  Bitwise eXclusive-OR */
  OP_BXOR3,      /*  18  */
  OP_CALL,       /*  19  Call subroutine. */
  OP_CI1I3,      /*  20  */
  OP_CI2I3,      /*  21  */
  OP_CI3I1,      /*  22  */
  OP_CI3I2,      /*  23  */
  OP_CONSTF4,    /*  24  */
  OP_CONSTGP3,   /*  25  */
  OP_CONSTGP4,   /*  26  Load constant to stack. */
  OP_CONSTI1,    /*  27  */
  OP_CONSTI2,    /*  28  */
  OP_CONSTI3,    /*  29  */
  OP_CONSTI4,    /*  30  */
  OP_CONSTP3,    /*  31  */
  OP_CONSTP4,    /*  32  */
  OP_CONSTU1,    /*  33  */
  OP_CONSTU2,    /*  34  */
  OP_CONSTU3,    /*  35  */
  OP_CONSTU4,    /*  36  */
  OP_CU2I3,      /*  37  */
  OP_CU3U2,      /*  38  */
  OP_CVFI,       /*  39  Convert to float from integer */
  OP_CVFI3,      /*  40  */
  OP_CVIF,       /*  41  Convert to integer from float */
  OP_CVIU3,      /*  42  */
  OP_CVUI3,      /*  43  */
  OP_DIVF,       /*  44  Divide floats */
  OP_DIVI,       /*  45  Divide signed integers. */
  OP_DIVI3,      /*  46  */
  OP_DIVU,       /*  47  Divide unsigned integers. */
  OP_DIVU3,      /*  48  */
  OP_ENTER,      /*  49  Begin subroutine. */
  OP_EQ,         /*  50  Compare integers, jump if equal. */
  OP_EQ3,        /*  51  */
  OP_EQF,        /*  52  Compare floats, jump if equal */
  OP_EQU3,       /*  53  */
  OP_GEF,        /*  54  Compare floats, jump if greater-than-or-equal */
  OP_GEI,        /*  55  Compare integers, jump if greater-than-or-equal. */
  OP_GEI3,       /*  56  */
  OP_GEU,        /*  57  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GEU3,       /*  58  */
  OP_GTF,        /*  59  Compare floats, jump if greater-than */
  OP_GTI,        /*  60  Compare integers, jump if greater-than. */
  OP_GTI3,       /*  61  */
  OP_GTU,        /*  62  Compare unsigned integers, jump if greater-than */
  OP_GTU3,       /*  63  */
  OP_JUMP,       /*  64  Unconditional jump. */
  OP_LEAVE,      /*  65  End subroutine. */
  OP_LEF,        /*  66  Compare floats, jump if less-than-or-equal */
  OP_LEI,        /*  67  Compare integers, jump if less-than-or-equal. */
  OP_LEI3,       /*  68  */
  OP_LEU,        /*  69  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  70  */
  OP_LOAD1,      /*  71  Load 1-byte from memory */
  OP_LOAD2,      /*  72  Load 2-bytes from memory */
  OP_LOAD3,      /*  73  Load 3-bytes from memory */
  OP_LOAD4,      /*  74  Load 4-bytes from memory */
  OP_LOADF4,     /*  75  Load 4 byte float from memory */
  OP_LOCAL,      /*  76  Get local variable. */
  OP_LSH,        /*  77  Left-shift */
  OP_LSH3,       /*  78  */
  OP_LTF,        /*  79  Compare floats, jump if less-than */
  OP_LTI,        /*  80  Compare integers, jump if less-than. */
  OP_LTI3,       /*  81  */
  OP_LTU,        /*  82  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  83  */
  OP_MODI,       /*  84  Modulus (signed). */
  OP_MODI3,      /*  85  */
  OP_MODU,       /*  86  Modulus (unsigned). */
  OP_MODU3,      /*  87  */
  OP_MULF,       /*  88  Multiply floats */
  OP_MULI,       /*  89  Multiply signed integers. */
  OP_MULI3,      /*  90  */
  OP_MULU,       /*  91  Multiply unsigned integers. */
  OP_MULU3,      /*  92  */
  OP_NE,         /*  93  Compare integers, jump if not equal. */
  OP_NE3,        /*  94  */
  OP_NEF,        /*  95  Compare floats, jump if not-equal */
  OP_NEGF,       /*  96  Negate float */
  OP_NEGI,       /*  97  Negate integer. */
  OP_NEGI3,      /*  98  */
  OP_POP,        /*  99  Discard top-of-stack. */
  OP_PUSH,       /* 100  Push to stack. */
  OP_RSHI,       /* 101  Right-shift (algebraic; preserve sign) */
  OP_RSHI3,      /* 102  */
  OP_RSHU,       /* 103  Right-shift (bitwise; ignore sign) */
  OP_RSHU3,      /* 104  */
  OP_SEX16,      /* 105  Sign-Extend 16-bit */
  OP_SEX24,      /* 106  */
  OP_SEX8,       /* 107  Sign-Extend 8-bit */
  OP_SEX8_3,     /* 108  */
  OP_STORE1,     /* 109  Store 1-byte to memory */
  OP_STORE2,     /* 110  Store 2-byte to memory */
  OP_STORE3,     /* 111  */
  OP_STORE4,     /* 112  *(stack[top-1]) = stack[top] */
  OP_STOREF4,    /* 113  *(stack[top-1]) = stack[top] */
  OP_SUB,        /* 114  Subtract integers (two's complement). */
  OP_SUB3,       /* 115  */
  OP_SUBF,       /* 116  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
