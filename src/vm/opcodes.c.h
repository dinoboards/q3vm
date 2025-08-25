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
    "CI3I4",      /*  22  */
    "CI3U4",      /*  23  */
    "CI4F4",      /*  24  Convert to integer from float */
    "CI4I3",      /*  25  */
    "CI4U3",      /*  26  */
    "CONSTGP3",   /*  27  push address pointer to stack. */
    "CONSTI1",    /*  28  */
    "CONSTI2",    /*  29  */
    "CONSTI3",    /*  30  */
    "CONSTI4",    /*  31  */
    "CONSTP3",    /*  32  */
    "CONSTU1",    /*  33  */
    "CONSTU2",    /*  34  */
    "CONSTU3",    /*  35  */
    "CONSTU4",    /*  36  */
    "CU1I3",      /*  37  */
    "CU2I3",      /*  38  */
    "CU3U2",      /*  39  */
    "CU3U4",      /*  40  */
    "CU4I3",      /*  41  */
    "CU4U3",      /*  42  */
    "CVFI3",      /*  43  */
    "CVIU3",      /*  44  */
    "CVUI3",      /*  45  */
    "DIVF4",      /*  46  Divide floats */
    "DIVI",       /*  47  Divide signed integers. */
    "DIVI3",      /*  48  */
    "DIVU",       /*  49  Divide unsigned integers. */
    "DIVU3",      /*  50  */
    "ENTER",      /*  51  Begin subroutine. */
    "EQ3",        /*  52  */
    "EQ4",        /*  53  Compare integers, jump if equal. */
    "EQF4",       /*  54  Compare floats, jump if equal */
    "EQU3",       /*  55  */
    "GEF4",       /*  56  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  57  */
    "GEI4",       /*  58  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  59  */
    "GEU4",       /*  60  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  61  Compare floats, jump if greater-than */
    "GTI3",       /*  62  */
    "GTI4",       /*  63  Compare integers, jump if greater-than. */
    "GTU3",       /*  64  */
    "GTU4",       /*  65  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  66  Unconditional jump. */
    "LEAVE",      /*  67  End subroutine. */
    "LEF4",       /*  68  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  69  */
    "LEI4",       /*  70  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  71  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  72  */
    "LOAD1",      /*  73  Load 1-byte from memory */
    "LOAD2",      /*  74  Load 2-bytes from memory */
    "LOAD3",      /*  75  Load 3-bytes from memory */
    "LOAD4",      /*  76  Load 4-bytes from memory */
    "LOADF4",     /*  77  Load 4 byte float from memory */
    "LOCAL",      /*  78  Get local variable. */
    "LSH3",       /*  79  */
    "LSH4",       /*  80  Left-shift */
    "LTF",        /*  81  Compare floats, jump if less-than */
    "LTI3",       /*  82  */
    "LTI4",       /*  83  Compare integers, jump if less-than. */
    "LTU",        /*  84  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  85  */
    "MODI3",      /*  86  */
    "MODI4",      /*  87  Modulus (signed). */
    "MODU3",      /*  88  */
    "MODU4",      /*  89  Modulus (unsigned). */
    "MULF4",      /*  90  Multiply floats */
    "MULI3",      /*  91  */
    "MULI4",      /*  92  Multiply signed integers. */
    "MULU3",      /*  93  */
    "MULU4",      /*  94  Multiply unsigned integers. */
    "NE3",        /*  95  */
    "NE4",        /*  96  Compare integers, jump if not equal. */
    "NEF",        /*  97  Compare floats, jump if not-equal */
    "NEGF4",      /*  98  Negate float */
    "NEGI3",      /*  99  */
    "NEGI4",      /* 100  Negate integer. */
    "POP",        /* 101  Discard top-of-stack. */
    "PUSH",       /* 102  Push to stack. */
    "RSHI3",      /* 103  */
    "RSHI4",      /* 104  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 105  */
    "RSHU4",      /* 106  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 107  Store 1-byte to memory */
    "STORE2",     /* 108  Store 2-byte to memory */
    "STORE3",     /* 109  */
    "STORE4",     /* 110  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 111  */
    "SUB4",       /* 112  Subtract integers (two's complement). */
    "SUBF4",      /* 113  Subtract floats */
};
