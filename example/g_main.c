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
  int a = 250;
  int b = 200;
  int c = 100;
  int d = 75;
  int e = -25;
  int f = 0;
  int x = 0;
  x = a += b -= c *= d /= e %= f = -7;
  return a == 2250 && b == 2000 && c == -1800 && d == -18 && e == -4 && f == -7 && x == 2250;
}
