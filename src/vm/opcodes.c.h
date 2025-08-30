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
    "CONSTP3",    /*  25  Push address pointer to stack */
    "CONSTs1",    /*  26  Push 1 byte constant */
    "CONSTs2",    /*  27  Push 2 byte constant */
    "CONSTs3",    /*  28  Push 3 byte constant */
    "CONSTs4",    /*  29  Push 4 byte constant */
    "CU1I3",      /*  30  Convert uint8 to int24 */
    "CU2I3",      /*  31  Convert uint16 to int24 */
    "CU3U4",      /*  32  Convert uint24 to uint32 */
    "DIVF4",      /*  33  Divide floats */
    "DIVI3",      /*  34  Divide int24 */
    "DIVI4",      /*  35  Divide int32 */
    "DIVU3",      /*  36  Divide uint24 */
    "DIVU4",      /*  37  Divide uint32 */
    "ENTER",      /*  38  Begin subroutine */
    "EQ3",        /*  39  Compare (u)int24, jump if == */
    "EQ4",        /*  40  Compare (u)int32, jump if == */
    "GEF4",       /*  41  Compare floats, jump if >= */
    "GEI3",       /*  42  Compare int24, jump if > */
    "GEI4",       /*  43  Compare int32, jump if >= */
    "GEU3",       /*  44  Compare uint24, jump if >= */
    "GEU4",       /*  45  Compare uint24, jump if >= */
    "GTF4",       /*  46  Compare floats, jump if > */
    "GTI3",       /*  47  Compare int24, jump if > */
    "GTI4",       /*  48  Compare int32, jump if > */
    "GTU3",       /*  49  Compare uint24, jump if > */
    "GTU4",       /*  50  Compare uint32, jump if > */
    "JUMP",       /*  51  Unconditional jump */
    "LEAVE",      /*  52  End subroutine */
    "LEF4",       /*  53  Compare floats, jump if <= */
    "LEI3",       /*  54  Compare int24, jump if <= */
    "LEI4",       /*  55  Compare int32, jump if <= */
    "LEU3",       /*  56  Compare uint24, jump if <= */
    "LEU4",       /*  57  Compare uint32, jump if <= */
    "LOAD1",      /*  58  Load 1-byte from memory */
    "LOAD2",      /*  59  Load 2-bytes from memory */
    "LOAD3",      /*  60  Load 3-bytes from memory */
    "LOAD4",      /*  61  Load 4-bytes from memory */
    "LOCAL",      /*  62  Get local variable (8 bit offset) */
    "LOCAL_FAR",  /*  63  Get local variable (16 bit offset) */
    "LSH3",       /*  64  left shift (u)int24 */
    "LSH4",       /*  65  Left-shift (u)int32 */
    "LTF4",       /*  66  Compare floats, jump if < */
    "LTI3",       /*  67  Compare int24, jump if < */
    "LTI4",       /*  68  Compare int32, jump if < */
    "LTU3",       /*  69  Compare uint24, jump if < */
    "LTU4",       /*  70  Compare uint32, jump if < */
    "MODI3",      /*  71  Modulus int24 */
    "MODI4",      /*  72  Modulus int32 */
    "MODU3",      /*  73  Modulus uint24 */
    "MODU4",      /*  74  Modulus uint32 */
    "MULF4",      /*  75  Multiply floats */
    "MULI3",      /*  76  Multiple int24 */
    "MULI4",      /*  77  Multiply int32 */
    "MULU3",      /*  78  Multiply uint24 */
    "MULU4",      /*  79  Multiply uint32 */
    "NE3",        /*  80  Compare (u)int24, jump if != */
    "NE4",        /*  81  Compare integers, jump if != */
    "NEF4",       /*  82  Compare floats, jump if != */
    "NEGF4",      /*  83  Negate float */
    "NEGI3",      /*  84  Negate int24 */
    "NEGI4",      /*  85  Negate int32 */
    "POP",        /*  86  Discard top-of-stack */
    "PUSH",       /*  87  Push no-value to stack */
    "RSHI3",      /*  88  Right-shift int24 (preserve sign) */
    "RSHI4",      /*  89  Right-shift int32 (preserve sign) */
    "RSHU3",      /*  90  Right-shift uint24 */
    "RSHU4",      /*  91  Right-shift uint32 */
    "STORE1",     /*  92  Store 1-byte to memory */
    "STORE2",     /*  93  Store 2-byte to memory */
    "STORE3",     /*  94  Store 3-byte to memory */
    "STORE4",     /*  95  Store 4-byte to memory */
    "SUB3",       /*  96  Subtract (u)int24 (two's complement). */
    "SUB4",       /*  97  Subtract (u)int32 (two's complement). */
    "SUBF4",      /*  98  Subtract floats */
    "DI",         /*  99  Disable Interrupts */
    "EI",         /* 100  Enable Interrupts */
};
