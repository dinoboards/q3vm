
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

static const uint8_t     init8     = 'A';
static const uint16_t    init16    = 0x1234;
static const uint24_t    init24    = 0x123456;
static const uint32_t    init32    = 0x12345678;
static const float       initfloat = 12345.123;
static const char *const str       = "abc";
static const char        str2[]    = "abc";

int fn(int32_t d);
int fnx(float);
int sub_test_1(void);
int sub_test_2(void);
int sub_test_3(void);
int sub_test_4(void);
int sub_test_5(void);
int sub_test_6(void);
int sub_test_7(void);
int sub_test_8(void);
int sub_test_9(void);
int sub_test_10(void);
int sub_test_11(void);
int sub_test_12(void);
int sub_test_13(void);
int sub_test_14(void);
int sub_test_15(void);
int sub_test_OP_CI3s4(void);
int sub_test_OP_CI2s3(void);
int sub_test_OP_CI4I3(void);
int sub_test_OP_CI4U3(void);
int sub_test_OP_CONSTs1(void);
int sub_test_OP_CONSTs2(void);
int sub_test_OP_CONSTs3(void);
int sub_test_OP_CONSTs4(void);
int sub_test_OP_CU1I3(void);
int sub_test_OP_CU2I3(void);
int sub_test_OP_CU3U2(void);
int sub_test_OP_CU3U4(void);
int sub_test_OP_CU4I3(void);
int sub_test_OP_CU4U3(void);
int sub_test_OP_CVFI3(void);
int sub_test_OP_DIVI3(void);
int sub_test_OP_DIVU3(void);
int sub_test_OP_GEI3(void);
int sub_test_OP_GEU3(void);
int sub_test_OP_GEU4(void);
int sub_test_OP_GTF4(void);
int sub_test_OP_GTU3(void);
int sub_test_OP_GTU4(void);
int sub_test_OP_JUMP(void);
int sub_test_OP_LEF4(void);
int sub_test_OP_LEI3(void);
int sub_test_OP_LEI4(void);
int sub_test_OP_LEU3(void);
int sub_test_OP_LEU4(void);
int sub_test_OP_LTU4(void);
int sub_test_OP_MODI3(void);
int sub_test_OP_MODI4(void);
int sub_test_OP_MODU3(void);
int sub_test_OP_MODU4(void);
int sub_test_OP_MULF4(void);
int sub_test_OP_MULI3(void);
int sub_test_OP_MULI4(void);
int sub_test_OP_MULU3(void);
int sub_test_OP_MULU4(void);
int sub_test_OP_NE3(void);
int sub_test_OP_NE4(void);
int sub_test_OP_NEF4(void);
int sub_test_OP_NEGF4(void);
int sub_test_OP_NEGI3(void);
int sub_test_OP_NEGI4(void);
int sub_test_OP_RSHI3(void);
int sub_test_OP_RSHI4(void);
int sub_test_OP_RSHU3(void);
int sub_test_OP_RSHU4(void);
int sub_test_static_init(void);
int sub_test_struct_passing(void);

#define fabs(f) ((f) < 0 ? -(f) : (f))

