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
  OP_CONSTI4,    /*  25  */
  OP_CONSTP3,    /*  26  */
  OP_CONSTs1,    /*  27  */
  OP_CONSTs2,    /*  28  */
  OP_CONSTs3,    /*  29  */
  OP_CONSTU4,    /*  30  */
  OP_CU1I3,      /*  31  */
  OP_CU2I3,      /*  32  */
  OP_CU3U2,      /*  33  */
  OP_CU3U4,      /*  34  */
  OP_CU4I3,      /*  35  */
  OP_CU4U3,      /*  36  */
  OP_CVFI3,      /*  37  */
  OP_CVIU3,      /*  38  */
  OP_CVUI3,      /*  39  */
  OP_DIVF4,      /*  40  Divide floats */
  OP_DIVI,       /*  41  Divide signed integers. */
  OP_DIVI3,      /*  42  */
  OP_DIVU,       /*  43  Divide unsigned integers. */
  OP_DIVU3,      /*  44  */
  OP_ENTER,      /*  45  Begin subroutine. */
  OP_EQ3,        /*  46  */
  OP_EQ4,        /*  47  Compare integers, jump if equal. */
  OP_EQF4,       /*  48  Compare floats, jump if equal */
  OP_EQU3,       /*  49  */
  OP_GEF4,       /*  50  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  51  */
  OP_GEI4,       /*  52  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  53  */
  OP_GEU4,       /*  54  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  55  Compare floats, jump if greater-than */
  OP_GTI3,       /*  56  */
  OP_GTI4,       /*  57  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  58  */
  OP_GTU4,       /*  59  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  60  Unconditional jump. */
  OP_LEAVE,      /*  61  End subroutine. */
  OP_LEF4,       /*  62  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  63  */
  OP_LEI4,       /*  64  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  65  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  66  */
  OP_LOAD1,      /*  67  Load 1-byte from memory */
  OP_LOAD2,      /*  68  Load 2-bytes from memory */
  OP_LOAD3,      /*  69  Load 3-bytes from memory */
  OP_LOAD4,      /*  70  Load 4-bytes from memory */
  OP_LOADF4,     /*  71  Load 4 byte float from memory */
  OP_LOCAL,      /*  72  Get local variable. */
  OP_LSH3,       /*  73  */
  OP_LSH4,       /*  74  Left-shift */
  OP_LTF,        /*  75  Compare floats, jump if less-than */
  OP_LTI3,       /*  76  */
  OP_LTI4,       /*  77  Compare integers, jump if less-than. */
  OP_LTU,        /*  78  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  79  */
  OP_MODI3,      /*  80  */
  OP_MODI4,      /*  81  Modulus (signed). */
  OP_MODU3,      /*  82  */
  OP_MODU4,      /*  83  Modulus (unsigned). */
  OP_MULF4,      /*  84  Multiply floats */
  OP_MULI3,      /*  85  */
  OP_MULI4,      /*  86  Multiply signed integers. */
  OP_MULU3,      /*  87  */
  OP_MULU4,      /*  88  Multiply unsigned integers. */
  OP_NE3,        /*  89  */
  OP_NE4,        /*  90  Compare integers, jump if not equal. */
  OP_NEF,        /*  91  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  92  Negate float */
  OP_NEGI3,      /*  93  */
  OP_NEGI4,      /*  94  Negate integer. */
  OP_POP,        /*  95  Discard top-of-stack. */
  OP_PUSH,       /*  96  Push to stack. */
  OP_RSHI3,      /*  97  */
  OP_RSHI4,      /*  98  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /*  99  */
  OP_RSHU4,      /* 100  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /* 101  Store 1-byte to memory */
  OP_STORE2,     /* 102  Store 2-byte to memory */
  OP_STORE3,     /* 103  */
  OP_STORE4,     /* 104  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 105  */
  OP_SUB4,       /* 106  Subtract integers (two's complement). */
  OP_SUBF4,      /* 107  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
