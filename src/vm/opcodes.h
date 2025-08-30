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
  OP_BLOCK_COPY, /*  12  memcpy */
  OP_BOR3,       /*  13  Bitwise OR int24 */
  OP_BOR4,       /*  14  Bitwise OR int32 */
  OP_BXOR3,      /*  15  Bitwise eXclusive-OR int24 */
  OP_BXOR4,      /*  16  Bitwise eXclusive-OR int32 */
  OP_CALL,       /*  17  Call subroutine. */
  OP_CF4I3,      /*  18  Convert float to int24 */
  OP_CF4I4,      /*  19  Convert float to int32 */
  OP_CI1I3,      /*  20  Convert int8 to int24 */
  OP_CI2I3,      /*  21  Convert int16 to int24 */
  OP_CI3F4,      /*  22  Convert int24 to float */
  OP_CI3s4,      /*  23  Convert int24 to (u)int32 */
  OP_CI4F4,      /*  24  Convert int32 to float */
  OP_CONSTI3_I1, /*  25  */
  OP_CONSTI3_I2, /*  26  */
  OP_CONSTP3,    /*  27  Push address pointer to stack */
  OP_CONSTs1,    /*  28  Push 1 byte constant */
  OP_CONSTs2,    /*  29  Push 2 byte constant */
  OP_CONSTs3,    /*  30  Push 3 byte constant */
  OP_CONSTs4,    /*  31  Push 4 byte constant */
  OP_CONSTU3_U1, /*  32  */
  OP_CONSTU3_U2, /*  33  */
  OP_CU1I3,      /*  34  Convert uint8 to int24 */
  OP_CU2I3,      /*  35  Convert uint16 to int24 */
  OP_CU3U4,      /*  36  Convert uint24 to uint32 */
  OP_DI,         /*  37  Disable Interrupts */
  OP_DIVF4,      /*  38  Divide floats */
  OP_DIVI3,      /*  39  Divide int24 */
  OP_DIVI4,      /*  40  Divide int32 */
  OP_DIVU3,      /*  41  Divide uint24 */
  OP_DIVU4,      /*  42  Divide uint32 */
  OP_EI,         /*  43  Enable Interrupts */
  OP_ENTER,      /*  44  Begin subroutine */
  OP_EQ3,        /*  45  Compare (u)int24, jump if == */
  OP_EQ4,        /*  46  Compare (u)int32, jump if == */
  OP_GEF4,       /*  47  Compare floats, jump if >= */
  OP_GEI3,       /*  48  Compare int24, jump if > */
  OP_GEI4,       /*  49  Compare int32, jump if >= */
  OP_GEU3,       /*  50  Compare uint24, jump if >= */
  OP_GEU4,       /*  51  Compare uint24, jump if >= */
  OP_GTF4,       /*  52  Compare floats, jump if > */
  OP_GTI3,       /*  53  Compare int24, jump if > */
  OP_GTI4,       /*  54  Compare int32, jump if > */
  OP_GTU3,       /*  55  Compare uint24, jump if > */
  OP_GTU4,       /*  56  Compare uint32, jump if > */
  OP_JUMP,       /*  57  Unconditional jump */
  OP_LEAVE,      /*  58  End subroutine */
  OP_LEF4,       /*  59  Compare floats, jump if <= */
  OP_LEI3,       /*  60  Compare int24, jump if <= */
  OP_LEI4,       /*  61  Compare int32, jump if <= */
  OP_LEU3,       /*  62  Compare uint24, jump if <= */
  OP_LEU4,       /*  63  Compare uint32, jump if <= */
  OP_LOAD1,      /*  64  Load 1-byte from memory */
  OP_LOAD2,      /*  65  Load 2-bytes from memory */
  OP_LOAD3,      /*  66  Load 3-bytes from memory */
  OP_LOAD4,      /*  67  Load 4-bytes from memory */
  OP_LOCAL,      /*  68  Get local variable (8 bit offset) */
  OP_LOCAL_FAR,  /*  69  Get local variable (16 bit offset) */
  OP_LSH3,       /*  70  left shift (u)int24 */
  OP_LSH4,       /*  71  Left-shift (u)int32 */
  OP_LTF4,       /*  72  Compare floats, jump if < */
  OP_LTI3,       /*  73  Compare int24, jump if < */
  OP_LTI4,       /*  74  Compare int32, jump if < */
  OP_LTU3,       /*  75  Compare uint24, jump if < */
  OP_LTU4,       /*  76  Compare uint32, jump if < */
  OP_MODI3,      /*  77  Modulus int24 */
  OP_MODI4,      /*  78  Modulus int32 */
  OP_MODU3,      /*  79  Modulus uint24 */
  OP_MODU4,      /*  80  Modulus uint32 */
  OP_MULF4,      /*  81  Multiply floats */
  OP_MULI3,      /*  82  Multiple int24 */
  OP_MULI4,      /*  83  Multiply int32 */
  OP_MULU3,      /*  84  Multiply uint24 */
  OP_MULU4,      /*  85  Multiply uint32 */
  OP_NE3,        /*  86  Compare (u)int24, jump if != */
  OP_NE4,        /*  87  Compare integers, jump if != */
  OP_NEF4,       /*  88  Compare floats, jump if != */
  OP_NEGF4,      /*  89  Negate float */
  OP_NEGI3,      /*  90  Negate int24 */
  OP_NEGI4,      /*  91  Negate int32 */
  OP_POP,        /*  92  Discard top-of-stack */
  OP_PUSH,       /*  93  Push no-value to stack */
  OP_RSHI3,      /*  94  Right-shift int24 (preserve sign) */
  OP_RSHI4,      /*  95  Right-shift int32 (preserve sign) */
  OP_RSHU3,      /*  96  Right-shift uint24 */
  OP_RSHU4,      /*  97  Right-shift uint32 */
  OP_STORE1,     /*  98  Store 1-byte to memory */
  OP_STORE2,     /*  99  Store 2-byte to memory */
  OP_STORE3,     /* 100  Store 3-byte to memory */
  OP_STORE4,     /* 101  Store 4-byte to memory */
  OP_SUB3,       /* 102  Subtract (u)int24 (two's complement). */
  OP_SUB4,       /* 103  Subtract (u)int32 (two's complement). */
  OP_SUBF4,      /* 104  Subtract floats */
  OP_MAX,        /* Make this the last item */

} opcode_t;

#define OPCODE_TABLE_SIZE OP_MAX

extern const char *const opnames[OPCODE_TABLE_SIZE];

#endif
