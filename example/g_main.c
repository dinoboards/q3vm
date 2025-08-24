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

float a;
float b;

#define fabs(f) ((f) < 0 ? -(f) : (f))

int main(void) {
  volatile long           i;
  volatile long           iloop = 2;
  char                    str[] = "Hello %s\n";
  volatile float          f     = 0.0f;
  volatile float          df    = 0.0001f;
  volatile int            xi    = 128;
  volatile unsigned       xu    = 128;
  volatile unsigned       xu2   = 3;
  volatile unsigned short us    = 1;
  volatile short          si    = 1;
  volatile long           j;
  static unsigned char    mem1[8];
  static unsigned char    mem2[8]       = "Hello"; /* don't change this string */
  int                     doStupidStuff = 0;       /* misbehave and see if the interpreter deals correctly with that */

  /* float */
  for (i = 0; i < iloop; i++) {
    f += df;
    f = -f;
    f = -f;
    f /= 2.0f;
    f *= 2.0f;
  }

  // if (f <= 203.8 || f >= 204)
  //   return -1;

  /* integer stuff */
  for (j = 0; j < 32; j++) {
    xi = us;
    xi = si;
    xi = j;
    xi = xi << 3;
    xi = xi >> 2;
    xi = xi * 3;
    xi = xi / 3;
    xi = xi % 2;
    xi = xi & 3;
    xi = xi | 4;
    xi = xi ^ 4;
    xu = xu * 3;
    xu = xu / 3;
    xu = xu + 2;
    xu = xu - 2;
    xu = xu % 2;
    xu = xu << xu2;
    xu = xu >> xu2;
    xu = xu / xu2;
    xu = xu % xu2;
    xu = xu * xu2;
    us += 2;
    us = us << 3;
    xi = us + 3;

    xu = ~xu;
    xi = (short)xi;
    f  = j * j;

    if (j > 0) {
      xi = -xi;
    } else {
      xi = 2 * xi;
    }
    if (j >= 0) {
      xi = -xi;
    } else {
      xi = 2 * xi;
    }
    if (j < 5) {
      xi = -xi;
    } else {
      xi = 2 * xi;
    }
    if (j <= 5) {
      xi = -xi;
    } else {
      xi = 2 * xi;
    }
    xu = j;
    if (xu > 5U) {
      xi = -xi;
    } else {
      xi = 2 * xi;
    }
    if (xu >= 5U) {
      xi = -xi;
    } else {
      xi = 2 * xi;
    }
    if (xu < 5U) {
      xi = -xi;
    } else {
      xi = 2 * xi;
    }
    if (xu <= 5U) {
      xi = -xi;
    } else {
      xi = 2 * xi;
    }
    if (f > 0) {
      f = -f;
    } else {
      f = 2 * f;
    }
    if (f >= 0) {
      f = -f;
    } else {
      f = 2 * f;
    }
    if (f < 1) {
      f = -f;
    } else {
      f = 2 * f;
    }
    if (f <= 1) {
      f = -f;
    } else {
      f = 2 * f;
    }
    f = 0.1f;
    if (f != df) {
      f = 128 * f;
    }
    f *= 0.1f;
    f = df;
    if (f != df) {
      f = 128 * f;
    }
    f *= 0.1f;
    if (f == 0.0f) {
      f = -f;
    } else {
      f = 0.0f;
    }
    df = f + 0.1f;
    if (df == f) {
      df = 1.2f * df;
    }
    df = f;
    if (df == f) {
      df = 1.2f * df;
    }
    df = 0.95f * df;
    if (f == df) {
      f = -f;
    } else {
      f = 2 * f;
    }
  }
}
