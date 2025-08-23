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

typedef unsigned int uint24_t;
typedef int          int24_t;

typedef unsigned long uint32_t;
typedef long          int32_t;

/** @brief Simple function to sum up character values.
  This is used for a test in the makefile.
  @param[in] f pointer to string.
  @return test number. */
int testCase(const char *f);

/* this call is supposed to fail */
int badcall(int i);

/* test float system calls */
float floatff(float f);

/* test recursive calls */
int recursive(int i);

int fib(int n);

volatile int        bssTest;         /* don't initialize, should be zero */
volatile static int dataTest = -999; /* don't change, should be 999 */

/*
================
vmMain

This is the only way control passes into the module.
This must be the very first function compiled into the .qvm file
================
*/

int vmMain(int command, int arg0, int arg1, int arg2) {
  char str[] = "Hello\n";

  // printf("cmd:   %i\n", command);
  // printf("arg0:  %i\n", arg0);
  // printf("arg1:  %i\n", arg1);
  // printf("arg2:  %i\n", arg2);

  printf(str, "World");
}
