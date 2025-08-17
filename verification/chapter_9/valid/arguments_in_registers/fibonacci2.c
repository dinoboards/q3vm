int fib(int n);

int main(void) {
  int n = 17;
  return fib(n) == 1597 ? 1 : 2;
}

int fib(int n) {
  if (n < 2) {
    return n;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}
