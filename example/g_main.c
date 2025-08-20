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

int vmMain(int command, int arg0, int arg1, int arg2) {
  int16_t  a = 0x9000;
  uint16_t c = 0 - a;

  return c == 28672;
}
