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
    "CONSTP3",    /*  25  */
    "CONSTs1",    /*  26  */
    "CONSTs2",    /*  27  */
    "CONSTs3",    /*  28  */
    "CONSTs4",    /*  29  */
    "CU1I3",      /*  30  */
    "CU2I3",      /*  31  */
    "CU3U2",      /*  32  */
    "CU3U4",      /*  33  */
    "CU4I3",      /*  34  */
    "CU4U3",      /*  35  */
    "CVFI3",      /*  36  */
    "CVIU3",      /*  37  */
    "CVUI3",      /*  38  */
    "DIVF4",      /*  39  Divide floats */
    "DIVI",       /*  40  Divide signed integers. */
    "DIVI3",      /*  41  */
    "DIVU",       /*  42  Divide unsigned integers. */
    "DIVU3",      /*  43  */
    "ENTER",      /*  44  Begin subroutine. */
    "EQ3",        /*  45  */
    "EQ4",        /*  46  Compare integers, jump if equal. */
    "EQF4",       /*  47  Compare floats, jump if equal */
    "EQU3",       /*  48  */
    "GEF4",       /*  49  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  50  */
    "GEI4",       /*  51  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  52  */
    "GEU4",       /*  53  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  54  Compare floats, jump if greater-than */
    "GTI3",       /*  55  */
    "GTI4",       /*  56  Compare integers, jump if greater-than. */
    "GTU3",       /*  57  */
    "GTU4",       /*  58  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  59  Unconditional jump. */
    "LEAVE",      /*  60  End subroutine. */
    "LEF4",       /*  61  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  62  */
    "LEI4",       /*  63  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  64  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  65  */
    "LOAD1",      /*  66  Load 1-byte from memory */
    "LOAD2",      /*  67  Load 2-bytes from memory */
    "LOAD3",      /*  68  Load 3-bytes from memory */
    "LOAD4",      /*  69  Load 4-bytes from memory */
    "LOADF4",     /*  70  Load 4 byte float from memory */
    "LOCAL",      /*  71  Get local variable. */
    "LSH3",       /*  72  */
    "LSH4",       /*  73  Left-shift */
    "LTF",        /*  74  Compare floats, jump if less-than */
    "LTI3",       /*  75  */
    "LTI4",       /*  76  Compare integers, jump if less-than. */
    "LTU",        /*  77  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  78  */
    "MODI3",      /*  79  */
    "MODI4",      /*  80  Modulus (signed). */
    "MODU3",      /*  81  */
    "MODU4",      /*  82  Modulus (unsigned). */
    "MULF4",      /*  83  Multiply floats */
    "MULI3",      /*  84  */
    "MULI4",      /*  85  Multiply signed integers. */
    "MULU3",      /*  86  */
    "MULU4",      /*  87  Multiply unsigned integers. */
    "NE3",        /*  88  */
    "NE4",        /*  89  Compare integers, jump if not equal. */
    "NEF",        /*  90  Compare floats, jump if not-equal */
    "NEGF4",      /*  91  Negate float */
    "NEGI3",      /*  92  */
    "NEGI4",      /*  93  Negate integer. */
    "POP",        /*  94  Discard top-of-stack. */
    "PUSH",       /*  95  Push to stack. */
    "RSHI3",      /*  96  */
    "RSHI4",      /*  97  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /*  98  */
    "RSHU4",      /*  99  Right-shift (bitwise; ignore sign) */
    "STORE1",     /* 100  Store 1-byte to memory */
    "STORE2",     /* 101  Store 2-byte to memory */
    "STORE3",     /* 102  */
    "STORE4",     /* 103  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 104  */
    "SUB4",       /* 105  Subtract integers (two's complement). */
    "SUBF4",      /* 106  Subtract floats */
};
