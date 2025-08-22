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

unsigned long a = 33554420ul; // 2^25 - 12

int main(void) {

  /* because a is too large to fit in an unsigned int,
   * casting it to unsigned int and back is equivalent to subtracting
   * 2^24, resulting in 16777216
   */
  unsigned long b = (unsigned long)(unsigned int)a;

  if (b != 16777204ul)
    return 1;

  /* Casting a to signed int results in -12, and
   * casting it back to unsigned long results in 2^32 - 12,
   * or 4294967284
   */
  b = (unsigned long)(signed int)a;
  if (b != 4294967284ul)
    return 2;

  return 0;
}
