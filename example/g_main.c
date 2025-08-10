#include "bg_lib.h"

void printf(const char *fmt, ...);
int  fib(int n);

/*
================
vmMain

This is the only way control passes into the module.
This must be the very first function compiled into the .qvm file
================
*/
// these are int32_t
int vmMain(int command, int arg0, int arg1, int arg2) {
  if (command == 0) {
    printf("sizeof(int): %d\n", sizeof(int));
    printf("Hello World! - fib(5) = %i\n", fib(5));
  } else {
    printf("Unknown command.\n");
  }

  return 0;
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
