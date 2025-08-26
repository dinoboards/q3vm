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
    "CU4I3",      /*  32  */
    "CU4U3",      /*  33  */
    "CVFI3",      /*  34  */
    "CVIU3",      /*  35  */
    "CVUI3",      /*  36  */
    "DIVF4",      /*  37  Divide floats */
    "DIVI",       /*  38  Divide signed integers. */
    "DIVI3",      /*  39  */
    "DIVU",       /*  40  Divide unsigned integers. */
    "DIVU3",      /*  41  */
    "ENTER",      /*  42  Begin subroutine. */
    "EQ3",        /*  43  */
    "EQ4",        /*  44  Compare integers, jump if equal. */
    "EQF4",       /*  45  Compare floats, jump if equal */
    "EQU3",       /*  46  */
    "GEF4",       /*  47  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  48  */
    "GEI4",       /*  49  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  50  */
    "GEU4",       /*  51  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  52  Compare floats, jump if greater-than */
    "GTI3",       /*  53  */
    "GTI4",       /*  54  Compare integers, jump if greater-than. */
    "GTU3",       /*  55  */
    "GTU4",       /*  56  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  57  Unconditional jump. */
    "LEAVE",      /*  58  End subroutine. */
    "LEF4",       /*  59  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  60  */
    "LEI4",       /*  61  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  62  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  63  */
    "LOAD1",      /*  64  Load 1-byte from memory */
    "LOAD2",      /*  65  Load 2-bytes from memory */
    "LOAD3",      /*  66  Load 3-bytes from memory */
    "LOAD4",      /*  67  Load 4-bytes from memory */
    "LOADF4",     /*  68  Load 4 byte float from memory */
    "LOCAL",      /*  69  Get local variable. */
    "LSH3",       /*  70  */
    "LSH4",       /*  71  Left-shift */
    "LTF",        /*  72  Compare floats, jump if less-than */
    "LTI3",       /*  73  */
    "LTI4",       /*  74  Compare integers, jump if less-than. */
    "LTU",        /*  75  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  76  */
    "MODI3",      /*  77  */
    "MODI4",      /*  78  Modulus (signed). */
    "MODU3",      /*  79  */
    "MODU4",      /*  80  Modulus (unsigned). */
    "MULF4",      /*  81  Multiply floats */
    "MULI3",      /*  82  */
    "MULI4",      /*  83  Multiply signed integers. */
    "MULU3",      /*  84  */
    "MULU4",      /*  85  Multiply unsigned integers. */
    "NE3",        /*  86  */
    "NE4",        /*  87  Compare integers, jump if not equal. */
    "NEF",        /*  88  Compare floats, jump if not-equal */
    "NEGF4",      /*  89  Negate float */
    "NEGI3",      /*  90  */
    "NEGI4",      /*  91  Negate integer. */
    "POP",        /*  92  Discard top-of-stack. */
    "PUSH",       /*  93  Push to stack. */
    "RSHI3",      /*  94  */
    "RSHI4",      /*  95  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /*  96  */
    "RSHU4",      /*  97  Right-shift (bitwise; ignore sign) */
    "STORE1",     /*  98  Store 1-byte to memory */
    "STORE2",     /*  99  Store 2-byte to memory */
    "STORE3",     /* 100  */
    "STORE4",     /* 101  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 102  */
    "SUB4",       /* 103  Subtract integers (two's complement). */
    "SUBF4",      /* 104  Subtract floats */
};
