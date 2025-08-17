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
  VM_Free(&vm);
  free(image);

  return (retVal == -1) ? 0 : -1;
}

int testNominal(const char *filepath) {
  vm_t     vm;
  int      imageSize;
  uint8_t *image  = loadImage(filepath, &imageSize);
  int      retVal = -1;

  if (!image) {
    fprintf(stderr, "Failed to load bytecode image from %s\n", filepath);
    return retVal;
  }

  VM_Debug(1);
  if (VM_Create(&vm, image, imageSize, dataSegment, sizeof(dataSegment), systemCalls) == 0) {
    /* normal call, should give us 0 */
    retVal = VM_Call(&vm, 0);
    /* now do the proper call, this should give us 333 */
    retVal += VM_Call(&vm, 0, 0, 1, 2);
    /* so now retVal should be 333 if everything is as expected */
    printf("Result (should be 333): %i\n", retVal);
    /* now do an invalid function call within the VM */
    retVal += (VM_Call(&vm, 2) + 1); /* we expect a -1, so we add a +1 to cancel it out */
  }
  VM_VmProfile_f(&vm);
  VM_Free(&vm);
  free(image);

  if (retVal == 333) {
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
  VM_Create(&vm, (uint8_t *)&vmHeader,
            sizeof(vmHeader_t) + to_ustdint(vmHeader.codeLength) + to_ustdint(vmHeader.dataLength) +
                to_ustdint(vmHeader.litLength) - 1,
            dataSegment, sizeof(dataSegment), systemCalls);

  VM_Call(NULL, 0);

  VM_Free(NULL);

  vm.callLevel = 1;
  VM_Free(&vm);
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

void Com_Error(vmErrorCode_t level, const char *error) { fprintf(stderr, "Err(%i): %s\n", level, error); }

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
