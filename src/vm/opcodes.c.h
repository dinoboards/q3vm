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
    "CF4I3",      /*  18  */
    "CF4I4",      /*  19  Convert to float from integer */
    "CI1I3",      /*  20  */
    "CI2I3",      /*  21  */
    "CI3F4",      /*  22  */
    "CI3s4",      /*  23  */
    "CI4F4",      /*  24  Convert to integer from float */
    "CONSTGP3",   /*  25  push address pointer to stack. */
    "CONSTP3",    /*  26  */
    "CONSTs1",    /*  27  */
    "CONSTs2",    /*  28  */
    "CONSTs3",    /*  29  */
    "CONSTs4",    /*  30  */
    "CU1I3",      /*  31  */
    "CU2I3",      /*  32  */
    "CU3U4",      /*  33  */
    "DIVF4",      /*  34  Divide floats */
    "DIVI",       /*  35  Divide signed integers. */
    "DIVI3",      /*  36  */
    "DIVU",       /*  37  Divide unsigned integers. */
    "DIVU3",      /*  38  */
    "ENTER",      /*  39  Begin subroutine. */
    "EQ3",        /*  40  */
    "EQ4",        /*  41  Compare integers, jump if equal. */
    "EQF4",       /*  42  Compare floats, jump if equal */
    "EQU3",       /*  43  */
    "GEF4",       /*  44  Compare floats, jump if greater-than-or-equal */
    "GEI3",       /*  45  */
    "GEI4",       /*  46  Compare integers, jump if greater-than-or-equal. */
    "GEU3",       /*  47  */
    "GEU4",       /*  48  Compare unsigned integers, jump if greater-than-or-equal */
    "GTF4",       /*  49  Compare floats, jump if greater-than */
    "GTI3",       /*  50  */
    "GTI4",       /*  51  Compare integers, jump if greater-than. */
    "GTU3",       /*  52  */
    "GTU4",       /*  53  Compare unsigned integers, jump if greater-than */
    "JUMP",       /*  54  Unconditional jump. */
    "LEAVE",      /*  55  End subroutine. */
    "LEF4",       /*  56  Compare floats, jump if less-than-or-equal */
    "LEI3",       /*  57  */
    "LEI4",       /*  58  Compare integers, jump if less-than-or-equal. */
    "LEU",        /*  59  Compare unsigned integers, jump if less-than-or-equal */
    "LEU3",       /*  60  */
    "LOAD1",      /*  61  Load 1-byte from memory */
    "LOAD2",      /*  62  Load 2-bytes from memory */
    "LOAD3",      /*  63  Load 3-bytes from memory */
    "LOAD4",      /*  64  Load 4-bytes from memory */
    "LOADF4",     /*  65  Load 4 byte float from memory */
    "LOCAL",      /*  66  Get local variable. */
    "LSH3",       /*  67  */
    "LSH4",       /*  68  Left-shift */
    "LTF",        /*  69  Compare floats, jump if less-than */
    "LTI3",       /*  70  */
    "LTI4",       /*  71  Compare integers, jump if less-than. */
    "LTU",        /*  72  Compare unsigned integers, jump if less-than */
    "LTU3",       /*  73  */
    "MODI3",      /*  74  */
    "MODI4",      /*  75  Modulus (signed). */
    "MODU3",      /*  76  */
    "MODU4",      /*  77  Modulus (unsigned). */
    "MULF4",      /*  78  Multiply floats */
    "MULI3",      /*  79  */
    "MULI4",      /*  80  Multiply signed integers. */
    "MULU3",      /*  81  */
    "MULU4",      /*  82  Multiply unsigned integers. */
    "NE3",        /*  83  */
    "NE4",        /*  84  Compare integers, jump if not equal. */
    "NEF",        /*  85  Compare floats, jump if not-equal */
    "NEGF4",      /*  86  Negate float */
    "NEGI3",      /*  87  */
    "NEGI4",      /*  88  Negate integer. */
    "POP",        /*  89  Discard top-of-stack. */
    "PUSH",       /*  90  Push to stack. */
    "RSHI3",      /*  91  */
    "RSHI4",      /*  92  Right-shift (algebraic; preserve sign) */
    "RSHU3",      /*  93  */
    "RSHU4",      /*  94  Right-shift (bitwise; ignore sign) */
    "STORE1",     /*  95  Store 1-byte to memory */
    "STORE2",     /*  96  Store 2-byte to memory */
    "STORE3",     /*  97  */
    "STORE4",     /*  98  *(stack[top-1]) = stack[top] */
    "SUB3",       /*  99  */
    "SUB4",       /* 100  Subtract integers (two's complement). */
    "SUBF4",      /* 101  Subtract floats */
};
