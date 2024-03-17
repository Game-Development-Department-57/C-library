#include <stdio.h>

int main(void)
{
  printf("         int :%d\n         long:%d\n", sizeof(int),          sizeof(long));
  printf("unsigned int :%d\nunsigned long:%d\n", sizeof(unsigned int), sizeof(unsigned long));
  printf("float        :%d\ndouble       :%d\n", sizeof(float),        sizeof(double));
  return 0;
}
