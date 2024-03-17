#include <stdio.h>
#include "data/endian.h"
#include "binary/memory.h"

int main(void)
{
  float  pi = 3.14;
  double e = 2.71828182845904;
  BinaryDump((unsigned char*)&pi, 4, 16);
  BinaryDump((unsigned char*)&e, 8, 16);
  printf("\n");
  endianSet((void*)&pi, 4);
  endianSet((void*)&e,  8);
  BinaryDump((unsigned char*)&pi, 4, 16);
  BinaryDump((unsigned char*)&e,  8, 16);
}
