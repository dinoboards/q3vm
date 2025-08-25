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
  OP_CI2I4,      /*  21  Sign-Extend 16-bit */
  OP_CI3F4,      /*  22  */
  OP_CI3I1,      /*  23  */
  OP_CI3I2,      /*  24  */
  OP_CI3I4,      /*  25  */
  OP_CI3U4,      /*  26  */
  OP_CI4F4,      /*  27  Convert to integer from float */
  OP_CI4I3,      /*  28  */
  OP_CI4U3,      /*  29  */
  OP_CONSTGP3,   /*  30  push address pointer to stack. */
  OP_CONSTI1,    /*  31  */
  OP_CONSTI2,    /*  32  */
  OP_CONSTI3,    /*  33  */
  OP_CONSTI4,    /*  34  */
  OP_CONSTP3,    /*  35  */
  OP_CONSTU1,    /*  36  */
  OP_CONSTU2,    /*  37  */
  OP_CONSTU3,    /*  38  */
  OP_CONSTU4,    /*  39  */
  OP_CU1I3,      /*  40  */
  OP_CU2I3,      /*  41  */
  OP_CU3U2,      /*  42  */
  OP_CU3U4,      /*  43  */
  OP_CU4I3,      /*  44  */
  OP_CU4U3,      /*  45  */
  OP_CVFI3,      /*  46  */
  OP_CVIU3,      /*  47  */
  OP_CVUI3,      /*  48  */
  OP_DIVF4,      /*  49  Divide floats */
  OP_DIVI,       /*  50  Divide signed integers. */
  OP_DIVI3,      /*  51  */
  OP_DIVU,       /*  52  Divide unsigned integers. */
  OP_DIVU3,      /*  53  */
  OP_ENTER,      /*  54  Begin subroutine. */
  OP_EQ3,        /*  55  */
  OP_EQ4,        /*  56  Compare integers, jump if equal. */
  OP_EQF4,       /*  57  Compare floats, jump if equal */
  OP_EQU3,       /*  58  */
  OP_GEF4,       /*  59  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  60  */
  OP_GEI4,       /*  61  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  62  */
  OP_GEU4,       /*  63  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  64  Compare floats, jump if greater-than */
  OP_GTI3,       /*  65  */
  OP_GTI4,       /*  66  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  67  */
  OP_GTU4,       /*  68  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  69  Unconditional jump. */
  OP_LEAVE,      /*  70  End subroutine. */
  OP_LEF4,       /*  71  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  72  */
  OP_LEI4,       /*  73  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  74  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  75  */
  OP_LOAD1,      /*  76  Load 1-byte from memory */
  OP_LOAD2,      /*  77  Load 2-bytes from memory */
  OP_LOAD3,      /*  78  Load 3-bytes from memory */
  OP_LOAD4,      /*  79  Load 4-bytes from memory */
  OP_LOADF4,     /*  80  Load 4 byte float from memory */
  OP_LOCAL,      /*  81  Get local variable. */
  OP_LSH3,       /*  82  */
  OP_LSH4,       /*  83  Left-shift */
  OP_LTF,        /*  84  Compare floats, jump if less-than */
  OP_LTI3,       /*  85  */
  OP_LTI4,       /*  86  Compare integers, jump if less-than. */
  OP_LTU,        /*  87  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  88  */
  OP_MODI3,      /*  89  */
  OP_MODI4,      /*  90  Modulus (signed). */
  OP_MODU3,      /*  91  */
  OP_MODU4,      /*  92  Modulus (unsigned). */
  OP_MULF4,      /*  93  Multiply floats */
  OP_MULI3,      /*  94  */
  OP_MULI4,      /*  95  Multiply signed integers. */
  OP_MULU3,      /*  96  */
  OP_MULU4,      /*  97  Multiply unsigned integers. */
  OP_NE3,        /*  98  */
  OP_NE4,        /*  99  Compare integers, jump if not equal. */
  OP_NEF,        /* 100  Compare floats, jump if not-equal */
  OP_NEGF4,      /* 101  Negate float */
  OP_NEGI3,      /* 102  */
  OP_NEGI4,      /* 103  Negate integer. */
  OP_POP,        /* 104  Discard top-of-stack. */
  OP_PUSH,       /* 105  Push to stack. */
  OP_RSHI3,      /* 106  */
  OP_RSHI4,      /* 107  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 108  */
  OP_RSHU4,      /* 109  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 110  Store 1-byte to memory */
  OP_STORE2,     /* 111  Store 2-byte to memory */
  OP_STORE3,     /* 112  */
  OP_STORE4,     /* 113  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 114  */
  OP_SUB4,       /* 115  Subtract integers (two's complement). */
  OP_SUBF4,      /* 116  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
