

float a;
float b;

#define fabs(f) ((f) < 0 ? -(f) : (f))

int main(void) {
  float c;
  a = 1.2f;
  b = 3.4f;

  c = a + b;

  if (fabs(c - 4.6f) >= 0.0001)
    return 1;

  return 0;
}
