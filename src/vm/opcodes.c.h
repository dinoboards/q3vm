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
    "CONSTGP3",   /*  25  Push address pointer to stack (duplicate?) */
    "CONSTP3",    /*  26  Push address pointer to stack */
    "CONSTs1",    /*  27  Push 1 byte constant */
    "CONSTs2",    /*  28  Push 2 byte constant */
    "CONSTs3",    /*  29  Push 3 byte constant */
    "CONSTs4",    /*  30  Push 4 byte constant */
    "CU1I3",      /*  31  Convert uint8 to int24 */
    "CU2I3",      /*  32  Convert uint16 to int24 */
    "CU3U4",      /*  33  Convert uint24 to uint32 */
    "DIVF4",      /*  34  Divide floats */
    "DIVI3",      /*  35  Divide int24 */
    "DIVI4",      /*  36  Divide int32 */
    "DIVU3",      /*  37  Divide uint24 */
    "DIVU4",      /*  38  Divide uint32 */
    "ENTER",      /*  39  Begin subroutine */
    "EQ3",        /*  40  Compare (u)int24, jump if == */
    "EQ4",        /*  41  Compare (u)int32, jump if == */
    "EQF4",       /*  42  Compare floats, jump if == */
    "GEF4",       /*  43  Compare floats, jump if >= */
    "GEI3",       /*  44  Compare int24, jump if > */
    "GEI4",       /*  45  Compare int32, jump if >= */
    "GEU3",       /*  46  Compare uint24, jump if >= */
    "GEU4",       /*  47  Compare uint24, jump if >= */
    "GTF4",       /*  48  Compare floats, jump if > */
    "GTI3",       /*  49  Compare int24, jump if > */
    "GTI4",       /*  50  Compare int32, jump if > */
    "GTU3",       /*  51  Compare uint24, jump if > */
    "GTU4",       /*  52  Compare uint32, jump if > */
    "JUMP",       /*  53  Unconditional jump */
    "LEAVE",      /*  54  End subroutine */
    "LEF4",       /*  55  Compare floats, jump if <= */
    "LEI3",       /*  56  Compare int24, jump if <= */
    "LEI4",       /*  57  Compare int32, jump if <= */
    "LEU3",       /*  58  Compare uint24, jump if <= */
    "LEU4",       /*  59  Compare uint32, jump if <= */
    "LOAD1",      /*  60  Load 1-byte from memory */
    "LOAD2",      /*  61  Load 2-bytes from memory */
    "LOAD3",      /*  62  Load 3-bytes from memory */
    "LOAD4",      /*  63  Load 4-bytes from memory */
    "LOCAL",      /*  64  Get local variable */
    "LSH3",       /*  65  left shift (u)int24 */
    "LSH4",       /*  66  Left-shift (u)int32 */
    "LTF4",       /*  67  Compare floats, jump if < */
    "LTI3",       /*  68  Compare int24, jump if < */
    "LTI4",       /*  69  Compare int32, jump if < */
    "LTU3",       /*  70  Compare uint24, jump if < */
    "LTU4",       /*  71  Compare uint32, jump if < */
    "MODI3",      /*  72  Modulus int24 */
    "MODI4",      /*  73  Modulus int32 */
    "MODU3",      /*  74  Modulus uint24 */
    "MODU4",      /*  75  Modulus uint32 */
    "MULF4",      /*  76  Multiply floats */
    "MULI3",      /*  77  Multiple int24 */
    "MULI4",      /*  78  Multiply int32 */
    "MULU3",      /*  79  Multiply uint24 */
    "MULU4",      /*  80  Multiply uint32 */
    "NE3",        /*  81  Compare (u)int24, jump if != */
    "NE4",        /*  82  Compare integers, jump if != */
    "NEF4",       /*  83  Compare floats, jump if != */
    "NEGF4",      /*  84  Negate float */
    "NEGI3",      /*  85  Negate int24 */
    "NEGI4",      /*  86  Negate int32 */
    "POP",        /*  87  Discard top-of-stack */
    "PUSH",       /*  88  Push no-value to stack */
    "RSHI3",      /*  89  Right-shift int24 (preserve sign) */
    "RSHI4",      /*  90  Right-shift int32 (preserve sign) */
    "RSHU3",      /*  91  Right-shift uint24 */
    "RSHU4",      /*  92  Right-shift uint32 */
    "STORE1",     /*  93  Store 1-byte to memory */
    "STORE2",     /*  94  Store 2-byte to memory */
    "STORE3",     /*  95  Store 3-byte to memory */
    "STORE4",     /*  96  Store 4-byte to memory */
    "SUB3",       /*  97  Subtract (u)int24 (two's complement). */
    "SUB4",       /*  98  Subtract (u)int32 (two's complement). */
    "SUBF4",      /*  99  Subtract floats */
};
