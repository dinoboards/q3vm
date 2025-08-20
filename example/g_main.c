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

volatile static int dataTest = -999; /* don't change, should be 999 */

int vmMain(int command, int arg0, int arg1, int arg2) {
  int a = -2593;
  a     = a % 3;
  {
    int b = -a;
    return b;
  }
}
