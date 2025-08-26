## Op byte codes


### Valid Opcode Param types:

 * v: int32_t
 * v24: uint24_t
 * v16: uint16_t
 * v8: uint8_t
 * iv8: int8_t


### Registers
* PC => Program Counter
* PS => Program Stack
* OS => Operation Stack (stack of `int32_t` types)
* R0: *OS
* R1: *(OS - 1)  # OS-1 is converted to uint8_t and wraps ? not sure why?

### Implemented Opcode functions

| Op Code           | LCC Code                       | Description                                                   |
| ----------------- | ------------------------------ | ------------------------------------------------------------- |
| OP_UNDEF          | CVFt, LOADt                    | `Undefined?`                                                  |
| OP_IGNORE         |                                | Special code that is never emitted                            |
| OP_BREAK          | BREAK                          | `with DEBUG_VM defined, breaks into a debug mode`             |
| OP_ENTER v16      | PROC                           | `PS -= v16`                                                   |
| OP_LEAVE v16      | RET, ENDPROC                   | `PS += v16`                                                   |
| OP_CALL           | CALL                           | `*PS = PC; PC = *OS--; if PC < 0, invoke a System Call`       |
| OP_PUSH           | ENDPROC                        | `OS++`                                                        |
| OP_POP            | POP                            | `OS--`                                                        |
| OP_CONSTGP3 v24   | ADDRGP3                        | `OS++; *OS = v24`                                             |
| OP_CONSTP3 v24    | CNSTP4                         | `OS++; *OS = (int32)v24`                                      |
| OP_CONSTU1 v8     | CNSTU1                         | `OS++; *OS = (uint32)v8`                                      |
| OP_CONSTI1 iv8    | CNSTI1                         | `OS++; *OS = (int32)iv8`                                      |
| OP_CONSTU2 v16    | CNSTU2                         | `OS++; *OS = (uint32)v16`                                     |
| OP_CONSTI2 iv16   | CNSTI2                         | `OS++; *OS = (int32)iv16`                                     |
| OP_CONSTU4 v32/f  | CNSTU4, CNSTF4                 | `OS++; *OS = v32/f`                                           |
| OP_CONSTI4 v32    | CNSTI4                         | `OS++; *OS = (int32)v32`                                      |
| OP_LOCAL v16      | ADDRFP4, ADDRLP4               | `OS++; *OS = &PS[v16]`                                        |
| OP_JUMP           | JUMPV                          | `PC = R0; OS--;`                                              |
| OP_EQ4 v          | EQI4, EQU4                     | `OS -= 2; PC = R1 == R0 ? v : sizeof(v)`                      |
| OP_NE4 v          | NEI4, NEU4                     | `OS -= 2; PC = R1 != R0 ? v : sizeof(v)`                      |
| OP_LTI4           | LTI4                           | `OS -= 2; PC = R1 < R0 ? v : sizeof(v) `                      |
| OP_LEI4           | LEI4                           | `OS -= 2; PC = R1 <= R0 ? v : sizeof(v)`                      |
| OP_GTI4           | GTI4                           | `OS -= 2; PC = R1 > R0 ? v : sizeof(v) `                      |
| OP_GEI4           | GEI4                           | `OS -= 2; PC = R1 >= R0 ? v : sizeof(v)`                      |
| OP_LTU            | LTU4                           | `OS -= 2; PC = (uint32_t)R1 >= (uint32_t)R0 ? v : sizeof(v) ` |
| OP_LEU4            | LEU4                           | `OS -= 2; PC = (uint32_t)R1 <= (uint32_t)R0 ? v : sizeof(v) ` |
| OP_GTU4           | GTU4                           | `OS -= 2; pc = (uint32_t)R1 > (uint32_t)R0 ? v : sizeof(v)  ` |
| OP_GEU4           | GEU4                           | `OS -= 2; PC = (uint32_t)R1 >= (uint32_t)R0 ? v : sizeof(v) ` |
| OP_EQF4           | EQF4                           | `OS -= 2; PC = (float)R1 == (float)R0 ? v : sizeof(v)`        |
| OP_NEF            | NEF4                           | `OS -= 2; PC = (float)R1 != (float)R0 ? v : sizeof(v)`        |
| OP_LTF            | LTF4                           | `OS -= 2; PC = (float)R1 < (float)R0 ? v : sizeof(v)`         |
| OP_LEF4            | LEF4                           | `OS -= 2; PC = (float)R1 <= (float)R0 ? v : sizeof(v)`        |
| OP_GTF4           | GTF4                           | `OS -= 2; PC = (float)R1 > (float)R0 ? v : sizeof(v)`         |
| OP_GEF4           | GEF                            | `OS -= 2; PC = (float)R1 >= (float)R0 ? v : sizeof(v)`        |
| OP_LOAD1          | INDIRI1, INDIRU1               | `*OS = *((int8_t*)R0)`                                        |
| OP_LOAD2          | INDIRI2, INDIRU2               | `*OS = *((int16_t*)R0)`                                       |
| OP_LOAD3          | INDIRI3                        | `*OS = *((int24_t*)R0)`                                       |
| OP_LOAD4          | INDIRI4, INDIRP4, INDIRU4      | `*OS = *((int32_t*)R0)`                                       |
| OP_LOAD4         | INDIRF4                        | `*OS = *((float*)R0)`                                         |
| OP_STORE1         | ASGNI1, ASGNU1                 | `OS - =2; *((uint8_t)R1) = R0`                                |
| OP_STORE2         | ASGNI2, ASGNU2                 | `OS - =2; *((uint16_t)R1) = R0`                               |
| OP_STORE4         | ASGNI4, ASGNP4, ASGNU4, ASGNF4 | `OS - =2; *((uint32_t)R1) = R0`                               |
| OP_ARG v8         | ARGt                           | `OS--; PS[v8]= R0`                                            |
| OP_BLOCK_COPY v24 | ASGNB                          | `memcpy(R1, R0, v24); OS -= 2`                                |
| OP_CI1I4          | CVII4 1                        | `*OS = (int32_t)(int8_t)*OS`                                  |
| OP_CI2I4          | CVII4 2                        | `*OS = (int32_t)(int16_t)*OS`                                 |
| OP_NEGI4          | NEGI4                          | `*OS = -R0`                                                   |
| OP_ADD4           | ADDP, ADDI4, ADDP4, ADDU4      | `OS--; *OS = R1 + R0`                                         |
| OP_SUB4           | SUBI4, SUBP4, SUBU4            | `OS--; *OS = R1 - R0`                                         |
| OP_DIVI4           | DIVI4                          | `OS--; *OS = R1 / R0`                                         |
| OP_DIVU4           | DIVU4                          | `OS--; *OS = (uint32_t)R1) / (uint32_t)R0`                    |
| OP_MODI4          | MODI4                          | `OS--; *OS = R1 % R0`                                         |
| OP_MODU4          | MODU4                          | `OS--; *OS = (uint32_t)R1 % (uint32_t)R0;`                    |
| OP_MULI4          | MULI4                          | `OS--; *OS = R1 * R0`                                         |
| OP_MULU4          | MULU4                          | `OS--; *OS = (uint32_t)R1 * (uint32_t)R0`                     |
| OP_BAND4          | BANDI4, BANDU4                 | `OS--; *OS = (uint32_t)R1 & (uint32_t)R0`                     |
| OP_BOR4           | BORI4, BORU4                   | `OS--; *OS = (uint32_t)R1 \| (uint32_t)R0`                    |
| OP_BXOR4          | BXORI4,BXORU4                  | `OS--; *OS = (uint32_t)R1 ^ (uint32_t)R0`                     |
| OP_BCOM4          | BCOMI4, BCOMU4                 | `OS--; *OS = ~(uint32_t)R0`                                   |
| OP_LSH4           | LSHI4, LSHU4                   | `OS--; *OS = R1 << R0`                                        |
| OP_RSHI4          | RSHI4                          | `OS--; *OS = R1 >> R0`                                        |
| OP_RSHU4          | RSHU4                          | `OS--; *OS = (uint32_t)R1 >> R0`                              |
| OP_NEGF4          | NEGF4                          | `*OS = -(float)R0`                                            |
| OP_ADDF4          | ADDF4                          | `OS--; *OS = (float)R1 + (float)R0`                           |
| OP_SUBF4          | SUBF4                          | `OS--; *OS = (float)R1 - (float)R0`                           |
| OP_DIVF4          | DIVF4                          | `OS--; *OS = (float)R1 / (float)R0`                           |
| OP_MULF4          | OP_MULF4                       | `OS--; *OS = (float)R1 * (float)R0`                           |
| OP_CI4F4          | CVIF4                          | `*OS = convertToInt((float)*OS)`                              |
| OP_CF4I4          | CVFI4                          | `*OS = convertToFloat(*OS)`                                   |

> int to float does not perform numerical conversion - assumes the int is actually a float representation

