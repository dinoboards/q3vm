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
    "OP_CI3I2",      /*  22  */
    "OP_CONSTF4",    /*  23  */
    "OP_CONSTGP3",   /*  24  */
    "OP_CONSTGP4",   /*  25  Load constant to stack. */
    "OP_CONSTI1",    /*  26  */
    "OP_CONSTI2",    /*  27  */
    "OP_CONSTI3",    /*  28  */
    "OP_CONSTI4",    /*  29  */
    "OP_CONSTP3",    /*  30  */
    "OP_CONSTP4",    /*  31  */
    "OP_CONSTU1",    /*  32  */
    "OP_CONSTU2",    /*  33  */
    "OP_CONSTU3",    /*  34  */
    "OP_CONSTU4",    /*  35  */
    "OP_CU2I3",      /*  36  */
    "OP_CU3U2",      /*  37  */
    "OP_CVFI",       /*  38  Convert to float from integer */
    "OP_CVFI3",      /*  39  */
    "OP_CVIF",       /*  40  Convert to integer from float */
    "OP_CVIU3",      /*  41  */
    "OP_CVUI3",      /*  42  */
    "OP_DIVF",       /*  43  Divide floats */
    "OP_DIVI",       /*  44  Divide signed integers. */
    "OP_DIVI3",      /*  45  */
    "OP_DIVU",       /*  46  Divide unsigned integers. */
    "OP_DIVU3",      /*  47  */
    "OP_ENTER",      /*  48  Begin subroutine. */
    "OP_EQ",         /*  49  Compare integers, jump if equal. */
    "OP_EQ3",        /*  50  */
    "OP_EQF",        /*  51  Compare floats, jump if equal */
    "OP_EQU3",       /*  52  */
    "OP_GEF",        /*  53  Compare floats, jump if greater-than-or-equal */
    "OP_GEI",        /*  54  Compare integers, jump if greater-than-or-equal. */
    "OP_GEI3",       /*  55  */
    "OP_GEU",        /*  56  Compare unsigned integers, jump if greater-than-or-equal */
    "OP_GEU3",       /*  57  */
    "OP_GTF",        /*  58  Compare floats, jump if greater-than */
    "OP_GTI",        /*  59  Compare integers, jump if greater-than. */
    "OP_GTI3",       /*  60  */
    "OP_GTU",        /*  61  Compare unsigned integers, jump if greater-than */
    "OP_GTU3",       /*  62  */
    "OP_JUMP",       /*  63  Unconditional jump. */
    "OP_LEAVE",      /*  64  End subroutine. */
    "OP_LEF",        /*  65  Compare floats, jump if less-than-or-equal */
    "OP_LEI",        /*  66  Compare integers, jump if less-than-or-equal. */
    "OP_LEI3",       /*  67  */
    "OP_LEU",        /*  68  Compare unsigned integers, jump if less-than-or-equal */
    "OP_LEU3",       /*  69  */
    "OP_LOAD1",      /*  70  Load 1-byte from memory */
    "OP_LOAD2",      /*  71  Load 2-bytes from memory */
    "OP_LOAD3",      /*  72  Load 3-bytes from memory */
    "OP_LOAD4",      /*  73  Load 4-bytes from memory */
    "OP_LOADF4",     /*  74  Load 4 byte float from memory */
    "OP_LOCAL",      /*  75  Get local variable. */
    "OP_LSH",        /*  76  Left-shift */
    "OP_LSH3",       /*  77  */
    "OP_LTF",        /*  78  Compare floats, jump if less-than */
    "OP_LTI",        /*  79  Compare integers, jump if less-than. */
    "OP_LTI3",       /*  80  */
    "OP_LTU",        /*  81  Compare unsigned integers, jump if less-than */
    "OP_LTU3",       /*  82  */
    "OP_MODI",       /*  83  Modulus (signed). */
    "OP_MODI3",      /*  84  */
    "OP_MODU",       /*  85  Modulus (unsigned). */
    "OP_MODU3",      /*  86  */
    "OP_MULF",       /*  87  Multiply floats */
    "OP_MULI",       /*  88  Multiply signed integers. */
    "OP_MULI3",      /*  89  */
    "OP_MULU",       /*  90  Multiply unsigned integers. */
    "OP_MULU3",      /*  91  */
    "OP_NE",         /*  92  Compare integers, jump if not equal. */
    "OP_NE3",        /*  93  */
    "OP_NEF",        /*  94  Compare floats, jump if not-equal */
    "OP_NEGF",       /*  95  Negate float */
    "OP_NEGI",       /*  96  Negate integer. */
    "OP_NEGI3",      /*  97  */
    "OP_POP",        /*  98  Discard top-of-stack. */
    "OP_PUSH",       /*  99  Push to stack. */
    "OP_RSHI",       /* 100  Right-shift (algebraic; preserve sign) */
    "OP_RSHI3",      /* 101  */
    "OP_RSHU",       /* 102  Right-shift (bitwise; ignore sign) */
    "OP_RSHU3",      /* 103  */
    "OP_SEX16",      /* 104  Sign-Extend 16-bit */
    "OP_SEX24",      /* 105  */
    "OP_SEX8",       /* 106  Sign-Extend 8-bit */
    "OP_SEX8_3",     /* 107  */
    "OP_STORE1",     /* 108  Store 1-byte to memory */
    "OP_STORE2",     /* 109  Store 2-byte to memory */
    "OP_STORE3",     /* 110  */
    "OP_STORE4",     /* 111  *(stack[top-1]) = stack[top] */
    "OP_STOREF4",    /* 112  *(stack[top-1]) = stack[top] */
    "OP_SUB",        /* 113  Subtract integers (two's complement). */
    "OP_SUB3",       /* 114  */
    "OP_SUBF",       /* 115  Subtract floats */
};
