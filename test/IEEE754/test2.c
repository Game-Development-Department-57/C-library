#include <stdio.h>
#include "data/IEEE754.h"
#include "binary/memory.h"

int main(void)
{
  IEEE754BINARY128 binary128;
  long double ld;
  binary128 = IEEE754Binary128Create();
  ld = IEEE754Binary128ItoF(binary128);
  BinaryDump((unsigned char*)&binary128, 16, 16);
  printf("\n");
  BinaryDump((unsigned char*)&ld, 16, 16);
  printf("\n");

  return 0;
}
