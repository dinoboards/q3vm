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

int x = 1;
int y = 0;

int vmMain(int command, int arg0, int arg1, int arg2) {
  y = -1;
  x = (x << 1) | 1; // x = 3
  if (x != 3) {
    return 1;
  }
  y = ((y & -5) ^ 12) >> 2; // y = -3
  if (y != -3) {
    return 2;
  }
  return 0;
}
