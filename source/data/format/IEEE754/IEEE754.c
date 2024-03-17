#include <stdio.h>
#include "IEEE754FORMAT.h"
#include "binary/ftype.h"





//typedef struct tagUUUUU{} UUUUU;

IEEE754BINARY16 IEEE754Binary16Create(void);
IEEE754BINARY16 IEEE754Binary16Set(IEEE754BINARY16 binary16);
float           IEEE754Binary16Get(IEEE754BINARY16 binary16);
IEEE754BINARY16 IEEE754Binary16FtoI();
IEEE754BINARY16 IEEE754Binary16ItoF();





typedef union tagFloatInt
{
  float  f;
  FDWORD i;
}FloatInt;

IEEE754BINARY32 IEEE754Binary32Create(void)
{
  IEEE754BINARY32 binary32;

  binary32.sign     = 0;
  binary32.exponent = 128;
  binary32.fraction = 0;

  return binary32;
}

IEEE754BINARY32 IEEE754Binary32Set(IEEE754BINARY32 binary32, float f)
{
  FloatInt fi;
  fi.f = f;

  binary32.sign     = (fi.i & IEEE754BINARY32_SIGN)     >> IEEE754BINARY32_SIGN_SHIFT;
  binary32.exponent = (fi.i & IEEE754BINARY32_EXPONENT) >> IEEE754BINARY32_EXPONENT_SHIFT;
  binary32.fraction = (fi.i & IEEE754BINARY32_FRACTION) >> IEEE754BINARY32_FRACTION_SHIFT;

  return binary32;
}

float IEEE754Binary32Get(IEEE754BINARY32 binary32)
{
  FloatInt fi;
  fi.i = 0;

  fi.i += binary32.sign     << IEEE754BINARY32_SIGN_SHIFT;
  fi.i += binary32.exponent << IEEE754BINARY32_EXPONENT_SHIFT;
  fi.i += binary32.fraction << IEEE754BINARY32_FRACTION_SHIFT;

  return fi.f;
}

IEEE754BINARY32 IEEE754Binary32FtoI(float f)
{
  IEEE754BINARY32 binary32;
  FloatInt fi;
  fi.f = f;

  binary32.sign     = (fi.i & IEEE754BINARY32_SIGN)     >> IEEE754BINARY32_SIGN_SHIFT;
  binary32.exponent = (fi.i & IEEE754BINARY32_EXPONENT) >> IEEE754BINARY32_EXPONENT_SHIFT;
  binary32.fraction = (fi.i & IEEE754BINARY32_FRACTION) >> IEEE754BINARY32_FRACTION_SHIFT;

  return binary32;
}

float IEEE754Binary32ItoF(IEEE754BINARY32 binary32)
{
  FloatInt fi;
  fi.i = 0;

  fi.i += binary32.sign     << IEEE754BINARY32_SIGN_SHIFT;
  fi.i += binary32.exponent << IEEE754BINARY32_EXPONENT_SHIFT;
  fi.i += binary32.fraction << IEEE754BINARY32_FRACTION_SHIFT;

  return fi.f;
}





typedef union tagDoubleLong
{
  double d;
  FQWORD l;
}DoubleLong;

IEEE754BINARY64 IEEE754Binary64Create(void)
{
  IEEE754BINARY64 binary64;

  binary64.sign      = 0;
  binary64.exponent  = 1024;
  binary64.fractionH = 0;
  binary64.fractionL = 0;

  return binary64;
}

IEEE754BINARY64 IEEE754Binary64Set(IEEE754BINARY64 binary64, double d)
{
  DoubleLong dl;
  dl.d = d;

  binary64.sign      = (dl.l & IEEE754BINARY64_SIGN)      >> IEEE754BINARY64_SIGN_SHIFT;
  binary64.exponent  = (dl.l & IEEE754BINARY64_EXPONENT)  >> IEEE754BINARY64_EXPONENT_SHIFT;
  binary64.fractionH = (dl.l & IEEE754BINARY64_FRACTIONH) >> IEEE754BINARY64_FRACTIONH_SHIFT;
  binary64.fractionL = (dl.l & IEEE754BINARY64_FRACTIONL) >> IEEE754BINARY64_FRACTIONL_SHIFT;

  return binary64;
}

double IEEE754Binary64Get(IEEE754BINARY64 binary64)
{
  DoubleLong dl;
  dl.l = 0;

  dl.l += (FQWORD)binary64.sign      << IEEE754BINARY64_SIGN_SHIFT;
  dl.l += (FQWORD)binary64.exponent  << IEEE754BINARY64_EXPONENT_SHIFT;
  dl.l += (FQWORD)binary64.fractionH << IEEE754BINARY64_FRACTIONH_SHIFT;
  dl.l += (FQWORD)binary64.fractionH << IEEE754BINARY64_FRACTIONL_SHIFT;

  return dl.d;
}

