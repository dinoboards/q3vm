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
    "CU3U4",      /*  32  */
    "CU4I3",      /*  33  */
    "CU4U3",      /*  34  */
    "CVFI3",      /*  35  */
    "CVIU3",      /*  36  */
    "CVUI3",      /*  37  */
    "DIVF4",      /*  38  Divide floats */
    "DIVI",       /*  39  Divide signed integers. */
    "DIVI3",      /*  40  */
    "DIVU",       /*  41  Divide unsigned integers. */
    "DIVU3",      /*  42  */
    "ENTER",      /*  43  Begin subroutine. */
    "EQ3",        /*  44  */
    "EQ4",        /*  45  Compare integers, jump if equal. */
    "EQF4",       /*  46  Compare floats, jump if equal */
    "EQU3",       /*  47  */
    "GEF4",       /*  48  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  49  */
    "GEI4",       /*  50  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  51  */
    "GEU4",       /*  52  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  53  Compare floats, jump if greater-than */
    "GTI3",       /*  54  */
    "GTI4",       /*  55  Compare integers, jump if greater-than. */
    "GTU3",       /*  56  */
    "GTU4",       /*  57  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  58  Unconditional jump. */
    "LEAVE",      /*  59  End subroutine. */
    "LEF4",       /*  60  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  61  */
    "LEI4",       /*  62  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  63  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  64  */
    "LOAD1",      /*  65  Load 1-byte from memory */
    "LOAD2",      /*  66  Load 2-bytes from memory */
    "LOAD3",      /*  67  Load 3-bytes from memory */
    "LOAD4",      /*  68  Load 4-bytes from memory */
    "LOADF4",     /*  69  Load 4 byte float from memory */
    "LOCAL",      /*  70  Get local variable. */
    "LSH3",       /*  71  */
    "LSH4",       /*  72  Left-shift */
    "LTF",        /*  73  Compare floats, jump if less-than */
    "LTI3",       /*  74  */
    "LTI4",       /*  75  Compare integers, jump if less-than. */
    "LTU",        /*  76  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  77  */
    "MODI3",      /*  78  */
    "MODI4",      /*  79  Modulus (signed). */
    "MODU3",      /*  80  */
    "MODU4",      /*  81  Modulus (unsigned). */
    "MULF4",      /*  82  Multiply floats */
    "MULI3",      /*  83  */
    "MULI4",      /*  84  Multiply signed integers. */
    "MULU3",      /*  85  */
    "MULU4",      /*  86  Multiply unsigned integers. */
    "NE3",        /*  87  */
    "NE4",        /*  88  Compare integers, jump if not equal. */
    "NEF",        /*  89  Compare floats, jump if not-equal */
    "NEGF4",      /*  90  Negate float */
    "NEGI3",      /*  91  */
    "NEGI4",      /*  92  Negate integer. */
    "POP",        /*  93  Discard top-of-stack. */
    "PUSH",       /*  94  Push to stack. */
    "RSHI3",      /*  95  */
    "RSHI4",      /*  96  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /*  97  */
    "RSHU4",      /*  98  Right-shift (bitwise; ignore sign) */
    "STORE1",     /*  99  Store 1-byte to memory */
    "STORE2",     /* 100  Store 2-byte to memory */
    "STORE3",     /* 101  */
    "STORE4",     /* 102  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 103  */
    "SUB4",       /* 104  Subtract integers (two's complement). */
    "SUBF4",      /* 105  Subtract floats */
};
