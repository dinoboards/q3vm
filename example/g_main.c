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
  /* Converting a positive int to an unsigned long preserves its value */
  if (!int_to_ulong(10, 10ul)) {
    return 1;
  }

  /* When you convert a negative int to an unsigned long,
   * add 2^32 until it's positive
   */
  if (!int_to_ulong(-10, 4294967286ul)) {
    return 2;
  }

  /* Extending an unsigned int to a signed long preserves its value */
  if (!uint_to_long(16777120u, 16777120l)) {
    return 3;
  }

  /* Extending an unsigned int to an unsigned long preserves its value */
  if (!uint_to_ulong(16777120u, 16777120ul)) {
    return 4;
  }
  /* Zero-extend constant 16777120
   * from an unsigned int to an unsigned long
   * to test the assembly rewrite rule for MovZeroExtend
   */
  if ((unsigned long)16777120u != 16777120ul) {
    return 5;
  }
  return 0;
}

int int_to_ulong(int i, unsigned long expected) {
  unsigned long result = (unsigned long)i;
  return result == expected;
}

int uint_to_long(unsigned int ui, long expected) {
  long result = (long)ui;
  return result == expected;
}

int uint_to_ulong(unsigned ui, unsigned long expected) { return (unsigned long)ui == expected; }
