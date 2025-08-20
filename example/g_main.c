#include "bg_lib.h"

void printf(const char *fmt, ...);
/*
================
vmMain

This is the only way control passes into the module.
This must be the very first function compiled into the .qvm file
================
*/

typedef unsigned char uint8_t;
typedef char          int8_t;

typedef unsigned short uint16_t;
typedef short          int16_t;

typedef void (*fun_ptr_t)(int);

int vmMain(int command, int arg0, int arg1, int arg2) {
  int a = 10;
  int b = 20;
  for (b = -20; b < 0; b = b + 1) {
    a = a - 1;
    if (a <= 0)
      break;
  }

  return a == 0 && b == -11;
}
