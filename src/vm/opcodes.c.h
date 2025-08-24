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
    "CF4I4",      /*  19  Convert to float from integer */
    "CI1I3",      /*  20  */
    "CI1I4",      /*  21  Sign-Extend 8-bit */
    "CI2I3",      /*  22  */
    "CI2I4",      /*  23  Sign-Extend 16-bit */
    "CI3I1",      /*  24  */
    "CI3I2",      /*  25  */
    "CI3I4",      /*  26  */
    "CI3U4",      /*  27  */
    "CI4F4",      /*  28  Convert to integer from float */
    "CI4I3",      /*  29  */
    "CI4U3",      /*  30  */
    "CONSTGP3",   /*  31  push address pointer to stack. */
    "CONSTI1",    /*  32  */
    "CONSTI2",    /*  33  */
    "CONSTI3",    /*  34  */
    "CONSTI4",    /*  35  */
    "CONSTP3",    /*  36  */
    "CONSTU1",    /*  37  */
    "CONSTU2",    /*  38  */
    "CONSTU3",    /*  39  */
    "CONSTU4",    /*  40  */
    "CU1I3",      /*  41  */
    "CU2I3",      /*  42  */
    "CU3U2",      /*  43  */
    "CU3U4",      /*  44  */
    "CU4I3",      /*  45  */
    "CU4U3",      /*  46  */
    "CVFI3",      /*  47  */
    "CVIU3",      /*  48  */
    "CVUI3",      /*  49  */
    "DIVF4",      /*  50  Divide floats */
    "DIVI",       /*  51  Divide signed integers. */
    "DIVI3",      /*  52  */
    "DIVU",       /*  53  Divide unsigned integers. */
    "DIVU3",      /*  54  */
    "ENTER",      /*  55  Begin subroutine. */
    "EQ3",        /*  56  */
    "EQ4",        /*  57  Compare integers, jump if equal. */
    "EQF4",       /*  58  Compare floats, jump if equal */
    "EQU3",       /*  59  */
    "GEF4",       /*  60  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  61  */
    "GEI4",       /*  62  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  63  */
    "GEU4",       /*  64  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  65  Compare floats, jump if greater-than */
    "GTI3",       /*  66  */
    "GTI4",       /*  67  Compare integers, jump if greater-than. */
    "GTU3",       /*  68  */
    "GTU4",       /*  69  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  70  Unconditional jump. */
    "LEAVE",      /*  71  End subroutine. */
    "LEF",        /*  72  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  73  */
    "LEI4",       /*  74  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  75  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  76  */
    "LOAD1",      /*  77  Load 1-byte from memory */
    "LOAD2",      /*  78  Load 2-bytes from memory */
    "LOAD3",      /*  79  Load 3-bytes from memory */
    "LOAD4",      /*  80  Load 4-bytes from memory */
    "LOADF4",     /*  81  Load 4 byte float from memory */
    "LOCAL",      /*  82  Get local variable. */
    "LSH3",       /*  83  */
    "LSH4",       /*  84  Left-shift */
    "LTF",        /*  85  Compare floats, jump if less-than */
    "LTI3",       /*  86  */
    "LTI4",       /*  87  Compare integers, jump if less-than. */
    "LTU",        /*  88  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  89  */
    "MODI3",      /*  90  */
    "MODI4",      /*  91  Modulus (signed). */
    "MODU3",      /*  92  */
    "MODU4",      /*  93  Modulus (unsigned). */
    "MULF4",      /*  94  Multiply floats */
    "MULI3",      /*  95  */
    "MULI4",      /*  96  Multiply signed integers. */
    "MULU3",      /*  97  */
    "MULU4",      /*  98  Multiply unsigned integers. */
    "NE3",        /*  99  */
    "NE4",        /* 100  Compare integers, jump if not equal. */
    "NEF",        /* 101  Compare floats, jump if not-equal */
    "NEGF4",      /* 102  Negate float */
    "NEGI3",      /* 103  */
    "NEGI4",      /* 104  Negate integer. */
    "POP",        /* 105  Discard top-of-stack. */
    "PUSH",       /* 106  Push to stack. */
    "RSHI3",      /* 107  */
    "RSHI4",      /* 108  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 109  */
    "RSHU4",      /* 110  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 111  Store 1-byte to memory */
    "STORE2",     /* 112  Store 2-byte to memory */
    "STORE3",     /* 113  */
    "STORE4",     /* 114  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 115  */
    "SUB4",       /* 116  Subtract integers (two's complement). */
    "SUBF4",      /* 117  Subtract floats */
};
