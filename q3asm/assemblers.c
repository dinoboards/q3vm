struct assemblers_s;

typedef void (*assemblerFn)(const struct assemblers_s assembler);

typedef struct assemblers_s {
  const char *const prefix;
  const opcode_t    opcode;
  const opcode_t    secondary_opcode;
  assemblerFn       emit;

} assemblers_t;

#define ASMFn(O) void TryNewAssemble_##O(const assemblers_t assembler)

#define ASMMultipleFn(O) void TryNewAssemble_##O(const assemblers_t _unsued __attribute__((unused)))

#define DIRFn(O) void TryNewAssemble_##O(const assemblers_t _unsued __attribute__((unused)))

ASMFn(CODE_24BIT) {
  Parse();
  const int v = ParseExpression();

  WriteInt24Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt24(&segment[CODESEG], v);
}

ASMMultipleFn(CODE_ADDRG) {
  Parse();
  symbol_t *s = NULL;
  const int v = ParseExpression2(&s);

  if (s && s->segment->index == CODESEG && v < 0) {
    if (v >= -15) {
      WriteCode(OP_CONSTP3_SC1 + abs(v) - 1);
      EmitByte(&segment[CODESEG], OP_CONSTP3_SC1 + abs(v) - 1);
      return;
    }

    WriteInt8Code(OP_CONSTP3_SCn, -v);
    EmitByte(&segment[CODESEG], OP_CONSTP3_SCn);
    EmitByte(&segment[CODESEG], -v);
    return;
  }

  int relative_offset = v - (currentSegment->imageUsed + 1);

  if (passNumber >= 1 && s->segment->index == CODESEG) {

    if (relative_offset <= 127 && relative_offset >= -128) {
      sprintf(lineBuffer + strlen(lineBuffer), " ($%06X)", v);
      WriteInt8Code(OP_CONSTP3_1, relative_offset);
      EmitByte(&segment[CODESEG], OP_CONSTP3_1);
      EmitByte(&segment[CODESEG], relative_offset);
      return;
    }

    if (relative_offset <= 32767 && relative_offset >= -32768) {
      sprintf(lineBuffer + strlen(lineBuffer), " ($%06X)", v);
      WriteInt16Code(OP_CONSTP3_2, relative_offset);
      EmitByte(&segment[CODESEG], OP_CONSTP3_2);
      EmitInt16(&segment[CODESEG], relative_offset);
      return;
    }
  }

  WriteInt24Code(OP_CONSTP3, v);

  EmitByte(&segment[CODESEG], OP_CONSTP3);
  EmitInt24(&segment[CODESEG], v);
}

ASMMultipleFn(CODE_BLOCK_COPY) {
  Parse();
  const unsigned int v = ParseExpression();

  if (v <= 255) {
    WriteInt8Code(OP_BLK_CPY_U1, v);

    EmitByte(&segment[CODESEG], OP_BLK_CPY_U1);
    EmitByte(&segment[CODESEG], v);
    return;
  }

  if (v < 0x10000) {
    WriteInt16Code(OP_BLK_CPY_U2, v);

    EmitByte(&segment[CODESEG], OP_BLK_CPY_U2);
    EmitInt16(&segment[CODESEG], v);
    return;
  }

  WriteInt24Code(OP_BLK_CPY, v);

  EmitByte(&segment[CODESEG], OP_BLK_CPY);
  EmitInt24(&segment[CODESEG], v);
}

ASMMultipleFn(CODE_CONSTI_24BIT) {
  Parse();
  const int v = ParseExpression();

  if (v <= 127 && v >= -128) {
    WriteInt8Code(OP_CONSTI3_I1, v);

    EmitByte(&segment[CODESEG], OP_CONSTI3_I1);
    EmitByte(&segment[CODESEG], v);
    return;
  }

  if (v <= 32767 && v >= -32768) {
    WriteInt16Code(OP_CONSTI3_I2, v);

    EmitByte(&segment[CODESEG], OP_CONSTI3_I2);
    EmitInt16(&segment[CODESEG], v);
    return;
  }

  WriteInt24Code(OP_CONSTs3, v);

  EmitByte(&segment[CODESEG], OP_CONSTs3);
  EmitInt24(&segment[CODESEG], v);
}

