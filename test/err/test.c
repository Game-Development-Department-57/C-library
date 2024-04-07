#include <error/err.h>
#include <stdio.h>

int main(void)
{
  err id = 0x80001000;
  printf("sign:%d\nreserved:%d\nrecord-a:%d\nrecord-b:%d\n\n", errGetSign(id), errGetReserved(id), errGetRecordA(id), errGetRecordB(id));
  return 0;
}
