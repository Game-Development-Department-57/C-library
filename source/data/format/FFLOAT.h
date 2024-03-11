#ifndef DATA_FORMAT_FFLOAT_H
#define DATA_FORMAT_FFLOAT_H

#include "binary/ftype.h"

typedef struct tagFFLOAT16
{
  FDWORD sign     : 1;
  FDWORD exponent : 5;
  FDWORD fraction : 10;
}FFLOAT16;

#endif