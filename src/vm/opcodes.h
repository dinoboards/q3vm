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
  OP_CI3I1,      /*  22  */
  OP_CI3I2,      /*  23  */
  OP_CI3I4,      /*  24  */
  OP_CI3U4,      /*  25  */
  OP_CI4F4,      /*  26  Convert to integer from float */
  OP_CI4I3,      /*  27  */
  OP_CI4U3,      /*  28  */
  OP_CONSTGP3,   /*  29  push address pointer to stack. */
  OP_CONSTI1,    /*  30  */
  OP_CONSTI2,    /*  31  */
  OP_CONSTI3,    /*  32  */
  OP_CONSTI4,    /*  33  */
  OP_CONSTP3,    /*  34  */
  OP_CONSTU1,    /*  35  */
  OP_CONSTU2,    /*  36  */
  OP_CONSTU3,    /*  37  */
  OP_CONSTU4,    /*  38  */
  OP_CU1I3,      /*  39  */
  OP_CU2I3,      /*  40  */
  OP_CU3U2,      /*  41  */
  OP_CU3U4,      /*  42  */
  OP_CU4I3,      /*  43  */
  OP_CU4U3,      /*  44  */
  OP_CVFI3,      /*  45  */
  OP_CVIU3,      /*  46  */
  OP_CVUI3,      /*  47  */
  OP_DIVF4,      /*  48  Divide floats */
  OP_DIVI,       /*  49  Divide signed integers. */
  OP_DIVI3,      /*  50  */
  OP_DIVU,       /*  51  Divide unsigned integers. */
  OP_DIVU3,      /*  52  */
  OP_ENTER,      /*  53  Begin subroutine. */
  OP_EQ3,        /*  54  */
  OP_EQ4,        /*  55  Compare integers, jump if equal. */
  OP_EQF4,       /*  56  Compare floats, jump if equal */
  OP_EQU3,       /*  57  */
  OP_GEF4,       /*  58  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  59  */
  OP_GEI4,       /*  60  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  61  */
  OP_GEU4,       /*  62  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  63  Compare floats, jump if greater-than */
  OP_GTI3,       /*  64  */
  OP_GTI4,       /*  65  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  66  */
  OP_GTU4,       /*  67  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  68  Unconditional jump. */
  OP_LEAVE,      /*  69  End subroutine. */
  OP_LEF4,       /*  70  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  71  */
  OP_LEI4,       /*  72  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  73  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  74  */
  OP_LOAD1,      /*  75  Load 1-byte from memory */
  OP_LOAD2,      /*  76  Load 2-bytes from memory */
  OP_LOAD3,      /*  77  Load 3-bytes from memory */
  OP_LOAD4,      /*  78  Load 4-bytes from memory */
  OP_LOADF4,     /*  79  Load 4 byte float from memory */
  OP_LOCAL,      /*  80  Get local variable. */
  OP_LSH3,       /*  81  */
  OP_LSH4,       /*  82  Left-shift */
  OP_LTF,        /*  83  Compare floats, jump if less-than */
  OP_LTI3,       /*  84  */
  OP_LTI4,       /*  85  Compare integers, jump if less-than. */
  OP_LTU,        /*  86  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  87  */
  OP_MODI3,      /*  88  */
  OP_MODI4,      /*  89  Modulus (signed). */
  OP_MODU3,      /*  90  */
  OP_MODU4,      /*  91  Modulus (unsigned). */
  OP_MULF4,      /*  92  Multiply floats */
  OP_MULI3,      /*  93  */
  OP_MULI4,      /*  94  Multiply signed integers. */
  OP_MULU3,      /*  95  */
  OP_MULU4,      /*  96  Multiply unsigned integers. */
  OP_NE3,        /*  97  */
  OP_NE4,        /*  98  Compare integers, jump if not equal. */
  OP_NEF,        /*  99  Compare floats, jump if not-equal */
  OP_NEGF4,      /* 100  Negate float */
  OP_NEGI3,      /* 101  */
  OP_NEGI4,      /* 102  Negate integer. */
  OP_POP,        /* 103  Discard top-of-stack. */
  OP_PUSH,       /* 104  Push to stack. */
  OP_RSHI3,      /* 105  */
  OP_RSHI4,      /* 106  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 107  */
  OP_RSHU4,      /* 108  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 109  Store 1-byte to memory */
  OP_STORE2,     /* 110  Store 2-byte to memory */
  OP_STORE3,     /* 111  */
  OP_STORE4,     /* 112  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 113  */
  OP_SUB4,       /* 114  Subtract integers (two's complement). */
  OP_SUBF4,      /* 115  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
