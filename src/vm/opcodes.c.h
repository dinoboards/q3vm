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
    "CONSTI2",    /*  25  */
    "CONSTI3",    /*  26  */
    "CONSTI4",    /*  27  */
    "CONSTP3",    /*  28  */
    "CONSTs1",    /*  29  */
    "CONSTU2",    /*  30  */
    "CONSTU3",    /*  31  */
    "CONSTU4",    /*  32  */
    "CU1I3",      /*  33  */
    "CU2I3",      /*  34  */
    "CU3U2",      /*  35  */
    "CU3U4",      /*  36  */
    "CU4I3",      /*  37  */
    "CU4U3",      /*  38  */
    "CVFI3",      /*  39  */
    "CVIU3",      /*  40  */
    "CVUI3",      /*  41  */
    "DIVF4",      /*  42  Divide floats */
    "DIVI",       /*  43  Divide signed integers. */
    "DIVI3",      /*  44  */
    "DIVU",       /*  45  Divide unsigned integers. */
    "DIVU3",      /*  46  */
    "ENTER",      /*  47  Begin subroutine. */
    "EQ3",        /*  48  */
    "EQ4",        /*  49  Compare integers, jump if equal. */
    "EQF4",       /*  50  Compare floats, jump if equal */
    "EQU3",       /*  51  */
    "GEF4",       /*  52  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  53  */
    "GEI4",       /*  54  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  55  */
    "GEU4",       /*  56  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  57  Compare floats, jump if greater-than */
    "GTI3",       /*  58  */
    "GTI4",       /*  59  Compare integers, jump if greater-than. */
    "GTU3",       /*  60  */
    "GTU4",       /*  61  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  62  Unconditional jump. */
    "LEAVE",      /*  63  End subroutine. */
    "LEF4",       /*  64  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  65  */
    "LEI4",       /*  66  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  67  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  68  */
    "LOAD1",      /*  69  Load 1-byte from memory */
    "LOAD2",      /*  70  Load 2-bytes from memory */
    "LOAD3",      /*  71  Load 3-bytes from memory */
    "LOAD4",      /*  72  Load 4-bytes from memory */
    "LOADF4",     /*  73  Load 4 byte float from memory */
    "LOCAL",      /*  74  Get local variable. */
    "LSH3",       /*  75  */
    "LSH4",       /*  76  Left-shift */
    "LTF",        /*  77  Compare floats, jump if less-than */
    "LTI3",       /*  78  */
    "LTI4",       /*  79  Compare integers, jump if less-than. */
    "LTU",        /*  80  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  81  */
    "MODI3",      /*  82  */
    "MODI4",      /*  83  Modulus (signed). */
    "MODU3",      /*  84  */
    "MODU4",      /*  85  Modulus (unsigned). */
    "MULF4",      /*  86  Multiply floats */
    "MULI3",      /*  87  */
    "MULI4",      /*  88  Multiply signed integers. */
    "MULU3",      /*  89  */
    "MULU4",      /*  90  Multiply unsigned integers. */
    "NE3",        /*  91  */
    "NE4",        /*  92  Compare integers, jump if not equal. */
    "NEF",        /*  93  Compare floats, jump if not-equal */
    "NEGF4",      /*  94  Negate float */
    "NEGI3",      /*  95  */
    "NEGI4",      /*  96  Negate integer. */
    "POP",        /*  97  Discard top-of-stack. */
    "PUSH",       /*  98  Push to stack. */
    "RSHI3",      /*  99  */
    "RSHI4",      /* 100  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 101  */
    "RSHU4",      /* 102  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 103  Store 1-byte to memory */
    "STORE2",     /* 104  Store 2-byte to memory */
    "STORE3",     /* 105  */
    "STORE4",     /* 106  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 107  */
    "SUB4",       /* 108  Subtract integers (two's complement). */
    "SUBF4",      /* 109  Subtract floats */
};
