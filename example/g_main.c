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

int main(void) {
  /* initializing a tests the rewrite rule for
   * movq $large_const, memory_address
   */
  long a = 16777210L;
  long b = 0l;
  /* Assign the value of one long variable
   * (which is too large for an int to represent)
   * to another long variable
   */
  b = a;
  return (b == 16777210L);
}