int main(void) {

#pragma asm DI
#pragma asm EI

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

  if (sub_test_15())
    return 15;

  if (sub_test_OP_CI3s4())
    return 16;

  if (sub_test_OP_CI2s3())
    return 17;

  if (sub_test_OP_CI4I3())
    return 18;

  if (sub_test_OP_CI4U3())
    return 19;

  if (sub_test_OP_CONSTs1())
    return 20;

  if (sub_test_OP_CONSTs2())
    return 21;

  if (sub_test_OP_CONSTs3())
    return 22;

  if (sub_test_OP_CONSTs4())
    return 23;

  if (sub_test_OP_CU1I3())
    return 24;

  if (sub_test_OP_CU2I3())
    return 25;

  if (sub_test_OP_CU3U2())
    return 26;

  if (sub_test_OP_CU3U4())
    return 26;

  if (sub_test_OP_CU4I3())
    return 27;

  if (sub_test_OP_CU4U3())
    return 28;

  if (sub_test_OP_CVFI3())
    return 29;

  if (sub_test_OP_DIVI3())
    return 30;

  if (sub_test_OP_DIVU3())
    return 31;

  if (sub_test_OP_GEI3())
    return 32;

  if (sub_test_OP_GEU3())
    return 33;

  if (sub_test_OP_GEU4())
    return 34;

  if (sub_test_OP_GTF4())
    return 35;

  if (sub_test_OP_GTU3())
    return 36;

  if (sub_test_OP_GTU4())
    return 37;

  if (sub_test_OP_JUMP())
    return 38;

  if (sub_test_OP_LEF4())
    return 39;

  if (sub_test_OP_LEI3())
    return 40;

  if (sub_test_OP_LEI4())
    return 41;

  if (sub_test_OP_LEU3())
    return 42;

  if (sub_test_OP_LEU4())
    return 43;

  if (sub_test_OP_LTU4())
    return 44;

  if (sub_test_OP_MODI3())
    return 45;

  if (sub_test_OP_MODI4())
    return 46;

  if (sub_test_OP_MODU3())
    return 47;

  if (sub_test_OP_MODU4())
    return 48;

  if (sub_test_OP_MULF4())
    return 49;

  if (sub_test_OP_MULI3())
    return 50;

  if (sub_test_OP_MULI4())
    return 51;

  if (sub_test_OP_MULU3())
    return 52;

  if (sub_test_OP_MULU4())
    return 53;

  if (sub_test_OP_NE3())
    return 54;

  if (sub_test_OP_NE4())
    return 55;

  if (sub_test_OP_NEF4())
    return 56;

  if (sub_test_OP_NEGF4())
    return 57;

  if (sub_test_OP_NEGI3())
    return 58;

  if (sub_test_OP_NEGI4())
    return 59;

  if (sub_test_OP_RSHI3())
    return 60;

  if (sub_test_OP_RSHI4())
    return 61;

  if (sub_test_OP_RSHU3())
    return 62;

  if (sub_test_OP_RSHU4())
    return 63;

  if (sub_test_static_init())
    return 64;

  if (sub_test_struct_passing())
    return 65;

  return 0;
}

