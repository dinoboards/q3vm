
assemblers_t assemblers[] = {

    {"ASGNB",   OP_BLOCK_COPY, assfn(CODE_24BIT)},
    {"CNSTP4",  OP_CONSTP4,    assfn(CODE_24BIT)},
    {"ADDRGP3", OP_CONSTGP3,   assfn(CODE_24BIT)},
    {"ADDRGP4", OP_CONSTGP4,   assfn(CODE_24BIT)}, /* why is this only 24bit?? */
    {"CNSTP3",  OP_CONSTP3,    assfn(CODE_24BIT)},
    {"CNSTF4",  OP_CONSTF4,    assfn(CODE_FLOAT)},
    {"CNSTI4",  OP_CONSTI4,    assfn(CODE_32BIT)},
    {"CNSTU4",  OP_CONSTU4,    assfn(CODE_32BIT)},
    {"CNSTI2",  OP_CONSTI2,    assfn(CODE_16BIT)},
    {"CNSTU2",  OP_CONSTU2,    assfn(CODE_16BIT)},
    {"CNSTU1",  OP_CONSTU1,    assfn(CODE_8BIT) },
    {"CNSTI1",  OP_CONSTI1,    assfn(CODE_8BIT) },
};
