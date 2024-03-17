#include <stdio.h>
#include "data/IEEE754.h"

typedef union tagLDoubleLLong
{
  long double ld;
  struct tagLDoubleLLong_
  {
    FQWORD lh;
    FQWORD ll;
  };
} LDoubleLLong;

typedef struct tagLDoubleLLongL
{
  FQWORD lh;
  FQWORD ll;
}LDoubleLLongL;

int main(void)
{
  printf("%d\n", sizeof(LDoubleLLongL));
}
