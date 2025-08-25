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

int fn(int32_t d);
int fnx(float);
int sub_test_1();
int sub_test_2();
int sub_test_3();
int sub_test_4();
int sub_test_5();
int sub_test_6();
int sub_test_7();
int sub_test_8();
int sub_test_9();
int sub_test_10();
int sub_test_11();
int sub_test_12();
int sub_test_13();
int sub_test_14();

#define fabs(f) ((f) < 0 ? -(f) : (f))

int main(void) {

  if (sub_test_1())
    return 1;

  if (sub_test_2())
    return 2;

  if (sub_test_3())
    return 3;

  if (sub_test_4())
    return 4;

  if (sub_test_5())
    return 5;

  if (sub_test_6())
    return 6;

  if (sub_test_7())
    return 7;

  if (sub_test_8())
    return 8;

  if (sub_test_9())
    return 9;

  if (sub_test_10())
    return 10;

  if (sub_test_11())
    return 11;

  if (sub_test_12())
    return 12;

  if (sub_test_13())
    return 13;

  if (sub_test_14())
    return 14;

  return 0;
}

int sub_test_1() {
  float c;
  a = 1.2f;
  b = 3.4f;

  c = a + b;

  if (fabs(c - 4.6f) >= 0.0001)
    return 1;

  return 0;
}

int sub_test_2(void) {
  int32_t d = 4;

  return fn(d);
}

int fn(int32_t d) { return fnx(d); }

int fnx(float f) {
  if (f > 3.9 && f < 4.1)
    return 0;

  return 1;
}

int sub_test_3() {
  uint32_t x;

  a = 1.2;
  x = a;

  if (x == 1)
    return 0;

  return 1;
}

int sub_test_4() {
  uint24_t a = 0x5A5A5A;
  uint24_t b;

  b = ~a;
  if (b == 0xA5A5A5)
    return 0;

  return 1;
}

int sub_test_5() {
  uint32_t a = 0x00FF;
  uint32_t b = 0x7788;
  uint32_t c;

  c = a | b;

  if (c == 0x77FF)
    return 0;

  return 1;
}

int sub_test_6() {
  uint32_t a = 0x00FF;
  uint32_t b = 0x7788;
  uint32_t c;

  c = a ^ b;

  if (c == 0x7777)
    return 0;

  return 1;
}

int sub_test_7() {
  int8_t  aa;
  int24_t bb;

  aa = -12;
  bb = aa;

  if (bb == -12)
    return 0;

  return 1;
}

int sub_test_8() {
  int8_t  aa;
  int32_t bb;

  aa = -12;
  bb = (int32_t)aa;

  if (bb == -12)
    return 0;

  return 1;
}

int sub_test_9() {
  int16_t aa;
  int24_t bb;

  aa = -12;
  bb = (int24_t)aa;

  if (bb == -12)
    return 0;

  return 1;
}

int sub_test_10() {
  int16_t aa;
  int32_t bb;

  aa = -12;
  bb = (int32_t)aa;

  if (bb == -12)
    return 0;

  return 1;
}

int sub_test_11() {
  int24_t aa;
  float   bb;

  aa = -12;
  bb = (float)aa;

  if (bb == -12.0)
    return 0;

  return 1;
}

int sub_test_12() {
  int24_t aa;
  int8_t  bb;

  aa = -12;
  bb = aa;

  if (bb == -12)
    return 0;

  return 1;
}

int sub_test_13() {
  int24_t aa;
  int16_t bb;

  aa = -12;
  bb = aa;

  if (bb == -12)
    return 0;

  return 1;
}

int sub_test_14() {
  int32_t aa;
  int16_t bb;

  aa = -12;
  bb = aa;

  if (bb == -12)
    return 0;

  return 1;
}
