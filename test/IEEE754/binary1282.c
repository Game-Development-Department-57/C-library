#include "binary/memory.h"

int main(void)
{
  long double a = -2.71828182845904;
  BinaryDump((unsigned char*)&a, sizeof(long double), 16);
}
