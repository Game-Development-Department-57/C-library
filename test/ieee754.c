#include <stdio.h>
#include "data/IEEE754.h"

int main(void)
{
  float  f = 3.14;
  double d = 2.71828182845904;
  IEEE754BINARY32 binary32;
  IEEE754BINARY64 binary64;
  binary32 = IEEE754Binary32Create(f);
  binary64 = IEEE754Binary64Create(d);
  printf("sign:%d\nexponent:%d\nfraction:%d\n", binary32.sign, binary32.exponent, binary32.fraction);
  printf("\n");
  printf("sign:%d\nexponent:%d\nfractionH:%d\nfractionL:%d\n", binary64.sign, binary64.exponent, binary64.fractionH, binary64.fractionL);
  return 0;
}
