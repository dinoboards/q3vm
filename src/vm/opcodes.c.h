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
    "CVFI3",      /*  33  */
    "CVIU3",      /*  34  */
    "CVUI3",      /*  35  */
    "DIVF4",      /*  36  Divide floats */
    "DIVI",       /*  37  Divide signed integers. */
    "DIVI3",      /*  38  */
    "DIVU",       /*  39  Divide unsigned integers. */
    "DIVU3",      /*  40  */
    "ENTER",      /*  41  Begin subroutine. */
    "EQ3",        /*  42  */
    "EQ4",        /*  43  Compare integers, jump if equal. */
    "EQF4",       /*  44  Compare floats, jump if equal */
    "EQU3",       /*  45  */
    "GEF4",       /*  46  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  47  */
    "GEI4",       /*  48  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  49  */
    "GEU4",       /*  50  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  51  Compare floats, jump if greater-than */
    "GTI3",       /*  52  */
    "GTI4",       /*  53  Compare integers, jump if greater-than. */
    "GTU3",       /*  54  */
    "GTU4",       /*  55  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  56  Unconditional jump. */
    "LEAVE",      /*  57  End subroutine. */
    "LEF4",       /*  58  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  59  */
    "LEI4",       /*  60  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  61  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  62  */
    "LOAD1",      /*  63  Load 1-byte from memory */
    "LOAD2",      /*  64  Load 2-bytes from memory */
    "LOAD3",      /*  65  Load 3-bytes from memory */
    "LOAD4",      /*  66  Load 4-bytes from memory */
    "LOADF4",     /*  67  Load 4 byte float from memory */
    "LOCAL",      /*  68  Get local variable. */
    "LSH3",       /*  69  */
    "LSH4",       /*  70  Left-shift */
    "LTF",        /*  71  Compare floats, jump if less-than */
    "LTI3",       /*  72  */
    "LTI4",       /*  73  Compare integers, jump if less-than. */
    "LTU",        /*  74  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  75  */
    "MODI3",      /*  76  */
    "MODI4",      /*  77  Modulus (signed). */
    "MODU3",      /*  78  */
    "MODU4",      /*  79  Modulus (unsigned). */
    "MULF4",      /*  80  Multiply floats */
    "MULI3",      /*  81  */
    "MULI4",      /*  82  Multiply signed integers. */
    "MULU3",      /*  83  */
    "MULU4",      /*  84  Multiply unsigned integers. */
    "NE3",        /*  85  */
    "NE4",        /*  86  Compare integers, jump if not equal. */
    "NEF",        /*  87  Compare floats, jump if not-equal */
    "NEGF4",      /*  88  Negate float */
    "NEGI3",      /*  89  */
    "NEGI4",      /*  90  Negate integer. */
    "POP",        /*  91  Discard top-of-stack. */
    "PUSH",       /*  92  Push to stack. */
    "RSHI3",      /*  93  */
    "RSHI4",      /*  94  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /*  95  */
    "RSHU4",      /*  96  Right-shift (bitwise; ignore sign) */
    "STORE1",     /*  97  Store 1-byte to memory */
    "STORE2",     /*  98  Store 2-byte to memory */
    "STORE3",     /*  99  */
    "STORE4",     /* 100  *(stack[top-1]) = stack[top] */
    "SUB3",       /* 101  */
    "SUB4",       /* 102  Subtract integers (two's complement). */
    "SUBF4",      /* 103  Subtract floats */
};
