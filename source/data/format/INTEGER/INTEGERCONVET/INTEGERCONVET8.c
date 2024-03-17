#include "data/format/INTEGER/INTEGERTYPE.h"

INTEGER8 integer8to8(INTEGER8 integer8)
{
  return integer8;
}

INTEGER16 integer8to16(INTEGER8 integer8)
{
  INTEGER16 integer16;
  integer16.integer = (signed short) integer8.integer;
  return integer16;
}

INTEGER32 integer8to32(INTEGER8 integer8)
{
  INTEGER32 integer32;
  integer32.integer = (signed int) integer8.integer;
  return integer32;
}

INTEGER64 integer8to64(INTEGER8 integer8)
{
  INTEGER64 integer64;
  integer64.integer = (signed long long) integer8.integer;
  return integer64;
}

INTEGER128 integer8to128(INTEGER8 integer8)
{
  INTEGER128 integer128;
  integer128.integer[0] = (signed long long) integer8.integer;
  integer128.integer[1] = (signed long long) 0x0000000000000000;
  return integer128;
}

INTEGER256 integer8to256(INTEGER8 integer8)
{
  INTEGER256 integer256;
  integer256.integer[0] = (signed long long) integer8.integer;
  integer256.integer[1] = (signed long long) 0x0000000000000000;
  integer256.integer[2] = (signed long long) 0x0000000000000000;
  integer256.integer[3] = (signed long long) 0x0000000000000000;
  return integer256;
}

INTEGER512 integer8to512(INTEGER8 integer8)
{
  INTEGER512 integer512;
  integer512.integer[0] = (signed long long) integer8.integer;
  integer512.integer[1] = (signed long long) 0x0000000000000000;
  integer512.integer[2] = (signed long long) 0x0000000000000000;
  integer512.integer[3] = (signed long long) 0x0000000000000000;
  integer512.integer[4] = (signed long long) 0x0000000000000000;
  integer512.integer[5] = (signed long long) 0x0000000000000000;
  integer512.integer[6] = (signed long long) 0x0000000000000000;
  integer512.integer[7] = (signed long long) 0x0000000000000000;
  return integer512;
}

INTEGER1024 integer8to1024(INTEGER8 integer8)
{
  INTEGER1024 integer1024;
  integer1024.integer[0]  = (signed long long) integer8.integer;
  integer1024.integer[1]  = (signed long long) 0x0000000000000000;
  integer1024.integer[2]  = (signed long long) 0x0000000000000000;
  integer1024.integer[3]  = (signed long long) 0x0000000000000000;
  integer1024.integer[4]  = (signed long long) 0x0000000000000000;
  integer1024.integer[5]  = (signed long long) 0x0000000000000000;
  integer1024.integer[6]  = (signed long long) 0x0000000000000000;
  integer1024.integer[7]  = (signed long long) 0x0000000000000000;
  integer1024.integer[8]  = (signed long long) 0x0000000000000000;
  integer1024.integer[9]  = (signed long long) 0x0000000000000000;
  integer1024.integer[10] = (signed long long) 0x0000000000000000;
  integer1024.integer[11] = (signed long long) 0x0000000000000000;
  integer1024.integer[12] = (signed long long) 0x0000000000000000;
  integer1024.integer[13] = (signed long long) 0x0000000000000000;
  integer1024.integer[14] = (signed long long) 0x0000000000000000;
  integer1024.integer[15] = (signed long long) 0x0000000000000000;
  return integer1024;
}