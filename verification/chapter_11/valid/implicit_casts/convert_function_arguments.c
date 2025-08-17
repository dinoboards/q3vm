/* Test that function arguments, including arguments put on the stack,
 * are converted to the corresponding parameter type */

int foo(long a, int b, int c, int d, long e, int f, long g, int h);

// 67108864 + 16777216 -5

int main(void) {
  int      a = -1;
  long int b = 16777218L; // 2^24 + 2, becomes 2 when converted to an int
  long     c = -16777215; // -2^24, becomes 0 when converted to int
  long     d = 100663291; // 2^26 + 2^24 - 5, becomes -5 when converted to an int
  int      e = -101;
  long     f = -123;
  int      g = -10;
  long     h = 0 - 4294966062L; // -2^24 + 1234, becomes 1234 when converted
                                // to an int
  return foo(a, b, c, d, e, f, g, h);
}

int foo(long a, int b, int c, int d, long e, int f, long g, int h) {
  if (a != -1l)
    return 1;

  if (b != 2)
    return 2;

  if (c != 0)
    return 3;

  if (d != -5)
    return 4;

  if (e != -101l)
    return 5;

  if (f != -123)
    return 6;

  if (g != -10l)
    return 7;

  if (h != 1234)
    return 8;

  return 0;
}
