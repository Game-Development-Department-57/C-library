#include <stdio.h>
#include "data/list/list.h"

int main(void)
{
  List a, b;
  a = listCreate();
  b = listCreate();
  
  printf("a:%p\nb:%p\n\n", a, b);
  
  
  int aa, ab, ac;
  aa = 0;
  ab = 1;
  ac = 2;
  
  listAdd(a, &aa);
  listAdd(a, &ab);
  listAdd(a, &ac);
  
  listDelete(b);
  
  b = listSlice(a, 0, 1);
  
  printf("a[0]:%d\n\n", *(int*)listGet(b, 0));
  
  listDelete(a);
  printf("a:%p\nb:%p\n\n", a, b);
  printf("a:%d\nb:%d\n\n", listLength(a), listLength(b));
  
  return 0;
}