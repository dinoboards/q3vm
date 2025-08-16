struct assemblers_s;

typedef void (*assemblerFn)(const struct assemblers_s assembler);

typedef struct assemblers_s {
  const char *const prefix;
  const opcode_t    opcode;
  assemblerFn       emit;
} assemblers_t;

#define ASMFn(O) void TryNewAssemble_##O(const assemblers_t assembler)

#define DIRFn(O) void TryNewAssemble_##O(const assemblers_t assembler __attribute__((unused)))

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
