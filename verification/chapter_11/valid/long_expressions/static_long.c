/* Test initializing and updating a long global variable */
static long foo = 16777210l;

int main(void) {
  if (foo + 5l == 16777215l) {
    // assign a constant that can't fit in 24 bits; tests assembly rewrite rule
    foo = 268435468L;
    if (foo == 268435468L)
      return 1;
  }
  return 0;
}
