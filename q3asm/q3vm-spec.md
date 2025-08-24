
## LCC Generated Assembly Mnemonics

### Data type and size codes:

| Data Type Postfix | Description/size                                                                    |
| ----------------- | ----------------------------------------------------------------------------------- |
| B                 | block (sequence of octets, of arbitrary length (e.g. character strings or structs)) |
| F4                | little-endian IEEE-754 32-bit single-precision floating point value.                |
| P4                | Four-octet pointer (memory address) value.                                          |
| I4                | Four-octet signed integer. Corresponds to Q3VM's C data type "signed int".          |
| I2                | Two-octet signed integer. Corresponds to Q3VM's C data type "signed short".         |
| I1                | One-octet signed integer. Corresponds to Q3VM's C data type "signed char".          |
| U4                | Four-octet unsigned integer. Corresponds to Q3VM's C data type "unsigned int".      |
| U2                | Two-octet unsigned integer. Corresponds to Q3VM's C data type "unsigned short".     |
| U1                | One-octet unsigned integer. Corresponds to Q3VM's C data type "unsigned char".      |


### Generalized opcodes list (lcc bytecode):

| Instruction | description                                                                                                                                                                                                                                                        |
| ----------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| CNSTt v     | CONSTANT. Reads v as a value of type t. For floats, v is the bit pattern of the float value.                                                                                                                                                                       |
| ASGNt       | ASSIGN. Pops a value from stack, interpreted according to t, to use as the assignment value. Pops another value from stack, interpreted as a pointer value (memory address) to  se as the assignment destination.                                                  |
| INDIRt      | INDIRECTION. Pops a value from stack, interpreted as a pointer value (memory address). Retrieves the 32-bit value from the indicated memory location, and interprets the 32-bit value according to t, then pushes to stack. (think of it as pointer dereferencing) |
| CVFt        | CONVERT TO FLOAT. Pops a value from stack, interpreted according to t, converted to its equivalent float (F4) form, then pushed to stack.                                                                                                                          |
| CVIt        | CONVERT TO (signed) INTEGER. Pops a value from stack, interpreted according to t, converted to its equivalent signed integer (I4) form, then pushed to stack.                                                                                                      |
| CVUt        | CONVERT TO UNSIGNED INTEGER. Pops a value from stack, interpreted according to t, converted to its equivalent unsigned integer (U4) form, then pushed to stack.                                                                                                    |
| CVPt        | CONVERT TO UNSIGNED INTEGER. Pops a value from stack, interpreted according to t, converted to its equivalent pointer (P4) form, then pushed to stack.                                                                                                             |
| NEGt        | ARITHMETIC NEGATE. Pops a value from stack, interpreted according to t, negated arithmeticaly (multiplied by -1 or -1.0), then pushed to stack.                                                                                                                    |
| ADDRGP3 v   | ADDRESS OF GLOBAL (pointer). Takes v as a memory address, takes the 24-bit value at the address, pushes the 32-bit value to stack (i.e. get value of a global variable\|function/symbol).                                                                          |
| ADDRLP4 v   | ADDRESS OF (from?) LOCAL (pointer). Address of a local variable. Local Pointer(?) plus v. First local variable is at 0.                                                                                                                                            |
| ADDRFP4 v   | ADDRESS (from?) FRAME (pointer). Address of an argument (with repect to the frame pointer). Frame Pointer plus (minus?) v. First argument is at 0, second argument at 4, etc (XXX: verify).                                                                        |
| ADDt        | ADD. Pops a value from stack, interpreted according to t, as second operand. Pops another value from stack, interpreted t, as first operand. The two values are arithmeticaly added, pushes sum to stack.                                                          |
| SUBt        | SUBTRACT. Pops a value from stack, interpreted t, as second operand. Pops another value from stack, interpreted t, as first operand. Subtracts second operand from first operand, pushes difference to stack.                                                      |
| MULt        | MULTIPLY. Pops a value from stack, interpreted t, as second operand. Pops another value from stack, interpreted t, as first operand. Multiplies the values together, pushes product to stack.                                                                      |
| DIVt        | DIVIDE. Pops a value from stack, interpreted t, as second operand. Pops another value from stack, interpreted t, as first operand. Second operand divides into first operand, pushes quotient to stack (XXX: integer division C style?).                           |
| MODt        | MODULUS. Pops a value from stack, as t, as second operand. Pops another value from stack, as t, as first operand. The second operand divides into the first operand, pushes remainder to stack.                                                                    |
| LSHt        | LEFT SHIFT. Pops a value from stack, as t, as second operand. Pops another value from stack, as t, as first operand. First operand bit-wise shifts left by number of bits specified by second operand, pushes result to stack.                                     |
| RSHt        | RIGHT SHIFT. Pops a value from stack, as t, as second operand. Pops another value from stack, as t, as first operand. First operand bit-wise shifts right by number of bits specified by second operand, pushes result to stack. Sign-extension depends on t.      |
| BANDt       | BINARY/BITWISE AND. Pops a value from stack (t) as second operand. Pops another value from stack (t) as first operand. The two operands combine by bitwise AND, pushes result to stack.                                                                            |
| BCOMt       | BINARY/BITWISE COMPLEMENT. Pops a value from stack (t). Flips (almost-)every bit to its opposite value. Changing the high bit (bit 31) depends on t.                                                                                                               |
| BORt        | BINARY/BITWISE OR. Pops a value from stack (t) as second operand. Pops another value from stack (t) as first operand. Combines the two operands by bitwise OR, pushes result to stack.                                                                             |
| BXORt       | BINARY/BITWISE XOR. Pops two values, XORs, pushes result to stack.                                                                                                                                                                                                 |
| EQt v       | EQUAL-TO. Pops two values from stack (as type t), compares the two values. Jumps to address v if true.                                                                                                                                                             |
| GEt v       | GREATER-THAN OR EQUAL-TO. Pops a value from stack (type t) as second operand. Pops another value from stack (type t) as first operand. Compares if first operand is equal to the second operand. Jumps to address v if true.                                       |
| GTt v       | GREATER-THAN. Pops a second operand (type t) then a first operand (type t). Compares if first operand is greater than the second operand. Jumps to address v if true.                                                                                              |
| LEt v       | LESS-THAN OR EQUAL-TO. Pops a second operand (type t) then a first operand (type t). Compares if first operand is less than or equal to the second operand. Jumps to address v if true.                                                                            |
| LTt v       | LESS-THAN. Pops a second operand (t) then a first operand (t). Compares if first operand is less than the second operand. Jumps to address v if true.                                                                                                              |
| NEt v       | NOT-EQUAL. Pops two values (t), compares the two values. Compares if first operand is not equal to the second operand. Jumps to address v if true.                                                                                                                 |
| JUMPV       | Pops a pointer value from stack, sets PC to the value (jump).                                                                                                                                                                                                      |
| RETt        | Pop value from stack, shrink stack to eliminate local frame, push value back to stack. Or copy top of stack to bottom of frame and shrink stack size/pointer?                                                                                                      |
| ARGt        | Pop value from stack as type t, store into arguments-marshalling space.                                                                                                                                                                                            |
| CALLt       | Pops value from stack as address of a function. Makes a procedure call to the function, which is expected to return a value of type t.                                                                                                                             |
| POP         | Pop stack (discard top of stack). (functions of void type still return a (nonsense) 32-bit value)                                                                                                                                                                  |


