#include "opcodes.h"

const char *const opnames[OPCODE_TABLE_SIZE] = {
    "UNDEF",        /*   0  Error: VM halt */
    "IGNORE",       /*   1  No operation */
    "ADD3",         /*   2  Add int24 (two's complement) */
    "ADD4",         /*   3  Add int32 (two's complement) */
    "ADDF4",        /*   4  Add floats */
    "ARG3",         /*   5  Marshal 3 byte argument */
    "ARG4",         /*   6  Marshal 4 byte argument */
    "BAND3",        /*   7  Bitwise AND int24 */
    "BAND4",        /*   8  Bitwise AND int32 */
    "BCOM3",        /*   9  Bitwise Complement int24 */
    "BCOM4",        /*  10  Bitwise COMplement int32 */
    "BLK_CPY",      /*  11  memcpy */
    "BLK_CPY_U1",   /*  12  */
    "BLK_CPY_U2",   /*  13  */
    "BOR3",         /*  14  Bitwise OR int24 */
    "BOR4",         /*  15  Bitwise OR int32 */
    "BREAK",        /*  16  vm->breakCount++ */
    "BXOR3",        /*  17  Bitwise eXclusive-OR int24 */
    "BXOR4",        /*  18  Bitwise eXclusive-OR int32 */
    "CALL",         /*  19  Call subroutine. */
    "CF4I3",        /*  20  Convert float to int24 */
    "CF4I4",        /*  21  Convert float to int32 */
    "CI1I3",        /*  22  Convert int8 to int24 */
    "CI2I3",        /*  23  Convert int16 to int24 */
    "CI3F4",        /*  24  Convert int24 to float */
    "CI3s4",        /*  25  Convert int24 to (u)int32 */
    "CI4F4",        /*  26  Convert int32 to float */
    "CONSTI3_I1",   /*  27  */
    "CONSTI3_I2",   /*  28  */
    "CONSTP3",      /*  29  Push address pointer to stack */
    "CONSTP3_1",    /*  30  */
    "CONSTP3_2",    /*  31  */
    "CONSTP3_FD",   /*  32  */
    "CONSTP3_SC01", /*  33  */
    "CONSTP3_SC02", /*  34  */
    "CONSTP3_SC03", /*  35  */
    "CONSTP3_SC04", /*  36  */
    "CONSTP3_SC05", /*  37  */
    "CONSTP3_SC06", /*  38  */
    "CONSTP3_SC07", /*  39  */
    "CONSTP3_SC08", /*  40  */
    "CONSTP3_SC09", /*  41  */
    "CONSTP3_SC10", /*  42  */
    "CONSTP3_SC11", /*  43  */
    "CONSTP3_SC12", /*  44  */
    "CONSTP3_SC13", /*  45  */
    "CONSTP3_SC14", /*  46  */
    "CONSTP3_SC15", /*  47  */
    "CONSTP3_SCn",  /*  48  */
    "CONSTs1",      /*  49  Push 1 byte constant */
    "CONSTs2",      /*  50  Push 2 byte constant */
    "CONSTs3",      /*  51  Push 3 byte constant */
    "CONSTs4",      /*  52  Push 4 byte constant */
    "CONSTU3_U1",   /*  53  */
    "CONSTU3_U2",   /*  54  */
    "CU1I3",        /*  55  Convert uint8 to int24 */
    "CU2I3",        /*  56  Convert uint16 to int24 */
    "CU3U4",        /*  57  Convert uint24 to uint32 */
    "DI",           /*  58  Disable Interrupts */
    "DIVF4",        /*  59  Divide floats */
    "DIVI3",        /*  60  Divide int24 */
    "DIVI4",        /*  61  Divide int32 */
    "DIVU3",        /*  62  Divide uint24 */
    "DIVU4",        /*  63  Divide uint32 */
    "EI",           /*  64  Enable Interrupts */
    "ENTER",        /*  65  Begin subroutine */
    "EQ3",          /*  66  Compare (u)int24, jump if == */
    "EQ3_1",        /*  67  Compare (u)int24, jump if == */
    "EQ4",          /*  68  Compare (u)int32, jump if == */
    "GEF4",         /*  69  Compare floats, jump if >= */
    "GEI3",         /*  70  Compare int24, jump if > */
    "GEI3_1",       /*  71  */
    "GEI4",         /*  72  Compare int32, jump if >= */
    "GEU3",         /*  73  Compare uint24, jump if >= */
    "GEU3_1",       /*  74  */
    "GEU4",         /*  75  Compare uint24, jump if >= */
    "GTF4",         /*  76  Compare floats, jump if > */
    "GTI3",         /*  77  Compare int24, jump if > */
    "GTI3_1",       /*  78  */
    "GTI4",         /*  79  Compare int32, jump if > */
    "GTU3",         /*  80  Compare uint24, jump if > */
    "GTU3_1",       /*  81  */
    "GTU4",         /*  82  Compare uint32, jump if > */
    "JUMP",         /*  83  Unconditional jump */
    "LEAVE",        /*  84  End subroutine */
    "LEF4",         /*  85  Compare floats, jump if <= */
    "LEI3",         /*  86  Compare int24, jump if <= */
    "LEI3_1",       /*  87  */
    "LEI4",         /*  88  Compare int32, jump if <= */
    "LEU3",         /*  89  Compare uint24, jump if <= */
    "LEU3_1",       /*  90  */
    "LEU4",         /*  91  Compare uint32, jump if <= */
    "LOAD1",        /*  92  Load 1-byte from memory */
    "LOAD2",        /*  93  Load 2-bytes from memory */
    "LOAD3",        /*  94  Load 3-bytes from memory */
    "LOAD4",        /*  95  Load 4-bytes from memory */
    "LOCAL",        /*  96  Get local variable (8 bit offset) */
    "LOCAL_FAR",    /*  97  Get local variable (16 bit offset) */
    "LSH3",         /*  98  left shift (u)int24 */
    "LSH4",         /*  99  Left-shift (u)int32 */
    "LTF4",         /* 100  Compare floats, jump if < */
    "LTI3",         /* 101  Compare int24, jump if < */
    "LTI3_1",       /* 102  */
    "LTI4",         /* 103  Compare int32, jump if < */
    "LTU3",         /* 104  Compare uint24, jump if < */
    "LTU3_1",       /* 105  */
    "LTU4",         /* 106  Compare uint32, jump if < */
    "MODI3",        /* 107  Modulus int24 */
    "MODI4",        /* 108  Modulus int32 */
    "MODU3",        /* 109  Modulus uint24 */
    "MODU4",        /* 110  Modulus uint32 */
    "MULF4",        /* 111  Multiply floats */
    "MULI3",        /* 112  Multiple int24 */
    "MULI4",        /* 113  Multiply int32 */
    "MULU3",        /* 114  Multiply uint24 */
    "MULU4",        /* 115  Multiply uint32 */
    "NE3",          /* 116  Compare (u)int24, jump if != */
    "NE3_1",        /* 117  */
    "NE4",          /* 118  Compare integers, jump if != */
    "NEF4",         /* 119  Compare floats, jump if != */
    "NEGF4",        /* 120  Negate float */
    "NEGI3",        /* 121  Negate int24 */
    "NEGI4",        /* 122  Negate int32 */
    "POP",          /* 123  Discard top-of-stack */
    "PUSH",         /* 124  Push no-value to stack */
    "RSHI3",        /* 125  Right-shift int24 (preserve sign) */
    "RSHI4",        /* 126  Right-shift int32 (preserve sign) */
    "RSHU3",        /* 127  Right-shift uint24 */
    "RSHU4",        /* 128  Right-shift uint32 */
    "STORE1",       /* 129  Store 1-byte to memory */
    "STORE2",       /* 130  Store 2-byte to memory */
    "STORE3",       /* 131  Store 3-byte to memory */
    "STORE4",       /* 132  Store 4-byte to memory */
    "SUB3",         /* 133  Subtract (u)int24 (two's complement). */
    "SUB4",         /* 134  Subtract (u)int32 (two's complement). */
    "SUBF4",        /* 135  Subtract floats */
};
