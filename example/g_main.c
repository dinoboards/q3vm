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

// these are int32_t
int vmMain(int command, int arg0, int arg1, int arg2) {
  switch (command) {
  case 0:
    printf("!!sizeof(int): %d\n", sizeof(int));
    printf("Hello World! - fib(5) = %i\n", fib(5));
    printf("someimmutabledata at: %d\n", (int)&someimmutabledata);
    printf("changingdata at: %d\n", (int)&changingdata);
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
  char    text[1024];

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
