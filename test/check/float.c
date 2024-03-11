#include <stdio.h>
#include "data/endian.h"
#include "binary/memory.h"

int main(void)
{
  float pi = 3.14;
  float e = 2.71828182845904;
  BinaryDump((unsigned char*)&pi, 4, 16);
  BinaryDump((unsigned char*)&e, 4, 16);
  printf("\n");
  endianSet((void*)&pi, 4);
  BinaryDump((unsigned char*)&pi, 4, 16);
}
