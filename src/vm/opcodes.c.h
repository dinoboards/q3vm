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
    "CI3s4",      /*  22  */
    "CI4F4",      /*  23  Convert to integer from float */
    "CI4I3",      /*  24  */
    "CI4U3",      /*  25  */
    "CONSTGP3",   /*  26  push address pointer to stack. */
    "CONSTI1",    /*  27  */
    "CONSTI2",    /*  28  */
    "CONSTI3",    /*  29  */
    "CONSTI4",    /*  30  */
    "CONSTP3",    /*  31  */
    "CONSTU1",    /*  32  */
    "CONSTU2",    /*  33  */
    "CONSTU3",    /*  34  */
    "CONSTU4",    /*  35  */
    "CU1I3",      /*  36  */
    "CU2I3",      /*  37  */
    "CU3U2",      /*  38  */
    "CU3U4",      /*  39  */
    "CU4I3",      /*  40  */
    "CU4U3",      /*  41  */
    "CVFI3",      /*  42  */
    "CVIU3",      /*  43  */
    "CVUI3",      /*  44  */
    "DIVF4",      /*  45  Divide floats */
    "DIVI",       /*  46  Divide signed integers. */
    "DIVI3",      /*  47  */
    "DIVU",       /*  48  Divide unsigned integers. */
    "DIVU3",      /*  49  */
    "ENTER",      /*  50  Begin subroutine. */
    "EQ3",        /*  51  */
    "EQ4",        /*  52  Compare integers, jump if equal. */
    "EQF4",       /*  53  Compare floats, jump if equal */
    "EQU3",       /*  54  */
    "GEF4",       /*  55  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  56  */
    "GEI4",       /*  57  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  58  */
    "GEU4",       /*  59  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  60  Compare floats, jump if greater-than */
    "GTI3",       /*  61  */
    "GTI4",       /*  62  Compare integers, jump if greater-than. */
    "GTU3",       /*  63  */
    "GTU4",       /*  64  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  65  Unconditional jump. */
    "LEAVE",      /*  66  End subroutine. */
    "LEF4",       /*  67  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  68  */
    "LEI4",       /*  69  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  70  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  71  */
    "LOAD1",      /*  72  Load 1-byte from memory */
    "LOAD2",      /*  73  Load 2-bytes from memory */
    "LOAD3",      /*  74  Load 3-bytes from memory */
    "LOAD4",      /*  75  Load 4-bytes from memory */
    "LOADF4",     /*  76  Load 4 byte float from memory */
    "LOCAL",      /*  77  Get local variable. */
    "LSH3",       /*  78  */
    "LSH4",       /*  79  Left-shift */
    "LTF",        /*  80  Compare floats, jump if less-than */
    "LTI3",       /*  81  */
    "LTI4",       /*  82  Compare integers, jump if less-than. */
    "LTU",        /*  83  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  84  */
    "MODI3",      /*  85  */
    "MODI4",      /*  86  Modulus (signed). */
    "MODU3",      /*  87  */
    "MODU4",      /*  88  Modulus (unsigned). */
    "MULF4",      /*  89  Multiply floats */
    "MULI3",      /*  90  */
    "MULI4",      /*  91  Multiply signed integers. */
    "MULU3",      /*  92  */
    "MULU4",      /*  93  Multiply unsigned integers. */
    "NE3",        /*  94  */
    "NE4",        /*  95  Compare integers, jump if not equal. */
    "NEF",        /*  96  Compare floats, jump if not-equal */
    "NEGF4",      /*  97  Negate float */
    "NEGI3",      /*  98  */
    "NEGI4",      /*  99  Negate integer. */
    "POP",        /* 100  Discard top-of-stack. */
    "PUSH",       /* 101  Push to stack. */
    "RSHI3",      /* 102  */
    "RSHI4",      /* 103  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 104  */
    "RSHU4",      /* 105  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 106  Store 1-byte to memory */
    "STORE2",     /* 107  Store 2-byte to memory */
    "STORE3",     /* 108  */
    "STORE4",     /* 109  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 110  */
    "SUB4",       /* 111  Subtract integers (two's complement). */
    "SUBF4",      /* 112  Subtract floats */
};
