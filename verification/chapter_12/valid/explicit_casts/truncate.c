/* Test truncating wider to narrow types */

int main(void) {
  /* truncate long */

  /* 100 is in the range of unsigned int,
   * so truncating it to an unsigned int
   * will preserve its value
   */
  // if (!long_to_uint(100l, 100u)) {
  //   return 1;
  // }

  // /* -2147482414 (i.e. -2^31 + 1234) is outside the range of unsigned int,
  //  * so add 2^32 to bring it within range */
  // if (!long_to_uint(-2147482414, 1234u)) {
  //   return 2;
  // }

  /* truncate unsigned long */

  /* 100 can be cast to an int or unsigned int without changing its value */
  if (!ulong_to_int(100ul, 100)) {
    return 3;
  }

  if (!ulong_to_uint(100ul, 100u)) {
    return 4;
  }

  /* 16777120 (i.e. 2^24 - 96) can be cast to an unsigned int without changing its value,
   * but must be reduced modulo 2^24 to cast to a signed int
   */
  if (!ulong_to_uint(16777120ul, 16777120u)) {
    return 5;
  }

  if (!ulong_to_int(16777120ul, -96)) {
    return 6;
  }

  /* 1082130432 (i.e. 2^30 + 2^23) must be reduced modulo 2^24
   * to represent as a signed or unsigned int
   */

  if (!ulong_to_uint(1082130432ul, 8388608u)) { // reduce to 2^24
    return 7;
  }

  if (!ulong_to_int(1082130432ul, -8388608)) { // reduce to -2^23
    return 8;
  }

  /* truncate unsigned long constant that can't
   * be expressed in 32 bits, to test rewrite rule
   */
  {
    unsigned int ui = (unsigned int)67108869ul; // 2^26 + 5
    if (ui != 5)
      return 9;

    return 0;
  }
}

int ulong_to_int(unsigned long ul, int expected) {
  int result = (int)ul;
  return (result == expected);
}

int ulong_to_uint(unsigned long ul, unsigned expected) { return ((unsigned int)ul == expected); }

int long_to_uint(long l, unsigned int expected) { return (unsigned int)l == expected; }
