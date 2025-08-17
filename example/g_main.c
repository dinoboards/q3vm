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

typedef unsigned int uint24_t;
typedef int          int24_t;

typedef unsigned long uint32_t;
typedef long          int32_t;

typedef void (*fun_ptr_t)(int);

uint8_t fn_uint8(void);

int8_t fn_int8(void);

uint16_t fn_uint16(void);

int16_t fn_int16(void);

uint24_t fn_uint24(void);

int24_t fn_int24(void);

uint32_t fn_uint32(void);

int32_t fn_int32(void);

float fn_float(void);

typedef struct a_struct_s {
  int a;
  int b;
} a_struct_t;

a_struct_t *fn_struct(void);

fun_ptr_t fn_fn(void);

// these are int32_t
int vmMain(int command, int arg0, int arg1, int arg2) {
  char     str[] = "local string ref\n";
  uint8_t  ua;
  int8_t   a;
  uint16_t ub;
  int16_t  b;
  uint24_t uc;
  int24_t  c;
  uint32_t ud;
  int32_t  d;
  uint8_t *pua;

  float f;

  ua = 130;
  a  = -123;
  ub = 45000;
  b  = -32000;
  uc = 0x80000;
  c  = -0x20000;
  ud = 0x12345678;
  d  = 0x11223344;

  f = 1.345;

  switch (command) {
  case 0:
    printf("ua: %d, a: %d, ub: %d, b: %d, uc: %d, c: %d, ud: %d, d:%d, f: %f\r\n", ua, a, ub, b, uc, c, ud, d, f);

    d = (long)f;
    printf("ua: %d, a: %d, ub: %d, b: %d, uc: %d, c: %d, ud: %d, d:%d, f: %f\r\n", ua, a, ub, b, uc, c, ud, d, f);

    f = (float)d;
    printf("ua: %d, a: %d, ub: %d, b: %d, uc: %d, c: %d, ud: %d, d:%d, f: %f\r\n", ua, a, ub, b, uc, c, ud, d, f);

    d  = a;
    d  = ua;
    d  = b;
    d  = ub;
    d  = c;
    d  = uc;
    d  = ud;
    ud = a;
    ud = ua;
    ud = b;
    ud = ub;
    ud = c;
    ud = uc;
    ud = d;

    c  = a;
    c  = ua;
    c  = b;
    c  = ub;
    c  = uc;
    c  = d;
    c  = ud;
    uc = a;
    uc = ua;
    uc = b;
    uc = ub;
    uc = d;
    uc = ud;

    b  = a;
    b  = ua;
    b  = ub;
    b  = c;
    b  = uc;
    b  = d;
    b  = ud;
    ub = a;
    ub = ua;
    ub = b;
    ub = c;
    ub = uc;
    ub = d;
    ub = ud;

    a  = ua;
    a  = b;
    a  = ub;
    a  = c;
    a  = uc;
    a  = d;
    a  = ud;
    ua = a;
    ua = b;
    ua = ub;
    ua = c;
    ua = uc;
    ua = d;
    ua = ud;

    d  = -d;
    ud = -d;

    ud += 1;
    d = d + 1;

    pua = 0;
    pua += 1;

    printf("ua: %d, a: %d, ub: %d, b: %d, uc: %d, c: %d, ud: %d, d:%d, f: %f\r\n", ua, a, ub, b, uc, c, ud, d, f);
    printf("pua: %d\r\n", pua);

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

  case 3: {
    d = someimmutabledata[1];
    return 0;
  }

  case 4:
    d = changingdata[1];
    return 0;

  case 5:
    d = fn_uint8();
    d = fn_int8();
    d = fn_uint16();
    d = fn_int16();
    d = fn_uint24();
    d = fn_int24();
    d = fn_uint32();
    d = fn_int32();
    d = fn_float();
    fn_struct();
    fn_fn();
    break;

  default:
    printf("Unknown command.\n");
    return -1;
  }
}

uint8_t fn_uint8(void) { return 1; }

int8_t fn_int8(void) { return 1; }

uint16_t fn_uint16(void) { return 1; }

int16_t fn_int16(void) { return 1; }

uint24_t fn_uint24(void) { return 1; }

int24_t fn_int24(void) { return 1; }

uint32_t fn_uint32(void) { return 1; }

int32_t fn_int32(void) { return 1; }

float fn_float(void) { return 1.1; }

a_struct_t *fn_struct(void) { return 0; }

fun_ptr_t fn_fn(void) { return 0; }

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
