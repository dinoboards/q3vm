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
  instructionCount++;
  Parse();
  const int v = ParseExpression();

  WriteInt24Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt24(&segment[CODESEG], v);
}

ASMFn(CODE_FLOAT) {
  instructionCount++;
  Parse();
  const int v = ParseExpression();

  WriteFloatCode(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt32(&segment[CODESEG], v);
}

ASMFn(CODE_32BIT) {
  instructionCount++;
  Parse();
  const int v = ParseExpression();

  WriteInt32Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt32(&segment[CODESEG], v);
}

ASMFn(CODE_16BIT) {
  instructionCount++;
  Parse();
  const int v = ParseExpression();

  WriteInt16Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt16(&segment[CODESEG], v);
}

ASMFn(CODE_8BIT) {
  instructionCount++;
  Parse();
  const int v = ParseExpression();

  WriteInt8Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitByte(&segment[CODESEG], v);
}

// call instructions reset currentArgOffset
ASMFn(CALL) {
  instructionCount++;
  WriteCode(assembler.opcode);

  EmitByte(&segment[CODESEG], assembler.opcode);
  currentArgOffset = 0;
}

ASMFn(ARGF) {
  instructionCount++;
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

ASMFn(ARG) {
  instructionCount++;
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
  instructionCount++;
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
  instructionCount++;
  Parse();
  v = ParseExpression();
  v = 6 + currentArgs + v;

  WriteInt16Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt16(&segment[CODESEG], v);
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
  instructionCount++;

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

// address of a parameter is converted to OP_LOCAL
ASMFn(ADDRF) {
  int v;

  instructionCount++;
  Parse();
  v = ParseExpression();
  v = 12 + currentArgs + currentLocals + v;

  WriteInt16Code(assembler.opcode, v);

  EmitByte(&segment[CODESEG], assembler.opcode);
  EmitInt16(&segment[CODESEG], v);
}

ASMFn(CODE_OP) {
  instructionCount++;
  WriteCode(assembler.opcode);

  EmitByte(&segment[CODESEG], assembler.opcode);
}

ASMMultipleFn(CODE_SEX) {
  instructionCount++;

  opcode_t opcode;

  Parse();
  switch (token[0]) {
  case '1':
    opcode = OP_SEX8;
    break;

  case '2':
    opcode = OP_SEX16;
    break;

  case '3':
    WriteComment();
    return;

  default:
    CodeError("Bad sign extension: %s\n", token);
    return;
  }
  WriteCode(opcode);

  EmitByte(&segment[CODESEG], opcode);
}

ASMFn(PROC) {
  char name[1024];
  instructionCount++;

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
  instructionCount += 2;
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
