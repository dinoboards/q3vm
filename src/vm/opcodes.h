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
  OP_CONSTGP3,   /*  24  push address pointer to stack. */
  OP_CONSTI1,    /*  25  */
  OP_CONSTI2,    /*  26  */
  OP_CONSTI3,    /*  27  */
  OP_CONSTI4,    /*  28  */
  OP_CONSTP3,    /*  29  */
  OP_CONSTU1,    /*  30  */
  OP_CONSTU2,    /*  31  */
  OP_CONSTU3,    /*  32  */
  OP_CONSTU4,    /*  33  */
  OP_CU1I3,      /*  34  */
  OP_CU2I3,      /*  35  */
  OP_CU3U2,      /*  36  */
  OP_CU3U4,      /*  37  */
  OP_CU4I3,      /*  38  */
  OP_CU4U3,      /*  39  */
  OP_CVFI3,      /*  40  */
  OP_CVIU3,      /*  41  */
  OP_CVUI3,      /*  42  */
  OP_DIVF4,      /*  43  Divide floats */
  OP_DIVI,       /*  44  Divide signed integers. */
  OP_DIVI3,      /*  45  */
  OP_DIVU,       /*  46  Divide unsigned integers. */
  OP_DIVU3,      /*  47  */
  OP_ENTER,      /*  48  Begin subroutine. */
  OP_EQ3,        /*  49  */
  OP_EQ4,        /*  50  Compare integers, jump if equal. */
  OP_EQF4,       /*  51  Compare floats, jump if equal */
  OP_EQU3,       /*  52  */
  OP_GEF4,       /*  53  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  54  */
  OP_GEI4,       /*  55  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  56  */
  OP_GEU4,       /*  57  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  58  Compare floats, jump if greater-than */
  OP_GTI3,       /*  59  */
  OP_GTI4,       /*  60  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  61  */
  OP_GTU4,       /*  62  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  63  Unconditional jump. */
  OP_LEAVE,      /*  64  End subroutine. */
  OP_LEF4,       /*  65  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  66  */
  OP_LEI4,       /*  67  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  68  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  69  */
  OP_LOAD1,      /*  70  Load 1-byte from memory */
  OP_LOAD2,      /*  71  Load 2-bytes from memory */
  OP_LOAD3,      /*  72  Load 3-bytes from memory */
  OP_LOAD4,      /*  73  Load 4-bytes from memory */
  OP_LOADF4,     /*  74  Load 4 byte float from memory */
  OP_LOCAL,      /*  75  Get local variable. */
  OP_LSH3,       /*  76  */
  OP_LSH4,       /*  77  Left-shift */
  OP_LTF,        /*  78  Compare floats, jump if less-than */
  OP_LTI3,       /*  79  */
  OP_LTI4,       /*  80  Compare integers, jump if less-than. */
  OP_LTU,        /*  81  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  82  */
  OP_MODI3,      /*  83  */
  OP_MODI4,      /*  84  Modulus (signed). */
  OP_MODU3,      /*  85  */
  OP_MODU4,      /*  86  Modulus (unsigned). */
  OP_MULF4,      /*  87  Multiply floats */
  OP_MULI3,      /*  88  */
  OP_MULI4,      /*  89  Multiply signed integers. */
  OP_MULU3,      /*  90  */
  OP_MULU4,      /*  91  Multiply unsigned integers. */
  OP_NE3,        /*  92  */
  OP_NE4,        /*  93  Compare integers, jump if not equal. */
  OP_NEF,        /*  94  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  95  Negate float */
  OP_NEGI3,      /*  96  */
  OP_NEGI4,      /*  97  Negate integer. */
  OP_POP,        /*  98  Discard top-of-stack. */
  OP_PUSH,       /*  99  Push to stack. */
  OP_RSHI3,      /* 100  */
  OP_RSHI4,      /* 101  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 102  */
  OP_RSHU4,      /* 103  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 104  Store 1-byte to memory */
  OP_STORE2,     /* 105  Store 2-byte to memory */
  OP_STORE3,     /* 106  */
  OP_STORE4,     /* 107  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 108  */
  OP_SUB4,       /* 109  Subtract integers (two's complement). */
  OP_SUBF4,      /* 110  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
