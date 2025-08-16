struct assemblers_s;

typedef void (*assemblerFn)(const struct assemblers_s assembler);

typedef struct assemblers_s {
  const char *const prefix;
  const opcode_t    opcode;
  assemblerFn       emit;
} assemblers_t;

#define ASMFn(O) void TryNewAssemble_##O(const assemblers_t assembler)

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