ASMMultipleFn(CODE_CONSTU_24BIT) {
  Parse();
  const unsigned int v = ParseExpression();

  if (v <= 255) {
    WriteInt8Code(OP_CONSTU3_U1, v);

    EmitByte(&segment[CODESEG], OP_CONSTU3_U1);
    EmitByte(&segment[CODESEG], v);
    return;
  }

  if (v < 0x10000) {
    WriteInt16Code(OP_CONSTU3_U2, v);

    EmitByte(&segment[CODESEG], OP_CONSTU3_U2);
    EmitInt16(&segment[CODESEG], v);
    return;
  }

  WriteInt24Code(OP_CONSTs3, v);

  EmitByte(&segment[CODESEG], OP_CONSTs3);
  EmitInt24(&segment[CODESEG], v);
}

ASMFn(CODE_PTR) {
  Parse();
  const int v = ParseExpression();

  int relative_offset = v - (currentSegment->imageUsed + 1);

  if (passNumber >= 1 && assembler.secondary_opcode != OP_UNDEF) {

    if (relative_offset <= 127 && relative_offset >= -128) {
      sprintf(lineBuffer + strlen(lineBuffer), " ($%06X)", v);
      WriteInt8Code(assembler.secondary_opcode, relative_offset);
      EmitByte(&segment[CODESEG], assembler.secondary_opcode);
      EmitByte(&segment[CODESEG], relative_offset);
      return;
    }
  }

  sprintf(lineBuffer + strlen(lineBuffer), " ($%06X)", v);
  WriteInt16Code(assembler.opcode, relative_offset);

  EmitByte(&segment[CODESEG], assembler.opcode);

  if (relative_offset > 32767 || relative_offset < -32768) {
    CodeError("branch to far. Relative jump outside range of 16 bit integer.\n");
    return;
  }

  EmitInt16(&segment[CODESEG], relative_offset);
}

ASMFn(CODE_FLOAT) {
  Parse();
  const int v = ParseExpression();

  WriteFloatCode(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt32(&segment[CODESEG], v);
}

ASMFn(CODE_32BIT) {
  Parse();
  const int v = ParseExpression();

  WriteInt32Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt32(&segment[CODESEG], v);
}

ASMFn(CODE_16BIT) {
  Parse();
  const int v = ParseExpression();

  WriteInt16Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt16(&segment[CODESEG], v);
}

ASMFn(CODE_8BIT) {
  Parse();
  const int v = ParseExpression();

  WriteInt8Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitByte(&segment[CODESEG], v);
}

// call instructions reset currentArgOffset
ASMFn(CALL) {
  WriteCode(assembler.opcode);

  EmitByte(&segment[CODESEG], assembler.opcode);
  currentArgOffset = 0;
}

ASMFn(ARG3) {
  const int v = 6 + currentArgOffset;

  WriteInt8Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);

  EmitByte(&segment[CODESEG], v);
  currentArgOffset += 3;

  if (v >= 256) {
    CodeError("currentArgOffset >= 256");
    return;
  }
}

ASMFn(ARG4) {
  const int v = 6 + currentArgOffset;

  WriteInt8Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);

  EmitByte(&segment[CODESEG], v);
  currentArgOffset += 4;

  if (v >= 256) {
    CodeError("currentArgOffset >= 256");
    return;
  }
}

// address of a local is converted to OP_LOCAL
ASMMultipleFn(ADDRL) {
  int v;

  Parse();
  v = ParseExpression();
  v = 6 + currentArgs + v;

  if (v >= 256) {
    WriteInt16Code(OP_LOCAL_FAR, v);

    EmitByte(&segment[CODESEG], OP_LOCAL_FAR);
    EmitInt16(&segment[CODESEG], v);
    return;
  }

  WriteInt8Code(OP_LOCAL, v);

  EmitByte(&segment[CODESEG], OP_LOCAL);
  EmitByte(&segment[CODESEG], v);
}

