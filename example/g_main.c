#include "bg_lib.h"

// void printf(const char *fmt, ...);
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

typedef unsigned int uint24_t;
typedef int          int24_t;

typedef unsigned long uint32_t;
typedef long          int32_t;

/*
================
vmMain

This is the only way control passes into the module.
This must be the very first function compiled into the .qvm file
================
*/

/* Test basic arithmetic operations on long integers
 * when one or both operands and the result are outside the range of int */

uint8_t a;
int24_t b;

int main(void) {
  a = 23;
  b = a;
}
