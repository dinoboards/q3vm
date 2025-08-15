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
  printf("AAAAA%c", 66);
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

#define ALT       0x00000001 /* alternate form */
#define HEXPREFIX 0x00000002 /* add 0x or 0X prefix */
#define LADJUST   0x00000004 /* left adjustment */
#define LONGDBL   0x00000008 /* long double */
#define LONGINT   0x00000010 /* long integer */
#define QUADINT   0x00000020 /* quad integer */
#define SHORTINT  0x00000040 /* short integer */
#define ZEROPAD   0x00000080 /* zero (as opposed to blank) pad */
#define FPT       0x00000100 /* floating point number */

#define to_digit(c) ((c) - '0')
#define is_digit(c) ((unsigned)to_digit(c) <= 9)
#define to_char(n)  ((n) + '0')

int xxvsprintf(char *buffer, const char *fmt, va_list argptr) {
  int  *arg;
  char *buf_p;
  char  ch;
  int   width;

  buf_p = buffer;
  arg   = (int *)argptr;


  while (1) {
    // run through the format string until we hit a '%' or '\0'
    for (ch = *fmt; (ch = *fmt) != '\0' && ch != '%'; fmt++) {
      *buf_p++ = ch;
    }
    if (ch == '\0') {
      goto done;
    }

    // skip over the '%'
    fmt++;

   trap_Printf("Break it by setting width\n");
    // reset formatting state
    width = 0;

    ch = *fmt;
    switch (ch) {
    case 'c':
      trap_Printf("OK IF LOOK BEFORE!!!!\n");
      *buf_p++ = (char)*arg;
      arg++;
      break;
    }
  }

done:
  *buf_p = 0;
  return buf_p - buffer;
}

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
