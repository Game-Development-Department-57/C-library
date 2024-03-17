#include <stdio.h>
#include "data/IEEE754.h"

int main(void)
{
  IEEE754BINARY32 binary32;
  binary32 = IEEE754Binary32Create();
  binary32.exponent = 0;
  binary32.fraction = 1;
  printf("%f\n", IEEE754Binary32ItoF(binary32));
  return 0;
}
