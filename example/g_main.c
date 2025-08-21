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

int main(void) {
  // this would be equal to zero if we only considered lower 24 bits
  long l    = 1073741824l; // 2^30
  long zero = 0l;
  if (not(l)) {
    return 1;
  }
  if (!not(zero)) {
    return 2;
  }
  if (!if_cond(l)) {
    return 3;
  }
  if (if_cond(zero)) {
    return 4;
  }

  if (and(zero, 1)) {
    return 5;
  }

  if (!or(1, l)) {
    return 6;
  }

  return 0;
}

int not(long l) { return !l; }

int if_cond(long l) {
  if (l) {
    return 1;
  }
  return 0;
}

int and(long l1, int l2) { return l1 && l2; }

int or(int l1, long l2) { return l1 || l2; }
