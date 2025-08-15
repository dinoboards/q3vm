#include "target-support.h"

ustdint_t to_ustdint(uint24_t x) {
  ustdint_t retVal = x.byt[2];
  retVal           = retVal << 8 | x.byt[1];
  retVal           = retVal << 8 | x.byt[0];
  return retVal;
}

stdint_t to_stdint(int24_t x) {
  ustdint_t retVal = x.byt[2];
  retVal           = retVal << 8 | x.byt[1];
  retVal           = retVal << 8 | x.byt[0];

  /* generate the sign bit mask. 'b' is the extracted number of bits */
  int m = 1U << (24 - 1);

  /* Transform a 'b' bits unsigned number 'x' into a signed number 'r' */
  return (retVal ^ m) - m;
}

uint24_t to_uint24(ustdint_t x) {
  uint24_t retVal;
  retVal.byt[0] = x & 0xff;
  retVal.byt[1] = (x >> 8) & 0xff;
  retVal.byt[2] = (x >> 16) & 0xff;
  return retVal;
}

int24_t to_int24(ustdint_t x) {
  int24_t retVal;
  retVal.byt[0] = x & 0xff;
  retVal.byt[1] = (x >> 8) & 0xff;
  retVal.byt[2] = (x >> 16) & 0xff;
  return retVal;
}
