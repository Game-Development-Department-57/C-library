#include <stdlib.h>

#include "data/ftype.h"
#include "binary/binary.h"

typedef struct tagVECTOR
{
  size_t length;
  size_t reserved;
  FBYTE* vector;
  FBYTE  buffer[32];
} VECTOR;

size_t vectorReservedSize(size_t size)
{
  return 16 * (size / 16 + 2);
}

FBYTE* vectorAlloc(size_t size)
{
  return (FBYTE*) malloc(VectorReservedSize(size));
}

VECTOR* vectorInit(size_t size)
{
  if (size < 0) return NULL;
  VECTOR* vector = (VECTOR*) malloc(sizeof(VECTOR));
  if (vector == NULL) return NULL;
  
  vector->length   = size;
  vector->reserved = vectorReservedSize(size);
  if (vector->reserved <= 32)
  {
    vector->reserved = 32;
    vector->vector   = vector->buffer;
  }else
  {
    vector->vector = (FBYTE*) malloc(vector->reserved);
    if (vector->vector == NULL) {free(vector); return NULL;}
  }
  
  return vector;
}

int vectorResize(VECTOR* vector, size_t size)
{
  size_t reserved_size = vectorReservedSize(size);
  
  if (reserved_size <= 32)
  {
    if (vector->reserved > 32)
      binaryCpy((void*)vector->buffer, (void*)vector->vector, 32);
    else
      ;
  }else if (vector->reserved <= 32)
  {
    FBYTE* buffer = malloc(reserved_size);
    if (buffer == NULL) {return -1;}
    vector->vector = buffer;
    binaryCpy((void*)vector->vector, (void*)vector->buffer, 32);
  }else if (vector->reserved >= reserved_size)
  {
    if ((vector->reserved - reserved_size) >= 32)
    {
      FBYTE* buffer = (FBYTE*) realloc(vector->vector, reserved_size);
      if (buffer == NULL) {return -1;}
      vector->vector = buffer;
    }else 
    {
      ;
    }
  }else if (vector->vector < reserved_size)
  {
    FBYTE* buffer = (FBYTE*) realloc(vector->vector, reserved_size);
    if (buffer == NULL) {return -1;}
    vector->vector = buffer;
  }
  vector->reserved = reserved_size;
  return 0;
}

size_t vectorGetReserved(VECTOR* vector)
{
  return vector->reserved;
}

size_t vectorGetSize(VECTOR* vector)
{
  return vector->size;
}
void*  vectorGetBuffer(VECTOR* vector)
{
  return (void*) vector->vector;
}
