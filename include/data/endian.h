#ifndef DATA_ENDIAN_H
#define DATA_ENDIAN_H

#include "binary/ftype.h"

int  endianGet(void);
void endianSet(void* src, int size);
void endianReverse(void* src, int size);
void endianReverse2(void* dst, void* src, int size);
void endianSet2(void* dst, void* src, int size);

#endif