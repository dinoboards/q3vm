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
    "ARGF4",      /*   8  */
    "BAND3",      /*   9  */
    "BAND4",      /*  10  Bitwise AND */
    "BCOM3",      /*  11  */
    "BCOM4",      /*  12  Bitwise COMplement */
    "BLOCK_COPY", /*  13  memcpy */
    "BOR3",       /*  14  */
    "BOR4",       /*  15  Bitwise OR */
    "BXOR3",      /*  16  */
    "BXOR4",      /*  17  Bitwise eXclusive-OR */
    "CALL",       /*  18  Call subroutine. */
    "CI1I3",      /*  19  */
    "CI1I4",      /*  20  Sign-Extend 8-bit */
    "CI2I3",      /*  21  */
    "CI2I4",      /*  22  Sign-Extend 16-bit */
    "CI3I1",      /*  23  */
    "CI3I2",      /*  24  */
    "CI3I4",      /*  25  */
    "CI3U4",      /*  26  */
    "CI4I3",      /*  27  */
    "CI4U3",      /*  28  */
    "CONSTF4",    /*  29  */
    "CONSTGP3",   /*  30  */
    "CONSTGP4",   /*  31  Load constant to stack. */
    "CONSTI1",    /*  32  */
    "CONSTI2",    /*  33  */
    "CONSTI3",    /*  34  */
    "CONSTI4",    /*  35  */
    "CONSTP3",    /*  36  */
    "CONSTP4",    /*  37  */
    "CONSTU1",    /*  38  */
    "CONSTU2",    /*  39  */
    "CONSTU3",    /*  40  */
    "CONSTU4",    /*  41  */
    "CU2I3",      /*  42  */
    "CU3U2",      /*  43  */
    "CU3U4",      /*  44  */
    "CU4I3",      /*  45  */
    "CU4U3",      /*  46  */
    "CVFI",       /*  47  Convert to float from integer */
    "CVFI3",      /*  48  */
    "CVIF",       /*  49  Convert to integer from float */
    "CVIU3",      /*  50  */
    "CVUI3",      /*  51  */
    "DIVF",       /*  52  Divide floats */
    "DIVI",       /*  53  Divide signed integers. */
    "DIVI3",      /*  54  */
    "DIVU",       /*  55  Divide unsigned integers. */
    "DIVU3",      /*  56  */
    "ENTER",      /*  57  Begin subroutine. */
    "EQ",         /*  58  Compare integers, jump if equal. */
    "EQ3",        /*  59  */
    "EQF",        /*  60  Compare floats, jump if equal */
    "EQU3",       /*  61  */
    "GEF",        /*  62  Compare floats, jump if greater-than-or-equal */
    "GEI",        /*  63  Compare integers, jump if greater-than-or-equal. */
    "GEI3",       /*  64  */
    "GEU",        /*  65  Compare unsigned integers, jump if greater-than-or-equal */
    "GEU3",       /*  66  */
    "GTF",        /*  67  Compare floats, jump if greater-than */
    "GTI",        /*  68  Compare integers, jump if greater-than. */
    "GTI3",       /*  69  */
    "GTU",        /*  70  Compare unsigned integers, jump if greater-than */
    "GTU3",       /*  71  */
    "JUMP",       /*  72  Unconditional jump. */
    "LEAVE",      /*  73  End subroutine. */
    "LEF",        /*  74  Compare floats, jump if less-than-or-equal */
    "LEI",        /*  75  Compare integers, jump if less-than-or-equal. */
    "LEI3",       /*  76  */
    "LEU",        /*  77  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  78  */
    "LOAD1",      /*  79  Load 1-byte from memory */
    "LOAD2",      /*  80  Load 2-bytes from memory */
    "LOAD3",      /*  81  Load 3-bytes from memory */
    "LOAD4",      /*  82  Load 4-bytes from memory */
    "LOADF4",     /*  83  Load 4 byte float from memory */
    "LOCAL",      /*  84  Get local variable. */
    "LSH",        /*  85  Left-shift */
    "LSH3",       /*  86  */
    "LTF",        /*  87  Compare floats, jump if less-than */
    "LTI",        /*  88  Compare integers, jump if less-than. */
    "LTI3",       /*  89  */
    "LTU",        /*  90  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  91  */
    "MODI",       /*  92  Modulus (signed). */
    "MODI3",      /*  93  */
    "MODU",       /*  94  Modulus (unsigned). */
    "MODU3",      /*  95  */
    "MULF",       /*  96  Multiply floats */
    "MULI",       /*  97  Multiply signed integers. */
    "MULI3",      /*  98  */
    "MULU",       /*  99  Multiply unsigned integers. */
    "MULU3",      /* 100  */
    "NE",         /* 101  Compare integers, jump if not equal. */
    "NE3",        /* 102  */
    "NEF",        /* 103  Compare floats, jump if not-equal */
    "NEGF",       /* 104  Negate float */
    "NEGI",       /* 105  Negate integer. */
    "NEGI3",      /* 106  */
    "POP",        /* 107  Discard top-of-stack. */
    "PUSH",       /* 108  Push to stack. */
    "RSHI",       /* 109  Right-shift (algebraic; preserve sign) */
    "RSHI3",      /* 110  */
    "RSHU",       /* 111  Right-shift (bitwise; ignore sign) */
    "RSHU3",      /* 112  */
    "SEX24",      /* 113  */
    "SEX8_3",     /* 114  */
    "STORE1",     /* 115  Store 1-byte to memory */
    "STORE2",     /* 116  Store 2-byte to memory */
    "STORE3",     /* 117  */
    "STORE4",     /* 118  *(stack[top-1]) = stack[top] */
    "SUB",        /* 119  Subtract integers (two's complement). */
    "SUB3",       /* 120  */
    "SUBF",       /* 121  Subtract floats */
};
