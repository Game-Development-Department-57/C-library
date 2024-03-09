#include <stdlib.h>

#include "ftype.h"

typedef struct tagVector
{
  int length;
  int reserved;
  FQWORD vector;
  FQWORD buffer[8];
} Vector;

int VectorReservedSize(int length)
{
  return 8 * (length / 8 + 1);
}

FQWORD VectorAlloc(int size)
{
  return (FQWORD) malloc(sizeof(FQWORD) * VectorReservedSize(size));
}

Vector* VectorInit(int size)
{
  if (size < 0) return NULL;
}