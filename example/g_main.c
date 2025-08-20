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

long sign_extend(int i, long expected);

int vmMain(int command, int arg0, int arg1, int arg2) {
  long l;
  /* Converting a positive or negative int to a long preserves its value */
  if (!sign_extend(10, 10l)) {
    return 1;
  }

  if (!sign_extend(-10, -10l)) {
    return 2;
  }

  l = (long)100;
  if (l != 100l) {
    return 3;
  }
  return 0;
}

long sign_extend(int i, long expected) {
  long extended = (long)i;
  return (extended == expected);
}
