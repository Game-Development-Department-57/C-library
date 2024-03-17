#include <stdio.h>
#include "data/IEEE754.h"

int main(void)
{
  IEEE754BINARY32  binary32;
  IEEE754BINARY64  binary64;
  IEEE754BINARY128 binary128;

  binary32  = IEEE754Binary32Create();
  binary64  = IEEE754Binary64Create();
  binary128 = IEEE754Binary128Create();

  printf("Binary32 :%f\n",   IEEE754Binary32ItoF(binary32));
  printf("Binary64 :%lf\n",  IEEE754Binary64ItoF(binary64));
  printf("Binary128:%llf\n", IEEE754Binary128ItoF(binary128));

  return 0;
}
