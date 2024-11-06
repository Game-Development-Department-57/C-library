#include <stdlib.h>
#include "err.h"
#include "vector.h"

typedef struct tagVECTOR
{
  size_t length;
  size_t reserved;
  char*  vector;
  char   buffer[32];
} VECTOR, *Vector;

Vector vectorCreate(void)
{
  Vector vec = (Vector)malloc(sizeof(VECTOR));
  if (vec == NULL) return NULL;
  
  vec->length   = 0;
  vec->reserved = 32;
  vec->vector   = vec->buffer;
  vec->buffer   = NULL;
  
  return vec;
}

void   vectorDelete(Vector vec)
{
  if (vec == NULL) return;
  
  if (vec->vector != vec->buffer)
    free(vec->vector);
  free(vec);
  
  return;
}

err    vectorAdd(Vector vec, Item item)
{
  
}

err    vectorDel(Vector vec, Index index){}

err    vectorCrean(Vector vec){}

err    vectorFill(Vector vec, Item item){}

Item   vectorGet(Vector vec, Index index){}

err    vectorSet(Vector vec, Index index, Item item){}

Index  vectorLength(Vector vec){}

Vector vectorCopy(Vector vec){}
