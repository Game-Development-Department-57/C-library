#include <stdio.h>
#include "binary/ftype.h"
#include "data/endian.h"

int main(void)
{
  int a = 0x01020304;
  char* ap = (char*) &a;
  printf("%02X %02X %02X %02X\n", ap[0], ap[1], ap[2], ap[3]);
  FQWORD aq = (unsigned long) a;
  FQWORD bq = endianSet(aq);
  char* bp = (char*) &bq;
  printf("%02X %02X %02X %02X %02X %02X %02X %02X\n", bp[0], bp[1], bp[2], bp[3], bp[4], bp[5], bp[6], bp[7]);

  return 0;
}
