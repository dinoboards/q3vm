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
    "BLOCK_COPY", /*  12  memcpy */
    "BOR3",       /*  13  Bitwise OR int24 */
    "BOR4",       /*  14  Bitwise OR int32 */
    "BXOR3",      /*  15  Bitwise eXclusive-OR int24 */
    "BXOR4",      /*  16  Bitwise eXclusive-OR int32 */
    "CALL",       /*  17  Call subroutine. */
    "CF4I3",      /*  18  Convert float to int24 */
    "CF4I4",      /*  19  Convert float to int32 */
    "CI1I3",      /*  20  Convert int8 to int24 */
    "CI2I3",      /*  21  Convert int16 to int24 */
    "CI3F4",      /*  22  Convert int24 to float */
    "CI3s4",      /*  23  Convert int24 to (u)int32 */
    "CI4F4",      /*  24  Convert int32 to float */
    "CONSTI3_I1", /*  25  */
    "CONSTI3_I2", /*  26  */
    "CONSTP3",    /*  27  Push address pointer to stack */
    "CONSTs1",    /*  28  Push 1 byte constant */
    "CONSTs2",    /*  29  Push 2 byte constant */
    "CONSTs3",    /*  30  Push 3 byte constant */
    "CONSTs4",    /*  31  Push 4 byte constant */
    "CONSTU3_U1", /*  32  */
    "CONSTU3_U2", /*  33  */
    "CU1I3",      /*  34  Convert uint8 to int24 */
    "CU2I3",      /*  35  Convert uint16 to int24 */
    "CU3U4",      /*  36  Convert uint24 to uint32 */
    "DI",         /*  37  Disable Interrupts */
    "DIVF4",      /*  38  Divide floats */
    "DIVI3",      /*  39  Divide int24 */
    "DIVI4",      /*  40  Divide int32 */
    "DIVU3",      /*  41  Divide uint24 */
    "DIVU4",      /*  42  Divide uint32 */
    "EI",         /*  43  Enable Interrupts */
    "ENTER",      /*  44  Begin subroutine */
    "EQ3",        /*  45  Compare (u)int24, jump if == */
    "EQ4",        /*  46  Compare (u)int32, jump if == */
    "GEF4",       /*  47  Compare floats, jump if >= */
    "GEI3",       /*  48  Compare int24, jump if > */
    "GEI4",       /*  49  Compare int32, jump if >= */
    "GEU3",       /*  50  Compare uint24, jump if >= */
    "GEU4",       /*  51  Compare uint24, jump if >= */
    "GTF4",       /*  52  Compare floats, jump if > */
    "GTI3",       /*  53  Compare int24, jump if > */
    "GTI4",       /*  54  Compare int32, jump if > */
    "GTU3",       /*  55  Compare uint24, jump if > */
    "GTU4",       /*  56  Compare uint32, jump if > */
    "JUMP",       /*  57  Unconditional jump */
    "LEAVE",      /*  58  End subroutine */
    "LEF4",       /*  59  Compare floats, jump if <= */
    "LEI3",       /*  60  Compare int24, jump if <= */
    "LEI4",       /*  61  Compare int32, jump if <= */
    "LEU3",       /*  62  Compare uint24, jump if <= */
    "LEU4",       /*  63  Compare uint32, jump if <= */
    "LOAD1",      /*  64  Load 1-byte from memory */
    "LOAD2",      /*  65  Load 2-bytes from memory */
    "LOAD3",      /*  66  Load 3-bytes from memory */
    "LOAD4",      /*  67  Load 4-bytes from memory */
    "LOCAL",      /*  68  Get local variable (8 bit offset) */
    "LOCAL_FAR",  /*  69  Get local variable (16 bit offset) */
    "LSH3",       /*  70  left shift (u)int24 */
    "LSH4",       /*  71  Left-shift (u)int32 */
    "LTF4",       /*  72  Compare floats, jump if < */
    "LTI3",       /*  73  Compare int24, jump if < */
    "LTI4",       /*  74  Compare int32, jump if < */
    "LTU3",       /*  75  Compare uint24, jump if < */
    "LTU4",       /*  76  Compare uint32, jump if < */
    "MODI3",      /*  77  Modulus int24 */
    "MODI4",      /*  78  Modulus int32 */
    "MODU3",      /*  79  Modulus uint24 */
    "MODU4",      /*  80  Modulus uint32 */
    "MULF4",      /*  81  Multiply floats */
    "MULI3",      /*  82  Multiple int24 */
    "MULI4",      /*  83  Multiply int32 */
    "MULU3",      /*  84  Multiply uint24 */
    "MULU4",      /*  85  Multiply uint32 */
    "NE3",        /*  86  Compare (u)int24, jump if != */
    "NE4",        /*  87  Compare integers, jump if != */
    "NEF4",       /*  88  Compare floats, jump if != */
    "NEGF4",      /*  89  Negate float */
    "NEGI3",      /*  90  Negate int24 */
    "NEGI4",      /*  91  Negate int32 */
    "POP",        /*  92  Discard top-of-stack */
    "PUSH",       /*  93  Push no-value to stack */
    "RSHI3",      /*  94  Right-shift int24 (preserve sign) */
    "RSHI4",      /*  95  Right-shift int32 (preserve sign) */
    "RSHU3",      /*  96  Right-shift uint24 */
    "RSHU4",      /*  97  Right-shift uint32 */
    "STORE1",     /*  98  Store 1-byte to memory */
    "STORE2",     /*  99  Store 2-byte to memory */
    "STORE3",     /* 100  Store 3-byte to memory */
    "STORE4",     /* 101  Store 4-byte to memory */
    "SUB3",       /* 102  Subtract (u)int24 (two's complement). */
    "SUB4",       /* 103  Subtract (u)int32 (two's complement). */
    "SUBF4",      /* 104  Subtract floats */
};
