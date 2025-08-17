int main(void) {
  int a = 0x7FFFFE;
  int b = 0;
  int c = a / 6 + !b;
  return c * 2 == a - 0x555552;
}
