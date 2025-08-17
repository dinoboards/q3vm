
int target(long a);

int main(void) { return target(16777210l); }

int target(long a) {
  // a = 16777210l

  /* This expression produces an intermediate result that cannot
   * fit in an int, in order to test that we track the sizes
   * of intermediate results and allocate enough stack
   * space for them.
   */
  long b = a * 5l - 10l;
  if (b == 83886040L) {
    return 1;
  }
  return 0;
}
