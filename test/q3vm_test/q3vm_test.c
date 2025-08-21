/*
      ___   _______     ____  __
     / _ \ |___ /\ \   / /  \/  |
    | | | |  |_ \ \ \ / /| |\/| |
    | |_| |____) | \ V / | |  | |
     \__\_______/   \_/  |_|  |_|


   Quake III Arena Virtual Machine
*/

#include "vm.h"
#include <stdio.h>
#include <stdlib.h>

/* The compiled bytecode calls native functions,
   defined in this file. */
uint32_t systemCalls(vm_t *vm, uint8_t *args);

/* Load an image from a file. Data is allocated with malloc.
   Call free() to unload image. */
uint8_t *loadImage(const char *filepath, int *size);

uint8_t dataSegment[0x8000];

int testInject(const char *filepath, int offset, int opcode) {
  vm_t     vm;
  int      imageSize;
  uint8_t *image  = loadImage(filepath, &imageSize);
  int      retVal = -1;

  if (!image) {
    fprintf(stderr, "Failed to load bytecode image from %s\n", filepath);
    return retVal;
  }

  fprintf(stderr, "Injecting wrong OP code %s at %i: %i\n", filepath, offset, opcode);
  memcpy(&image[offset], &opcode, sizeof(opcode)); /* INJECT */
  retVal = VM_Create(&vm, image, imageSize, dataSegment, sizeof(dataSegment), systemCalls);
  free(image);

  return (retVal == -1) ? 0 : -1;
}

#ifdef DEBUG_VM
static void COM_StripExtension(const char *in, char *out) {
  while (*in && *in != '.') {
    *out++ = *in++;
  }
  *out = 0;
}
#endif

int testNominal(const char *filepath) {
  vm_t     vm;
  int      imageSize;
  uint8_t *image       = loadImage(filepath, &imageSize);
  int      retVal      = -1;
  int      failedTests = 0;

  if (!image) {
    fprintf(stderr, "Failed to load bytecode image from %s\n", filepath);
    return retVal;
  }

  VM_Debug(3);
  if (VM_Create(&vm, image, imageSize, dataSegment, sizeof(dataSegment), systemCalls) == 0) {

#ifdef DEBUG_VM
    void *pDebugInfo = malloc(0x10000);
    int   mapFileImageSize;
    char  mapFilepath[VM_MAX_QPATH - 4];
    char  symbols[VM_MAX_QPATH];

    COM_StripExtension(filepath, mapFilepath);
    sprintf(symbols, "%s.map", mapFilepath);
    Com_Printf("Loading symbol file: %s...\n", symbols);

    char *mapFileImage = (char *)loadImage(symbols, &mapFileImageSize);
    VM_LoadDebugInfo(&vm, mapFileImage, pDebugInfo, 0x10000);
#endif

    /* normal call, should give us 0 */
    retVal = VM_Call(&vm, 0);
    if (retVal != 0 || vm.lastError != 0) {
      printf("Test RUN invoked at " __FILE__ " on line %d : failed.  retVal: %d, lastError: %d\n", __LINE__, retVal, vm.lastError);
      failedTests++;
    }

    /* now do the proper call, this should give us 333 */
    retVal = VM_Call(&vm, 0, 0, 1, 2);
    if (retVal != 333 || vm.lastError != 0) {
      printf("Test RUN invoked at " __FILE__ " on line %d : failed.  retVal: %d, lastError: %d\n", __LINE__, retVal, vm.lastError);
      failedTests++;
    }
    /* now do an invalid function call within the VM */
    retVal = VM_Call(&vm, 2);
    if (vm.lastError != VM_PC_OUT_OF_RANGE) {
      printf("Test RUN invoked at " __FILE__ " on line %d : failed.  retVal: %d, lastError: %d\n", __LINE__, retVal, vm.lastError);
      failedTests++;
    }
  }
  VM_VmProfile_f(&vm);
  free(image);

  if (failedTests == 0) {
    printf("All tests passed [x]\n");
    return 0;
  } else {
    printf("Test suite failed!!! [ ]\n");
    return -1;
  }
}

