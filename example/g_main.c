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

typedef unsigned char uint8_t;
typedef char          int8_t;

typedef unsigned short uint16_t;
typedef short          int16_t;

typedef unsigned long uint32_t;
typedef long          int32_t;

float f;
float r;

float alpha(float x);

// these are int32_t
int vmMain(int command, int arg0, int arg1, int arg2) {

  f = 1.2;

  printf("f: %f\n", f);

  r = alpha(f);

  printf("r: %f\n", r);
}

float alpha(float f) {

  int xx = 99;
  return f + xx;
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
  if (n <= 2)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

static const char *const someimmutabledata = "AAAA";
char                    *changingdata      = "bBBB";