IEEE754BINARY64 IEEE754Binary64FtoI(double d)
{
  IEEE754BINARY64 binary64;
  DoubleLong dl;
  dl.d = d;

  binary64.sign      = (dl.l & IEEE754BINARY64_SIGN)      >> IEEE754BINARY64_SIGN_SHIFT;
  binary64.exponent  = (dl.l & IEEE754BINARY64_EXPONENT)  >> IEEE754BINARY64_EXPONENT_SHIFT;
  binary64.fractionH = (dl.l & IEEE754BINARY64_FRACTIONH) >> IEEE754BINARY64_FRACTIONH_SHIFT;
  binary64.fractionL = (dl.l & IEEE754BINARY64_FRACTIONL) >> IEEE754BINARY64_FRACTIONL_SHIFT;

  return binary64;
}

double IEEE754Binary64ItoF(IEEE754BINARY64 binary64)
{
  DoubleLong dl;
  dl.l = 0;

  dl.l += (FQWORD)binary64.sign      << IEEE754BINARY64_SIGN_SHIFT;
  dl.l += (FQWORD)binary64.exponent  << IEEE754BINARY64_EXPONENT_SHIFT;
  dl.l += (FQWORD)binary64.fractionH << IEEE754BINARY64_FRACTION_SHIFT;
  dl.l += (FQWORD)binary64.fractionL << IEEE754BINARY64_FRACTIONL_SHIFT;

  return dl.d;
}





typedef union tagLDoubleLLong
{
  long double ld;
  struct tagLDoubleLLongL
  {
    FQWORD lh;
    FQWORD ll;
  };
} LDoubleLLong;

IEEE754BINARY128 IEEE754Binary128Create(void)
{
  IEEE754BINARY128 binary128;

  binary128.sign      = 0;
  binary128.exponent  = 16384;
  binary128.fractionH = 0;
  binary128.fractionL = 0;

  return binary128;
}

IEEE754BINARY128 IEEE754Binary128Set(IEEE754BINARY128 binary128, long double ld)
{
  LDoubleLLong ldll;
  ldll.ld = ld;

  binary128.sign      = (ldll.lh & IEEE754BINARY128_SIGN)      >> IEEE754BINARY128_SIGN_SHIFT;
  binary128.exponent  = (ldll.lh & IEEE754BINARY128_EXPONENT)  >> IEEE754BINARY128_EXPONENT_SHIFT;
  binary128.fractionH = (ldll.lh & IEEE754BINARY128_FRACTIONH) >> IEEE754BINARY128_FRACTIONH_SHIFT;
  binary128.fractionL = (ldll.ll & IEEE754BINARY128_FRACTIONL) >> IEEE754BINARY128_FRACTIONL_SHIFT;

  return binary128;
}

long double      IEEE754Binary128Get(IEEE754BINARY128 binary128)
{
  LDoubleLLong ldll;
  ldll.lh = 0;
  ldll.ll = 0;

  ldll.lh += (FQWORD)binary128.sign      << IEEE754BINARY128_SIGN_SHIFT;
  ldll.lh += (FQWORD)binary128.exponent  << IEEE754BINARY128_EXPONENT_SHIFT;
  ldll.lh +=         binary128.fractionH << IEEE754BINARY128_FRACTIONH_SHIFT;
  ldll.ll +=         binary128.fractionL << IEEE754BINARY128_FRACTIONL_SHIFT;

  return ldll.ld;
}

IEEE754BINARY128 IEEE754Binary128FtoI(long double ld)
{
  IEEE754BINARY128 binary128;
  LDoubleLLong ldll;
  ldll.ld = ld;

  binary128.sign      = (ldll.lh & IEEE754BINARY128_SIGN)      >> IEEE754BINARY128_SIGN_SHIFT;
  binary128.exponent  = (ldll.lh & IEEE754BINARY128_EXPONENT)  >> IEEE754BINARY128_EXPONENT_SHIFT;
  binary128.fractionH = (ldll.lh & IEEE754BINARY128_FRACTIONH) >> IEEE754BINARY128_FRACTIONH_SHIFT;
  binary128.fractionL = (ldll.ll & IEEE754BINARY128_FRACTIONL) >> IEEE754BINARY128_FRACTIONL_SHIFT;

  return binary128;
}

long double      IEEE754Binary128ItoF(IEEE754BINARY128 binary128)
{
  LDoubleLLong ldll;
  ldll.lh = 0;
  ldll.ll = 0;

  ldll.lh += (FQWORD)binary128.sign      << IEEE754BINARY128_SIGN_SHIFT;
  ldll.lh += (FQWORD)binary128.exponent  << IEEE754BINARY128_EXPONENT_SHIFT;
  ldll.lh +=         binary128.fractionH << IEEE754BINARY128_FRACTIONH_SHIFT;
  ldll.ll +=         binary128.fractionL << IEEE754BINARY128_FRACTIONL_SHIFT;

  return ldll.ld;
}