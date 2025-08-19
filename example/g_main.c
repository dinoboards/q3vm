#include "bg_lib.h"

void printf(const char *fmt, ...);
/*
================
vmMain

This is the only way control passes into the module.
This must be the very first function compiled into the .qvm file
================
*/

// these are int32_t
int vmMain(int command, int arg0, int arg1, int arg2) {
  unsigned int x = -1u;

  long         y = x;
  unsigned int z = y; // / -10l;

  // printf("z: %d\n", z);

  if (z != x)
    return -1;

  return 0;
}
