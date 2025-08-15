/*
      ___   _______     ____  __
     / _ \ |___ /\ \   / /  \/  |
    | | | |  |_ \ \ \ / /| |\/| |
    | |_| |____) | \ V / | |  | |
     \__\_______/   \_/  |_|  |_|


   Quake III Arena Virtual Machine
*/

#ifndef __Q3VM_H
#define __Q3VM_H

#include "target-support.h"

/******************************************************************************
 * SYSTEM INCLUDE FILES
 ******************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>  /* remove this if Com_Printf does not point to printf */
#include <string.h> /* remove this if Com_Mem*** does not point to memcpy */

/******************************************************************************
 * DEFINES
 ******************************************************************************/

#if 1
extern int snprintf(char *__restrict __s, size_t __maxlen, const char *__restrict __format, ...) __THROWNL
    __attribute__((__format__(__printf__, 3, 4)));

extern size_t strlcpy(char *dst, const char *src, size_t size);

#define DEBUG_VM /**< ifdef: enable debug functions and additional checks */
#endif

/** File start magic number for .qvm files (4 bytes, little endian) */
#define VM_MAGIC 0x44494E4F

/** Don't change stack size: Hardcoded in q3asm and reserved at end of BSS */
#define VM_PROGRAM_STACK_SIZE 0x1000

/** Max. number of bytes in .qvm */
#define VM_MAX_IMAGE_SIZE 0x400000

/**< Maximum length of a pathname, 64 to be Q3 compatible */
#define VM_MAX_QPATH 64

/** Redirect printf() calls with this macro */
#define Com_Printf printf

/** Redirect memset() calls with this macro */
#define Com_Memset memset

/** Redirect memcpy() calls with this macro */
#define Com_Memcpy memcpy

/** Translate from virtual machine memory to real machine memory. */
#define VMA(x, vm) VM_ArgPtr(args[x], vm)

/** Get argument in syscall and interpret it bit by bit as IEEE 754 float */
#define VMF(x) VM_IntToFloat(args[x])

typedef int std_int; /* can be a 32 or 24 bit number - depending on target CPU */

typedef int32_t vm_operand_t; /* int to store registers and instruction operand values */

/******************************************************************************
 * TYPEDEFS
 ******************************************************************************/

/** VM error codes */
typedef enum {
  VM_NO_ERROR                    = 0,   /**< 0 = OK */
  VM_INVALID_POINTER             = -1,  /**< NULL pointer for vm_t */
  VM_FAILED_TO_LOAD_BYTECODE     = -2,  /**< Invalid byte code */
  VM_NO_SYSCALL_CALLBACK         = -3,  /**< Syscall pointer missing */
  VM_FREE_ON_RUNNING_VM          = -4,  /**< Call to VM_Free while running */
  VM_BLOCKCOPY_OUT_OF_RANGE      = -5,  /**< VM tries to escape sandbox */
  VM_PC_OUT_OF_RANGE             = -6,  /**< Program counter out of range */
  VM_JUMP_TO_INVALID_INSTRUCTION = -7,  /**< VM tries to escape sandbox */
  VM_STACK_OVERFLOW              = -8,  /**< Only in DEBUG_VM mode */
  VM_STACK_ERROR                 = -11, /**< Stack corrupted after call */
  VM_DATA_OUT_OF_RANGE           = -12, /**< Syscall pointer not in sandbox */
  VM_MALLOC_FAILED               = -13, /**< Not enough memory */
  VM_BAD_INSTRUCTION             = -14, /**< Unknown OP code in bytecode */
  VM_NOT_LOADED                  = -15, /**< VM not loaded */
  VM_NOT_ENOUGH_RAM              = -16, /**< insufficient ram allocated for VM */
  VM_MALFORMED_HEADER            = -17,
  VM_ILLEGAL_OPCODE              = -18
} vmErrorCode_t;

/** File header of a bytecode .qvm file. Can be directly mapped to the start of
 *  the file. This is always little endian encoded in the file. */
typedef struct {
  uint32_t vmMagic;          /**< 00: Bytecode image shall start with VM_MAGIC */
  uint24_t instructionCount; /**< 04: Number of instructions in .qvm */
  uint24_t codeLength;       /**< 07: Bytes in code segment */
  uint24_t litLength;        /**< 0A: Bytes in strings segment (after .data segment) */
  uint24_t dataLength;       /**< 0D: Bytes in .data segment */
  uint24_t bssLength;        /**< 10: How many bytes should be used for .bss segment */
} vmHeader_t;

