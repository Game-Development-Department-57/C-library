#include <stdio.h>
#include "IEEE754FORMAT.h"
#include "data/endian.h"
#include "binary/ftype.h"

IEEE754BINARY16 IEEE754Binary16Create();

IEEE754BINARY32 IEEE754Binary32Create(float f)
{
  void* ptr = (void*)&f;
  endianSet(ptr, 4);
  unsigned int a = *(unsigned int*)ptr;
  printf("%08X\n", a);
  IEEE754BINARY32 binary32;
  binary32.sign     = ((a & IEEE754BINARY32_SIGN)     >> IEEE754BINARY32_SIGN_SHIFT);
  binary32.exponent = ((a & IEEE754BINARY32_EXPONENT) >> IEEE754BINARY32_EXPONENT_SHIFT);
  binary32.fraction = ((a & IEEE754BINARY32_FRACTION) >> IEEE754BINARY32_FRACTION_SHIFT);

  return binary32;
}
