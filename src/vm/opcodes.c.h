#include "opcodes.h"

const char *const opnames[OPCODE_TABLE_SIZE] = {
    "OP_UNDEF",      /*   1  Error: VM halt */
    "OP_IGNORE",     /*   2  No operation */
    "OP_BREAK",      /*   3  vm->breakCount++ */
    "OP_ADD",        /*   4  Add integers (two's complement). */
    "OP_ADD3",       /*   5  */
    "OP_ADDF",       /*   6  Add floats */
    "OP_ARG",        /*   7  Marshal argument */
    "OP_ARG4",       /*   8  */
    "OP_ARGF",       /*   9  */
    "OP_BAND",       /*  10  Bitwise AND */
    "OP_BAND3",      /*  11  */
    "OP_BCOM",       /*  12  Bitwise COMplement */
    "OP_BCOM3",      /*  13  */
    "OP_BLOCK_COPY", /*  14  memcpy */
    "OP_BOR",        /*  15  Bitwise OR */
    "OP_BOR3",       /*  16  */
    "OP_BXOR",       /*  17  Bitwise eXclusive-OR */
    "OP_BXOR3",      /*  18  */
    "OP_CALL",       /*  19  Call subroutine. */
    "OP_CI1I3",      /*  20  */
    "OP_CI2I3",      /*  21  */
    "OP_CI3I1",      /*  22  */
    "OP_CI3I2",      /*  23  */
    "OP_CI4I3",      /*  24  */
    "OP_CONSTF4",    /*  25  */
    "OP_CONSTGP3",   /*  26  */
    "OP_CONSTGP4",   /*  27  Load constant to stack. */
    "OP_CONSTI1",    /*  28  */
    "OP_CONSTI2",    /*  29  */
    "OP_CONSTI3",    /*  30  */
    "OP_CONSTI4",    /*  31  */
    "OP_CONSTP3",    /*  32  */
    "OP_CONSTP4",    /*  33  */
    "OP_CONSTU1",    /*  34  */
    "OP_CONSTU2",    /*  35  */
    "OP_CONSTU3",    /*  36  */
    "OP_CONSTU4",    /*  37  */
    "OP_CU2I3",      /*  38  */
    "OP_CU3U2",      /*  39  */
    "OP_CVFI",       /*  40  Convert to float from integer */
    "OP_CVFI3",      /*  41  */
    "OP_CVIF",       /*  42  Convert to integer from float */
    "OP_CVIU3",      /*  43  */
    "OP_CVUI3",      /*  44  */
    "OP_DIVF",       /*  45  Divide floats */
    "OP_DIVI",       /*  46  Divide signed integers. */
    "OP_DIVI3",      /*  47  */
    "OP_DIVU",       /*  48  Divide unsigned integers. */
    "OP_DIVU3",      /*  49  */
    "OP_ENTER",      /*  50  Begin subroutine. */
    "OP_EQ",         /*  51  Compare integers, jump if equal. */
    "OP_EQ3",        /*  52  */
    "OP_EQF",        /*  53  Compare floats, jump if equal */
    "OP_EQU3",       /*  54  */
    "OP_GEF",        /*  55  Compare floats, jump if greater-than-or-equal */
    "OP_GEI",        /*  56  Compare integers, jump if greater-than-or-equal. */
    "OP_GEI3",       /*  57  */
    "OP_GEU",        /*  58  Compare unsigned integers, jump if greater-than-or-equal */
    "OP_GEU3",       /*  59  */
    "OP_GTF",        /*  60  Compare floats, jump if greater-than */
    "OP_GTI",        /*  61  Compare integers, jump if greater-than. */
    "OP_GTI3",       /*  62  */
    "OP_GTU",        /*  63  Compare unsigned integers, jump if greater-than */
    "OP_GTU3",       /*  64  */
    "OP_JUMP",       /*  65  Unconditional jump. */
    "OP_LEAVE",      /*  66  End subroutine. */
    "OP_LEF",        /*  67  Compare floats, jump if less-than-or-equal */
    "OP_LEI",        /*  68  Compare integers, jump if less-than-or-equal. */
    "OP_LEI3",       /*  69  */
    "OP_LEU",        /*  70  Compare unsigned integers, jump if less-than-or-equal */
    "OP_LEU3",       /*  71  */
    "OP_LOAD1",      /*  72  Load 1-byte from memory */
    "OP_LOAD2",      /*  73  Load 2-bytes from memory */
    "OP_LOAD3",      /*  74  Load 3-bytes from memory */
    "OP_LOAD4",      /*  75  Load 4-bytes from memory */
    "OP_LOADF4",     /*  76  Load 4 byte float from memory */
    "OP_LOCAL",      /*  77  Get local variable. */
    "OP_LSH",        /*  78  Left-shift */
    "OP_LSH3",       /*  79  */
    "OP_LTF",        /*  80  Compare floats, jump if less-than */
    "OP_LTI",        /*  81  Compare integers, jump if less-than. */
    "OP_LTI3",       /*  82  */
    "OP_LTU",        /*  83  Compare unsigned integers, jump if less-than */
    "OP_LTU3",       /*  84  */
    "OP_MODI",       /*  85  Modulus (signed). */
    "OP_MODI3",      /*  86  */
    "OP_MODU",       /*  87  Modulus (unsigned). */
    "OP_MODU3",      /*  88  */
    "OP_MULF",       /*  89  Multiply floats */
    "OP_MULI",       /*  90  Multiply signed integers. */
    "OP_MULI3",      /*  91  */
    "OP_MULU",       /*  92  Multiply unsigned integers. */
    "OP_MULU3",      /*  93  */
    "OP_NE",         /*  94  Compare integers, jump if not equal. */
    "OP_NE3",        /*  95  */
    "OP_NEF",        /*  96  Compare floats, jump if not-equal */
    "OP_NEGF",       /*  97  Negate float */
    "OP_NEGI",       /*  98  Negate integer. */
    "OP_NEGI3",      /*  99  */
    "OP_POP",        /* 100  Discard top-of-stack. */
    "OP_PUSH",       /* 101  Push to stack. */
    "OP_RSHI",       /* 102  Right-shift (algebraic; preserve sign) */
    "OP_RSHI3",      /* 103  */
    "OP_RSHU",       /* 104  Right-shift (bitwise; ignore sign) */
    "OP_RSHU3",      /* 105  */
    "OP_SEX16",      /* 106  Sign-Extend 16-bit */
    "OP_SEX24",      /* 107  */
    "OP_SEX8",       /* 108  Sign-Extend 8-bit */
    "OP_SEX8_3",     /* 109  */
    "OP_STORE1",     /* 110  Store 1-byte to memory */
    "OP_STORE2",     /* 111  Store 2-byte to memory */
    "OP_STORE3",     /* 112  */
    "OP_STORE4",     /* 113  *(stack[top-1]) = stack[top] */
    "OP_STOREF4",    /* 114  *(stack[top-1]) = stack[top] */
    "OP_SUB",        /* 115  Subtract integers (two's complement). */
    "OP_SUB3",       /* 116  */
    "OP_SUBF",       /* 117  Subtract floats */
};
