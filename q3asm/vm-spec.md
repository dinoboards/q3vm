## Op byte codes


### Valid Opcode Param types:

 * v: int32_t
 * v24: uint24_t
 * v16: uint16_t
 * v8: uint8_t


### Registers
* PC => Program Counter
* PS => Program Stack
* OS => Operation Stack (stack of `int32_t` types)
* R0: *OS
* R1: *(OS - 1)  # OS-1 is converted to uint8_t and wraps ? not sure why?

### Implemented Opcode functions

| Op Code           | Description                                                   |
| ----------------- | ------------------------------------------------------------- |
| OP_UNDEF          | `Undefined?`                                                  |
| OP_IGNORE         | Special code that is never emitted                            |
| OP_BREAK          | `with DEBUG_VM defined, breaks into a debug mode`             |
| OP_ENTER v16      | `PS -= v16`                                                   |
| OP_LEAVE v16      | `PS += v16`                                                   |
| OP_CALL           | `*PS = PC; PC = *OS--; if PC < 0, invoke a System Call`       |
| OP_PUSH           | `OS++`                                                        |
| OP_POP            | `OS--`                                                        |
| OP_CONST v        | `OS++; *OS = v`                                               |
| OP_CONSTU1 v8     | `OS++; *OS = (int32)v8`                                       |
| OP_LOCAL          | `OS++; *OS = PS[v]`                                           |
| OP_JUMP           | `PC = R0; OS--;`                                              |
| OP_EQ v           | `OS -= 2; PC = R1 == R0 ? v : sizeof(v)`                      |
| OP_NE v           | `OS -= 2; PC = R1 != R0 ? v : sizeof(v)`                      |
| OP_LTI            | `OS -= 2; PC = R1 < R0 ? v : sizeof(v) `                      |
| OP_LEI            | `OS -= 2; PC = R1 <= R0 ? v : sizeof(v)`                      |
| OP_GTI            | `OS -= 2; PC = R1 > R0 ? v : sizeof(v) `                      |
| OP_GEI            | `OS -= 2; PC = R1 >= R0 ? v : sizeof(v)`                      |
| OP_LTU            | `OS -= 2; PC = (uint32_t)R1 >= (uint32_t)R0 ? v : sizeof(v) ` |
| OP_LEU            | `OS -= 2; PC = (uint32_t)R1 <= (uint32_t)R0 ? v : sizeof(v) ` |
| OP_GTU            | `OS -= 2; PC = (uint32_t)R1 > (uint32_t)R0 ? v : sizeof(v)  ` |
| OP_GEU            | `OS -= 2; PC = (uint32_t)R1 >= (uint32_t)R0 ? v : sizeof(v) ` |
| OP_EQF            | `OS -= 2; PC = (float)R1 == (float)R0 ? v : sizeof(v)`        |
| OP_NEF            | `OS -= 2; PC = (float)R1 != (float)R0 ? v : sizeof(v)`        |
| OP_LTF            | `OS -= 2; PC = (float)R1 < (float)R0 ? v : sizeof(v)`         |
| OP_LEF            | `OS -= 2; PC = (float)R1 <= (float)R0 ? v : sizeof(v)`        |
| OP_GTF            | `OS -= 2; PC = (float)R1 > (float)R0 ? v : sizeof(v)`         |
| OP_GEF            | `OS -= 2; PC = (float)R1 >= (float)R0 ? v : sizeof(v)`        |
| OP_LOAD1          | `*OS = *((int8_t*)R0)`                                        |
| OP_LOAD2          | `*OS = *((int16_t*)R0)`                                       |
| OP_LOAD4          | `*OS = *((int32_t*)R0)`                                       |
| OP_STORE1         | `OS - =2; *((uint8_t)R1) = R0`                                |
| OP_STORE2         | `OS - =2; *((uint16_t)R1) = R0`                               |
| OP_STORE4         | `OS - =2; *((uint32_t)R1) = R0`                               |
| OP_ARG v          | `OS--; PS[v]= R0`                                             |
| OP_BLOCK_COPY v24 | `memcpy(R1, R0, v24); OS -= 2`                                |
| OP_SEX8           | `*OS = (int32_t)(int8_t)*OS`                                  |
| OP_SEX16          | `*OS = (int32_t)(int16_t)*OS`                                 |
| OP_NEGI           | `*OS = -R0`                                                   |
| OP_ADD            | `OS--; *OS = R1 + R0`                                         |
| OP_SUB            | `OS--; *OS = R1 - R0`                                         |
| OP_DIVI           | `OS--; *OS = R1 / R0`                                         |
| OP_DIVU           | `OS--; *OS = (uint32_t)R1) / (uint32_t)R0`                    |
| OP_MODI           | `OS--; *OS = R1 % R0`                                         |
| OP_MODU           | `OS--; *OS = (uint32_t)R1 % (uint32_t)R0;`                    |
| OP_MULI           | `OS--; *OS = R1 * R0`                                         |
| OP_MULU           | `OS--; *OS = (uint32_t)R1 * (uint32_t)R0`                     |
| OP_BAND           | `OS--; *OS = (uint32_t)R1 & (uint32_t)R0`                     |
| OP_BOR            | `OS--; *OS = (uint32_t)R1 \| (uint32_t)R0`                    |
| OP_BXOR           | `OS--; *OS = (uint32_t)R1 ^ (uint32_t)R0`                     |
| OP_BCOM           | `OS--; *OS = ~(uint32_t)R0`                                   |
| OP_LSH            | `OS--; *OS = R1 << R0`                                        |
| OP_RSHI           | `OS--; *OS = R1 >> R0`                                        |
| OP_RSHU           | `OS--; *OS = (uint32_t)R1 >> R0`                              |
| OP_NEGF           | `*OS = -(float)R0`                                            |
| OP_ADDF           | `OS--; *OS = (float)R1 + (float)R0`                           |
| OP_SUBF           | `OS--; *OS = (float)R1 - (float)R0`                           |
| OP_DIVF           | `OS--; *OS = (float)R1 / (float)R0`                           |
| OP_MULF           | `OS--; *OS = (float)R1 * (float)R0`                           |
| OP_CVIF           | `*OS = convertToInt((float)*OS)`                              |
| OP_CVFI           | `*OS = convertToFloat(*OS)`                                   |

> int to float does not perform numerical conversion - assumes the int is actually a float representation
