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

static int long a;
int static long a;
long static a;

int my_function(long a, long int b, int long c);

int main(void) {
  /* Several different ways to declare local long variables */
  long     x = 1l;
  long int y = 2l;
  int long z = 3l;

  /* This links to the file-scope declarations of 'a' above */
  extern long a;
  a = 4;

  /* make sure we can use long type specifier in for loop initializer
   * i is 2^30 so this loop should have 31 iterations
   */
  {
    int  sum = 0;
    long i;
    for (i = 1073741824L; i > 0; i = i / 2) {
      sum = sum + 1;
    }

    /* Make sure everything has the expected value */
    if (x != 1) {
      return 1;
    }

    if (y != 2) {
      return 2;
    }

    if (a != 4) {
      return 3;
    }

    if (my_function(x, y, z) != 6) {
      return 4;
    }

    if (sum != 31) {
      return 5;
    }
    return 0;
  }
}

int my_function(long int x, int long y, long z) { return x + y + z; }
