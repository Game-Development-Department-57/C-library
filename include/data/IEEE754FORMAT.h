#include "binary/ftype.h"

typedef struct tagIEEE754BINARY16
{
  FDWORD sign;     /* 1bit */
  FDWORD exponent; /* 5bit */
  FDWORD fraction; /* 10bit */
} IEEE754BINARY16;

#define IEEE754BINARY16_SIGN     0x8000
#define IEEE754BINARY16_EXPONENT 0x7C00
#define IEEE754BINARY16_FRACTION 0x03FF


typedef struct tagIEEE754BINARY32
{
  FDWORD sign;     /* 1bit */
  FDWORD exponent; /* 8bit */
  FDWORD fraction; /* 23bit */
} IEEE754BINARY32;

#define IEEE754BINARY32_SIGN     0x80000000
#define IEEE754BINARY32_EXPONENT 0x7F800000
#define IEEE754BINARY32_FRACTION 0x007FFFFF


typedef struct tagIEEE754BINARY64
{
  FDWORD  sign;     /* 1bit */
  FDWORD  exponent; /* 11bit */
  struct tagIEEE754BINARY64FRACTION
  {
    FDWORD fractionH;
    FDWORD fractionL;
  }; /* 52bit */
} IEEE754BINARY64;

#define IEEE754BINARY64_SIGN      0x8000000000000000
#define IEEE754BINARY64_EXPONENT  0x7FF0000000000000
#define IEEE754BINARY64_FRACTION  0x000FFFFFFFFFFFFF
#define IEEE754BINARY64_FRACTIONH 0x000FFFFF00000000
#define IEEE754BINARY64_FRACTIONL 0x00000000FFFFFFFF


typedef struct tagIEEE754BINARY128
{
  FDWORD  sign;     /* 1bit */
  FDWORD  exponent; /* 15bit */
  struct tagIEEE754BINARY128FRACTION
  {
    FQWORD fractionH;
    FQWORD fractionL;
  }; /* 112bit */
} IEEE754BINARY128;

#define IEEE754BINARY128_SIGN      0x8000000000000000
#define IEEE754BINARY128_EXPONENT  0x7FFF000000000000
#define IEEE754BINARY128_FRACTIONH 0x0000FFFFFFFFFFFF
#define IEEE754BINARY128_FRACTIONL 0xFFFFFFFFFFFFFFFF