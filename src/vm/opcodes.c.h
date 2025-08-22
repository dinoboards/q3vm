#include "opcodes.h"

const char *const opnames[OPCODE_TABLE_SIZE] = {
    "UNDEF",      /*   0  Error: VM halt */
    "IGNORE",     /*   1  No operation */
    "BREAK",      /*   2  vm->breakCount++ */
    "ADD",        /*   3  Add integers (two's complement). */
    "ADD3",       /*   4  */
    "ADDF",       /*   5  Add floats */
    "ARG3",       /*   6  Marshal argument */
    "ARG4",       /*   7  */
    "ARGF",       /*   8  */
    "BAND",       /*   9  Bitwise AND */
    "BAND3",      /*  10  */
    "BCOM",       /*  11  Bitwise COMplement */
    "BCOM3",      /*  12  */
    "BLOCK_COPY", /*  13  memcpy */
    "BOR",        /*  14  Bitwise OR */
    "BOR3",       /*  15  */
    "BXOR",       /*  16  Bitwise eXclusive-OR */
    "BXOR3",      /*  17  */
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
    "CONSTF4",    /*  28  */
    "CONSTGP3",   /*  29  */
    "CONSTGP4",   /*  30  Load constant to stack. */
    "CONSTI1",    /*  31  */
    "CONSTI2",    /*  32  */
    "CONSTI3",    /*  33  */
    "CONSTI4",    /*  34  */
    "CONSTP3",    /*  35  */
    "CONSTP4",    /*  36  */
    "CONSTU1",    /*  37  */
    "CONSTU2",    /*  38  */
    "CONSTU3",    /*  39  */
    "CONSTU4",    /*  40  */
    "CU2I3",      /*  41  */
    "CU3U2",      /*  42  */
    "CU3U4",      /*  43  */
    "CU4I3",      /*  44  */
    "CU4U3",      /*  45  */
    "CVFI",       /*  46  Convert to float from integer */
    "CVFI3",      /*  47  */
    "CVIF",       /*  48  Convert to integer from float */
    "CVIU3",      /*  49  */
    "CVUI3",      /*  50  */
    "DIVF",       /*  51  Divide floats */
    "DIVI",       /*  52  Divide signed integers. */
    "DIVI3",      /*  53  */
    "DIVU",       /*  54  Divide unsigned integers. */
    "DIVU3",      /*  55  */
    "ENTER",      /*  56  Begin subroutine. */
    "EQ",         /*  57  Compare integers, jump if equal. */
    "EQ3",        /*  58  */
    "EQF",        /*  59  Compare floats, jump if equal */
    "EQU3",       /*  60  */
    "GEF",        /*  61  Compare floats, jump if greater-than-or-equal */
    "GEI",        /*  62  Compare integers, jump if greater-than-or-equal. */
    "GEI3",       /*  63  */
    "GEU",        /*  64  Compare unsigned integers, jump if greater-than-or-equal */
    "GEU3",       /*  65  */
    "GTF",        /*  66  Compare floats, jump if greater-than */
    "GTI",        /*  67  Compare integers, jump if greater-than. */
    "GTI3",       /*  68  */
    "GTU",        /*  69  Compare unsigned integers, jump if greater-than */
    "GTU3",       /*  70  */
    "JUMP",       /*  71  Unconditional jump. */
    "LEAVE",      /*  72  End subroutine. */
    "LEF",        /*  73  Compare floats, jump if less-than-or-equal */
    "LEI",        /*  74  Compare integers, jump if less-than-or-equal. */
    "LEI3",       /*  75  */
    "LEU",        /*  76  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  77  */
    "LOAD1",      /*  78  Load 1-byte from memory */
    "LOAD2",      /*  79  Load 2-bytes from memory */
    "LOAD3",      /*  80  Load 3-bytes from memory */
    "LOAD4",      /*  81  Load 4-bytes from memory */
    "LOADF4",     /*  82  Load 4 byte float from memory */
    "LOCAL",      /*  83  Get local variable. */
    "LSH",        /*  84  Left-shift */
    "LSH3",       /*  85  */
    "LTF",        /*  86  Compare floats, jump if less-than */
    "LTI",        /*  87  Compare integers, jump if less-than. */
    "LTI3",       /*  88  */
    "LTU",        /*  89  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  90  */
    "MODI",       /*  91  Modulus (signed). */
    "MODI3",      /*  92  */
    "MODU",       /*  93  Modulus (unsigned). */
    "MODU3",      /*  94  */
    "MULF",       /*  95  Multiply floats */
    "MULI",       /*  96  Multiply signed integers. */
    "MULI3",      /*  97  */
    "MULU",       /*  98  Multiply unsigned integers. */
    "MULU3",      /*  99  */
    "NE",         /* 100  Compare integers, jump if not equal. */
    "NE3",        /* 101  */
    "NEF",        /* 102  Compare floats, jump if not-equal */
    "NEGF",       /* 103  Negate float */
    "NEGI",       /* 104  Negate integer. */
    "NEGI3",      /* 105  */
    "POP",        /* 106  Discard top-of-stack. */
    "PUSH",       /* 107  Push to stack. */
    "RSHI",       /* 108  Right-shift (algebraic; preserve sign) */
    "RSHI3",      /* 109  */
    "RSHU",       /* 110  Right-shift (bitwise; ignore sign) */
    "RSHU3",      /* 111  */
    "SEX24",      /* 112  */
    "SEX8_3",     /* 113  */
    "STORE1",     /* 114  Store 1-byte to memory */
    "STORE2",     /* 115  Store 2-byte to memory */
    "STORE3",     /* 116  */
    "STORE4",     /* 117  *(stack[top-1]) = stack[top] */
    "STOREF4",    /* 118  *(stack[top-1]) = stack[top] */
    "SUB",        /* 119  Subtract integers (two's complement). */
    "SUB3",       /* 120  */
    "SUBF",       /* 121  Subtract floats */
};
