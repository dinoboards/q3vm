
#define DIRECTIVE   0
#define OP_MULTIPLE -1

assemblers_t assemblers[] = {
    {"ADDRESS", DIRECTIVE,     assfn(ADDRESS)   },
    {"ADDRF",   OP_LOCAL,      assfn(ADDRF)     },
    {"ADDRGP3", OP_CONSTGP3,   assfn(CODE_24BIT)},
    {"ADDRGP4", OP_CONSTGP4,   assfn(CODE_24BIT)}, /* why is this only 24bit?? */
    {"ADDRL",   OP_LOCAL,      assfn(ADDRL)     },
    {"ALIGN",   DIRECTIVE,     assfn(ALIGN)     },
    {"ARGF",    OP_ARGF,       assfn(ARGF)      },
    {"ARGI",    OP_ARGF,       assfn(ARG)       },
    {"ARGP",    OP_ARGF,       assfn(ARG)       },
    {"ARGU",    OP_ARGF,       assfn(ARG)       },
    {"ASGNB",   OP_BLOCK_COPY, assfn(CODE_24BIT)},
    {"BYTE",    DIRECTIVE,     assfn(BYTE)      },
    {"CALL",    OP_CALL,       assfn(CALL)      },
    {"CNSTF4",  OP_CONSTF4,    assfn(CODE_FLOAT)},
    {"CNSTI1",  OP_CONSTI1,    assfn(CODE_8BIT) },
    {"CNSTI2",  OP_CONSTI2,    assfn(CODE_16BIT)},
    {"CNSTI4",  OP_CONSTI4,    assfn(CODE_32BIT)},
    {"CNSTP3",  OP_CONSTP3,    assfn(CODE_24BIT)},
    {"CNSTP4",  OP_CONSTP4,    assfn(CODE_24BIT)},
    {"CNSTU1",  OP_CONSTU1,    assfn(CODE_8BIT) },
    {"CNSTU2",  OP_CONSTU2,    assfn(CODE_16BIT)},
    {"CNSTU4",  OP_CONSTU4,    assfn(CODE_32BIT)},
    {"ENDPROC", OP_MULTIPLE,   assfn(ENDPROC)   },
    {"EXPORT",  DIRECTIVE,     assfn(COMMENT)   },
    {"IMPORT",  DIRECTIVE,     assfn(COMMENT)   },
    {"LABEL",   DIRECTIVE,     assfn(LABEL)     },
    {"LINE",    DIRECTIVE,     assfn(COMMENT)   },
    {"POP",     OP_POP,        assfn(CODE_OP)   },
    {"PROC",    OP_ENTER,      assfn(PROC)      },
    {"RET",     OP_LEAVE,      assfn(RET)       },
};
