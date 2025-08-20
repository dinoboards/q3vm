#ifndef __OPCODES
#define __OPCODES

#include <stdint.h>

/** Enum for the virtual machine op codes */
typedef enum {
  OP_UNDEF,      /*   1  Error: VM halt */
  OP_IGNORE,     /*   2  No operation */
  OP_BREAK,      /*   3  vm->breakCount++ */
  OP_ENTER,      /*   4  Begin subroutine. */
  OP_LEAVE,      /*   5  End subroutine. */
  OP_CALL,       /*   6  Call subroutine. */
  OP_PUSH,       /*   7  Push to stack. */
  OP_POP,        /*   8  Discard top-of-stack. */
  OP_CONSTGP4,   /*   9  Load constant to stack. */
  OP_LOCAL,      /*  10  Get local variable. */
  OP_JUMP,       /*  11  Unconditional jump. */
  OP_EQ,         /*  12  Compare integers, jump if equal. */
  OP_NE,         /*  13  Compare integers, jump if not equal. */
  OP_LTI,        /*  14  Compare integers, jump if less-than. */
  OP_LEI,        /*  15  Compare integers, jump if less-than-or-equal. */
  OP_GTI,        /*  16  Compare integers, jump if greater-than. */
  OP_GEI,        /*  17  Compare integers, jump if greater-than-or-equal. */
  OP_LTU,        /*  18  Compare unsigned integers, jump if less-than */
  OP_LEU,        /*  19  Compare unsigned integers, jump if less-than-or-equal */
  OP_GTU,        /*  20  Compare unsigned integers, jump if greater-than */
  OP_GEU,        /*  21  Compare unsigned integers, jump if greater-than-or-equal */
  OP_EQF,        /*  22  Compare floats, jump if equal */
  OP_NEF,        /*  23  Compare floats, jump if not-equal */
  OP_LTF,        /*  24  Compare floats, jump if less-than */
  OP_LEF,        /*  25  Compare floats, jump if less-than-or-equal */
  OP_GTF,        /*  26  Compare floats, jump if greater-than */
  OP_GEF,        /*  27  Compare floats, jump if greater-than-or-equal */
  OP_LOAD1,      /*  28  Load 1-byte from memory */
  OP_LOAD2,      /*  29  Load 2-bytes from memory */
  OP_LOAD4,      /*  30  Load 4-bytes from memory */
  OP_LOADF4,     /*  31  Load 4 byte float from memory */
  OP_STORE1,     /*  32  Store 1-byte to memory */
  OP_STORE2,     /*  33  Store 2-byte to memory */
  OP_STORE4,     /*  34  *(stack[top-1]) = stack[top] */
  OP_STOREF4,    /*  35  *(stack[top-1]) = stack[top] */
  OP_ARG,        /*  36  Marshal argument */
  OP_BLOCK_COPY, /*  37  memcpy */
  OP_SEX8,       /*  38  Sign-Extend 8-bit */
  OP_SEX16,      /*  39  Sign-Extend 16-bit */
  OP_NEGI,       /*  40  Negate integer. */
  OP_ADD,        /*  41  Add integers (two's complement). */
  OP_SUB,        /*  42  Subtract integers (two's complement). */
  OP_DIVI,       /*  43  Divide signed integers. */
  OP_DIVU,       /*  44  Divide unsigned integers. */
  OP_MODI,       /*  45  Modulus (signed). */
  OP_MODU,       /*  46  Modulus (unsigned). */
  OP_MULI,       /*  47  Multiply signed integers. */
  OP_MULU,       /*  48  Multiply unsigned integers. */
  OP_BAND,       /*  49  Bitwise AND */
  OP_BOR,        /*  50  Bitwise OR */
  OP_BXOR,       /*  51  Bitwise eXclusive-OR */
  OP_BCOM,       /*  52  Bitwise COMplement */
  OP_LSH,        /*  53  Left-shift */
  OP_RSHI,       /*  54  Right-shift (algebraic; preserve sign) */
  OP_RSHU,       /*  55  Right-shift (bitwise; ignore sign) */
  OP_NEGF,       /*  56  Negate float */
  OP_ADDF,       /*  57  Add floats */
  OP_SUBF,       /*  58  Subtract floats */
  OP_DIVF,       /*  59  Divide floats */
  OP_MULF,       /*  60  Multiply floats */
  OP_CVIF,       /*  61  Convert to integer from float */
  OP_CVFI,       /*  62  Convert to float from integer */
  OP_CONSTU1,    /*  63  */
  OP_CONSTI1,    /*  64  */
  OP_CONSTU2,    /*  65  */
  OP_CONSTI2,    /*  66  */
  OP_CONSTU4,    /*  67  */
  OP_CONSTI4,    /*  68  */
  OP_CONSTF4,    /*  69  */
  OP_CONSTP4,    /*  70  */
  OP_LOAD3,      /*  71  Load 3-bytes from memory */
  OP_ADD3,       /*  72  */
  OP_BAND3,      /*  73  */
  OP_BCOM3,      /*  74  */
  OP_BOR3,       /*  75  */
  OP_BXOR3,      /*  76  */
  OP_CONSTI3,    /*  77  */
  OP_CONSTU3,    /*  78  */
  OP_CVFI3,      /*  79  */
  OP_CVIU3,      /*  80  */
  OP_CVUI3,      /*  81  */
  OP_DIVI3,      /*  82  */
  OP_DIVU3,      /*  83  */
  OP_EQ3,        /*  84  */
  OP_GEI3,       /*  85  */
  OP_GEU3,       /*  86  */
  OP_GTI3,       /*  87  */
  OP_GTU3,       /*  88  */
  OP_LEI3,       /*  89  */
  OP_LEU3,       /*  90  */
  OP_LSH3,       /*  91  */
  OP_LTI3,       /*  92  */
  OP_LTU3,       /*  93  */
  OP_MODI3,      /*  94  */
  OP_MODU3,      /*  95  */
  OP_MULI3,      /*  96  */
  OP_MULU3,      /*  97  */
  OP_NE3,        /*  98  */
  OP_NEGI3,      /*  99  */
  OP_RSHI3,      /* 100  */
  OP_RSHU3,      /* 101  */
  OP_SEX24,      /* 102  */
  OP_SEX8_3,     /* 103  */
  OP_STORE3,     /* 104  */
  OP_SUB3,       /* 105  */
  OP_CONSTGP3,   /* 106  */
  OP_CONSTP3,    /* 107  */
  OP_ARGF,       /* 108  */
  OP_ARG4,       /* 109  */
  OP_EQU3,       /* 110  */
  OP_CI1I3,      /* 111  */
  OP_CI3I2,      /* 112  */
  OP_CI2I3,      /* 113  */
  OP_CU2I3,      /* 114  */
  OP_CU3U2,      /* 115  */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
