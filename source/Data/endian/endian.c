#include <stdlib.h>
#include <string.h>
#include "binary/ftype.h"

static int endian_checker = 1;
static int endian_flag;

__attribute__((constructor))
void endianCheck(void)
{
  if (*(char*) &endian_checker)
  {
    endian_flag = 1;
  }else 
  {
    endian_flag = 0;
  }
  return;
}

int endianGet(void)
{
  return endian_flag;
}

void endianReverse(void* src, int size)
{
  void* ptr = malloc(size);
  if (ptr == NULL) return;
  memcpy(ptr, src, size);
  for (int i = 0; i < size; i++)
    ((char*)src)[i] = ((char*)ptr)[size-i-1];
  free(ptr);
  return;
}

void endianSet(void* src, int size)
{
  if (endian_flag)
  {
    endianReverse(src, size);
  }else
  {
    ;
  }
  return;
}

void endianReverse2(void* dst, void* src, int size)
{
  for (int i = 0; i < size; i++)
    ((char*)dst)[i] = ((char*)src)[size-i-1];
  return;
}

void endianSet2(void* dst, void* src, int size)
{
  if (endian_flag)
  {
    endianReverse2(dst, src, size);
  }else
  {
    ;
  }
  return;
}