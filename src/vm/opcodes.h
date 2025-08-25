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
  OP_CI3I2,      /*  22  */
  OP_CI3I4,      /*  23  */
  OP_CI3U4,      /*  24  */
  OP_CI4F4,      /*  25  Convert to integer from float */
  OP_CI4I3,      /*  26  */
  OP_CI4U3,      /*  27  */
  OP_CONSTGP3,   /*  28  push address pointer to stack. */
  OP_CONSTI1,    /*  29  */
  OP_CONSTI2,    /*  30  */
  OP_CONSTI3,    /*  31  */
  OP_CONSTI4,    /*  32  */
  OP_CONSTP3,    /*  33  */
  OP_CONSTU1,    /*  34  */
  OP_CONSTU2,    /*  35  */
  OP_CONSTU3,    /*  36  */
  OP_CONSTU4,    /*  37  */
  OP_CU1I3,      /*  38  */
  OP_CU2I3,      /*  39  */
  OP_CU3U2,      /*  40  */
  OP_CU3U4,      /*  41  */
  OP_CU4I3,      /*  42  */
  OP_CU4U3,      /*  43  */
  OP_CVFI3,      /*  44  */
  OP_CVIU3,      /*  45  */
  OP_CVUI3,      /*  46  */
  OP_DIVF4,      /*  47  Divide floats */
  OP_DIVI,       /*  48  Divide signed integers. */
  OP_DIVI3,      /*  49  */
  OP_DIVU,       /*  50  Divide unsigned integers. */
  OP_DIVU3,      /*  51  */
  OP_ENTER,      /*  52  Begin subroutine. */
  OP_EQ3,        /*  53  */
  OP_EQ4,        /*  54  Compare integers, jump if equal. */
  OP_EQF4,       /*  55  Compare floats, jump if equal */
  OP_EQU3,       /*  56  */
  OP_GEF4,       /*  57  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  58  */
  OP_GEI4,       /*  59  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  60  */
  OP_GEU4,       /*  61  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  62  Compare floats, jump if greater-than */
  OP_GTI3,       /*  63  */
  OP_GTI4,       /*  64  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  65  */
  OP_GTU4,       /*  66  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  67  Unconditional jump. */
  OP_LEAVE,      /*  68  End subroutine. */
  OP_LEF4,       /*  69  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  70  */
  OP_LEI4,       /*  71  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  72  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  73  */
  OP_LOAD1,      /*  74  Load 1-byte from memory */
  OP_LOAD2,      /*  75  Load 2-bytes from memory */
  OP_LOAD3,      /*  76  Load 3-bytes from memory */
  OP_LOAD4,      /*  77  Load 4-bytes from memory */
  OP_LOADF4,     /*  78  Load 4 byte float from memory */
  OP_LOCAL,      /*  79  Get local variable. */
  OP_LSH3,       /*  80  */
  OP_LSH4,       /*  81  Left-shift */
  OP_LTF,        /*  82  Compare floats, jump if less-than */
  OP_LTI3,       /*  83  */
  OP_LTI4,       /*  84  Compare integers, jump if less-than. */
  OP_LTU,        /*  85  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  86  */
  OP_MODI3,      /*  87  */
  OP_MODI4,      /*  88  Modulus (signed). */
  OP_MODU3,      /*  89  */
  OP_MODU4,      /*  90  Modulus (unsigned). */
  OP_MULF4,      /*  91  Multiply floats */
  OP_MULI3,      /*  92  */
  OP_MULI4,      /*  93  Multiply signed integers. */
  OP_MULU3,      /*  94  */
  OP_MULU4,      /*  95  Multiply unsigned integers. */
  OP_NE3,        /*  96  */
  OP_NE4,        /*  97  Compare integers, jump if not equal. */
  OP_NEF,        /*  98  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  99  Negate float */
  OP_NEGI3,      /* 100  */
  OP_NEGI4,      /* 101  Negate integer. */
  OP_POP,        /* 102  Discard top-of-stack. */
  OP_PUSH,       /* 103  Push to stack. */
  OP_RSHI3,      /* 104  */
  OP_RSHI4,      /* 105  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 106  */
  OP_RSHU4,      /* 107  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 108  Store 1-byte to memory */
  OP_STORE2,     /* 109  Store 2-byte to memory */
  OP_STORE3,     /* 110  */
  OP_STORE4,     /* 111  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 112  */
  OP_SUB4,       /* 113  Subtract integers (two's complement). */
  OP_SUBF4,      /* 114  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
