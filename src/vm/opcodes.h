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
  OP_CONSTI2,    /*  25  */
  OP_CONSTI3,    /*  26  */
  OP_CONSTI4,    /*  27  */
  OP_CONSTP3,    /*  28  */
  OP_CONSTs1,    /*  29  */
  OP_CONSTU2,    /*  30  */
  OP_CONSTU3,    /*  31  */
  OP_CONSTU4,    /*  32  */
  OP_CU1I3,      /*  33  */
  OP_CU2I3,      /*  34  */
  OP_CU3U2,      /*  35  */
  OP_CU3U4,      /*  36  */
  OP_CU4I3,      /*  37  */
  OP_CU4U3,      /*  38  */
  OP_CVFI3,      /*  39  */
  OP_CVIU3,      /*  40  */
  OP_CVUI3,      /*  41  */
  OP_DIVF4,      /*  42  Divide floats */
  OP_DIVI,       /*  43  Divide signed integers. */
  OP_DIVI3,      /*  44  */
  OP_DIVU,       /*  45  Divide unsigned integers. */
  OP_DIVU3,      /*  46  */
  OP_ENTER,      /*  47  Begin subroutine. */
  OP_EQ3,        /*  48  */
  OP_EQ4,        /*  49  Compare integers, jump if equal. */
  OP_EQF4,       /*  50  Compare floats, jump if equal */
  OP_EQU3,       /*  51  */
  OP_GEF4,       /*  52  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  53  */
  OP_GEI4,       /*  54  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  55  */
  OP_GEU4,       /*  56  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  57  Compare floats, jump if greater-than */
  OP_GTI3,       /*  58  */
  OP_GTI4,       /*  59  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  60  */
  OP_GTU4,       /*  61  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  62  Unconditional jump. */
  OP_LEAVE,      /*  63  End subroutine. */
  OP_LEF4,       /*  64  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  65  */
  OP_LEI4,       /*  66  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  67  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  68  */
  OP_LOAD1,      /*  69  Load 1-byte from memory */
  OP_LOAD2,      /*  70  Load 2-bytes from memory */
  OP_LOAD3,      /*  71  Load 3-bytes from memory */
  OP_LOAD4,      /*  72  Load 4-bytes from memory */
  OP_LOADF4,     /*  73  Load 4 byte float from memory */
  OP_LOCAL,      /*  74  Get local variable. */
  OP_LSH3,       /*  75  */
  OP_LSH4,       /*  76  Left-shift */
  OP_LTF,        /*  77  Compare floats, jump if less-than */
  OP_LTI3,       /*  78  */
  OP_LTI4,       /*  79  Compare integers, jump if less-than. */
  OP_LTU,        /*  80  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  81  */
  OP_MODI3,      /*  82  */
  OP_MODI4,      /*  83  Modulus (signed). */
  OP_MODU3,      /*  84  */
  OP_MODU4,      /*  85  Modulus (unsigned). */
  OP_MULF4,      /*  86  Multiply floats */
  OP_MULI3,      /*  87  */
  OP_MULI4,      /*  88  Multiply signed integers. */
  OP_MULU3,      /*  89  */
  OP_MULU4,      /*  90  Multiply unsigned integers. */
  OP_NE3,        /*  91  */
  OP_NE4,        /*  92  Compare integers, jump if not equal. */
  OP_NEF,        /*  93  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  94  Negate float */
  OP_NEGI3,      /*  95  */
  OP_NEGI4,      /*  96  Negate integer. */
  OP_POP,        /*  97  Discard top-of-stack. */
  OP_PUSH,       /*  98  Push to stack. */
  OP_RSHI3,      /*  99  */
  OP_RSHI4,      /* 100  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 101  */
  OP_RSHU4,      /* 102  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 103  Store 1-byte to memory */
  OP_STORE2,     /* 104  Store 2-byte to memory */
  OP_STORE3,     /* 105  */
  OP_STORE4,     /* 106  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 107  */
  OP_SUB4,       /* 108  Subtract integers (two's complement). */
  OP_SUBF4,      /* 109  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
