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
  OP_CONSTI3,    /*  25  */
  OP_CONSTI4,    /*  26  */
  OP_CONSTP3,    /*  27  */
  OP_CONSTs1,    /*  28  */
  OP_CONSTs2,    /*  29  */
  OP_CONSTU3,    /*  30  */
  OP_CONSTU4,    /*  31  */
  OP_CU1I3,      /*  32  */
  OP_CU2I3,      /*  33  */
  OP_CU3U2,      /*  34  */
  OP_CU3U4,      /*  35  */
  OP_CU4I3,      /*  36  */
  OP_CU4U3,      /*  37  */
  OP_CVFI3,      /*  38  */
  OP_CVIU3,      /*  39  */
  OP_CVUI3,      /*  40  */
  OP_DIVF4,      /*  41  Divide floats */
  OP_DIVI,       /*  42  Divide signed integers. */
  OP_DIVI3,      /*  43  */
  OP_DIVU,       /*  44  Divide unsigned integers. */
  OP_DIVU3,      /*  45  */
  OP_ENTER,      /*  46  Begin subroutine. */
  OP_EQ3,        /*  47  */
  OP_EQ4,        /*  48  Compare integers, jump if equal. */
  OP_EQF4,       /*  49  Compare floats, jump if equal */
  OP_EQU3,       /*  50  */
  OP_GEF4,       /*  51  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  52  */
  OP_GEI4,       /*  53  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  54  */
  OP_GEU4,       /*  55  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  56  Compare floats, jump if greater-than */
  OP_GTI3,       /*  57  */
  OP_GTI4,       /*  58  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  59  */
  OP_GTU4,       /*  60  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  61  Unconditional jump. */
  OP_LEAVE,      /*  62  End subroutine. */
  OP_LEF4,       /*  63  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  64  */
  OP_LEI4,       /*  65  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  66  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  67  */
  OP_LOAD1,      /*  68  Load 1-byte from memory */
  OP_LOAD2,      /*  69  Load 2-bytes from memory */
  OP_LOAD3,      /*  70  Load 3-bytes from memory */
  OP_LOAD4,      /*  71  Load 4-bytes from memory */
  OP_LOADF4,     /*  72  Load 4 byte float from memory */
  OP_LOCAL,      /*  73  Get local variable. */
  OP_LSH3,       /*  74  */
  OP_LSH4,       /*  75  Left-shift */
  OP_LTF,        /*  76  Compare floats, jump if less-than */
  OP_LTI3,       /*  77  */
  OP_LTI4,       /*  78  Compare integers, jump if less-than. */
  OP_LTU,        /*  79  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  80  */
  OP_MODI3,      /*  81  */
  OP_MODI4,      /*  82  Modulus (signed). */
  OP_MODU3,      /*  83  */
  OP_MODU4,      /*  84  Modulus (unsigned). */
  OP_MULF4,      /*  85  Multiply floats */
  OP_MULI3,      /*  86  */
  OP_MULI4,      /*  87  Multiply signed integers. */
  OP_MULU3,      /*  88  */
  OP_MULU4,      /*  89  Multiply unsigned integers. */
  OP_NE3,        /*  90  */
  OP_NE4,        /*  91  Compare integers, jump if not equal. */
  OP_NEF,        /*  92  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  93  Negate float */
  OP_NEGI3,      /*  94  */
  OP_NEGI4,      /*  95  Negate integer. */
  OP_POP,        /*  96  Discard top-of-stack. */
  OP_PUSH,       /*  97  Push to stack. */
  OP_RSHI3,      /*  98  */
  OP_RSHI4,      /*  99  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /* 100  */
  OP_RSHU4,      /* 101  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 102  Store 1-byte to memory */
  OP_STORE2,     /* 103  Store 2-byte to memory */
  OP_STORE3,     /* 104  */
  OP_STORE4,     /* 105  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 106  */
  OP_SUB4,       /* 107  Subtract integers (two's complement). */
  OP_SUBF4,      /* 108  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
