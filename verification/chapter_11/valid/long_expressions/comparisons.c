/* Test comparisons between longs, making sure to exercise all rewrite rules for cmp */

long l;
long l2;

int compare_constants(void);
int compare_constants_2(void);
int l_geq_2_60(void);
int uint_max_leq_l(void);
int l_eq_l2(void);

int main(void) {

  if (!compare_constants()) {
    return 1;
  }

  if (!compare_constants_2()) {
    return 2;
  }

  l = -2147483646L; // LONG_MIN + 1
  if (l_geq_2_60()) {
    return 3;
  }
  if (uint_max_leq_l()) {
    return 4;
  }

  l = 1073741824L; // 2^30
  if (!l_geq_2_60()) {
    return 5;
  }
  if (!uint_max_leq_l()) {
    return 6;
  }
  l2 = l;
  if (!l_eq_l2()) {
    return 7;
  }
  return 0;
}

/* Comparisons where both operands are constants */
int compare_constants(void) {
  /* Note that if we considered only the lower 32 bits of
   * each number (or cast them to ints), 255 would be larger,
   * because 33554433 == 2^25 + 1.
   * This exercises the rewrite rule for cmp with two constant operands
   */
  return 33554433L > 255l;
}

int compare_constants_2(void) {
  /* This exercises the rewrite rule for cmp where src is a large constant
   * and dst is a constant, because 536870913 can't fit in an int.
   */
  return 255l < 536870913L;
}

int l_geq_2_60(void) {
  /* This exercises the rewrite rule for cmp where src is a large constant
   * and dst is a variable.
   * 1073741824L == 2^30
   */
  return (l >= 1073741824L);
}

int uint_max_leq_l(void) {
  /* The first operand to cmp is a variable and second is a constant (UINT_MAX as a long). */
  return (4294967295L <= l);
}

int l_eq_l2(void) {
  /* Exercise rewrite rule for cmp where both operands are in memory */
  return (l == l2);
}
