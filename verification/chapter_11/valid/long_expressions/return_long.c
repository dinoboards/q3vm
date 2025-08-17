
long add(int a, int b);

int main(void) {
  long a = add(8388605, 8388605);
  /* Test returning a long from a function call */
  if (a == 16777210L) {
    return 1;
  }
  return 0;
}

long add(int a, int b) { return (long)a + (long)b; }
