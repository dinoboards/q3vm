#include "opcodes.h"

const char *const opnames[OPCODE_TABLE_SIZE] = {
    "UNDEF",      /*   0  Error: VM halt */
    "IGNORE",     /*   1  No operation */
    "BREAK",      /*   2  vm->breakCount++ */
    "ADD3",       /*   3  Add int24 (two's complement) */
    "ADD4",       /*   4  Add int32 (two's complement) */
    "ADDF4",      /*   5  Add floats */
    "ARG3",       /*   6  Marshal 3 byte argument */
    "ARG4",       /*   7  Marshal 4 byte argument */
    "BAND3",      /*   8  Bitwise AND int24 */
    "BAND4",      /*   9  Bitwise AND int32 */
    "BCOM3",      /*  10  Bitwise Complement int24 */
    "BCOM4",      /*  11  Bitwise COMplement int32 */
    "BLK_CPY",    /*  12  memcpy */
    "BLK_CPY_U1", /*  13  */
    "BLK_CPY_U2", /*  14  */
    "BOR3",       /*  15  Bitwise OR int24 */
    "BOR4",       /*  16  Bitwise OR int32 */
    "BXOR3",      /*  17  Bitwise eXclusive-OR int24 */
    "BXOR4",      /*  18  Bitwise eXclusive-OR int32 */
    "CALL",       /*  19  Call subroutine. */
    "CF4I3",      /*  20  Convert float to int24 */
    "CF4I4",      /*  21  Convert float to int32 */
    "CI1I3",      /*  22  Convert int8 to int24 */
    "CI2I3",      /*  23  Convert int16 to int24 */
    "CI3F4",      /*  24  Convert int24 to float */
    "CI3s4",      /*  25  Convert int24 to (u)int32 */
    "CI4F4",      /*  26  Convert int32 to float */
    "CONSTI3_I1", /*  27  */
    "CONSTI3_I2", /*  28  */
    "CONSTP3",    /*  29  Push address pointer to stack */
    "CONSTs1",    /*  30  Push 1 byte constant */
    "CONSTs2",    /*  31  Push 2 byte constant */
    "CONSTs3",    /*  32  Push 3 byte constant */
    "CONSTs4",    /*  33  Push 4 byte constant */
    "CONSTU3_U1", /*  34  */
    "CONSTU3_U2", /*  35  */
    "CU1I3",      /*  36  Convert uint8 to int24 */
    "CU2I3",      /*  37  Convert uint16 to int24 */
    "CU3U4",      /*  38  Convert uint24 to uint32 */
    "DI",         /*  39  Disable Interrupts */
    "DIVF4",      /*  40  Divide floats */
    "DIVI3",      /*  41  Divide int24 */
    "DIVI4",      /*  42  Divide int32 */
    "DIVU3",      /*  43  Divide uint24 */
    "DIVU4",      /*  44  Divide uint32 */
    "EI",         /*  45  Enable Interrupts */
    "ENTER",      /*  46  Begin subroutine */
    "EQ3",        /*  47  Compare (u)int24, jump if == */
    "EQ3_1",      /*  48  Compare (u)int24, jump if == */
    "EQ4",        /*  49  Compare (u)int32, jump if == */
    "GEF4",       /*  50  Compare floats, jump if >= */
    "GEI3",       /*  51  Compare int24, jump if > */
    "GEI4",       /*  52  Compare int32, jump if >= */
    "GEU3",       /*  53  Compare uint24, jump if >= */
    "GEU4",       /*  54  Compare uint24, jump if >= */
    "GTF4",       /*  55  Compare floats, jump if > */
    "GTI3",       /*  56  Compare int24, jump if > */
    "GTI4",       /*  57  Compare int32, jump if > */
    "GTU3",       /*  58  Compare uint24, jump if > */
    "GTU4",       /*  59  Compare uint32, jump if > */
    "JUMP",       /*  60  Unconditional jump */
    "LEAVE",      /*  61  End subroutine */
    "LEF4",       /*  62  Compare floats, jump if <= */
    "LEI3",       /*  63  Compare int24, jump if <= */
    "LEI4",       /*  64  Compare int32, jump if <= */
    "LEU3",       /*  65  Compare uint24, jump if <= */
    "LEU4",       /*  66  Compare uint32, jump if <= */
    "LOAD1",      /*  67  Load 1-byte from memory */
    "LOAD2",      /*  68  Load 2-bytes from memory */
    "LOAD3",      /*  69  Load 3-bytes from memory */
    "LOAD4",      /*  70  Load 4-bytes from memory */
    "LOCAL",      /*  71  Get local variable (8 bit offset) */
    "LOCAL_FAR",  /*  72  Get local variable (16 bit offset) */
    "LSH3",       /*  73  left shift (u)int24 */
    "LSH4",       /*  74  Left-shift (u)int32 */
    "LTF4",       /*  75  Compare floats, jump if < */
    "LTI3",       /*  76  Compare int24, jump if < */
    "LTI4",       /*  77  Compare int32, jump if < */
    "LTU3",       /*  78  Compare uint24, jump if < */
    "LTU4",       /*  79  Compare uint32, jump if < */
    "MODI3",      /*  80  Modulus int24 */
    "MODI4",      /*  81  Modulus int32 */
    "MODU3",      /*  82  Modulus uint24 */
    "MODU4",      /*  83  Modulus uint32 */
    "MULF4",      /*  84  Multiply floats */
    "MULI3",      /*  85  Multiple int24 */
    "MULI4",      /*  86  Multiply int32 */
    "MULU3",      /*  87  Multiply uint24 */
    "MULU4",      /*  88  Multiply uint32 */
    "NE3",        /*  89  Compare (u)int24, jump if != */
    "NE4",        /*  90  Compare integers, jump if != */
    "NEF4",       /*  91  Compare floats, jump if != */
    "NEGF4",      /*  92  Negate float */
    "NEGI3",      /*  93  Negate int24 */
    "NEGI4",      /*  94  Negate int32 */
    "POP",        /*  95  Discard top-of-stack */
    "PUSH",       /*  96  Push no-value to stack */
    "RSHI3",      /*  97  Right-shift int24 (preserve sign) */
    "RSHI4",      /*  98  Right-shift int32 (preserve sign) */
    "RSHU3",      /*  99  Right-shift uint24 */
    "RSHU4",      /* 100  Right-shift uint32 */
    "STORE1",     /* 101  Store 1-byte to memory */
    "STORE2",     /* 102  Store 2-byte to memory */
    "STORE3",     /* 103  Store 3-byte to memory */
    "STORE4",     /* 104  Store 4-byte to memory */
    "SUB3",       /* 105  Subtract (u)int24 (two's complement). */
    "SUB4",       /* 106  Subtract (u)int32 (two's complement). */
    "SUBF4",      /* 107  Subtract floats */
};
