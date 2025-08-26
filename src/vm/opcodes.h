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
  OP_CU4U3,      /*  32  */
  OP_CVFI3,      /*  33  */
  OP_CVIU3,      /*  34  */
  OP_CVUI3,      /*  35  */
  OP_DIVF4,      /*  36  Divide floats */
  OP_DIVI,       /*  37  Divide signed integers. */
  OP_DIVI3,      /*  38  */
  OP_DIVU,       /*  39  Divide unsigned integers. */
  OP_DIVU3,      /*  40  */
  OP_ENTER,      /*  41  Begin subroutine. */
  OP_EQ3,        /*  42  */
  OP_EQ4,        /*  43  Compare integers, jump if equal. */
  OP_EQF4,       /*  44  Compare floats, jump if equal */
  OP_EQU3,       /*  45  */
  OP_GEF4,       /*  46  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  47  */
  OP_GEI4,       /*  48  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  49  */
  OP_GEU4,       /*  50  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  51  Compare floats, jump if greater-than */
  OP_GTI3,       /*  52  */
  OP_GTI4,       /*  53  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  54  */
  OP_GTU4,       /*  55  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  56  Unconditional jump. */
  OP_LEAVE,      /*  57  End subroutine. */
  OP_LEF4,       /*  58  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  59  */
  OP_LEI4,       /*  60  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  61  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  62  */
  OP_LOAD1,      /*  63  Load 1-byte from memory */
  OP_LOAD2,      /*  64  Load 2-bytes from memory */
  OP_LOAD3,      /*  65  Load 3-bytes from memory */
  OP_LOAD4,      /*  66  Load 4-bytes from memory */
  OP_LOADF4,     /*  67  Load 4 byte float from memory */
  OP_LOCAL,      /*  68  Get local variable. */
  OP_LSH3,       /*  69  */
  OP_LSH4,       /*  70  Left-shift */
  OP_LTF,        /*  71  Compare floats, jump if less-than */
  OP_LTI3,       /*  72  */
  OP_LTI4,       /*  73  Compare integers, jump if less-than. */
  OP_LTU,        /*  74  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  75  */
  OP_MODI3,      /*  76  */
  OP_MODI4,      /*  77  Modulus (signed). */
  OP_MODU3,      /*  78  */
  OP_MODU4,      /*  79  Modulus (unsigned). */
  OP_MULF4,      /*  80  Multiply floats */
  OP_MULI3,      /*  81  */
  OP_MULI4,      /*  82  Multiply signed integers. */
  OP_MULU3,      /*  83  */
  OP_MULU4,      /*  84  Multiply unsigned integers. */
  OP_NE3,        /*  85  */
  OP_NE4,        /*  86  Compare integers, jump if not equal. */
  OP_NEF,        /*  87  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  88  Negate float */
  OP_NEGI3,      /*  89  */
  OP_NEGI4,      /*  90  Negate integer. */
  OP_POP,        /*  91  Discard top-of-stack. */
  OP_PUSH,       /*  92  Push to stack. */
  OP_RSHI3,      /*  93  */
  OP_RSHI4,      /*  94  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /*  95  */
  OP_RSHU4,      /*  96  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /*  97  Store 1-byte to memory */
  OP_STORE2,     /*  98  Store 2-byte to memory */
  OP_STORE3,     /*  99  */
  OP_STORE4,     /* 100  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 101  */
  OP_SUB4,       /* 102  Subtract integers (two's complement). */
  OP_SUBF4,      /* 103  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
