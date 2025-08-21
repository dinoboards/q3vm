/* Make sure we can handle adding, subtracting,
 * and multiplying by constants that are outside
 * the range of int, but inside the range of unsigned int;
 * this tests several assembly rewrite rules.
 */

/* Make x a global variable so this test doesn't rely on
 * correct argument passing for longs but won't get optimized away in part III
 */
long x = 5l;

int main(void) {

  if (!add_large()) {
    return 1;
  }

  if (!subtract_large()) {
    return 2;
  }

  if (!multiply_by_large()) {
    return 3;
  }

  return 0;
}

int add_large(void) {
  // x = 5l
  x = x + 16777210l;       // this constant is 2^24 - 6
  return (x == 16777215l); // 4294967295l); // -1
}

int subtract_large(void) {
  x = x - 16777210l;
  return (x == 5l);
}

int multiply_by_large(void) {
  // x = 5
  x = x * 429496729l;
  return (x == 2147483645l);
}
