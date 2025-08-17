#include "bg_lib.h"

void printf(const char *fmt, ...);
int  fib(int n);

static const char *const someimmutabledata;
char                    *changingdata;

/*
================
vmMain

This is the only way control passes into the module.
This must be the very first function compiled into the .qvm file
================
*/

char d;
int  nn;

typedef unsigned char uint8_t;
typedef char          int8_t;

typedef unsigned short uint16_t;
typedef short          int16_t;

typedef unsigned long uint32_t;
typedef long          int32_t;

// these are int32_t
int vmMain(int command, int arg0, int arg1, int arg2) {
  char     str[] = "local string ref\n";
  uint8_t  ua;
  int8_t   a;
  uint16_t ub;
  int16_t  b;
  uint32_t ud;
  int32_t  d;

  float f;

  ua = 130;
  a  = -123;
  ub = 45000;
  b  = -32000;
  ud = 0x12345678;
  d  = 0x11223344;

  f = 1.345;

  switch (command) {
  case 0:
    printf("ua: %d, a: %d, ub: %d, b: %d, ud: %d, d:%d, f: %f\r\n", ua, a, ub, b, ud, d, f);

    d = (long)f;
    printf("ua: %d, a: %d, ub: %d, b: %d, ud: %d, d:%d, f: %f\r\n", ua, a, ub, b, ud, d, f);

    f = (float)d;
    printf("ua: %d, a: %d, ub: %d, b: %d, ud: %d, d:%d, f: %f\r\n", ua, a, ub, b, ud, d, f);

    printf(str);
    printf("!!sizeof(int): %d\n", sizeof(int));
    printf("Hello World! - fib(5) = %i\n", fib(5));
    printf("someimmutabledata at: %d\n", (int)&someimmutabledata);
    printf("changingdata at: %d\n", (int)&changingdata);
    printf("nn(%d) = %d\n", &nn, nn);
    return 0;

  case 1:
    printf("Command 1\n");
    return 0;

  case 2:
    d = *((int *)&vmMain);
    return 0;

  case 3:
    d = someimmutabledata[1];
    return 0;

  case 4:
    d = changingdata[1];
    return 0;

  default:
    printf("Unknown command.\n");
    return -1;
  }
}

void printf(const char *fmt, ...) {
  va_list argptr;
  char    text[256];

  va_start(argptr, fmt);
  vsprintf(text, fmt, argptr);
  va_end(argptr);

  trap_Printf(text);
}

int fib(int n) {
  nn = n;
  if (n <= 2)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

static const char *const someimmutabledata = "AAAA";
char                    *changingdata      = "bBBB";
