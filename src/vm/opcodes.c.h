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
    "CI3I2",      /*  22  */
    "CI3I4",      /*  23  */
    "CI3U4",      /*  24  */
    "CI4F4",      /*  25  Convert to integer from float */
    "CI4I3",      /*  26  */
    "CI4U3",      /*  27  */
    "CONSTGP3",   /*  28  push address pointer to stack. */
    "CONSTI1",    /*  29  */
    "CONSTI2",    /*  30  */
    "CONSTI3",    /*  31  */
    "CONSTI4",    /*  32  */
    "CONSTP3",    /*  33  */
    "CONSTU1",    /*  34  */
    "CONSTU2",    /*  35  */
    "CONSTU3",    /*  36  */
    "CONSTU4",    /*  37  */
    "CU1I3",      /*  38  */
    "CU2I3",      /*  39  */
    "CU3U2",      /*  40  */
    "CU3U4",      /*  41  */
    "CU4I3",      /*  42  */
    "CU4U3",      /*  43  */
    "CVFI3",      /*  44  */
    "CVIU3",      /*  45  */
    "CVUI3",      /*  46  */
    "DIVF4",      /*  47  Divide floats */
    "DIVI",       /*  48  Divide signed integers. */
    "DIVI3",      /*  49  */
    "DIVU",       /*  50  Divide unsigned integers. */
    "DIVU3",      /*  51  */
    "ENTER",      /*  52  Begin subroutine. */
    "EQ3",        /*  53  */
    "EQ4",        /*  54  Compare integers, jump if equal. */
    "EQF4",       /*  55  Compare floats, jump if equal */
    "EQU3",       /*  56  */
    "GEF4",       /*  57  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  58  */
    "GEI4",       /*  59  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  60  */
    "GEU4",       /*  61  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  62  Compare floats, jump if greater-than */
    "GTI3",       /*  63  */
    "GTI4",       /*  64  Compare integers, jump if greater-than. */
    "GTU3",       /*  65  */
    "GTU4",       /*  66  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  67  Unconditional jump. */
    "LEAVE",      /*  68  End subroutine. */
    "LEF4",       /*  69  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  70  */
    "LEI4",       /*  71  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  72  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  73  */
    "LOAD1",      /*  74  Load 1-byte from memory */
    "LOAD2",      /*  75  Load 2-bytes from memory */
    "LOAD3",      /*  76  Load 3-bytes from memory */
    "LOAD4",      /*  77  Load 4-bytes from memory */
    "LOADF4",     /*  78  Load 4 byte float from memory */
    "LOCAL",      /*  79  Get local variable. */
    "LSH3",       /*  80  */
    "LSH4",       /*  81  Left-shift */
    "LTF",        /*  82  Compare floats, jump if less-than */
    "LTI3",       /*  83  */
    "LTI4",       /*  84  Compare integers, jump if less-than. */
    "LTU",        /*  85  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  86  */
    "MODI3",      /*  87  */
    "MODI4",      /*  88  Modulus (signed). */
    "MODU3",      /*  89  */
    "MODU4",      /*  90  Modulus (unsigned). */
    "MULF4",      /*  91  Multiply floats */
    "MULI3",      /*  92  */
    "MULI4",      /*  93  Multiply signed integers. */
    "MULU3",      /*  94  */
    "MULU4",      /*  95  Multiply unsigned integers. */
    "NE3",        /*  96  */
    "NE4",        /*  97  Compare integers, jump if not equal. */
    "NEF",        /*  98  Compare floats, jump if not-equal */
    "NEGF4",      /*  99  Negate float */
    "NEGI3",      /* 100  */
    "NEGI4",      /* 101  Negate integer. */
    "POP",        /* 102  Discard top-of-stack. */
    "PUSH",       /* 103  Push to stack. */
    "RSHI3",      /* 104  */
    "RSHI4",      /* 105  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 106  */
    "RSHU4",      /* 107  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 108  Store 1-byte to memory */
    "STORE2",     /* 109  Store 2-byte to memory */
    "STORE3",     /* 110  */
    "STORE4",     /* 111  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 112  */
    "SUB4",       /* 113  Subtract integers (two's complement). */
    "SUBF4",      /* 114  Subtract floats */
};
