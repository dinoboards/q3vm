#include "bg_lib.h"

void printf(const char *fmt, ...);
/*
================
vmMain

This is the only way control passes into the module.
This must be the very first function compiled into the .qvm file
================
*/

// these are int32_t
int vmMain(int command, int arg0, int arg1, int arg2) { return -1; }

void printf(const char *fmt, ...) {
  va_list argptr;
  char    text[256];

  va_start(argptr, fmt);
  vsprintf(text, fmt, argptr);
  va_end(argptr);

  trap_Printf(text);
}
