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
  OP_CI4U3,      /*  24  */
  OP_CONSTGP3,   /*  25  push address pointer to stack. */
  OP_CONSTI1,    /*  26  */
  OP_CONSTI2,    /*  27  */
  OP_CONSTI3,    /*  28  */
  OP_CONSTI4,    /*  29  */
  OP_CONSTP3,    /*  30  */
  OP_CONSTU1,    /*  31  */
  OP_CONSTU2,    /*  32  */
  OP_CONSTU3,    /*  33  */
  OP_CONSTU4,    /*  34  */
  OP_CU1I3,      /*  35  */
  OP_CU2I3,      /*  36  */
  OP_CU3U2,      /*  37  */
  OP_CU3U4,      /*  38  */
  OP_CU4I3,      /*  39  */
  OP_CU4U3,      /*  40  */
  OP_CVFI3,      /*  41  */
  OP_CVIU3,      /*  42  */
  OP_CVUI3,      /*  43  */
  OP_DIVF4,      /*  44  Divide floats */
  OP_DIVI,       /*  45  Divide signed integers. */
  OP_DIVI3,      /*  46  */
  OP_DIVU,       /*  47  Divide unsigned integers. */
  OP_DIVU3,      /*  48  */
  OP_ENTER,      /*  49  Begin subroutine. */
  OP_EQ3,        /*  50  */
  OP_EQ4,        /*  51  Compare integers, jump if equal. */
  OP_EQF4,       /*  52  Compare floats, jump if equal */
  OP_EQU3,       /*  53  */
  OP_GEF4,       /*  54  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  55  */
  OP_GEI4,       /*  56  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  57  */
  OP_GEU4,       /*  58  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  59  Compare floats, jump if greater-than */
  OP_GTI3,       /*  60  */
  OP_GTI4,       /*  61  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  62  */
  OP_GTU4,       /*  63  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  64  Unconditional jump. */
  OP_LEAVE,      /*  65  End subroutine. */
  OP_LEF4,       /*  66  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  67  */
  OP_LEI4,       /*  68  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  69  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  70  */
  OP_LOAD1,      /*  71  Load 1-byte from memory */
  OP_LOAD2,      /*  72  Load 2-bytes from memory */
  OP_LOAD3,      /*  73  Load 3-bytes from memory */
  OP_LOAD4,      /*  74  Load 4-bytes from memory */
  OP_LOADF4,     /*  75  Load 4 byte float from memory */
  OP_LOCAL,      /*  76  Get local variable. */
  OP_LSH3,       /*  77  */
  OP_LSH4,       /*  78  Left-shift */
  OP_LTF,        /*  79  Compare floats, jump if less-than */
  OP_LTI3,       /*  80  */
  OP_LTI4,       /*  81  Compare integers, jump if less-than. */
  OP_LTU,        /*  82  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  83  */
  OP_MODI3,      /*  84  */
  OP_MODI4,      /*  85  Modulus (signed). */
  OP_MODU3,      /*  86  */
  OP_MODU4,      /*  87  Modulus (unsigned). */
  OP_MULF4,      /*  88  Multiply floats */
  OP_MULI3,      /*  89  */
  OP_MULI4,      /*  90  Multiply signed integers. */
  OP_MULU3,      /*  91  */
  OP_MULU4,      /*  92  Multiply unsigned integers. */
  OP_NE3,        /*  93  */
  OP_NE4,        /*  94  Compare integers, jump if not equal. */
  OP_NEF,        /*  95  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  96  Negate float */
  OP_NEGI3,      /*  97  */
  OP_NEGI4,      /*  98  Negate integer. */
  OP_POP,        /*  99  Discard top-of-stack. */
  OP_PUSH,       /* 100  Push to stack. */
  OP_RSHI3,      /* 101  */
  OP_RSHI4,      /* 102  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 103  */
  OP_RSHU4,      /* 104  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 105  Store 1-byte to memory */
  OP_STORE2,     /* 106  Store 2-byte to memory */
  OP_STORE3,     /* 107  */
  OP_STORE4,     /* 108  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 109  */
  OP_SUB4,       /* 110  Subtract integers (two's complement). */
  OP_SUBF4,      /* 111  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
