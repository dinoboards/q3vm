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
    "CONSTGP3",   /*  24  push address pointer to stack. */
    "CONSTI1",    /*  25  */
    "CONSTI2",    /*  26  */
    "CONSTI3",    /*  27  */
    "CONSTI4",    /*  28  */
    "CONSTP3",    /*  29  */
    "CONSTU1",    /*  30  */
    "CONSTU2",    /*  31  */
    "CONSTU3",    /*  32  */
    "CONSTU4",    /*  33  */
    "CU1I3",      /*  34  */
    "CU2I3",      /*  35  */
    "CU3U2",      /*  36  */
    "CU3U4",      /*  37  */
    "CU4I3",      /*  38  */
    "CU4U3",      /*  39  */
    "CVFI3",      /*  40  */
    "CVIU3",      /*  41  */
    "CVUI3",      /*  42  */
    "DIVF4",      /*  43  Divide floats */
    "DIVI",       /*  44  Divide signed integers. */
    "DIVI3",      /*  45  */
    "DIVU",       /*  46  Divide unsigned integers. */
    "DIVU3",      /*  47  */
    "ENTER",      /*  48  Begin subroutine. */
    "EQ3",        /*  49  */
    "EQ4",        /*  50  Compare integers, jump if equal. */
    "EQF4",       /*  51  Compare floats, jump if equal */
    "EQU3",       /*  52  */
    "GEF4",       /*  53  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  54  */
    "GEI4",       /*  55  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  56  */
    "GEU4",       /*  57  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  58  Compare floats, jump if greater-than */
    "GTI3",       /*  59  */
    "GTI4",       /*  60  Compare integers, jump if greater-than. */
    "GTU3",       /*  61  */
    "GTU4",       /*  62  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  63  Unconditional jump. */
    "LEAVE",      /*  64  End subroutine. */
    "LEF4",       /*  65  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  66  */
    "LEI4",       /*  67  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  68  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  69  */
    "LOAD1",      /*  70  Load 1-byte from memory */
    "LOAD2",      /*  71  Load 2-bytes from memory */
    "LOAD3",      /*  72  Load 3-bytes from memory */
    "LOAD4",      /*  73  Load 4-bytes from memory */
    "LOADF4",     /*  74  Load 4 byte float from memory */
    "LOCAL",      /*  75  Get local variable. */
    "LSH3",       /*  76  */
    "LSH4",       /*  77  Left-shift */
    "LTF",        /*  78  Compare floats, jump if less-than */
    "LTI3",       /*  79  */
    "LTI4",       /*  80  Compare integers, jump if less-than. */
    "LTU",        /*  81  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  82  */
    "MODI3",      /*  83  */
    "MODI4",      /*  84  Modulus (signed). */
    "MODU3",      /*  85  */
    "MODU4",      /*  86  Modulus (unsigned). */
    "MULF4",      /*  87  Multiply floats */
    "MULI3",      /*  88  */
    "MULI4",      /*  89  Multiply signed integers. */
    "MULU3",      /*  90  */
    "MULU4",      /*  91  Multiply unsigned integers. */
    "NE3",        /*  92  */
    "NE4",        /*  93  Compare integers, jump if not equal. */
    "NEF",        /*  94  Compare floats, jump if not-equal */
    "NEGF4",      /*  95  Negate float */
    "NEGI3",      /*  96  */
    "NEGI4",      /*  97  Negate integer. */
    "POP",        /*  98  Discard top-of-stack. */
    "PUSH",       /*  99  Push to stack. */
    "RSHI3",      /* 100  */
    "RSHI4",      /* 101  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 102  */
    "RSHU4",      /* 103  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 104  Store 1-byte to memory */
    "STORE2",     /* 105  Store 2-byte to memory */
    "STORE3",     /* 106  */
    "STORE4",     /* 107  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 108  */
    "SUB4",       /* 109  Subtract integers (two's complement). */
    "SUBF4",      /* 110  Subtract floats */
};
