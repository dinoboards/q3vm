## "NotQ3VM" Opcodes

### Valid Opcode Param types:

 * v8: uint8_t
 * v16: uint16_t
 * v24: uint24_t
 * v32: int32_t
 * ptr: 3 byte pointer

### Registers
* PC => Program Counter
* PS => Program Stack
* OS => Operation Stack (stack of values - padded to 4 bytes)
* R0: *OS
* R1: *(OS - 1)

### Implemented Opcode functions

| Op Code           | LCC Code                           | Description                                             | Stack Type         |
| ----------------- | ---------------------------------- | ------------------------------------------------------- | ------------------ |
| OP_UNDEF          |                                    | N/A                                                     |                    |
| OP_IGNORE         |                                    | N/A Special code that is never emitted                  |                    |
| OP_BREAK          | BREAK                              | `with DEBUG_VM defined, breaks into a debug mode`       |                    |
| OP_ADD3           | ADDI3, ADDP3                       | `OS--; *OS = R1 + R0`                                   | (u)int24           |
| OP_ADD4           | ADDI4                              | `OS--; *OS = R1 + R0`                                   | (u)int32           |
| OP_ADDF4          | ADDF4                              | `OS--; *OS = R1 + R0`                                   | float              |
| OP_ARG3 v8        | ARGt                               | `OS--; PS[v8]= R0`                                      | 3 bytes            |
| OP_ARG4 v8        | ARGt                               | `OS--; PS[v8]= R0`                                      | 4 bytes            |
| OP_BAND3          | BANDI3, BANDU3                     | `OS--; *OS = R1 & R0`                                   | (u)int24           |
| OP_BAND4          | BANDI4, BANDU4                     | `OS--; *OS = R1 & R0`                                   | (u)int32           |
| OP_BCOM3          | BCOMI3, BCOMU3                     | `*OS = ~R0`                                             | (u)int24           |
| OP_BCOM4          | BCOMI4, BCOMU4                     | `*OS = ~R0`                                             | (u)int32           |
| OP_BLOCK_COPY v24 | ASGNB                              | `memcpy(R1, R0, v24); OS -= 2`                          | ptr                |
| OP_BOR3           | BORI3, BORU3                       | `OS--; *OS = R1 \| R0`                                  | (u)int24           |
| OP_BOR4           | BORI4, BORU4                       | `OS--; *OS = R1 \| R0`                                  | (u)int32           |
| OP_BXOR3          | BXORI3, BXORU3                     | `OS--; *OS = R1 ^ R0`                                   | (u)int24           |
| OP_BXOR4          | BXORI4, BXORU4                     | `OS--; *OS = R1 ^ R0`                                   | (u)int32           |
| OP_CALL           | CALL                               | `*PS = PC; PC = *OS--; if PC < 0, invoke a System Call` | ptr                |
| OP_CF4I3          | CVFI3                              | `*OS = (float)R0`                                       | float              |
| OP_CF4I4          | CVFI4                              | `*OS = (float)R0`                                       | float              |
| OP_CI1I3          | CVII3 1                            | `*OS = (int24)R0`                                       | int8               |
| OP_CI2I3          | CVII3 2                            | `*OS = (int24)R0`                                       | int16              |
| OP_CI3F4          | CVIF4 3                            | `*OS = (float)R0`                                       | int32              |
| OP_CI3s4          | CVII4 3, CVIU4 3                   | `*OS = (int32)R0`                                       | int24              |
| OP_CI4F4          | CVIF4 4                            | `*OS = (float)R0`                                       | int32              |
| OP_CONSTP3 v24    | CNSTP4, ADDRGP3                    | `OS++; *OS = v24`                                       |                    |
| OP_CONSTs1 v8     | CNSTU1, CNSTU1                     | `OS++; *OS = v8`                                        |                    |
| OP_CONSTs2 v16    | CNSTU2, CNSTU2                     | `OS++; *OS = v16`                                       |                    |
| OP_CONSTs3 v24    | CNSTU3, CNSTU3                     | `OS++; *OS = v24`                                       |                    |
| OP_CONSTs4 v32    | CNSTU4, CNSTU4                     | `OS++; *OS = v32`                                       |                    |
| OP_CU1I3          | CVUI3 1                            | `*OS = (int24)R0`                                       | uint8              |
| OP_CU2I3          | CVUI3 2                            | `*OS = (int24)R0`                                       | uint16             |
| OP_CU3U4          | CVUI3 3                            | `*OS = (uint32)R0`:                                     | uint24             |
| OP_DIVF4          | DIVF4                              | `OS--; *OS = R1 / R0`                                   | float              |
| OP_DIVI3          | DIVI3                              | `OS--; *OS = R1 / R0`                                   | int24              |
| OP_DIVI4          | DIVI4                              | `OS--; *OS = R1 / R0`                                   | int32              |
| OP_DIVU3          | DIVU3                              | `OS--; *OS = R1 / R0`                                   | uint24             |
| OP_DIVU4          | DIVU4                              | `OS--; *OS = R1 / R0`                                   | uint32             |
| OP_ENTER v16      | PROC                               | `PS -= v16`                                             |                    |
| OP_EQ3 v16        | EQI3, EQU3                         | `OS -= 2; PC += v16 if R1 == R0`                         | (u)int24           |
| OP_EQ4 v16        | EQI4, EQU4, EQF4                   | `OS -= 2; PC += v16 if R1 == R0 `                        | (u)int32/float     |
| OP_GEF4 v16       | GEF                                | `OS -= 2; PC += v16 if R1 >= R0 `                        | float              |
| OP_GEI3 v16       | GEI3                               | `OS -= 2; PC += v16 if R1 >= R0 `                        | int24              |
| OP_GEI4 v16       | GEI4                               | `OS -= 2; PC += v16 if R1 >= R0 `                        | int32              |
| OP_GEU3 v16       | GEU3                               | `OS -= 2; PC += v16 if R1 >= R0`                         | uint23             |
| OP_GEU4 v16       | GEU4                               | `OS -= 2; PC += v16 if R1 >= R0`                         | uint24             |
| OP_GTF4 v16       | GTF4                               | `OS -= 2; PC += v16 if R1 > R0`                          | float              |
| OP_GTI3 v16       | GTI3                               | `OS -= 2; PC += v16 if R1 > R0`                          | int23              |
| OP_GTI4 v16       | GTI4                               | `OS -= 2; PC += v16 if R1 > R0`                          | int24              |
| OP_GTU3 v16       | GTU3                               | `OS -= 2; pc += v16 if R1 > R0`                          | uint23             |
| OP_GTU4 v16       | GTU4                               | `OS -= 2; pc += v16 if R1 > R0`                          | uint24             |
| OP_JUMP           | JUMPV                              | `PC = R0; OS--;`                                        | ptr                |
| OP_LEAVE v16      | RET, ENDPROC                       | `PS += v16`                                             |                    |
| OP_LEF4 v16       | LEF4                               | `OS -= 2; PC += v16 if R1 <= R0`                         | float              |
| OP_LEI3 v16       | LEI3                               | `OS -= 2; PC += v16 if R1 <= R0`                         | int24              |
| OP_LEI4 v16       | LEI4                               | `OS -= 2; PC += v16 if R1 <= R0`                         | int32              |
| OP_LEU3 v16       | LEU3                               | `OS -= 2; PC += v16 if R1 <= R0`                         | uint24             |
| OP_LEU4 v16       | LEU4                               | `OS -= 2; PC += v16 if R1 <= R0`                         | uint32             |
| OP_LOAD1          | INDIRI1, INDIRU1                   | `*OS = *R0`                                             | (u)int8            |
| OP_LOAD2          | INDIRI2, INDIRU2                   | `*OS = *R0`                                             | (u)int16           |
| OP_LOAD3          | INDIRI3                            | `*OS = *R0`                                             | (u)int24           |
| OP_LOAD4          | INDIRI4, INDIRP4, INDIRU4, INDIRF4 | `*OS = *R0`                                             | (u)int32/float     |
| OP_LOCAL v16      | ADDRFP4, ADDRLP4                   | `OS++; *OS = &PS[v16]`                                  | ptr                |
| OP_LSH3           | LSHI3, LSHU3                       | `OS--; *OS = R1 << R0`                                  | (u)int24           |
| OP_LSH4           | LSHI4, LSHU4                       | `OS--; *OS = R1 << R0`                                  | (u)int32           |
| OP_LTF4 v16       | LTF4                               | `OS -= 2; PC += v16 if R1 < R0`                          | float              |
| OP_LTI3 v16       | LTI3                               | `OS -= 2; PC += v16 if R1 < R0 `                         | int24              |
| OP_LTI3 v16       | LTI3                               | `OS -= 2; PC += v16 if R1 < R0 `                         | int32              |
| OP_LTU3 v16       | LTU3                               | `OS -= 2; PC += v16 if R1 >= R0 `                        | uint23             |
| OP_LTU4 v16       | LTU4                               | `OS -= 2; PC += v16 if R1 >= R0 `                        | uint32             |
| OP_MODI3          | MODI3                              | `OS--; *OS = R1 % R0`                                   | int24              |
| OP_MODI4          | MODI4                              | `OS--; *OS = R1 % R0`                                   | int32              |
| OP_MODU3          | MODU3                              | `OS--; *OS = R1 % R0;`                                  | uint24             |
| OP_MODU4          | MODU4                              | `OS--; *OS = R1 % R0;`                                  | uint32             |
| OP_MULF4          | OP_MULF4                           | `OS--; *OS = R1 * R0`                                   | float              |
| OP_MULI3          | MULI3                              | `OS--; *OS = R1 * R0`                                   | int24              |
| OP_MULI4          | MULI4                              | `OS--; *OS = R1 * R0`                                   | int32              |
| OP_MULU3          | MULU3                              | `OS--; *OS = R1 * R0`                                   | uint24             |
| OP_MULU4          | MULU4                              | `OS--; *OS = R1 * R0`                                   | uint32             |
| OP_NE3 v16        | NEI3, NEU3                         | `OS -= 2; PC += v16 if R1 != R0`                         | (u)int24           |
| OP_NE4 v16        | NEI4, NEU4                         | `OS -= 2; PC += v16 if R1 != R0`                         | (u)int32           |
| OP_NEF4 v16       | NEF4                               | `OS -= 2; PC += v16 if R1 != R0`                         | float              |
| OP_NEGF4          | NEGF4                              | `*OS = -R0`                                             | float              |
| OP_NEGI3          | NEGI3                              | `*OS = -R0`                                             | int24              |
| OP_NEGI4          | NEGI4                              | `*OS = -R0`                                             | int32              |
| OP_POP            | POP                                | `OS--`                                                  |                    |
| OP_PUSH           | ENDPROC                            | `OS++`                                                  |                    |
| OP_RSHI3          | RSHI3                              | `OS--; *OS = R1 >> R0`                                  | int24              |
| OP_RSHI4          | RSHI4                              | `OS--; *OS = R1 >> R0`                                  | int32              |
| OP_RSHU3          | RSHU3                              | `OS--; *OS = R1 >> R0`                                  | uint24             |
| OP_RSHU4          | RSHU4                              | `OS--; *OS = R1 >> R0`                                  | uint32             |
| OP_STORE1         | ASGNI1, ASGNU1                     | `OS - =2; *R1 = R0`                                     | (u)int8, ptr       |
| OP_STORE2         | ASGNI2, ASGNU2                     | `OS - =2; *R1 = R0`                                     | (u)int16, ptr      |
| OP_STORE3         | ASGNI3, ASGNP3, ASGNU3, ASGNF3     | `OS - =2; *R1 = R0`                                     | (u)int24/ptr, ptr  |
| OP_STORE4         | ASGNI4, ASGNU4, ASGNF4             | `OS - =2; *R1 = R0`                                     | (u)int32/float,ptr |
| OP_SUB3           | SUBI3, SUBU4                       | `OS--; *OS = R1 - R0`                                   | (u)int24           |
| OP_SUB4           | SUBI4, SUBU4                       | `OS--; *OS = R1 - R0`                                   | (u)int32           |
| OP_SUBF4          | SUBF4                              | `OS--; *OS = R1 - R0`                                   | float              |
