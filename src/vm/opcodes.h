#ifndef __OPCODES
#define __OPCODES

#include <stdint.h>

/** Enum for the virtual machine op codes */
typedef enum {
  OP_UNDEF,        /*   0  Error: VM halt */
  OP_IGNORE,       /*   1  No operation */
  OP_ADD3,         /*   2  Add int24 (two's complement) */
  OP_ADD4,         /*   3  Add int32 (two's complement) */
  OP_ADDF4,        /*   4  Add floats */
  OP_ARG3,         /*   5  Marshal 3 byte argument */
  OP_ARG4,         /*   6  Marshal 4 byte argument */
  OP_BAND3,        /*   7  Bitwise AND int24 */
  OP_BAND4,        /*   8  Bitwise AND int32 */
  OP_BCOM3,        /*   9  Bitwise Complement int24 */
  OP_BCOM4,        /*  10  Bitwise COMplement int32 */
  OP_BLK_CPY,      /*  11  memcpy */
  OP_BLK_CPY_U1,   /*  12  */
  OP_BLK_CPY_U2,   /*  13  */
  OP_BOR3,         /*  14  Bitwise OR int24 */
  OP_BOR4,         /*  15  Bitwise OR int32 */
  OP_BREAK,        /*  16  vm->breakCount++ */
  OP_BXOR3,        /*  17  Bitwise eXclusive-OR int24 */
  OP_BXOR4,        /*  18  Bitwise eXclusive-OR int32 */
  OP_CALL,         /*  19  Call subroutine. */
  OP_CF4I3,        /*  20  Convert float to int24 */
  OP_CF4I4,        /*  21  Convert float to int32 */
  OP_CI1I3,        /*  22  Convert int8 to int24 */
  OP_CI2I3,        /*  23  Convert int16 to int24 */
  OP_CI3F4,        /*  24  Convert int24 to float */
  OP_CI3s4,        /*  25  Convert int24 to (u)int32 */
  OP_CI4F4,        /*  26  Convert int32 to float */
  OP_CONSTFD,      /*  27  */
  OP_CONSTI3_I1,   /*  28  */
  OP_CONSTI3_I2,   /*  29  */
  OP_CONSTP3,      /*  30  Push address pointer to stack */
  OP_CONSTP3_1,    /*  31  */
  OP_CONSTP3_2,    /*  32  */
  OP_CONSTP3_SC01, /*  33  */
  OP_CONSTP3_SC02, /*  34  */
  OP_CONSTP3_SC03, /*  35  */
  OP_CONSTP3_SC04, /*  36  */
  OP_CONSTP3_SC05, /*  37  */
  OP_CONSTP3_SC06, /*  38  */
  OP_CONSTP3_SC07, /*  39  */
  OP_CONSTP3_SC08, /*  40  */
  OP_CONSTP3_SC09, /*  41  */
  OP_CONSTP3_SC10, /*  42  */
  OP_CONSTP3_SC11, /*  43  */
  OP_CONSTP3_SC12, /*  44  */
  OP_CONSTP3_SC13, /*  45  */
  OP_CONSTP3_SC14, /*  46  */
  OP_CONSTP3_SC15, /*  47  */
  OP_CONSTP3_SCn,  /*  48  */
  OP_CONSTs1,      /*  49  Push 1 byte constant */
  OP_CONSTs2,      /*  50  Push 2 byte constant */
  OP_CONSTs3,      /*  51  Push 3 byte constant */
  OP_CONSTs4,      /*  52  Push 4 byte constant */
  OP_CONSTU3_U1,   /*  53  */
  OP_CONSTU3_U2,   /*  54  */
  OP_CU1I3,        /*  55  Convert uint8 to int24 */
  OP_CU2I3,        /*  56  Convert uint16 to int24 */
  OP_CU3U4,        /*  57  Convert uint24 to uint32 */
  OP_DI,           /*  58  Disable Interrupts */
  OP_DIVF4,        /*  59  Divide floats */
  OP_DIVI3,        /*  60  Divide int24 */
  OP_DIVI4,        /*  61  Divide int32 */
  OP_DIVU3,        /*  62  Divide uint24 */
  OP_DIVU4,        /*  63  Divide uint32 */
  OP_EI,           /*  64  Enable Interrupts */
  OP_ENTER,        /*  65  Begin subroutine */
  OP_EQ3,          /*  66  Compare (u)int24, jump if == */
  OP_EQ3_1,        /*  67  Compare (u)int24, jump if == */
  OP_EQ4,          /*  68  Compare (u)int32, jump if == */
  OP_GEF4,         /*  69  Compare floats, jump if >= */
  OP_GEI3,         /*  70  Compare int24, jump if > */
  OP_GEI3_1,       /*  71  */
  OP_GEI4,         /*  72  Compare int32, jump if >= */
  OP_GEU3,         /*  73  Compare uint24, jump if >= */
  OP_GEU3_1,       /*  74  */
  OP_GEU4,         /*  75  Compare uint24, jump if >= */
  OP_GTF4,         /*  76  Compare floats, jump if > */
  OP_GTI3,         /*  77  Compare int24, jump if > */
  OP_GTI3_1,       /*  78  */
  OP_GTI4,         /*  79  Compare int32, jump if > */
  OP_GTU3,         /*  80  Compare uint24, jump if > */
  OP_GTU3_1,       /*  81  */
  OP_GTU4,         /*  82  Compare uint32, jump if > */
  OP_JUMP,         /*  83  Unconditional jump */
  OP_LEAVE,        /*  84  End subroutine */
  OP_LEF4,         /*  85  Compare floats, jump if <= */
  OP_LEI3,         /*  86  Compare int24, jump if <= */
  OP_LEI3_1,       /*  87  */
  OP_LEI4,         /*  88  Compare int32, jump if <= */
  OP_LEU3,         /*  89  Compare uint24, jump if <= */
  OP_LEU3_1,       /*  90  */
  OP_LEU4,         /*  91  Compare uint32, jump if <= */
  OP_LOAD1,        /*  92  Load 1-byte from memory */
  OP_LOAD2,        /*  93  Load 2-bytes from memory */
  OP_LOAD3,        /*  94  Load 3-bytes from memory */
  OP_LOAD4,        /*  95  Load 4-bytes from memory */
  OP_LOCAL,        /*  96  Get local variable (8 bit offset) */
  OP_LOCAL_FAR,    /*  97  Get local variable (16 bit offset) */
  OP_LSH3,         /*  98  left shift (u)int24 */
  OP_LSH4,         /*  99  Left-shift (u)int32 */
  OP_LTF4,         /* 100  Compare floats, jump if < */
  OP_LTI3,         /* 101  Compare int24, jump if < */
  OP_LTI3_1,       /* 102  */
  OP_LTI4,         /* 103  Compare int32, jump if < */
  OP_LTU3,         /* 104  Compare uint24, jump if < */
  OP_LTU3_1,       /* 105  */
  OP_LTU4,         /* 106  Compare uint32, jump if < */
  OP_MODI3,        /* 107  Modulus int24 */
  OP_MODI4,        /* 108  Modulus int32 */
  OP_MODU3,        /* 109  Modulus uint24 */
  OP_MODU4,        /* 110  Modulus uint32 */
  OP_MULF4,        /* 111  Multiply floats */
  OP_MULI3,        /* 112  Multiple int24 */
  OP_MULI4,        /* 113  Multiply int32 */
  OP_MULU3,        /* 114  Multiply uint24 */
  OP_MULU4,        /* 115  Multiply uint32 */
  OP_NE3,          /* 116  Compare (u)int24, jump if != */
  OP_NE3_1,        /* 117  */
  OP_NE4,          /* 118  Compare integers, jump if != */
  OP_NEF4,         /* 119  Compare floats, jump if != */
  OP_NEGF4,        /* 120  Negate float */
  OP_NEGI3,        /* 121  Negate int24 */
  OP_NEGI4,        /* 122  Negate int32 */
  OP_POP,          /* 123  Discard top-of-stack */
  OP_PUSH,         /* 124  Push no-value to stack */
  OP_RSHI3,        /* 125  Right-shift int24 (preserve sign) */
  OP_RSHI4,        /* 126  Right-shift int32 (preserve sign) */
  OP_RSHU3,        /* 127  Right-shift uint24 */
  OP_RSHU4,        /* 128  Right-shift uint32 */
  OP_STORE1,       /* 129  Store 1-byte to memory */
  OP_STORE2,       /* 130  Store 2-byte to memory */
  OP_STORE3,       /* 131  Store 3-byte to memory */
  OP_STORE4,       /* 132  Store 4-byte to memory */
  OP_SUB3,         /* 133  Subtract (u)int24 (two's complement). */
  OP_SUB4,         /* 134  Subtract (u)int32 (two's complement). */
  OP_SUBF4,        /* 135  Subtract floats */
  OP_MAX,          /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
