#include <stdio.h>
#include "operator/complex/complex.h"

int main(void)
{
  complexd a, b, s;
  
  complexInit(a, 3.14, 2.18);
  b = (complexd) {3.14, -2.18};
  
  printf("a=");
  complexPrintln1d(a);
  printf("b=");
  complexPrintln1d(b);
  printf("\n");
  
  s = complexAdd2d(a, b);
  complexPrintln1d(s);
  
  s = complexSub2d(a, b);
  complexPrintln1d(s);
  
  s = complexMul2d(a, b);
  complexPrintln1d(s);
  
  s = complexDiv2d(a, b);
  complexPrintln1d(s);
  
  s = complexConjugate1d(a);
  complexPrintln1d(s);
  
  double double_s;
  double_s = complexAbsolute1d(b);
  printf("%lf\n", double_s);
  
  return 0;
}
