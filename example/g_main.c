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

int a = -5;

int main(int command, int arg0, int arg1) { printf("command: %d, arg0: %d, arg1: %d\n", command, arg0, arg1); }