// address of a parameter is converted to OP_LOCAL
ASMMultipleFn(ADDRF) {
  int v;

  Parse();
  v = ParseExpression();
  v = 12 + currentArgs + currentLocals + v;

  if (v >= 256) {
    WriteInt16Code(OP_LOCAL_FAR, v);

    EmitByte(&segment[CODESEG], OP_LOCAL_FAR);
    EmitInt16(&segment[CODESEG], v);
    return;
  }

  WriteInt8Code(OP_LOCAL, v);

  EmitByte(&segment[CODESEG], OP_LOCAL);
  EmitByte(&segment[CODESEG], v);
}

DIRFn(BYTE) {
  int       i;
  const int v  = ParseValue();
  int       v2 = ParseValue();

  for (i = 0; i < v; i++) {
    WriteDirectiveD8(v2);
    EmitByte(currentSegment, (v2 & 0xFF)); /* paranoid ANDing  -PH */
    v2 >>= 8;
  }
}

// ret just leaves something on the op stack
ASMFn(RET) {
  const int v = 6 + currentLocals + currentArgs;
  WriteInt16Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt16(&segment[CODESEG], v);
}

DIRFn(COMMENT) { WriteComment(); }

DIRFn(LABEL) {
  Parse();

  DefineSymbol(token, currentSegment->imageUsed);

  WritePC();
  WriteSymbol(token);
  WriteComment();
}

ASMFn(CODE_OP) {
  WriteCode(assembler.opcode);

  EmitByte(&segment[CODESEG], assembler.opcode);
}

