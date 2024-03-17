#include <stdio.h>

int main(void)
{
  long double ld, a, b;
  a = 3.1415926;
  b = 2.71828182845904;
  ld = a * b;
  printf("%ld\n", ld);
  printf("%d\n", sizeof(long double));
  return 0;
}