#ifdef DEBUG_VM
/** For debugging (DEBUG_VM): symbol list */
typedef struct vmSymbol_s {
  struct vmSymbol_s *next; /**< Linked list of symbols */

  int symValue;      /**< Value of symbol that we want to have the ASCII name for
                      */
  int  profileCount; /**< For the runtime profiler. +1 for each call. */
  char symName[1];   /**< Variable sized symbol name. Space is reserved by
                        malloc at load time. */
} vmSymbol_t;
#endif

/** Main struct (think of a kind of a main class) to keep all information of
 * the virtual machine together. Has pointer to the bytecode, the stack and
 * everything. Call VM_Create(...) to initialize this struct. Call VM_Free(...)
 * to cleanup this struct and free the memory. */
typedef struct vm_s {
  /** Function pointer to callback function for native functions called by
   * the bytecode. The function is identified by an integer id that
   * corresponds to the bytecode function ids defined in g_syscalls.asm.
   * Note however that parms equals to (-1 - function_id).
   * So -1 in g_syscalls.asm equals to 0 in the systemCall parms argument,
   *    -2 in g_syscalls.asm equals to 1 in the systemCall parms argument,
   *    -3 in g_syscalls.asm equals to 2 in the systemCall parms argument
   * and so on. You can convert it back to -1, -2, -3, but the 0 based
   * index might help a lookup table. */
  intptr_t (*systemCall)(struct vm_s *vm, intptr_t *parms);

  /*------------------------------------*/

  ustdint_t instructionCount; /**< Number of instructions for VM */

  const uint8_t *codeBase;   /**< Bytecode code segment in ROM */
  vm_size_t      codeLength; /**< Number of bytes in code segment */

  const uint8_t *litBase;   /* Start of the lit segment in ROM */
  vm_size_t      litLength; /* length of the lit segment*/

  uint8_t  *dataBase; /* Not the actual start location.  Its a calculated offset - workingRam - litLength */
  vm_size_t dataLength;

  uint8_t  *bssBase; /* Calculated offset of BSS base in RAM */
  vm_size_t bssLength;

  vm_size_t programStack; /* Index of current stack in RAM - initialised at top of RAM */

  vm_size_t workingRAMLength; /**< Number of bytes allocated for dataBase */

  /*
  stackBottom = workingRamLength - (dataLength + bssLength)

  */
#ifdef DEBUG_VM
  uint8_t  *debugStorage;
  stdint_t  debugStorageLength;
  vm_size_t stackBottom; /**< If programStack < stackBottom, error */
#endif

  /*------------------------------------*/

#ifdef DEBUG_VM
  std_int     numSymbols;    /**< Number of symbols from VM_LoadSymbols */
  vmSymbol_t *symbols;       /**< By VM_LoadSymbols: names for debugging */
  std_int     breakFunction; /**< For debugging: break at this function */
  std_int     breakCount;    /**< Used for breakpoints, triggered by OP_BREAK */
#endif

  /* TODO: this probably can be changed to a uint16_t */
  ustdint_t callLevel; /**< Counts recursive VM_Call */

  vmErrorCode_t lastError; /**< Last known error */
} vm_t;

/******************************************************************************
 * FUNCTION PROTOTYPES
 ******************************************************************************/

/** Initialize a virtual machine.
 * @param[out] vm Pointer to a virtual machine to initialize.
 * @param[in] module Path to the bytecode file. Used to load the
 *                   symbols. Otherwise not strictly required.
 * @param[in] bytecode Pointer to the bytecode. Directly byte by byte
 *                     the content of the .qvm file.
 * @param[in] length Number of bytes in the bytecode array.
 * @param[in] systemCalls Function pointer to callback function for native
 *   functions called by the bytecode. The function is identified by an integer
 *   id that corresponds to the bytecode function ids defined in g_syscalls.asm.
 *   Note however that parms equals to (-1 - function_id). So -1 in
 *   g_syscalls.asm equals to 0 in the systemCall parms argument, -2 in
 *   g_syscalls.asm is 1 in parms, -3 is 2 and so on.
 * @return 0 if everything is OK. -1 if something went wrong. */
bool VM_Create(vm_t                *vm,
               const uint8_t *const bytecode,
               const vm_size_t      length,
               uint8_t *const       dataSegment,
               const vm_size_t      dataSegmentLength,
               intptr_t (*systemCalls)(vm_t *, intptr_t *));

#ifdef DEBUG_VM
int VM_LoadDebugInfo(vm_t *vm, char *mapfileImage, uint8_t *debugStorage, int debugStorageLength);
#endif

