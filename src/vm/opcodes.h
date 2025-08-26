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
  OP_CF4I3,      /*  18  */
  OP_CF4I4,      /*  19  Convert to float from integer */
  OP_CI1I3,      /*  20  */
  OP_CI2I3,      /*  21  */
  OP_CI3F4,      /*  22  */
  OP_CI3s4,      /*  23  */
  OP_CI4F4,      /*  24  Convert to integer from float */
  OP_CONSTGP3,   /*  25  push address pointer to stack. */
  OP_CONSTP3,    /*  26  */
  OP_CONSTs1,    /*  27  */
  OP_CONSTs2,    /*  28  */
  OP_CONSTs3,    /*  29  */
  OP_CONSTs4,    /*  30  */
  OP_CU1I3,      /*  31  */
  OP_CU2I3,      /*  32  */
  OP_CU3U4,      /*  33  */
  OP_DIVF4,      /*  34  Divide floats */
  OP_DIVI3,      /*  35  */
  OP_DIVI4,      /*  36  Divide signed integers. */
  OP_DIVU3,      /*  37  */
  OP_DIVU4,      /*  38  Divide unsigned integers. */
  OP_ENTER,      /*  39  Begin subroutine. */
  OP_EQ3,        /*  40  */
  OP_EQ4,        /*  41  Compare integers, jump if equal. */
  OP_EQF4,       /*  42  Compare floats, jump if equal */
  OP_GEF4,       /*  43  Compare floats, jump if greater-than-or-equal */
  OP_GEI3,       /*  44  */
  OP_GEI4,       /*  45  Compare integers, jump if greater-than-or-equal. */
  OP_GEU3,       /*  46  */
  OP_GEU4,       /*  47  Compare unsigned integers, jump if greater-than-or-equal */
  OP_GTF4,       /*  48  Compare floats, jump if greater-than */
  OP_GTI3,       /*  49  */
  OP_GTI4,       /*  50  Compare integers, jump if greater-than. */
  OP_GTU3,       /*  51  */
  OP_GTU4,       /*  52  Compare unsigned integers, jump if greater-than */
  OP_JUMP,       /*  53  Unconditional jump. */
  OP_LEAVE,      /*  54  End subroutine. */
  OP_LEF4,       /*  55  Compare floats, jump if less-than-or-equal */
  OP_LEI3,       /*  56  */
  OP_LEI4,       /*  57  Compare integers, jump if less-than-or-equal. */
  OP_LEU3,       /*  58  */
  OP_LEU4,       /*  59  Compare unsigned integers, jump if less-than-or-equal */
  OP_LOAD1,      /*  60  Load 1-byte from memory */
  OP_LOAD2,      /*  61  Load 2-bytes from memory */
  OP_LOAD3,      /*  62  Load 3-bytes from memory */
  OP_LOAD4,      /*  63  Load 4-bytes from memory */
  OP_LOADF4,     /*  64  Load 4 byte float from memory */
  OP_LOCAL,      /*  65  Get local variable. */
  OP_LSH3,       /*  66  */
  OP_LSH4,       /*  67  Left-shift */
  OP_LTF,        /*  68  Compare floats, jump if less-than */
  OP_LTI3,       /*  69  */
  OP_LTI4,       /*  70  Compare integers, jump if less-than. */
  OP_LTU,        /*  71  Compare unsigned integers, jump if less-than */
  OP_LTU3,       /*  72  */
  OP_MODI3,      /*  73  */
  OP_MODI4,      /*  74  Modulus (signed). */
  OP_MODU3,      /*  75  */
  OP_MODU4,      /*  76  Modulus (unsigned). */
  OP_MULF4,      /*  77  Multiply floats */
  OP_MULI3,      /*  78  */
  OP_MULI4,      /*  79  Multiply signed integers. */
  OP_MULU3,      /*  80  */
  OP_MULU4,      /*  81  Multiply unsigned integers. */
  OP_NE3,        /*  82  */
  OP_NE4,        /*  83  Compare integers, jump if not equal. */
  OP_NEF,        /*  84  Compare floats, jump if not-equal */
  OP_NEGF4,      /*  85  Negate float */
  OP_NEGI3,      /*  86  */
  OP_NEGI4,      /*  87  Negate integer. */
  OP_POP,        /*  88  Discard top-of-stack. */
  OP_PUSH,       /*  89  Push to stack. */
  OP_RSHI3,      /*  90  */
  OP_RSHI4,      /*  91  Right-shift (algebraic; preserve sign) */
  OP_RSHU3,      /*  92  */
  OP_RSHU4,      /*  93  Right-shift (bitwise; ignore sign) */
  OP_STORE1,     /*  94  Store 1-byte to memory */
  OP_STORE2,     /*  95  Store 2-byte to memory */
  OP_STORE3,     /*  96  */
  OP_STORE4,     /*  97  *(stack[top-1]) = stack[top] */
  OP_SUB3,       /*  98  */
  OP_SUB4,       /*  99  Subtract integers (two's complement). */
  OP_SUBF4,      /* 100  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
