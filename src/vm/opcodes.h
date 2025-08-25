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
  OP_CI3s4,      /*  22  */
  OP_CI4F4,      /*  23  Convert to integer from float */
  OP_CI4I3,      /*  24  */
  OP_CI4U3,      /*  25  */
  OP_CONSTGP3,   /*  26  push address pointer to stack. */
  OP_CONSTI1,    /*  27  */
  OP_CONSTI2,    /*  28  */
  OP_CONSTI3,    /*  29  */
  OP_CONSTI4,    /*  30  */
  OP_CONSTP3,    /*  31  */
  OP_CONSTU1,    /*  32  */
  OP_CONSTU2,    /*  33  */
  OP_CONSTU3,    /*  34  */
  OP_CONSTU4,    /*  35  */
  OP_CU1I3,      /*  36  */
  OP_CU2I3,      /*  37  */
  OP_CU3U2,      /*  38  */
  OP_CU3U4,      /*  39  */
  OP_CU4I3,      /*  40  */
  OP_CU4U3,      /*  41  */
  OP_CVFI3,      /*  42  */
  OP_CVIU3,      /*  43  */
  OP_CVUI3,      /*  44  */
  OP_DIVF4,      /*  45  Divide floats */
  OP_DIVI,       /*  46  Divide signed integers. */
  OP_DIVI3,      /*  47  */
  OP_DIVU,       /*  48  Divide unsigned integers. */
  OP_DIVU3,      /*  49  */
  OP_ENTER,      /*  50  Begin subroutine. */
  OP_EQ3,        /*  51  */
  OP_EQ4,        /*  52  Compare integers, jump if equal. */
  OP_EQF4,       /*  53  Compare floats, jump if equal */
  OP_EQU3,       /*  54  */
  OP_GEF4,       /*  55  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  56  */
  OP_GEI4,       /*  57  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  58  */
  OP_GEU4,       /*  59  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  60  Compare floats, jump if greater-than */
  OP_GTI3,       /*  61  */
  OP_GTI4,       /*  62  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  63  */
  OP_GTU4,       /*  64  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  65  Unconditional jump. */
  OP_LEAVE,      /*  66  End subroutine. */
  OP_LEF4,       /*  67  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  68  */
  OP_LEI4,       /*  69  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  70  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  71  */
  OP_LOAD1,      /*  72  Load 1-byte from memory */
  OP_LOAD2,      /*  73  Load 2-bytes from memory */
  OP_LOAD3,      /*  74  Load 3-bytes from memory */
  OP_LOAD4,      /*  75  Load 4-bytes from memory */
  OP_LOADF4,     /*  76  Load 4 byte float from memory */
  OP_LOCAL,      /*  77  Get local variable. */
  OP_LSH3,       /*  78  */
  OP_LSH4,       /*  79  Left-shift */
  OP_LTF,        /*  80  Compare floats, jump if less-than */
  OP_LTI3,       /*  81  */
  OP_LTI4,       /*  82  Compare integers, jump if less-than. */
  OP_LTU,        /*  83  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  84  */
  OP_MODI3,      /*  85  */
  OP_MODI4,      /*  86  Modulus (signed). */
  OP_MODU3,      /*  87  */
  OP_MODU4,      /*  88  Modulus (unsigned). */
  OP_MULF4,      /*  89  Multiply floats */
  OP_MULI3,      /*  90  */
  OP_MULI4,      /*  91  Multiply signed integers. */
  OP_MULU3,      /*  92  */
  OP_MULU4,      /*  93  Multiply unsigned integers. */
  OP_NE3,        /*  94  */
  OP_NE4,        /*  95  Compare integers, jump if not equal. */
  OP_NEF,        /*  96  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  97  Negate float */
  OP_NEGI3,      /*  98  */
  OP_NEGI4,      /*  99  Negate integer. */
  OP_POP,        /* 100  Discard top-of-stack. */
  OP_PUSH,       /* 101  Push to stack. */
  OP_RSHI3,      /* 102  */
  OP_RSHI4,      /* 103  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 104  */
  OP_RSHU4,      /* 105  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 106  Store 1-byte to memory */
  OP_STORE2,     /* 107  Store 2-byte to memory */
  OP_STORE3,     /* 108  */
  OP_STORE4,     /* 109  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 110  */
  OP_SUB4,       /* 111  Subtract integers (two's complement). */
  OP_SUBF4,      /* 112  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
