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
    "CI4U3",      /*  24  */
    "CONSTGP3",   /*  25  push address pointer to stack. */
    "CONSTI1",    /*  26  */
    "CONSTI2",    /*  27  */
    "CONSTI3",    /*  28  */
    "CONSTI4",    /*  29  */
    "CONSTP3",    /*  30  */
    "CONSTU1",    /*  31  */
    "CONSTU2",    /*  32  */
    "CONSTU3",    /*  33  */
    "CONSTU4",    /*  34  */
    "CU1I3",      /*  35  */
    "CU2I3",      /*  36  */
    "CU3U2",      /*  37  */
    "CU3U4",      /*  38  */
    "CU4I3",      /*  39  */
    "CU4U3",      /*  40  */
    "CVFI3",      /*  41  */
    "CVIU3",      /*  42  */
    "CVUI3",      /*  43  */
    "DIVF4",      /*  44  Divide floats */
    "DIVI",       /*  45  Divide signed integers. */
    "DIVI3",      /*  46  */
    "DIVU",       /*  47  Divide unsigned integers. */
    "DIVU3",      /*  48  */
    "ENTER",      /*  49  Begin subroutine. */
    "EQ3",        /*  50  */
    "EQ4",        /*  51  Compare integers, jump if equal. */
    "EQF4",       /*  52  Compare floats, jump if equal */
    "EQU3",       /*  53  */
    "GEF4",       /*  54  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  55  */
    "GEI4",       /*  56  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  57  */
    "GEU4",       /*  58  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  59  Compare floats, jump if greater-than */
    "GTI3",       /*  60  */
    "GTI4",       /*  61  Compare integers, jump if greater-than. */
    "GTU3",       /*  62  */
    "GTU4",       /*  63  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  64  Unconditional jump. */
    "LEAVE",      /*  65  End subroutine. */
    "LEF4",       /*  66  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  67  */
    "LEI4",       /*  68  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  69  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  70  */
    "LOAD1",      /*  71  Load 1-byte from memory */
    "LOAD2",      /*  72  Load 2-bytes from memory */
    "LOAD3",      /*  73  Load 3-bytes from memory */
    "LOAD4",      /*  74  Load 4-bytes from memory */
    "LOADF4",     /*  75  Load 4 byte float from memory */
    "LOCAL",      /*  76  Get local variable. */
    "LSH3",       /*  77  */
    "LSH4",       /*  78  Left-shift */
    "LTF",        /*  79  Compare floats, jump if less-than */
    "LTI3",       /*  80  */
    "LTI4",       /*  81  Compare integers, jump if less-than. */
    "LTU",        /*  82  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  83  */
    "MODI3",      /*  84  */
    "MODI4",      /*  85  Modulus (signed). */
    "MODU3",      /*  86  */
    "MODU4",      /*  87  Modulus (unsigned). */
    "MULF4",      /*  88  Multiply floats */
    "MULI3",      /*  89  */
    "MULI4",      /*  90  Multiply signed integers. */
    "MULU3",      /*  91  */
    "MULU4",      /*  92  Multiply unsigned integers. */
    "NE3",        /*  93  */
    "NE4",        /*  94  Compare integers, jump if not equal. */
    "NEF",        /*  95  Compare floats, jump if not-equal */
    "NEGF4",      /*  96  Negate float */
    "NEGI3",      /*  97  */
    "NEGI4",      /*  98  Negate integer. */
    "POP",        /*  99  Discard top-of-stack. */
    "PUSH",       /* 100  Push to stack. */
    "RSHI3",      /* 101  */
    "RSHI4",      /* 102  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 103  */
    "RSHU4",      /* 104  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 105  Store 1-byte to memory */
    "STORE2",     /* 106  Store 2-byte to memory */
    "STORE3",     /* 107  */
    "STORE4",     /* 108  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 109  */
    "SUB4",       /* 110  Subtract integers (two's complement). */
    "SUBF4",      /* 111  Subtract floats */
};
