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
  OP_CONSTP3,    /*  25  */
  OP_CONSTs1,    /*  26  */
  OP_CONSTs2,    /*  27  */
  OP_CONSTs3,    /*  28  */
  OP_CONSTs4,    /*  29  */
  OP_CU1I3,      /*  30  */
  OP_CU2I3,      /*  31  */
  OP_CU3U4,      /*  32  */
  OP_CU4I3,      /*  33  */
  OP_CU4U3,      /*  34  */
  OP_CVFI3,      /*  35  */
  OP_CVIU3,      /*  36  */
  OP_CVUI3,      /*  37  */
  OP_DIVF4,      /*  38  Divide floats */
  OP_DIVI,       /*  39  Divide signed integers. */
  OP_DIVI3,      /*  40  */
  OP_DIVU,       /*  41  Divide unsigned integers. */
  OP_DIVU3,      /*  42  */
  OP_ENTER,      /*  43  Begin subroutine. */
  OP_EQ3,        /*  44  */
  OP_EQ4,        /*  45  Compare integers, jump if equal. */
  OP_EQF4,       /*  46  Compare floats, jump if equal */
  OP_EQU3,       /*  47  */
  OP_GEF4,       /*  48  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  49  */
  OP_GEI4,       /*  50  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  51  */
  OP_GEU4,       /*  52  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  53  Compare floats, jump if greater-than */
  OP_GTI3,       /*  54  */
  OP_GTI4,       /*  55  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  56  */
  OP_GTU4,       /*  57  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  58  Unconditional jump. */
  OP_LEAVE,      /*  59  End subroutine. */
  OP_LEF4,       /*  60  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  61  */
  OP_LEI4,       /*  62  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  63  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  64  */
  OP_LOAD1,      /*  65  Load 1-byte from memory */
  OP_LOAD2,      /*  66  Load 2-bytes from memory */
  OP_LOAD3,      /*  67  Load 3-bytes from memory */
  OP_LOAD4,      /*  68  Load 4-bytes from memory */
  OP_LOADF4,     /*  69  Load 4 byte float from memory */
  OP_LOCAL,      /*  70  Get local variable. */
  OP_LSH3,       /*  71  */
  OP_LSH4,       /*  72  Left-shift */
  OP_LTF,        /*  73  Compare floats, jump if less-than */
  OP_LTI3,       /*  74  */
  OP_LTI4,       /*  75  Compare integers, jump if less-than. */
  OP_LTU,        /*  76  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  77  */
  OP_MODI3,      /*  78  */
  OP_MODI4,      /*  79  Modulus (signed). */
  OP_MODU3,      /*  80  */
  OP_MODU4,      /*  81  Modulus (unsigned). */
  OP_MULF4,      /*  82  Multiply floats */
  OP_MULI3,      /*  83  */
  OP_MULI4,      /*  84  Multiply signed integers. */
  OP_MULU3,      /*  85  */
  OP_MULU4,      /*  86  Multiply unsigned integers. */
  OP_NE3,        /*  87  */
  OP_NE4,        /*  88  Compare integers, jump if not equal. */
  OP_NEF,        /*  89  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  90  Negate float */
  OP_NEGI3,      /*  91  */
  OP_NEGI4,      /*  92  Negate integer. */
  OP_POP,        /*  93  Discard top-of-stack. */
  OP_PUSH,       /*  94  Push to stack. */
  OP_RSHI3,      /*  95  */
  OP_RSHI4,      /*  96  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /*  97  */
  OP_RSHU4,      /*  98  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /*  99  Store 1-byte to memory */
  OP_STORE2,     /* 100  Store 2-byte to memory */
  OP_STORE3,     /* 101  */
  OP_STORE4,     /* 102  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 103  */
  OP_SUB4,       /* 104  Subtract integers (two's complement). */
  OP_SUBF4,      /* 105  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
