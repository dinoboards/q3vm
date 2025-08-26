struct assemblers_s;

typedef void (*assemblerFn)(const struct assemblers_s assembler);

typedef struct assemblers_s {
  const char *const prefix;
  const opcode_t    opcode;
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
ASMFn(ADDRL) {
  int v;
  Parse();
  v = ParseExpression();
  v = 6 + currentArgs + v;

  WriteInt8Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitByte(&segment[CODESEG], v);
}

// address of a parameter is converted to OP_LOCAL
ASMFn(ADDRF) {
  int v;

  Parse();
  v = ParseExpression();
  v = 12 + currentArgs + currentLocals + v;

  WriteInt8Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitByte(&segment[CODESEG], v);
}

DIRFn(BYTE) {
  int       i;
  const int v  = ParseValue();
  int       v2 = ParseValue();

  if (v == 2) {
    /* and 16-bit (2-byte) values will cause q3asm to barf. */
    CodeError("16 bit initialized data not supported");
  }

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
  opcode_t opcode;

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
  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMMultipleFn(CODE_CIxI2) {
  opcode_t opcode;

  Parse();
  switch (token[0]) {
  case '3':
    WriteComment(); /* NOP */
    return;

  case '4':
    WriteComment(); /* NOP */
    return;

  default:
    WriteComment();
    printf("TODO: CODE_CI%cI2\n", token[0]);
    // CodeError("Bad sign extension: %s\n", token);
    return;
  }
  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMMultipleFn(CODE_CIxU3) {
  opcode_t opcode;

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
  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMMultipleFn(CODE_CUxU2) {
  opcode_t opcode;

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
  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMMultipleFn(CODE_CUxU3) {
  opcode_t opcode;

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
  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
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

  currentLocals    = ParseValue(); // locals
  currentArgs      = ParseValue(); // arg marshalling
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
