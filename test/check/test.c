#include <stdio.h>

int main(void)
{
  union {double d; unsigned long l;} dl;
  dl.d = 2.71828182845904;
  printf("%016lX\n", dl.l);
  return 0;
}
