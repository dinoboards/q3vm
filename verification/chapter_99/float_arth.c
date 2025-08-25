
typedef unsigned char uint8_t;
typedef char          int8_t;

typedef unsigned short uint16_t;
typedef short          int16_t;

typedef unsigned int uint24_t;
typedef int          int24_t;

typedef unsigned long uint32_t;
typedef long          int32_t;

float a;
float b;

int fn(int32_t d);
int fnx(float);
int sub_test_1();
int sub_test_2();
int sub_test_3();

#define fabs(f) ((f) < 0 ? -(f) : (f))

int main(void) {
  if (sub_test_1())
    return 1;

  if (sub_test_2())
    return 2;

  if (sub_test_3())
    return 3;

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
