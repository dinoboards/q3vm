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
    "CONSTI4",    /*  25  */
    "CONSTP3",    /*  26  */
    "CONSTs1",    /*  27  */
    "CONSTs2",    /*  28  */
    "CONSTs3",    /*  29  */
    "CONSTU4",    /*  30  */
    "CU1I3",      /*  31  */
    "CU2I3",      /*  32  */
    "CU3U2",      /*  33  */
    "CU3U4",      /*  34  */
    "CU4I3",      /*  35  */
    "CU4U3",      /*  36  */
    "CVFI3",      /*  37  */
    "CVIU3",      /*  38  */
    "CVUI3",      /*  39  */
    "DIVF4",      /*  40  Divide floats */
    "DIVI",       /*  41  Divide signed integers. */
    "DIVI3",      /*  42  */
    "DIVU",       /*  43  Divide unsigned integers. */
    "DIVU3",      /*  44  */
    "ENTER",      /*  45  Begin subroutine. */
    "EQ3",        /*  46  */
    "EQ4",        /*  47  Compare integers, jump if equal. */
    "EQF4",       /*  48  Compare floats, jump if equal */
    "EQU3",       /*  49  */
    "GEF4",       /*  50  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  51  */
    "GEI4",       /*  52  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  53  */
    "GEU4",       /*  54  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  55  Compare floats, jump if greater-than */
    "GTI3",       /*  56  */
    "GTI4",       /*  57  Compare integers, jump if greater-than. */
    "GTU3",       /*  58  */
    "GTU4",       /*  59  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  60  Unconditional jump. */
    "LEAVE",      /*  61  End subroutine. */
    "LEF4",       /*  62  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  63  */
    "LEI4",       /*  64  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  65  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  66  */
    "LOAD1",      /*  67  Load 1-byte from memory */
    "LOAD2",      /*  68  Load 2-bytes from memory */
    "LOAD3",      /*  69  Load 3-bytes from memory */
    "LOAD4",      /*  70  Load 4-bytes from memory */
    "LOADF4",     /*  71  Load 4 byte float from memory */
    "LOCAL",      /*  72  Get local variable. */
    "LSH3",       /*  73  */
    "LSH4",       /*  74  Left-shift */
    "LTF",        /*  75  Compare floats, jump if less-than */
    "LTI3",       /*  76  */
    "LTI4",       /*  77  Compare integers, jump if less-than. */
    "LTU",        /*  78  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  79  */
    "MODI3",      /*  80  */
    "MODI4",      /*  81  Modulus (signed). */
    "MODU3",      /*  82  */
    "MODU4",      /*  83  Modulus (unsigned). */
    "MULF4",      /*  84  Multiply floats */
    "MULI3",      /*  85  */
    "MULI4",      /*  86  Multiply signed integers. */
    "MULU3",      /*  87  */
    "MULU4",      /*  88  Multiply unsigned integers. */
    "NE3",        /*  89  */
    "NE4",        /*  90  Compare integers, jump if not equal. */
    "NEF",        /*  91  Compare floats, jump if not-equal */
    "NEGF4",      /*  92  Negate float */
    "NEGI3",      /*  93  */
    "NEGI4",      /*  94  Negate integer. */
    "POP",        /*  95  Discard top-of-stack. */
    "PUSH",       /*  96  Push to stack. */
    "RSHI3",      /*  97  */
    "RSHI4",      /*  98  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /*  99  */
    "RSHU4",      /* 100  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 101  Store 1-byte to memory */
    "STORE2",     /* 102  Store 2-byte to memory */
    "STORE3",     /* 103  */
    "STORE4",     /* 104  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 105  */
    "SUB4",       /* 106  Subtract integers (two's complement). */
    "SUBF4",      /* 107  Subtract floats */
};
