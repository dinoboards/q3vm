int foo(void);

int main(void) {
  int x = 3;
  x -= foo();
  return x;
}

int foo(void) { return 2; }