### List of assembly directives:

| directive           | description                                                                                                                                                                    |
| ------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| equ s v             | Assign integer value v to symbol s.                                                                                                                                            |
| data                | Assemble to DATA segment (initialized 32-bit variables).                                                                                                                       |
| code                | Assemble to CODE segment (instructions).                                                                                                                                       |
| lit                 | Assemble to LIT segment (initialized 8-bit variables).                                                                                                                         |
| bss                 | Assemble to BSS segment (uninitialized block storage segment).                                                                                                                 |
| LABELV symbol       | Assigns the value of the currently computed Program Counter to the symbol named symbol. (i.e. the current assembled address value is assigned to symbol).                      |
| byte l v            | Write initialized value v of l octets. 1-octet values go into LIT segment. 2-octet values are invalid (fatal error). 4-octet values go into DATA segment.                      |
| skip v              | Skip v octets in the segment, leaving the octets uninitialized.                                                                                                                |
| export s            | Export symbol s for external linkage.                                                                                                                                          |
| import s            | Import symbol s.                                                                                                                                                               |
| align v             | Ensure memory alignment at a multiple of v, skipping octets if needed.                                                                                                         |
| address x           | ??? (evaluates expression x and append result to DATA segment)                                                                                                                 |
| file filename       | Set filename to filename for status and error reporting.                                                                                                                       |
| line lineno         | Indicates current source line of lineno.                                                                                                                                       |
| proc locals args    | Start of procedure (function) body. Set aside locals octets for local variables, and args octets for arguments marshalling (for all possible subcalls within this  procedure). |
| endproc locals args | End of procedure body. Clean up args bytes (for arguments marshalling) and locals bytes (for local variables).                                                                 |
