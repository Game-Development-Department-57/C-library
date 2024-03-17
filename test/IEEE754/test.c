#include <stdio.h>
#include "data/IEEE754.h"

int main(void)
{
  IEEE754BINARY128 binary128;
  binary128 = IEEE754Binary128FtoI((long double) 2.71828182845904);
  printf("sign:%d\nexponent:%d\n", binary128.sign, binary128.exponent);
  printf("fractionH:%016X\nfractionL:%016X\n", binary128.fractionH, binary128.fractionL);
  return 0;
}
