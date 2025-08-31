/*
      ___   _______     ____  __
     / _ \ |___ /\ \   / /  \/  |
    | | | |  |_ \ \ \ / /| |\/| |
    | |_| |____) | \ V / | |  | |
     \__\_______/   \_/  |_|  |_|


   Quake III Arena Virtual Machine

   Standalone host/interpreter: load a .qvm file, run it, exit.
   To implement the vm, only vm.c and vm.h are required.
   This file can be used as a template to integrate the VM in your application.
*/

#include "vm/vm.h"
#include <stdio.h>
#include <stdlib.h>

/* The compiled bytecode calls native functions, defined in this file.
 * Read README.md section "How to add a custom native function" for
 * details.
 * @param[in,out] vm Pointer to virtual machine, prepared by VM_Create.
 * @param[in,out] args Array with arguments of function call.
 * @return Return value handed back to virtual machine. */
uint32_t systemCalls(vm_t *vm, uint8_t *args);

/* Load an image from a file. Data is allocated with malloc.
   Call free() to unload image.
   @param[in] filepath Path to virtual machine binary file.
   @param[out] size File size in bytes is written to this memory location.
   @return Pointer to virtual machine image file (raw bytes). */
uint8_t *loadImage(const char *filepath, int *size);

#ifdef DEBUG_VM
static void COM_StripExtension(const char *in, char *out) {
  while (*in && *in != '.') {
    *out++ = *in++;
  }
  *out = 0;
}
#endif

/* Callback from the VM that something went wrong
 * @param[in] level Error id, see vmErrorCode_t definition.
 * @param[in] error Human readable error text. */
void vm_aborted_event(vmErrorCode_t level) { fprintf(stderr, "Err (%i)\n", level); }

int main(int argc, char **argv) {
  vm_t  vm;
  int   retVal = -1;
  int   imageSize;
  void *pData;

  if (argc < 2) {
    printf("No virtual machine supplied. Example: q3vm bytecode.qvm\n");
    return retVal;
  }

  /* load virtual machine image from file */
  char    *filepath = argv[1];
  uint8_t *image    = loadImage(filepath, &imageSize);
  if (!image) {
    return -1;
  }

  VM_Debug(4);

#define DATA_SIZE 4096
  pData = malloc(DATA_SIZE); /* allocate 64k ram for data, bss and stack*/

  /* set-up virtual machine */
  if (VM_Create(&vm, image, imageSize, pData, DATA_SIZE, systemCalls, vm_aborted_event) == 0) {
#ifdef DEBUG_VM
    void *pDebugInfo = malloc(0x10000);
    int   mapFileImageSize;
    char  symbols[VM_MAX_QPATH];

    COM_StripExtension(filepath, filepath);
    sprintf(symbols, "%s.map", filepath);
    printf("Loading symbol file: %s...\n", symbols);

    char *mapFileImage = (char *)loadImage(symbols, &mapFileImageSize);
    VM_LoadDebugInfo(&vm, mapFileImage, pDebugInfo, 0x10000);
#endif
    /* call virtual machine vmMain() with integer argument (here 0) */
    retVal = VM_Call(&vm, 0, 1, 2, 3);

    if (vm.lastError) {
      printf("VM Aborted with error code: %d\n", vm.lastError);
    }
  }
  /* output profile information in DEBUG_VM build: */
  VM_VmProfile_f(&vm);
  free(image); /* we can release the memory now */

  return retVal;
}

uint8_t *loadImage(const char *filepath, int *size) {
  FILE    *f;            /* bytecode input file */
  uint8_t *image = NULL; /* bytecode buffer */
  int      sz;           /* bytecode file size */

  *size = 0;
  f     = fopen(filepath, "rb");
  if (!f) {
    fprintf(stderr, "Failed to open file %s.\n", filepath);
    return NULL;
  }
  /* calculate file size */
  fseek(f, 0L, SEEK_END);
  sz = ftell(f);
  if (sz < 1) {
    fclose(f);
    return NULL;
  }
  rewind(f);

  image = (uint8_t *)malloc(sz);
  if (!image) {
    fclose(f);
    return NULL;
  }

  if (fread(image, 1, sz, f) != (size_t)sz) {
    free(image);
    fclose(f);
    return NULL;
  }

  fclose(f);
  *size = sz;
  return image;
}

uint32_t systemCalls(vm_t *vm, uint8_t *args) {
  const int id = -1 - VMA_UINT24(0);

  switch (id) {
  case -1: /* PRINTF */
    return printf("%s", (const char *)VMA_PTR(3, vm));

  case -2: /* ERROR */
    return fprintf(stderr, "%s", (const char *)VMA_PTR(3, vm));

  case -3: /* MEMSET */
    memset(VMA_PTR(3, vm), VMA_UINT24(6), VMA_UINT24(9));
    return VMA_UINT24(3);

  case -4: /* MEMCPY */
    memcpy(VMA_PTR(3, vm), VMA_PTR(6, vm), VMA_UINT24(9));
    return VMA_UINT24(3);

  case -6: /* FLOATFF */
    return VM_FloatToInt(VMA_F4(3) * 2.0f);

  case -254:
    return putchar(VMA_UINT24(3));

  default:
    fprintf(stderr, "Bad system call: %i\n", id);
  }
  return 0;
}