int sub_test_1(void) {
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

int sub_test_3(void) {
  uint32_t x;

  a = 1.2;
  x = a;

  if (x == 1)
    return 0;

  return 1;
}

int sub_test_4(void) {
  uint24_t a = 0x5A5A5A;
  uint24_t b;

  b = ~a;
  if (b == 0xA5A5A5)
    return 0;

  return 1;
}

int sub_test_5(void) {
  uint32_t a = 0x00FF;
  uint32_t b = 0x7788;
  uint32_t c;

  c = a | b;

  if (c == 0x77FF)
    return 0;

  return 1;
}

int sub_test_6(void) {
  uint32_t a = 0x00FF;
  uint32_t b = 0x7788;
  uint32_t c;

  c = a ^ b;

  if (c == 0x7777)
    return 0;

  return 1;
}

int sub_test_7(void) {
  int8_t  aa;
  int24_t bb;

  aa = -12;
  bb = aa;

  if (bb != -12)
    return 1;

  aa = (int8_t)(int24_t)aa;
  if (aa != -12)
    return 1;

  return 0;
}

int sub_test_8(void) {
  int8_t  aa;
  int32_t bb;

  aa = -12;
  bb = (int32_t)aa;

  if (bb != -12)
    return 1;

  aa = (int8_t)(int32_t)aa;
  if (aa != -12)
    return 1;

  return 0;
}

int sub_test_9(void) {
  int16_t aa;
  int24_t bb;

  aa = -12;
  bb = (int24_t)aa;

  if (bb != -12)
    return 1;

  aa = (int16_t)(int24_t)aa;
  if (aa != -12)
    return 1;

  return 0;
}

int sub_test_10(void) {
  int16_t aa;
  int32_t bb;

  aa = -12;
  bb = (int32_t)aa;

  if (bb != -12)
    return 1;

  aa = (int16_t)(int32_t)aa;
  if (aa != -12)
    return 1;

  return 0;
}

int sub_test_11(void) {
  int24_t aa;
  float   bb;

  aa = -12;
  bb = (float)aa;

  if (bb != -12.0)
    return 1;

  aa = (int24_t)(float)aa;
  if (aa != -12)
    return 1;

  return 0;
}

int sub_test_12(void) {
  int24_t aa;
  int8_t  bb;

  aa = -12;
  bb = aa;

  if (bb != -12)
    return 1;

  aa = (int24_t)(int8_t)aa;
  if (aa != -12)
    return 1;

  return 0;
}

int sub_test_13(void) {
  int24_t aa;
  int16_t bb;

  aa = -12;
  bb = aa;

  if (bb != -12)
    return 1;

  aa = (int24_t)(int16_t)aa;
  if (aa != -12)
    return 1;

  return 0;
}

int sub_test_14(void) {
  int32_t aa;
  int16_t bb;

  aa = -12;
  bb = aa;

  if (bb != -12)
    return 1;

  aa = (int32_t)(int16_t)aa;
  if (aa != -12)
    return 1;

  return 0;
}

int sub_test_15(void) {
  int16_t  aa;
  uint24_t bb;

  aa = -12;
  bb = (uint24_t)aa;

  if (bb != (uint24_t)-12)
    return 1;

  aa = (int16_t)(uint24_t)aa;
  if (aa != -12)
    return 1;

  return 0;
}

int sub_test_OP_CI3s4(void) {
  int24_t  a;
  uint32_t bu;
  int32_t  bs;

  a  = -12;
  bu = a;
  bs = a;

  if (bu != (uint32_t)-12L)
    return 1;

  if (bs != -12L)
    return 1;

  a = (int24_t)(uint32_t)a;
  if (a != -12)
    return 1;

  a = (int24_t)(int32_t)a;
  if (a != -12)
    return 1;

  return 0;
}

int sub_test_OP_CI2s3(void) {
  int16_t  a;
  uint24_t bu;
  int24_t  bs;

  a  = -12;
  bu = a;
  bs = a;

  if (bu != (uint24_t)-12)
    return 1;

  if (bs != -12)
    return 1;

  a = (int16_t)(uint24_t)a;
  if (a != -12)
    return 1;

  a = (int16_t)(int24_t)a;
  if (a != -12)
    return 1;

  return 0;
}

int sub_test_OP_CI4I3(void) {
  int32_t a;
  int24_t bs;

  a  = -12;
  bs = a;

  if (bs != -12)
    return 1;

  a = (int32_t)(int24_t)a;
  if (a != -12)
    return 1;

  return 0;
}

int sub_test_OP_CI4U3(void) {
  int32_t  a;
  uint24_t bs;

  a  = -12;
  bs = a;

  if (bs != 16777204)
    return 1;

  a = (int32_t)(uint24_t)a;
  if (a != -12)
    return 1;

  return 0;
}

int sub_test_OP_CONSTs1(void) {
  uint8_t a;
  int8_t  b;

  a = 12u;
  b = 12;

  if (a != b)
    return 1;

  b = -12;
  if (-a != b)
    return 1;

  return 0;
}

int sub_test_OP_CONSTs2(void) {
  uint16_t a;
  int16_t  b;

  a = 12u;
  b = 12;

  if (a != b)
    return 1;

  b = -12;
  if (-a != b)
    return 1;

  return 0;
}

int sub_test_OP_CONSTs3(void) {
  uint24_t a;
  int24_t  b;

  a = 12u;
  b = 12;

  if (a != b)
    return 1;

  b = -12;
  if ((0 - a) != b)
    return 1;

  return 0;
}

int sub_test_OP_CONSTs4(void) {
  uint32_t a;
  int32_t  b;
  float    c;

  a = 12u;
  b = 12;

  if (a != b)
    return 1;

  b = -12;
  if ((0 - a) != b)
    return 1;

  c = 12.0;

  if (c != 12.0)
    return 1;

  return 0;
}

int sub_test_OP_CU1I3(void) {
  uint8_t a;
  int24_t bs;

  a  = 244; //-12
  bs = a;

  if (bs != 244)
    return 1;

  a = (uint8_t)(int24_t)a;
  if (a != 244)
    return 1;

  return 0;
}

int sub_test_OP_CU2I3(void) {
  uint16_t a;
  int24_t  bs;

  a  = 0xFFF4; //-12
  bs = a;

  if (bs != 65524)
    return 1;

  a = (uint16_t)(int24_t)a;
  if (a != 65524)
    return 1;

  return 0;
}

int sub_test_OP_CU3U2(void) {
  uint24_t a;
  uint16_t bs;

  a  = 0x8234;
  bs = a;

  if (bs != 0x8234)
    return 1;

  a = (uint24_t)(uint16_t)a;
  if (a != 0x8234)
    return 1;

  return 0;
}

int sub_test_OP_CU3U4(void) {
  uint24_t a;
  uint32_t bs;

  a  = 0x823456;
  bs = a;

  if (bs != 0x823456)
    return 1;

  a = (uint24_t)(uint32_t)a;
  if (a != 0x823456)
    return 1;

  return 0;
}

int sub_test_OP_CU4I3(void) {
  uint32_t a;
  int24_t  bs;

  a  = 0x82345678;
  bs = a;

  if (bs != 0x345678)
    return 1;

  a = (uint32_t)(int24_t)a;

  if (a != 0x345678)
    return 1;

  return 0;
}

int sub_test_OP_CU4U3(void) {
  uint32_t a;
  uint24_t bs;

  a  = 0x82345678;
  bs = a;

  if (bs != 0x345678)
    return 1;

  a = (uint32_t)(uint24_t)a;
  if (a != 0x345678)
    return 1;

  return 0;
}

int sub_test_OP_CVFI3(void) {
  float   a;
  int24_t bs;

  a  = -2.3;
  bs = a;

  if (bs != -2)
    return 1;

  a = (float)(int24_t)a;
  if (a != -2)
    return 1;

  return 0;
}
int sub_test_OP_DIVI3(void) {
  int24_t a;
  int24_t b;
  int24_t c;

  a = -100;
  b = 10;

  c = a / b;

  if (c != -10)
    return 1;

  return 0;
}

int sub_test_OP_DIVU3(void) {
  uint24_t a;
  uint24_t b;
  uint24_t c;

  a = 100;
  b = 10;

  c = a / b;

  if (c != 10)
    return 1;

  return 0;
}

int sub_test_OP_GEI3(void) {
  int24_t a;
  int24_t b;
  int24_t c;

  a = 20;
  b = -20;

  c = a < b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_GEU3(void) {
  uint24_t a;
  uint24_t b;
  int24_t  c;

  a = 20;
  b = 2;

  c = a < b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_GEU4(void) {
  uint32_t a;
  uint32_t b;
  int24_t  c;

  a = 20;
  b = 2;

  c = a < b;

  if (c)
    return 1;

  a = 2;
  b = 20;

  c = a < b;

  if (!c)
    return 1;

  return 0;
}

int sub_test_OP_GTF4(void) {
  float   a;
  float   b;
  int24_t c;

  a = 20.0f;
  b = 2.0f;

  c = a <= b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_GTU3(void) {
  uint24_t a;
  uint24_t b;
  int24_t  c;

  a = 20;
  b = 2;

  c = a <= b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_GTU4(void) {
  uint32_t a;
  uint32_t b;
  int24_t  c;

  a = 20;
  b = 2;

  c = a <= b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_JUMP(void) {
  uint24_t a;

  a = 20;
  if (a)
    goto skip;

  a = 2;

skip:

  if (a == 2)
    return 1;

  return 0;
}

int sub_test_OP_LEF4(void) {
  float   a;
  float   b;
  int24_t c;

  a = 2.0f;
  b = 20.0f;

  c = a > b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_LEI3(void) {
  int24_t a;
  int24_t b;
  int24_t c;

  a = -2;
  b = 20;

  c = a > b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_LEI4(void) {
  int32_t a;
  int32_t b;
  int24_t c;

  a = -2;
  b = 20;

  c = a > b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_LEU4(void) {
  uint32_t a;
  uint32_t b;
  int24_t  c;

  a = 2;
  b = 20;

  c = a > b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_LEU3(void) {
  uint24_t a;
  uint24_t b;
  int24_t  c;

  a = 2;
  b = 20;

  c = a > b;

  if (c)
    return 1;

  return 0;
}

int sub_test_OP_LTU4(void) {
  uint32_t a;
  uint32_t b;
  int24_t  c;

  a = 2;
  b = 20;

  c = a > b;

  if (c)
    return 1;

  a = 20;
  b = 2;

  c = a > b;

  if (!c)
    return 1;

  return 0;
}

int sub_test_OP_MODI3(void) {
  int24_t a;
  int24_t b;
  int24_t c;

  a = 20;
  b = 3;

  c = a % b;

  if (c != 2)
    return 1;

  return 0;
}

int sub_test_OP_MODI4(void) {
  int32_t a;
  int32_t b;
  int24_t c;

  a = 20;
  b = 3;

  c = a % b;

  if (c != 2)
    return 1;

  return 0;
}

int sub_test_OP_MODU3(void) {
  uint24_t a;
  uint24_t b;
  int24_t  c;

  a = 20;
  b = 3;

  c = a % b;

  if (c != 2)
    return 1;

  return 0;
}

int sub_test_OP_MODU4(void) {
  uint32_t a;
  uint32_t b;
  int24_t  c;

  a = 20;
  b = 3;

  c = a % b;

  if (c != 2)
    return 1;

  return 0;
}

int sub_test_OP_MULF4(void) {
  float a;
  float b;
  float c;

  a = 20.0f;
  b = 3.0f;

  c = a * b;

  if (c != 60.0f)
    return 1;

  return 0;
}

int sub_test_OP_MULI3(void) {
  int24_t a;
  int24_t b;
  int24_t c;

  a = 20;
  b = 3;

  c = a * b;

  if (c != 60)
    return 1;

  return 0;
}

int sub_test_OP_MULI4(void) {
  int32_t a;
  int32_t b;
  int32_t c;

  a = 20;
  b = 3;

  c = a * b;

  if (c != 60)
    return 1;

  return 0;
}

int sub_test_OP_MULU3(void) {
  uint24_t a;
  uint24_t b;
  uint24_t c;

  a = 20;
  b = 3;

  c = a * b;

  if (c != 60)
    return 1;

  return 0;
}

int sub_test_OP_MULU4(void) {
  uint32_t a;
  uint32_t b;
  uint32_t c;

  a = 20;
  b = 3;

  c = a * b;

  if (c != 60)
    return 1;

  return 0;
}

int sub_test_OP_NE3(void) {
  uint24_t a;
  uint24_t b;
  int24_t  c;

  a = 20;
  b = 2;

  c = a == b;

  if (c)
    return 1;

  a = 20;
  b = 20;

  c = a == b;

  if (!c)
    return 1;

  return 0;
}

int sub_test_OP_NE4(void) {
  uint24_t a;
  uint24_t b;
  int24_t  c;

  a = 20;
  b = 2;

  c = a == b;

  if (c)
    return 1;

  a = 20;
  b = 20;

  c = a == b;

  if (!c)
    return 1;

  return 0;
}

int sub_test_OP_NEF4(void) {
  float   a;
  float   b;
  int24_t c;

  a = 20.0f;
  b = 2.0f;

  c = a == b;

  if (c)
    return 1;

  a = 20.0f;
  b = 20.0f;

  c = a == b;

  if (!c)
    return 1;

  return 0;
}

int sub_test_OP_NEGF4(void) {
  float a = 10.0f;
  float b;

  b = -a;
  if (b == -10.0f)
    return 0;

  return 1;
}

int sub_test_OP_NEGI3(void) {
  int24_t a = 10;
  int24_t b;

  b = -a;
  if (b == -10)
    return 0;

  return 1;
}

int sub_test_OP_NEGI4(void) {
  int32_t a = 10;
  int32_t b;

  b = -a;
  if (b == -10)
    return 0;

  return 1;
}

int sub_test_OP_RSHI3(void) {
  int24_t a = -16;
  int24_t b = 2;
  int24_t c;

  c = a >> b;

  if (c == -4)
    return 0;

  return 1;
}

int sub_test_OP_RSHI4(void) {
  int32_t a = -16;
  int32_t b = 2;
  int32_t c;

  c = a >> b;

  if (c == -4)
    return 0;

  return 1;
}

int sub_test_OP_RSHU3(void) {
  uint24_t a = 0xFF0000;
  uint24_t b = 8;
  uint24_t c;

  c = a >> b;

  if (c == 0x00FF00)
    return 0;

  return 1;
}

int sub_test_OP_RSHU4(void) {
  uint32_t a = 0xFF000000;
  uint32_t b = 8;
  uint32_t c;

  c = a >> b;

  if (c == 0x00FF0000)
    return 0;

  return 1;
}

int sub_test_static_init(void) {

  if (init8 != 'A')
    return 1;

  if (init16 != 0x1234)
    return 1;

  if (init24 != 0x123456)
    return 1;

  if (init32 != 0x12345678)
    return 1;

  if (initfloat != 12345.123)
    return 1;

  if (str[0] != 'a' || str[1] != 'b' || str[2] != 'c' || str[3] != 0)
    return 1;

  if (str2[0] != 'a' || str2[1] != 'b' || str2[2] != 'c' || str2[3] != 0)
    return 1;

  return 0;
}

struct x_s {
  uint24_t a;
  uint8_t  b[700];
};

int spike_large_frame(int a, struct x_s b, int c, int d) {
  if (a != 1 || b.a != 1234 || c != 3 || d != 4)
    return 1;

  b.a = 999;

  return 0;
}

int sub_test_struct_passing(void) {
  struct x_s a;
  a.a = 1234;
  if (spike_large_frame(1, a, 3, 4))
    return 1;

  if (a.a != 1234)
    return 1;

  return 0;
}
