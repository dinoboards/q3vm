#include "opcodes.h"

const char *const opnames[OPCODE_TABLE_SIZE] = {
    "UNDEF",      /*   0  Error: VM halt */
    "IGNORE",     /*   1  No operation */
    "BREAK",      /*   2  vm->breakCount++ */
    "ADD3",       /*   3  */
    "ADD4",       /*   4  Add integers (two's complement). */
    "ADDF4",      /*   5  Add floats */
    "ARG3",       /*   6  Marshal argument */
    "ARG4",       /*   7  */
    "BAND3",      /*   8  */
    "BAND4",      /*   9  Bitwise AND */
    "BCOM3",      /*  10  */
    "BCOM4",      /*  11  Bitwise COMplement */
    "BLOCK_COPY", /*  12  memcpy */
    "BOR3",       /*  13  */
    "BOR4",       /*  14  Bitwise OR */
    "BXOR3",      /*  15  */
    "BXOR4",      /*  16  Bitwise eXclusive-OR */
    "CALL",       /*  17  Call subroutine. */
    "CF4I4",      /*  18  Convert to float from integer */
    "CI1I3",      /*  19  */
    "CI2I3",      /*  20  */
    "CI3F4",      /*  21  */
    "CI3I1",      /*  22  */
    "CI3I2",      /*  23  */
    "CI3I4",      /*  24  */
    "CI3U4",      /*  25  */
    "CI4F4",      /*  26  Convert to integer from float */
    "CI4I3",      /*  27  */
    "CI4U3",      /*  28  */
    "CONSTGP3",   /*  29  push address pointer to stack. */
    "CONSTI1",    /*  30  */
    "CONSTI2",    /*  31  */
    "CONSTI3",    /*  32  */
    "CONSTI4",    /*  33  */
    "CONSTP3",    /*  34  */
    "CONSTU1",    /*  35  */
    "CONSTU2",    /*  36  */
    "CONSTU3",    /*  37  */
    "CONSTU4",    /*  38  */
    "CU1I3",      /*  39  */
    "CU2I3",      /*  40  */
    "CU3U2",      /*  41  */
    "CU3U4",      /*  42  */
    "CU4I3",      /*  43  */
    "CU4U3",      /*  44  */
    "CVFI3",      /*  45  */
    "CVIU3",      /*  46  */
    "CVUI3",      /*  47  */
    "DIVF4",      /*  48  Divide floats */
    "DIVI",       /*  49  Divide signed integers. */
    "DIVI3",      /*  50  */
    "DIVU",       /*  51  Divide unsigned integers. */
    "DIVU3",      /*  52  */
    "ENTER",      /*  53  Begin subroutine. */
    "EQ3",        /*  54  */
    "EQ4",        /*  55  Compare integers, jump if equal. */
    "EQF4",       /*  56  Compare floats, jump if equal */
    "EQU3",       /*  57  */
    "GEF4",       /*  58  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  59  */
    "GEI4",       /*  60  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  61  */
    "GEU4",       /*  62  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  63  Compare floats, jump if greater-than */
    "GTI3",       /*  64  */
    "GTI4",       /*  65  Compare integers, jump if greater-than. */
    "GTU3",       /*  66  */
    "GTU4",       /*  67  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  68  Unconditional jump. */
    "LEAVE",      /*  69  End subroutine. */
    "LEF4",       /*  70  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  71  */
    "LEI4",       /*  72  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  73  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  74  */
    "LOAD1",      /*  75  Load 1-byte from memory */
    "LOAD2",      /*  76  Load 2-bytes from memory */
    "LOAD3",      /*  77  Load 3-bytes from memory */
    "LOAD4",      /*  78  Load 4-bytes from memory */
    "LOADF4",     /*  79  Load 4 byte float from memory */
    "LOCAL",      /*  80  Get local variable. */
    "LSH3",       /*  81  */
    "LSH4",       /*  82  Left-shift */
    "LTF",        /*  83  Compare floats, jump if less-than */
    "LTI3",       /*  84  */
    "LTI4",       /*  85  Compare integers, jump if less-than. */
    "LTU",        /*  86  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  87  */
    "MODI3",      /*  88  */
    "MODI4",      /*  89  Modulus (signed). */
    "MODU3",      /*  90  */
    "MODU4",      /*  91  Modulus (unsigned). */
    "MULF4",      /*  92  Multiply floats */
    "MULI3",      /*  93  */
    "MULI4",      /*  94  Multiply signed integers. */
    "MULU3",      /*  95  */
    "MULU4",      /*  96  Multiply unsigned integers. */
    "NE3",        /*  97  */
    "NE4",        /*  98  Compare integers, jump if not equal. */
    "NEF",        /*  99  Compare floats, jump if not-equal */
    "NEGF4",      /* 100  Negate float */
    "NEGI3",      /* 101  */
    "NEGI4",      /* 102  Negate integer. */
    "POP",        /* 103  Discard top-of-stack. */
    "PUSH",       /* 104  Push to stack. */
    "RSHI3",      /* 105  */
    "RSHI4",      /* 106  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 107  */
    "RSHU4",      /* 108  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 109  Store 1-byte to memory */
    "STORE2",     /* 110  Store 2-byte to memory */
    "STORE3",     /* 111  */
    "STORE4",     /* 112  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 113  */
    "SUB4",       /* 114  Subtract integers (two's complement). */
    "SUBF4",      /* 115  Subtract floats */
};
