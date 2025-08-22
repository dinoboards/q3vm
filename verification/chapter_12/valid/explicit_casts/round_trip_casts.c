/* Converting a value to a different type, then back to the original type,
 * does not always recover its original value
 */

// start with a global variable so we can't optimize away casts in Part III

unsigned long a = 33554420ul; // 2^25 - 12

int main(void) {

  /* because a is too large to fit in an unsigned int,
   * casting it to unsigned int and back is equivalent to subtracting
   * 2^24, resulting in 16777216
   */
  unsigned long b = (unsigned long)(unsigned int)a;

  if (b != 16777204ul)
    return 1;

  /* Casting a to signed int results in -12, and
   * casting it back to unsigned long results in 2^32 - 12,
   * or 4294967284
   */
  b = (unsigned long)(signed int)a;
  if (b != 4294967284ul)
    return 2;

  return 0;
}
