#include <stdio.h>

void testThrow(void)
{
    throwSet(0x00000001, 0, "Hello", "testthrow", "testThrow", "");
    return;
}

int main(void)
{
  Throw mythrow;
  throwTry
  {
    testThrow();
  } throwCatch(mythrow)
  {
    printf("%s", mythrow.msg);
  }
  return 0;
}