int three(void);

int main(void) {
  /* The function call operator () is higher precedence
   * than unary prefix operators
   */
  return !three();
}

int three(void) { return 3; }
