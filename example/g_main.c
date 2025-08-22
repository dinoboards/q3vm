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

long a;
long b;

int addition(void);
int subtraction(void);
int multiplication(void);
int division(void);
int remaind(void);
int complement(void);

int main(void) {

  /* Addition */
  a = 4294967290l; // 2^32 - 6
  b = 5l;
  if (!addition()) {
    return 1;
  }

  /* Subtraction */
  a = -16777210l;
  b = 90l;
  if (!subtraction()) {
    return 2;
  }

  /* Multiplication */
  a = 16777210l;
  if (!multiplication()) {
    return 3;
  }

  /* Division */
  a = 16777210l;
  if (!division()) {
    return 4;
  }

  /* Remainder */
  a = 33554425l; // 2^25 - 7
  if (!remaind()) {
    return 5;
  }

  /* Complement */
  a = 2147483647l; // LONG_MAX - 1
  if (!complement()) {
    return 6;
  }

  return 0;
}

int addition(void) {
  // a == 16777210l, i.e. 2^24 - 6
  // b = 5;
  return (a + b == 4294967295l);
}

int subtraction(void) {
  // a = -16777210l;
  // b = 90l;
  return (a - b == -16777300l);
}

int multiplication(void) {
  // a = 16777210l;
  return (a * 4l == 67108840l);
}

int division(void) {
  // a = 16777210l;
  b = a / 128l;
  return (b == 131071l);
}

int remaind(void) {
  // a = 33554425l; // 2^25 - 7
  b = -a % 16777210l;
  return (b == -5l);
}

int complement(void) {
  // a = 2147483647l, i.e. LONG_MAX - 1
  return (~a == -2147483648l);
}
