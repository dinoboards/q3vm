#ifndef __OPCODES
#define __OPCODES

#include <stdint.h>

/** Enum for the virtual machine op codes */
typedef enum {
  OP_UNDEF,      /*   0  Error: VM halt */
  OP_IGNORE,     /*   1  No operation */
  OP_BREAK,      /*   2  vm->breakCount++ */
  OP_ADD3,       /*   3  Add int24 (two's complement) */
  OP_ADD4,       /*   4  Add int32 (two's complement) */
  OP_ADDF4,      /*   5  Add floats */
  OP_ARG3,       /*   6  Marshal 3 byte argument */
  OP_ARG4,       /*   7  Marshal 4 byte argument */
  OP_BAND3,      /*   8  Bitwise AND int24 */
  OP_BAND4,      /*   9  Bitwise AND int32 */
  OP_BCOM3,      /*  10  Bitwise Complement int24 */
  OP_BCOM4,      /*  11  Bitwise COMplement int32 */
  OP_BLK_CPY,    /*  12  memcpy */
  OP_BLK_CPY_U1, /*  13  */
  OP_BLK_CPY_U2, /*  14  */
  OP_BOR3,       /*  15  Bitwise OR int24 */
  OP_BOR4,       /*  16  Bitwise OR int32 */
  OP_BXOR3,      /*  17  Bitwise eXclusive-OR int24 */
  OP_BXOR4,      /*  18  Bitwise eXclusive-OR int32 */
  OP_CALL,       /*  19  Call subroutine. */
  OP_CF4I3,      /*  20  Convert float to int24 */
  OP_CF4I4,      /*  21  Convert float to int32 */
  OP_CI1I3,      /*  22  Convert int8 to int24 */
  OP_CI2I3,      /*  23  Convert int16 to int24 */
  OP_CI3F4,      /*  24  Convert int24 to float */
  OP_CI3s4,      /*  25  Convert int24 to (u)int32 */
  OP_CI4F4,      /*  26  Convert int32 to float */
  OP_CONSTI3_I1, /*  27  */
  OP_CONSTI3_I2, /*  28  */
  OP_CONSTP3,    /*  29  Push address pointer to stack */
  OP_CONSTP3_1,  /*  30  */
  OP_CONSTP3_2,  /*  31  */
  OP_CONSTs1,    /*  32  Push 1 byte constant */
  OP_CONSTs2,    /*  33  Push 2 byte constant */
  OP_CONSTs3,    /*  34  Push 3 byte constant */
  OP_CONSTs4,    /*  35  Push 4 byte constant */
  OP_CONSTU3_U1, /*  36  */
  OP_CONSTU3_U2, /*  37  */
  OP_CU1I3,      /*  38  Convert uint8 to int24 */
  OP_CU2I3,      /*  39  Convert uint16 to int24 */
  OP_CU3U4,      /*  40  Convert uint24 to uint32 */
  OP_DI,         /*  41  Disable Interrupts */
  OP_DIVF4,      /*  42  Divide floats */
  OP_DIVI3,      /*  43  Divide int24 */
  OP_DIVI4,      /*  44  Divide int32 */
  OP_DIVU3,      /*  45  Divide uint24 */
  OP_DIVU4,      /*  46  Divide uint32 */
  OP_EI,         /*  47  Enable Interrupts */
  OP_ENTER,      /*  48  Begin subroutine */
  OP_EQ3,        /*  49  Compare (u)int24, jump if == */
  OP_EQ3_1,      /*  50  Compare (u)int24, jump if == */
  OP_EQ4,        /*  51  Compare (u)int32, jump if == */
  OP_GEF4,       /*  52  Compare floats, jump if >= */
  OP_GEI3,       /*  53  Compare int24, jump if > */
  OP_GEI3_1,     /*  54  */
  OP_GEI4,       /*  55  Compare int32, jump if >= */
  OP_GEU3,       /*  56  Compare uint24, jump if >= */
  OP_GEU3_1,     /*  57  */
  OP_GEU4,       /*  58  Compare uint24, jump if >= */
  OP_GTF4,       /*  59  Compare floats, jump if > */
  OP_GTI3,       /*  60  Compare int24, jump if > */
  OP_GTI3_1,     /*  61  */
  OP_GTI4,       /*  62  Compare int32, jump if > */
  OP_GTU3,       /*  63  Compare uint24, jump if > */
  OP_GTU3_1,     /*  64  */
  OP_GTU4,       /*  65  Compare uint32, jump if > */
  OP_JUMP,       /*  66  Unconditional jump */
  OP_LEAVE,      /*  67  End subroutine */
  OP_LEF4,       /*  68  Compare floats, jump if <= */
  OP_LEI3,       /*  69  Compare int24, jump if <= */
  OP_LEI3_1,     /*  70  */
  OP_LEI4,       /*  71  Compare int32, jump if <= */
  OP_LEU3,       /*  72  Compare uint24, jump if <= */
  OP_LEU3_1,     /*  73  */
  OP_LEU4,       /*  74  Compare uint32, jump if <= */
  OP_LOAD1,      /*  75  Load 1-byte from memory */
  OP_LOAD2,      /*  76  Load 2-bytes from memory */
  OP_LOAD3,      /*  77  Load 3-bytes from memory */
  OP_LOAD4,      /*  78  Load 4-bytes from memory */
  OP_LOCAL,      /*  79  Get local variable (8 bit offset) */
  OP_LOCAL_FAR,  /*  80  Get local variable (16 bit offset) */
  OP_LSH3,       /*  81  left shift (u)int24 */
  OP_LSH4,       /*  82  Left-shift (u)int32 */
  OP_LTF4,       /*  83  Compare floats, jump if < */
  OP_LTI3,       /*  84  Compare int24, jump if < */
  OP_LTI3_1,     /*  85  */
  OP_LTI4,       /*  86  Compare int32, jump if < */
  OP_LTU3,       /*  87  Compare uint24, jump if < */
  OP_LTU3_1,     /*  88  */
  OP_LTU4,       /*  89  Compare uint32, jump if < */
  OP_MODI3,      /*  90  Modulus int24 */
  OP_MODI4,      /*  91  Modulus int32 */
  OP_MODU3,      /*  92  Modulus uint24 */
  OP_MODU4,      /*  93  Modulus uint32 */
  OP_MULF4,      /*  94  Multiply floats */
  OP_MULI3,      /*  95  Multiple int24 */
  OP_MULI4,      /*  96  Multiply int32 */
  OP_MULU3,      /*  97  Multiply uint24 */
  OP_MULU4,      /*  98  Multiply uint32 */
  OP_NE3,        /*  99  Compare (u)int24, jump if != */
  OP_NE3_1,      /* 100  */
  OP_NE4,        /* 101  Compare integers, jump if != */
  OP_NEF4,       /* 102  Compare floats, jump if != */
  OP_NEGF4,      /* 103  Negate float */
  OP_NEGI3,      /* 104  Negate int24 */
  OP_NEGI4,      /* 105  Negate int32 */
  OP_POP,        /* 106  Discard top-of-stack */
  OP_PUSH,       /* 107  Push no-value to stack */
  OP_RSHI3,      /* 108  Right-shift int24 (preserve sign) */
  OP_RSHI4,      /* 109  Right-shift int32 (preserve sign) */
  OP_RSHU3,      /* 110  Right-shift uint24 */
  OP_RSHU4,      /* 111  Right-shift uint32 */
  OP_STORE1,     /* 112  Store 1-byte to memory */
  OP_STORE2,     /* 113  Store 2-byte to memory */
  OP_STORE3,     /* 114  Store 3-byte to memory */
  OP_STORE4,     /* 115  Store 4-byte to memory */
  OP_SUB3,       /* 116  Subtract (u)int24 (two's complement). */
  OP_SUB4,       /* 117  Subtract (u)int32 (two's complement). */
  OP_SUBF4,      /* 118  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