ASMMultipleFn(CODE_CIxI4) {
  opcode_t opcode;

  Parse();
  switch (token[0]) {
  case '3':
    opcode = OP_CI3s4;
    break;

  default:
    CodeError("Bad sign extension: %s\n", token);
    return;
  }
  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMMultipleFn(CODE_CIxI3) {
  opcode_t opcode;

  Parse();
  switch (token[0]) {
  case '1':
    opcode = OP_CI1I3;
    break;

  case '2':
    opcode = OP_CI2I3;
    break;

  case '4':
    WriteComment();
    return;

  default:
    WriteComment();
    printf("TODO: CODE_CI%cI3\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }
  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMMultipleFn(CODE_CUxI3) {
  opcode_t opcode;

  Parse();

  switch (token[0]) {
  case '1':
    opcode = OP_CU1I3;
    break;

  case '2':
    opcode = OP_CU2I3;
    break;

  case '3':
  case '4':
    WriteComment();
    return;

  default:
    WriteComment();
    printf("TODO: CODE_CU%cI3\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }

  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMMultipleFn(CODE_CIxU4) {
  opcode_t opcode;

  Parse();

  switch (token[0]) {
  case '3':
    opcode = OP_CI3s4;
    break;

  case '4':
    WriteComment();
    return;

  default:
    WriteComment();
    printf("TODO: CODE_CI%cU4\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }

  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMMultipleFn(CODE_CIxF4) {
  opcode_t opcode;

  Parse();

  switch (token[0]) {
  case '3':
    opcode = OP_CI3F4;
    break;

  case '4':
    opcode = OP_CI4F4;
    break;

  default:
    WriteComment();
    printf("TODO: CODE_CI%cF4\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }

  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMMultipleFn(CODE_CIxI1) {
  Parse();
  switch (token[0]) {
  case '3':
  case '4':
    WriteComment(); /* No operation needed for size reduction */
    return;

  default:
    WriteComment();
    printf("TODO: CODE_CI%cI1\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }
}

ASMMultipleFn(CODE_CIxI2) {
  Parse();
  switch (token[0]) {
  case '3':
  case '4':
    WriteComment(); /* NOP */
    return;

  default:
    WriteComment();
    printf("TODO: CODE_CI%cI2\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }
}

ASMMultipleFn(CODE_CIxU3) {
  Parse();
  switch (token[0]) {
  case '3':
  case '4':
    WriteComment();
    return;

  default:
    WriteComment();
    printf("TODO: CODE_CI%cU3\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }
}

ASMMultipleFn(CODE_CUxU2) {
  Parse();
  switch (token[0]) {
  case '3':
    WriteComment(); // TODO should clear top byte
    return;

  default:
    WriteComment();
    printf("TODO: CODE_CU%cU2\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }
}

ASMMultipleFn(CODE_CUxU3) {
  Parse();
  switch (token[0]) {
  case '4':
    WriteComment();
    return;

  default:
    WriteComment();
    printf("TODO: CODE_CU%cU3\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }
}

ASMMultipleFn(CODE_CUxU4) {
  opcode_t opcode;

  Parse();
  switch (token[0]) {
  case '3':
    opcode = OP_CU3U4;
    break;

  default:
    WriteComment();
    printf("TODO: CODE_CU%cU4\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }
  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMFn(PROC) {
  char name[1024];
  Parse(); // function name
  strcpy(name, token);

  WritePC();
  WriteSymbol(token);
  WriteComment();

  DefineSymbol(token, segment[CODESEG].imageUsed);

  currentLocals = ParseValue(); // locals
  currentArgs   = ParseValue(); // arg marshalling
  sprintf(infoBuffer, "ARGS: %d", currentArgs);
  WriteInfo();

  sprintf(infoBuffer, "LOCALS: %d", currentLocals);
  WriteInfo();

  const uint16_t v = (uint16_t)(6 + currentLocals + currentArgs);

  if (v >= 32767) {
    CodeError("Locals > 32k in %s\n", name);
    return;
  }

  WriteInt16Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt16(&segment[CODESEG], v);
}

ASMMultipleFn(ENDPROC) {
  Parse();      // skip the function name
  ParseValue(); // locals
  ParseValue(); // arg marshalling

  WriteCode(OP_PUSH);
  // all functions must leave something on the opstack
  EmitByte(&segment[CODESEG], OP_PUSH);

  const uint16_t v = 6 + currentLocals + currentArgs;
  WritePC();
  WriteOpcode(OP_LEAVE);
  WriteInt16(v);
  WriteNewLine();

  EmitByte(&segment[CODESEG], OP_LEAVE);
  EmitInt16(&segment[CODESEG], v);
}

DIRFn(ALIGN) {
  const int v = ParseValue();

  currentSegment->imageUsed = (currentSegment->imageUsed + v - 1) & ~(v - 1);
  WritePC();
  WriteDirective("ALIGN");
  WriteNumber(v);
  WriteComment();
}

DIRFn(ADDRESS) {
  Parse();
  const int v = ParseExpression();

  WriteDirectiveD24(v);

  EmitInt24(currentSegment, v);
}

DIRFn(SKIP) {
  const int v = ParseValue();
  WritePC();
  WriteDirective("SKIP");
  WriteNumber(v);
  WriteComment();
  currentSegment->imageUsed += v;
  WritePC();
  WriteNewLine();
}

DIRFn(CODE) {
  currentSegment = &segment[CODESEG];

  WriteDirectiveSegment(CODESEG);
}

DIRFn(LIT) {
  currentSegment = &segment[LITSEG];

  WriteDirectiveSegment(LITSEG);
}

DIRFn(BSS) {
  currentSegment = &segment[BSSSEG];

  WriteDirectiveSegment(BSSSEG);
}

DIRFn(DATA) {
  currentSegment = &segment[DATASEG];

  WriteDirectiveSegment(DATASEG);
}

DIRFn(EQU) {
  char name[1024];
  Parse();
  strcpy(name, token);

  Parse();
  const int v = atoiNoCap(token);

  WriteDirectiveEQU(name, v);

  DefineSymbol(name, v);
}
