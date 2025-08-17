// an external variable is in scope inside a switch statement
// even if we jump over the point where it's declared

int main(void) {
  int        a = 10;
  extern int x; // bring x into scope

  switch (a) {
  case 1:
    return 1; // fail
  case 2:
    return 2; // fail
  case 10:
    if (x * 2 == 30) {
      return 0; // success
    }
  default:
    return 5; // fail
  }
  return 6; // also fail; shouldn't have made it to this point
}

int x = 15;
