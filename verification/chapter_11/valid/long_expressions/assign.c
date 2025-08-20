int main(void) {
  /* initializing a tests the rewrite rule for
   * movq $large_const, memory_address
   */
  long a = 16777210L;
  long b = 0l;
  /* Assign the value of one long variable
   * (which is too large for an int to represent)
   * to another long variable
   */
  b = a;
  return (b == 16777210L);
}
