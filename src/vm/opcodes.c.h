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
    "CI2I4",      /*  21  Sign-Extend 16-bit */
    "CI3F4",      /*  22  */
    "CI3I1",      /*  23  */
    "CI3I2",      /*  24  */
    "CI3I4",      /*  25  */
    "CI3U4",      /*  26  */
    "CI4F4",      /*  27  Convert to integer from float */
    "CI4I3",      /*  28  */
    "CI4U3",      /*  29  */
    "CONSTGP3",   /*  30  push address pointer to stack. */
    "CONSTI1",    /*  31  */
    "CONSTI2",    /*  32  */
    "CONSTI3",    /*  33  */
    "CONSTI4",    /*  34  */
    "CONSTP3",    /*  35  */
    "CONSTU1",    /*  36  */
    "CONSTU2",    /*  37  */
    "CONSTU3",    /*  38  */
    "CONSTU4",    /*  39  */
    "CU1I3",      /*  40  */
    "CU2I3",      /*  41  */
    "CU3U2",      /*  42  */
    "CU3U4",      /*  43  */
    "CU4I3",      /*  44  */
    "CU4U3",      /*  45  */
    "CVFI3",      /*  46  */
    "CVIU3",      /*  47  */
    "CVUI3",      /*  48  */
    "DIVF4",      /*  49  Divide floats */
    "DIVI",       /*  50  Divide signed integers. */
    "DIVI3",      /*  51  */
    "DIVU",       /*  52  Divide unsigned integers. */
    "DIVU3",      /*  53  */
    "ENTER",      /*  54  Begin subroutine. */
    "EQ3",        /*  55  */
    "EQ4",        /*  56  Compare integers, jump if equal. */
    "EQF4",       /*  57  Compare floats, jump if equal */
    "EQU3",       /*  58  */
    "GEF4",       /*  59  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  60  */
    "GEI4",       /*  61  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  62  */
    "GEU4",       /*  63  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  64  Compare floats, jump if greater-than */
    "GTI3",       /*  65  */
    "GTI4",       /*  66  Compare integers, jump if greater-than. */
    "GTU3",       /*  67  */
    "GTU4",       /*  68  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  69  Unconditional jump. */
    "LEAVE",      /*  70  End subroutine. */
    "LEF4",       /*  71  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  72  */
    "LEI4",       /*  73  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  74  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  75  */
    "LOAD1",      /*  76  Load 1-byte from memory */
    "LOAD2",      /*  77  Load 2-bytes from memory */
    "LOAD3",      /*  78  Load 3-bytes from memory */
    "LOAD4",      /*  79  Load 4-bytes from memory */
    "LOADF4",     /*  80  Load 4 byte float from memory */
    "LOCAL",      /*  81  Get local variable. */
    "LSH3",       /*  82  */
    "LSH4",       /*  83  Left-shift */
    "LTF",        /*  84  Compare floats, jump if less-than */
    "LTI3",       /*  85  */
    "LTI4",       /*  86  Compare integers, jump if less-than. */
    "LTU",        /*  87  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  88  */
    "MODI3",      /*  89  */
    "MODI4",      /*  90  Modulus (signed). */
    "MODU3",      /*  91  */
    "MODU4",      /*  92  Modulus (unsigned). */
    "MULF4",      /*  93  Multiply floats */
    "MULI3",      /*  94  */
    "MULI4",      /*  95  Multiply signed integers. */
    "MULU3",      /*  96  */
    "MULU4",      /*  97  Multiply unsigned integers. */
    "NE3",        /*  98  */
    "NE4",        /*  99  Compare integers, jump if not equal. */
    "NEF",        /* 100  Compare floats, jump if not-equal */
    "NEGF4",      /* 101  Negate float */
    "NEGI3",      /* 102  */
    "NEGI4",      /* 103  Negate integer. */
    "POP",        /* 104  Discard top-of-stack. */
    "PUSH",       /* 105  Push to stack. */
    "RSHI3",      /* 106  */
    "RSHI4",      /* 107  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 108  */
    "RSHU4",      /* 109  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 110  Store 1-byte to memory */
    "STORE2",     /* 111  Store 2-byte to memory */
    "STORE3",     /* 112  */
    "STORE4",     /* 113  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 114  */
    "SUB4",       /* 115  Subtract integers (two's complement). */
    "SUBF4",      /* 116  Subtract floats */
};
