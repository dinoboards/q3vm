#include "opcodes.h"

const char *const opnames[OPCODE_TABLE_SIZE] = {
    "UNDEF",      /*   0  Error: VM halt */
    "IGNORE",     /*   1  No operation */
    "BREAK",      /*   2  vm->breakCount++ */
    "ADD",        /*   3  Add integers (two's complement). */
    "ADD3",       /*   4  */
    "ADDF",       /*   5  Add floats */
    "ARG",        /*   6  Marshal argument */
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
    "CU4U3",      /*  44  */
    "CVFI",       /*  45  Convert to float from integer */
    "CVFI3",      /*  46  */
    "CVIF",       /*  47  Convert to integer from float */
    "CVIU3",      /*  48  */
    "CVUI3",      /*  49  */
    "DIVF",       /*  50  Divide floats */
    "DIVI",       /*  51  Divide signed integers. */
    "DIVI3",      /*  52  */
    "DIVU",       /*  53  Divide unsigned integers. */
    "DIVU3",      /*  54  */
    "ENTER",      /*  55  Begin subroutine. */
    "EQ",         /*  56  Compare integers, jump if equal. */
    "EQ3",        /*  57  */
    "EQF",        /*  58  Compare floats, jump if equal */
    "EQU3",       /*  59  */
    "GEF",        /*  60  Compare floats, jump if greater-than-or-equal */
    "GEI",        /*  61  Compare integers, jump if greater-than-or-equal. */
    "GEI3",       /*  62  */
    "GEU",        /*  63  Compare unsigned integers, jump if greater-than-or-equal */
    "GEU3",       /*  64  */
    "GTF",        /*  65  Compare floats, jump if greater-than */
    "GTI",        /*  66  Compare integers, jump if greater-than. */
    "GTI3",       /*  67  */
    "GTU",        /*  68  Compare unsigned integers, jump if greater-than */
    "GTU3",       /*  69  */
    "JUMP",       /*  70  Unconditional jump. */
    "LEAVE",      /*  71  End subroutine. */
    "LEF",        /*  72  Compare floats, jump if less-than-or-equal */
    "LEI",        /*  73  Compare integers, jump if less-than-or-equal. */
    "LEI3",       /*  74  */
    "LEU",        /*  75  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  76  */
    "LOAD1",      /*  77  Load 1-byte from memory */
    "LOAD2",      /*  78  Load 2-bytes from memory */
    "LOAD3",      /*  79  Load 3-bytes from memory */
    "LOAD4",      /*  80  Load 4-bytes from memory */
    "LOADF4",     /*  81  Load 4 byte float from memory */
    "LOCAL",      /*  82  Get local variable. */
    "LSH",        /*  83  Left-shift */
    "LSH3",       /*  84  */
    "LTF",        /*  85  Compare floats, jump if less-than */
    "LTI",        /*  86  Compare integers, jump if less-than. */
    "LTI3",       /*  87  */
    "LTU",        /*  88  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  89  */
    "MODI",       /*  90  Modulus (signed). */
    "MODI3",      /*  91  */
    "MODU",       /*  92  Modulus (unsigned). */
    "MODU3",      /*  93  */
    "MULF",       /*  94  Multiply floats */
    "MULI",       /*  95  Multiply signed integers. */
    "MULI3",      /*  96  */
    "MULU",       /*  97  Multiply unsigned integers. */
    "MULU3",      /*  98  */
    "NE",         /*  99  Compare integers, jump if not equal. */
    "NE3",        /* 100  */
    "NEF",        /* 101  Compare floats, jump if not-equal */
    "NEGF",       /* 102  Negate float */
    "NEGI",       /* 103  Negate integer. */
    "NEGI3",      /* 104  */
    "POP",        /* 105  Discard top-of-stack. */
    "PUSH",       /* 106  Push to stack. */
    "RSHI",       /* 107  Right-shift (algebraic; preserve sign) */
    "RSHI3",      /* 108  */
    "RSHU",       /* 109  Right-shift (bitwise; ignore sign) */
    "RSHU3",      /* 110  */
    "SEX24",      /* 111  */
    "SEX8_3",     /* 112  */
    "STORE1",     /* 113  Store 1-byte to memory */
    "STORE2",     /* 114  Store 2-byte to memory */
    "STORE3",     /* 115  */
    "STORE4",     /* 116  *(stack[top-1]) = stack[top] */
    "STOREF4",    /* 117  *(stack[top-1]) = stack[top] */
    "SUB",        /* 118  Subtract integers (two's complement). */
    "SUB3",       /* 119  */
    "SUBF",       /* 120  Subtract floats */
};
