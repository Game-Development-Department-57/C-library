#include <stdio.h>
#include "data/endian.h"
#include "binary/memory.h"

int main(void)
{
  float pi = 3.14;
  unsigned int a;
  BinaryDump((unsigned char*)&pi, 4, 16);
  printf("\n");
  endianSet2((void*)&a, (void*)&pi, 4);
  BinaryDump((unsigned char*)&a, 4, 16);
}
