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

int vmMain(int command, int arg0, int arg1, int arg2) {
  uint8_t a = 128;
  uint8_t b = 129;

  uint8_t c = b - a;

  return c == 1;
}
