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
    "CONSTP3_1",  /*  30  */
    "CONSTP3_2",  /*  31  */
    "CONSTs1",    /*  32  Push 1 byte constant */
    "CONSTs2",    /*  33  Push 2 byte constant */
    "CONSTs3",    /*  34  Push 3 byte constant */
    "CONSTs4",    /*  35  Push 4 byte constant */
    "CONSTU3_U1", /*  36  */
    "CONSTU3_U2", /*  37  */
    "CU1I3",      /*  38  Convert uint8 to int24 */
    "CU2I3",      /*  39  Convert uint16 to int24 */
    "CU3U4",      /*  40  Convert uint24 to uint32 */
    "DI",         /*  41  Disable Interrupts */
    "DIVF4",      /*  42  Divide floats */
    "DIVI3",      /*  43  Divide int24 */
    "DIVI4",      /*  44  Divide int32 */
    "DIVU3",      /*  45  Divide uint24 */
    "DIVU4",      /*  46  Divide uint32 */
    "EI",         /*  47  Enable Interrupts */
    "ENTER",      /*  48  Begin subroutine */
    "EQ3",        /*  49  Compare (u)int24, jump if == */
    "EQ3_1",      /*  50  Compare (u)int24, jump if == */
    "EQ4",        /*  51  Compare (u)int32, jump if == */
    "GEF4",       /*  52  Compare floats, jump if >= */
    "GEI3",       /*  53  Compare int24, jump if > */
    "GEI3_1",     /*  54  */
    "GEI4",       /*  55  Compare int32, jump if >= */
    "GEU3",       /*  56  Compare uint24, jump if >= */
    "GEU3_1",     /*  57  */
    "GEU4",       /*  58  Compare uint24, jump if >= */
    "GTF4",       /*  59  Compare floats, jump if > */
    "GTI3",       /*  60  Compare int24, jump if > */
    "GTI3_1",     /*  61  */
    "GTI4",       /*  62  Compare int32, jump if > */
    "GTU3",       /*  63  Compare uint24, jump if > */
    "GTU3_1",     /*  64  */
    "GTU4",       /*  65  Compare uint32, jump if > */
    "JUMP",       /*  66  Unconditional jump */
    "LEAVE",      /*  67  End subroutine */
    "LEF4",       /*  68  Compare floats, jump if <= */
    "LEI3",       /*  69  Compare int24, jump if <= */
    "LEI3_1",     /*  70  */
    "LEI4",       /*  71  Compare int32, jump if <= */
    "LEU3",       /*  72  Compare uint24, jump if <= */
    "LEU3_1",     /*  73  */
    "LEU4",       /*  74  Compare uint32, jump if <= */
    "LOAD1",      /*  75  Load 1-byte from memory */
    "LOAD2",      /*  76  Load 2-bytes from memory */
    "LOAD3",      /*  77  Load 3-bytes from memory */
    "LOAD4",      /*  78  Load 4-bytes from memory */
    "LOCAL",      /*  79  Get local variable (8 bit offset) */
    "LOCAL_FAR",  /*  80  Get local variable (16 bit offset) */
    "LSH3",       /*  81  left shift (u)int24 */
    "LSH4",       /*  82  Left-shift (u)int32 */
    "LTF4",       /*  83  Compare floats, jump if < */
    "LTI3",       /*  84  Compare int24, jump if < */
    "LTI3_1",     /*  85  */
    "LTI4",       /*  86  Compare int32, jump if < */
    "LTU3",       /*  87  Compare uint24, jump if < */
    "LTU3_1",     /*  88  */
    "LTU4",       /*  89  Compare uint32, jump if < */
    "MODI3",      /*  90  Modulus int24 */
    "MODI4",      /*  91  Modulus int32 */
    "MODU3",      /*  92  Modulus uint24 */
    "MODU4",      /*  93  Modulus uint32 */
    "MULF4",      /*  94  Multiply floats */
    "MULI3",      /*  95  Multiple int24 */
    "MULI4",      /*  96  Multiply int32 */
    "MULU3",      /*  97  Multiply uint24 */
    "MULU4",      /*  98  Multiply uint32 */
    "NE3",        /*  99  Compare (u)int24, jump if != */
    "NE3_1",      /* 100  */
    "NE4",        /* 101  Compare integers, jump if != */
    "NEF4",       /* 102  Compare floats, jump if != */
    "NEGF4",      /* 103  Negate float */
    "NEGI3",      /* 104  Negate int24 */
    "NEGI4",      /* 105  Negate int32 */
    "POP",        /* 106  Discard top-of-stack */
    "PUSH",       /* 107  Push no-value to stack */
    "RSHI3",      /* 108  Right-shift int24 (preserve sign) */
    "RSHI4",      /* 109  Right-shift int32 (preserve sign) */
    "RSHU3",      /* 110  Right-shift uint24 */
    "RSHU4",      /* 111  Right-shift uint32 */
    "STORE1",     /* 112  Store 1-byte to memory */
    "STORE2",     /* 113  Store 2-byte to memory */
    "STORE3",     /* 114  Store 3-byte to memory */
    "STORE4",     /* 115  Store 4-byte to memory */
    "SUB3",       /* 116  Subtract (u)int24 (two's complement). */
    "SUB4",       /* 117  Subtract (u)int32 (two's complement). */
    "SUBF4",      /* 118  Subtract floats */
};
