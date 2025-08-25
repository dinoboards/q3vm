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
    "CONSTI3",    /*  25  */
    "CONSTI4",    /*  26  */
    "CONSTP3",    /*  27  */
    "CONSTs1",    /*  28  */
    "CONSTs2",    /*  29  */
    "CONSTU3",    /*  30  */
    "CONSTU4",    /*  31  */
    "CU1I3",      /*  32  */
    "CU2I3",      /*  33  */
    "CU3U2",      /*  34  */
    "CU3U4",      /*  35  */
    "CU4I3",      /*  36  */
    "CU4U3",      /*  37  */
    "CVFI3",      /*  38  */
    "CVIU3",      /*  39  */
    "CVUI3",      /*  40  */
    "DIVF4",      /*  41  Divide floats */
    "DIVI",       /*  42  Divide signed integers. */
    "DIVI3",      /*  43  */
    "DIVU",       /*  44  Divide unsigned integers. */
    "DIVU3",      /*  45  */
    "ENTER",      /*  46  Begin subroutine. */
    "EQ3",        /*  47  */
    "EQ4",        /*  48  Compare integers, jump if equal. */
    "EQF4",       /*  49  Compare floats, jump if equal */
    "EQU3",       /*  50  */
    "GEF4",       /*  51  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  52  */
    "GEI4",       /*  53  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  54  */
    "GEU4",       /*  55  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  56  Compare floats, jump if greater-than */
    "GTI3",       /*  57  */
    "GTI4",       /*  58  Compare integers, jump if greater-than. */
    "GTU3",       /*  59  */
    "GTU4",       /*  60  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  61  Unconditional jump. */
    "LEAVE",      /*  62  End subroutine. */
    "LEF4",       /*  63  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  64  */
    "LEI4",       /*  65  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  66  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  67  */
    "LOAD1",      /*  68  Load 1-byte from memory */
    "LOAD2",      /*  69  Load 2-bytes from memory */
    "LOAD3",      /*  70  Load 3-bytes from memory */
    "LOAD4",      /*  71  Load 4-bytes from memory */
    "LOADF4",     /*  72  Load 4 byte float from memory */
    "LOCAL",      /*  73  Get local variable. */
    "LSH3",       /*  74  */
    "LSH4",       /*  75  Left-shift */
    "LTF",        /*  76  Compare floats, jump if less-than */
    "LTI3",       /*  77  */
    "LTI4",       /*  78  Compare integers, jump if less-than. */
    "LTU",        /*  79  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  80  */
    "MODI3",      /*  81  */
    "MODI4",      /*  82  Modulus (signed). */
    "MODU3",      /*  83  */
    "MODU4",      /*  84  Modulus (unsigned). */
    "MULF4",      /*  85  Multiply floats */
    "MULI3",      /*  86  */
    "MULI4",      /*  87  Multiply signed integers. */
    "MULU3",      /*  88  */
    "MULU4",      /*  89  Multiply unsigned integers. */
    "NE3",        /*  90  */
    "NE4",        /*  91  Compare integers, jump if not equal. */
    "NEF",        /*  92  Compare floats, jump if not-equal */
    "NEGF4",      /*  93  Negate float */
    "NEGI3",      /*  94  */
    "NEGI4",      /*  95  Negate integer. */
    "POP",        /*  96  Discard top-of-stack. */
    "PUSH",       /*  97  Push to stack. */
    "RSHI3",      /*  98  */
    "RSHI4",      /*  99  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /* 100  */
    "RSHU4",      /* 101  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 102  Store 1-byte to memory */
    "STORE2",     /* 103  Store 2-byte to memory */
    "STORE3",     /* 104  */
    "STORE4",     /* 105  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 106  */
    "SUB4",       /* 107  Subtract integers (two's complement). */
    "SUBF4",      /* 108  Subtract floats */
};
