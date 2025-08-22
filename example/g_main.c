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

#pragma GCC diagnostic ignored "-Woverflow"

int return_truncated_long(long l);

long return_extended_int(int i);

int truncate_on_assignment(long l, int expected);

int main(void) {

  // return statements

  /* return_truncated_long will truncate 2^24 + 2 to 2
   * assigning it to result converts this to a long
   * but preserves its value.
   */
  long result = return_truncated_long(16777218l);
  if (result != 2l) {
    return 1;
  }

  /* return_extended_int sign-extends its argument, preserving its value */
  result = return_extended_int(-10);
  if (result != -10) {
    return 2;
  }

  // initializer

  /* This is 2^24 + 2,
   * it will be truncated to 2 by assignment
   */
  {
    int i = 16777218l;
    if (i != 2) {
      return 3;
    }

    // assignment expression

    // 2^26 will be truncated to 0 when assigned to an int
    if (!truncate_on_assignment(67108864l, 0)) {
      return 4;
    }

    return 0;
  }
}

int return_truncated_long(long l) { return l; }

long return_extended_int(int i) { return i; }

int truncate_on_assignment(long l, int expected) {
  int result = l; // implicit conversion truncates l
  return result == expected;
}