/** Free the memory of the virtual machine.
 * @param[in] vm Pointer to initialized virtual machine. */
void VM_Free(vm_t *vm);

/** Run a function from the virtual machine.
 * Use the command argument to tell the VM what to do.
 * You can supply additional (up to (`MAX_VMMAIN_ARGS`-1)) parameters to pass to the bytecode.
 * @param[in] vm Pointer to initialized virtual machine.
 * @param[in] command Basic parameter passed to the bytecode.
 * @return Return value of the function call by the VM. */
intptr_t VM_Call(vm_t *vm, ustdint_t command, ...);

/** Helper function for syscalls VMA(x) macro:
 * Translate from virtual machine memory to real machine memory.
 * If this is a memory range, use the VM_MemoryRangeValid() function to
 * make sure that this syscall does not escape from the sandbox.
 * @param[in] vmAddr Address in virtual machine memory
 * @param[in,out] vm Current VM
 * @return translated address. */
void *VM_ArgPtr(intptr_t vmAddr, vm_t *vm);

/** Helper function for syscalls VMF(x) macro:
 * Get argument in syscall and interpret it bit by bit as IEEE 754 float.
 * That is: just put the int32_t in a float/int32_t union and return the float.
 * If the VM calls a native function with a float argument: don't
 * cast the in32_t argument to a float, but rather interpret it directly
 * as a floating point variable.
 * @param[in] x Argument on call stack.
 * @return Value as float. */
float VM_IntToFloat(int32_t x);

/** Helper function for syscalls:
 * Just put the float in a float/int32_t union and return the int32_t.
 * @param[in] f Floating point number.
 * @return Floating point number as integer */
int32_t VM_FloatToInt(float f);

/** Helper function for syscalls:
 * Check if address + range in in the valid VM memory range.
 * Use this function in the syscall callback to keep the VM in its sandbox.
 * @param[in] vmAddr Address in virtual machine memory
 * @param[in] len Length in bytes
 * @param[in] vm Current VM
 * @return 0 if valid (!), -1 if invalid. */
bool VM_MemoryRangeValid(const vm_size_t vmAddr, const vm_size_t len, const vm_t *const vm);

#ifdef DEBUG_VM
/** Print call statistics for every function. Only works with DEBUG_VM.
 * Does nothing if DEBUG_VM is not defined.
 * @param[in] vm VM to profile */
void VM_VmProfile_f(vm_t *vm);

/** Set the printf debug level. Only useful with DEBUG_VM.
 * Set to 1 for general informations and 2 to output every opcode name.
 * @param[in] level If level is 0: be quiet (default). */
void VM_Debug(uint8_t level);
#else
#define VM_VmProfile_f(a)
#define VM_Debug(a)
#endif

/******************************************************************************
 * CALLBACK FUNCTIONS (USER DEFINED IN HOST APPLICATION)
 ******************************************************************************/

/** Implement this error callback function for error callbacks in the host
 * application.
 * @param[in] level Error identifier, see vmErrorCode_t.
 * @param[in] error Human readable error text. */
void Com_Error(vmErrorCode_t level, const char *error);