void testArguments(void) {
  vm_t vm = {0};
  int  imageSize;

  vm.codeLength = 0;
  VM_Call(&vm, 0);

  VM_ArgPtr(0, NULL);
  VM_ArgPtr(1, NULL);
  VM_MemoryRangeValid(0, 0, NULL);
  loadImage(NULL, &imageSize);

  loadImage("invalidpathfoobar", &imageSize);

  VM_Create(NULL, NULL, 0, dataSegment, sizeof(dataSegment), NULL);
  printf("3\r\n");
  VM_Create(&vm, NULL, 0, dataSegment, sizeof(dataSegment), NULL);
  VM_Create(&vm, NULL, 0, dataSegment, sizeof(dataSegment), systemCalls);
  VM_Create(&vm, NULL, 0, dataSegment, sizeof(dataSegment), systemCalls);

  uint8_t bogus[] = "bogusbogusbogubogusbogus"
                    "bogusbogusbogubogusbogus"
                    "bogusbogusbogubogusbogus"
                    "bogusbogusbogubogusbogus";
  VM_Create(&vm, bogus, sizeof(bogus), dataSegment, sizeof(dataSegment), NULL);
  VM_Create(&vm, bogus, sizeof(bogus), dataSegment, sizeof(dataSegment), systemCalls);
  VM_Create(&vm, bogus, sizeof(vmHeader_t) - 4, dataSegment, sizeof(dataSegment), systemCalls);

  vmHeader_t vmHeader       = {0};
  vmHeader.vmMagic          = VM_MAGIC;
  vmHeader.instructionCount = to_uint24(1000);
  vmHeader.codeLength       = to_uint24(1024);
  vmHeader.dataLength       = to_uint24(2048);
  vmHeader.litLength        = to_uint24(0);
  vmHeader.bssLength        = to_uint24(256);

  printf("8\r\n");

  VM_Create(&vm, (uint8_t *)&vmHeader,
            sizeof(vmHeader_t) + to_ustdint(vmHeader.codeLength) + to_ustdint(vmHeader.dataLength) +
                to_ustdint(vmHeader.litLength) - 1,
            dataSegment, sizeof(dataSegment), systemCalls);

  VM_Call(NULL, 0);

  vm.callLevel = 1;
}

int main(int argc, char **argv) {
  const char *files[] = {"test.qvm", argv[argc > 1]};
  const char *file    = files[argc > 1];

  printf("\nExpect Negative assertions:\n");
  testArguments();

  testInject(NULL, 0, 0);
  testNominal(NULL);
  testInject(file, 32, 0);
  testInject(file, 32, 63);
  testInject(file, 32, 65);
  testInject(file, 4, -1);

  printf("Completed Expected Negative Assertions\n");

  /* finally: test the normal case */
  return testNominal(file);
}

#ifdef DEBUG_VM
void Com_Error(vmErrorCode_t level, const char *error) { fprintf(stderr, "Err(%i): %s\n", level, error); }
#endif

uint8_t *loadImage(const char *filepath, int *size) {
  FILE    *f;            /* bytecode input file */
  uint8_t *image = NULL; /* bytecode buffer */
  int      sz;           /* bytecode file size */

  if (!filepath || filepath[0] == '\0') {
    return NULL;
  }

  *size = 0;
  f     = fopen(filepath, "rb");
  if (!f) {
    fprintf(stderr, "Failed to open file %s.\n", filepath);
    return NULL;
  }
  /* calculate file size */
  fseek(f, 0L, SEEK_END);
  sz = ftell(f);
  /*
  if (sz < 1)
  {
      fclose(f);
      return NULL;
  }
  */
  rewind(f);

  image = (uint8_t *)malloc(sz);
  /*
  if (!image)
  {
      fclose(f);
      return NULL;
  }
  */

  fread(image, 1, sz, f);
  fclose(f);
  *size = sz;
  return image;
}

/* Callback from the VM: system function call */
uint32_t systemCalls(vm_t *vm, uint8_t *args) {
  const int id = -1 - VMA_UINT24(0);

  switch (id) {
  case -1: /* PRINTF */
    return printf("%s", (const char *)VMA_PTR(3, vm));

  case -2: /* ERROR */
    return fprintf(stderr, "%s", (const char *)VMA_PTR(3, vm));

  case -3: /* MEMSET */
    if (VM_MemoryRangeValid(VMA_UINT24(3) /*addr*/, VMA_UINT24(9) /*len*/, vm) == 0) {
      memset(VMA_PTR(3, vm), VMA_UINT24(6), VMA_UINT24(9));
    }
    return VMA_UINT24(3);

  case -4: /* MEMCPY */
    if (VM_MemoryRangeValid(VMA_UINT24(3) /*addr*/, VMA_UINT24(9) /*len*/, vm) == 0 &&
        VM_MemoryRangeValid(VMA_UINT24(6) /*addr*/, VMA_UINT24(9) /*len*/, vm) == 0) {
      memcpy(VMA_PTR(3, vm), VMA_PTR(6, vm), VMA_UINT24(9));
    }
    return VMA_UINT24(3);

  case -6: /* FLOATFF */
    return VM_FloatToInt(VMA_F4(3) * 2.0f);

  case -7: /* RECURSIVE */
    return VM_Call(vm, 1, VMA_UINT24(3));

  default:
    fprintf(stderr, "Bad system call: %ld\n", (long int)args[0]);
  }
  return 0;
}
