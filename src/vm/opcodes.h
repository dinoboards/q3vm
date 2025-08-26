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
  OP_CU4I3,      /*  32  */
  OP_CU4U3,      /*  33  */
  OP_CVFI3,      /*  34  */
  OP_CVIU3,      /*  35  */
  OP_CVUI3,      /*  36  */
  OP_DIVF4,      /*  37  Divide floats */
  OP_DIVI,       /*  38  Divide signed integers. */
  OP_DIVI3,      /*  39  */
  OP_DIVU,       /*  40  Divide unsigned integers. */
  OP_DIVU3,      /*  41  */
  OP_ENTER,      /*  42  Begin subroutine. */
  OP_EQ3,        /*  43  */
  OP_EQ4,        /*  44  Compare integers, jump if equal. */
  OP_EQF4,       /*  45  Compare floats, jump if equal */
  OP_EQU3,       /*  46  */
  OP_GEF4,       /*  47  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  48  */
  OP_GEI4,       /*  49  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  50  */
  OP_GEU4,       /*  51  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  52  Compare floats, jump if greater-than */
  OP_GTI3,       /*  53  */
  OP_GTI4,       /*  54  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  55  */
  OP_GTU4,       /*  56  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  57  Unconditional jump. */
  OP_LEAVE,      /*  58  End subroutine. */
  OP_LEF4,       /*  59  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  60  */
  OP_LEI4,       /*  61  Compare integers, jump if less-than-or-equal. */
  OP_LEU,        /*  62  Compare unsigned integers, jump if less-than-or-equal */
  OP_LEU3,       /*  63  */
  OP_LOAD1,      /*  64  Load 1-byte from memory */
  OP_LOAD2,      /*  65  Load 2-bytes from memory */
  OP_LOAD3,      /*  66  Load 3-bytes from memory */
  OP_LOAD4,      /*  67  Load 4-bytes from memory */
  OP_LOADF4,     /*  68  Load 4 byte float from memory */
  OP_LOCAL,      /*  69  Get local variable. */
  OP_LSH3,       /*  70  */
  OP_LSH4,       /*  71  Left-shift */
  OP_LTF,        /*  72  Compare floats, jump if less-than */
  OP_LTI3,       /*  73  */
  OP_LTI4,       /*  74  Compare integers, jump if less-than. */
  OP_LTU,        /*  75  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  76  */
  OP_MODI3,      /*  77  */
  OP_MODI4,      /*  78  Modulus (signed). */
  OP_MODU3,      /*  79  */
  OP_MODU4,      /*  80  Modulus (unsigned). */
  OP_MULF4,      /*  81  Multiply floats */
  OP_MULI3,      /*  82  */
  OP_MULI4,      /*  83  Multiply signed integers. */
  OP_MULU3,      /*  84  */
  OP_MULU4,      /*  85  Multiply unsigned integers. */
  OP_NE3,        /*  86  */
  OP_NE4,        /*  87  Compare integers, jump if not equal. */
  OP_NEF,        /*  88  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  89  Negate float */
  OP_NEGI3,      /*  90  */
  OP_NEGI4,      /*  91  Negate integer. */
  OP_POP,        /*  92  Discard top-of-stack. */
  OP_PUSH,       /*  93  Push to stack. */
  OP_RSHI3,      /*  94  */
  OP_RSHI4,      /*  95  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /*  96  */
  OP_RSHU4,      /*  97  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /*  98  Store 1-byte to memory */
  OP_STORE2,     /*  99  Store 2-byte to memory */
  OP_STORE3,     /* 100  */
  OP_STORE4,     /* 101  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /* 102  */
  OP_SUB4,       /* 103  Subtract integers (two's complement). */
  OP_SUBF4,      /* 104  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