/** Enum for the virtual machine op codes */
typedef enum : uint8_t {
  OP_UNDEF,      /* 00: Error: VM halt */
  OP_IGNORE,     /* 01: No operation */
  OP_BREAK,      /* 02: vm->breakCount++ */
  OP_ENTER,      /* 03: Begin subroutine. */
  OP_LEAVE,      /* 04: End subroutine. */
  OP_CALL,       /* 05: Call subroutine. */
  OP_PUSH,       /* 06: Push to stack. */
  OP_POP,        /* 07: Discard top-of-stack. */
  OP_CONSTGP4,   /* 08: Load constant to stack. */
  OP_LOCAL,      /* 09: Get local variable. */
  OP_JUMP,       /* 0A: Unconditional jump. */
  OP_EQ,         /* 0B: Compare integers, jump if equal. */
  OP_NE,         /* 0C: Compare integers, jump if not equal. */
  OP_LTI,        /* 0D: Compare integers, jump if less-than. */
  OP_LEI,        /* OE: Compare integers, jump if less-than-or-equal. */
  OP_GTI,        /* 0F: Compare integers, jump if greater-than. */
  OP_GEI,        /* 10: Compare integers, jump if greater-than-or-equal. */
  OP_LTU,        /* 11: Compare unsigned integers, jump if less-than */
  OP_LEU,        /* 12: Compare unsigned integers, jump if less-than-or-equal */
  OP_GTU,        /* 13: Compare unsigned integers, jump if greater-than */
  OP_GEU,        /* 14: Compare unsigned integers, jump if greater-than-or-equal */
  OP_EQF,        /* 15: Compare floats, jump if equal */
  OP_NEF,        /* 16: Compare floats, jump if not-equal */
  OP_LTF,        /* 17: Compare floats, jump if less-than */
  OP_LEF,        /* 18: Compare floats, jump if less-than-or-equal */
  OP_GTF,        /* 19: Compare floats, jump if greater-than */
  OP_GEF,        /* 1A: Compare floats, jump if greater-than-or-equal */
  OP_LOAD1,      /* 1B: Load 1-byte from memory */
  OP_LOAD2,      /* 1C: Load 2-bytes from memory */
  OP_LOAD4,      /* 1D: Load 4-bytes from memory */
  OP_LOADF4,     /* 1E: Load 4 byte float from memory */
  OP_STORE1,     /* 1F: Store 1-byte to memory */
  OP_STORE2,     /* 20: Store 2-byte to memory */
  OP_STORE4,     /* 21: *(stack[top-1]) = stack[top] */
  OP_STOREF4,    /* 22: *(stack[top-1]) = stack[top] */
  OP_ARG,        /* 23: Marshal argument */
  OP_BLOCK_COPY, /* 24: memcpy */
  OP_SEX8,       /* 25: Sign-Extend 8-bit */
  OP_SEX16,      /* 26: Sign-Extend 16-bit */
  OP_NEGI,       /* 27: Negate integer. */
  OP_ADD,        /* 28: Add integers (two's complement). */
  OP_SUB,        /* 29: Subtract integers (two's complement). */
  OP_DIVI,       /* 2A: Divide signed integers. */
  OP_DIVU,       /* 2B: Divide unsigned integers. */
  OP_MODI,       /* 2C: Modulus (signed). */
  OP_MODU,       /* 2D: Modulus (unsigned). */
  OP_MULI,       /* 2E: Multiply signed integers. */
  OP_MULU,       /* 2F: Multiply unsigned integers. */
  OP_BAND,       /* 30: Bitwise AND */
  OP_BOR,        /* 31: Bitwise OR */
  OP_BXOR,       /* 32: Bitwise eXclusive-OR */
  OP_BCOM,       /* 33: Bitwise COMplement */
  OP_LSH,        /* 34: Left-shift */
  OP_RSHI,       /* 35: Right-shift (algebraic; preserve sign) */
  OP_RSHU,       /* 36: Right-shift (bitwise; ignore sign) */
  OP_NEGF,       /* 37: Negate float */
  OP_ADDF,       /* 38: Add floats */
  OP_SUBF,       /* 39: Subtract floats */
  OP_DIVF,       /* 3A: Divide floats */
  OP_MULF,       /* 3B: Multiply floats */
  OP_CVIF,       /* 3C: Convert to integer from float */
  OP_CVFI,       /* 3D: Convert to float from integer */
  OP_CONSTU1,    /* 3E: */
  OP_CONSTI1,    /* 3F: */
  OP_CONSTU2,    /* 40: */
  OP_CONSTI2,    /* 41: */
  OP_CONSTU4,    /* 42: */
  OP_CONSTI4,    /* 43: */
  OP_CONSTF4,    /* 44: */
  OP_CONSTP4,    /* 45: */
  OP_LOAD3,      /* 46: Load 3-bytes from memory */
  OP_ADD3,
  OP_BAND3,
  OP_BCOM3,
  OP_BOR3,
  OP_BXOR3,
  OP_CONSTI3,
  OP_CONSTU3,
  OP_CVFI3,
  OP_CVIU3,
  OP_CVUI3,
  OP_DIVI3,
  OP_DIVU3,
  OP_EQ3,
  OP_GEI3,
  OP_GEU3,
  OP_GTI3,
  OP_GTU3,
  OP_LEI3,
  OP_LEU3,
  OP_LSH3,
  OP_LTI3,
  OP_LTU3,
  OP_MODI3,
  OP_MODU3,
  OP_MULI3,
  OP_MULU3,
  OP_NE3,
  OP_NEGI3,
  OP_RSHI3,
  OP_RSHU3,
  OP_SEX24,
  OP_SEX8_3,
  OP_STORE3,
  OP_SUB3,
  OP_CONSTGP3,
  OP_CONSTP3,

  OP_MAX /* ??: Make this the last item */
} opcode_t;

#endif /* __Q3VM_H */
