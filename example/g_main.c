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
  int i = 10;
  do
    ;
  while ((i = i - 5) >= 256);

  return i;
}
