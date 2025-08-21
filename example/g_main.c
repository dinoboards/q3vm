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

long x = 5l;

int main(void) {

  if (!add_large()) {
    return 1;
  }

  if (!subtract_large()) {
    return 2;
  }

  if (!multiply_by_large()) {
    return 3;
  }

  return 0;
}

int add_large(void) {
  // x = 5l
  x = x + 16777210l;       // this constant is 2^24 - 6
  return (x == 16777215l); // 4294967295l); // -1
}

int subtract_large(void) {
  x = x - 16777210l;
  return (x == 5l);
}

int multiply_by_large(void) {
  // x = 5
  x = x * 429496729l;
  return (x == 2147483645l);
}
