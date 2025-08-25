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
  OP_CI3I4,      /*  22  */
  OP_CI3U4,      /*  23  */
  OP_CI4F4,      /*  24  Convert to integer from float */
  OP_CI4I3,      /*  25  */
  OP_CI4U3,      /*  26  */
  OP_CONSTGP3,   /*  27  push address pointer to stack. */
  OP_CONSTI1,    /*  28  */
  OP_CONSTI2,    /*  29  */
  OP_CONSTI3,    /*  30  */
  OP_CONSTI4,    /*  31  */
  OP_CONSTP3,    /*  32  */
  OP_CONSTU1,    /*  33  */
  OP_CONSTU2,    /*  34  */
  OP_CONSTU3,    /*  35  */
  OP_CONSTU4,    /*  36  */
  OP_CU1I3,      /*  37  */
  OP_CU2I3,      /*  38  */
  OP_CU3U2,      /*  39  */
  OP_CU3U4,      /*  40  */
  OP_CU4I3,      /*  41  */
  OP_CU4U3,      /*  42  */
  OP_CVFI3,      /*  43  */
  OP_CVIU3,      /*  44  */
  OP_CVUI3,      /*  45  */
  OP_DIVF4,      /*  46  Divide floats */
  OP_DIVI,       /*  47  Divide signed integers. */
  OP_DIVI3,      /*  48  */
  OP_DIVU,       /*  49  Divide unsigned integers. */
  OP_DIVU3,      /*  50  */
  OP_ENTER,      /*  51  Begin subroutine. */
  OP_EQ3,        /*  52  */
  OP_EQ4,        /*  53  Compare integers, jump if equal. */
  OP_EQF4,       /*  54  Compare floats, jump if equal */
  OP_EQU3,       /*  55  */
  OP_GEF4,       /*  56  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  57  */
  OP_GEI4,       /*  58  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  59  */
  OP_GEU4,       /*  60  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  61  Compare floats, jump if greater-than */
  OP_GTI3,       /*  62  */
  OP_GTI4,       /*  63  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  64  */
  OP_GTU4,       /*  65  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  66  Unconditional jump. */
  OP_LEAVE,      /*  67  End subroutine. */
  OP_LEF4,       /*  68  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  69  */
  OP_LEI4,       /*  70  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  71  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  72  */
  OP_LOAD1,      /*  73  Load 1-byte from memory */
  OP_LOAD2,      /*  74  Load 2-bytes from memory */
  OP_LOAD3,      /*  75  Load 3-bytes from memory */
  OP_LOAD4,      /*  76  Load 4-bytes from memory */
  OP_LOADF4,     /*  77  Load 4 byte float from memory */
  OP_LOCAL,      /*  78  Get local variable. */
  OP_LSH3,       /*  79  */
  OP_LSH4,       /*  80  Left-shift */
  OP_LTF,        /*  81  Compare floats, jump if less-than */
  OP_LTI3,       /*  82  */
  OP_LTI4,       /*  83  Compare integers, jump if less-than. */
  OP_LTU,        /*  84  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  85  */
  OP_MODI3,      /*  86  */
  OP_MODI4,      /*  87  Modulus (signed). */
  OP_MODU3,      /*  88  */
  OP_MODU4,      /*  89  Modulus (unsigned). */
  OP_MULF4,      /*  90  Multiply floats */
  OP_MULI3,      /*  91  */
  OP_MULI4,      /*  92  Multiply signed integers. */
  OP_MULU3,      /*  93  */
  OP_MULU4,      /*  94  Multiply unsigned integers. */
  OP_NE3,        /*  95  */
  OP_NE4,        /*  96  Compare integers, jump if not equal. */
  OP_NEF,        /*  97  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  98  Negate float */
  OP_NEGI3,      /*  99  */
  OP_NEGI4,      /* 100  Negate integer. */
  OP_POP,        /* 101  Discard top-of-stack. */
  OP_PUSH,       /* 102  Push to stack. */
  OP_RSHI3,      /* 103  */
  OP_RSHI4,      /* 104  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 105  */
  OP_RSHU4,      /* 106  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 107  Store 1-byte to memory */
  OP_STORE2,     /* 108  Store 2-byte to memory */
  OP_STORE3,     /* 109  */
  OP_STORE4,     /* 110  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 111  */
  OP_SUB4,       /* 112  Subtract integers (two's complement). */
  OP_SUBF4,      /* 113  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
