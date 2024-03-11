#include <stdio.h>
#include "data/IEEE754.h"

int main(void)
{
  float f = 3.14;
  IEEE754BINARY32 binary32;
  binary32 = IEEE754Binary32Create(f);
  printf("sign:%d\nexponent:%d\nfraction:%d\n", binary32.sign, binary32.exponent, binary32.fraction);
  return 0;
}
