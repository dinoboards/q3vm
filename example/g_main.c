#include "bg_lib.h"

void printf(const char *fmt, ...);
int  fib(int n);

#if 0
static const char *const someimmutabledata;
char                    *changingdata;
#endif

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

void spike(short a, short b, short c);
void spike_print(char *a, ...);
void alpha(int a, int b);
void beta(int a, ...);
void gamma();

// these are int32_t
int vmMain(int command, int arg0, int arg1, int arg2) {
  printf("AAAAA %d", 66);
  return 1;
}

void alpha(int a, int b) {
  beta(a, b);

  return;
}

int p;

void beta(int a, ...) {
  va_list argptr;

  va_start(argptr, a);
  p = va_arg(argptr, int);
  if (p == 2)
    trap_Printf("p == 2\n");
  else
    trap_Printf("p != 2\n");

  va_end(argptr);

  trap_Printf("beta done!\n");
}

void gamma() { trap_Printf("GAMMA\n"); }

void spike(short a, short b, short c) {
  int aa = (int)&a;
  int bb = (int)&b;
  int cc = bb - aa;

  if (cc == 3)
    trap_Printf("diff 3\n");

  printf("diff??? %d\n", cc);
}

void spike_print(char *a, ...) {
  int p;

  va_list argptr;
  va_start(argptr, a);
  p = va_arg(argptr, int);
  if (p == 123)
    trap_Printf("is 123");
  else
    trap_Printf("is not 123");
  va_end(argptr);
}

#if 1
char text[256];

void printf(const char *fmt, ...) {
  va_list argptr;

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

#endif

#if 0

static const char *const someimmutabledata = "AAAA";
char                    *changingdata      = "bBBB";
#endif
