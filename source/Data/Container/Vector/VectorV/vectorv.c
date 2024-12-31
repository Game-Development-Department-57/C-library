#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include "err.h"
#include "vectorv_base.h"
#include "vectorv_type.h"
#include "vectorv_error.h"


VectorV vectorvCreate(size_t element_size)
{
  VectorV vec = (VectorV) malloc(sizeof(VECTORV));
  if (vec == NULL) return NULL;
  
  void* buf = malloc(VECTORV_INIT_BUFFER_SIZE * element_size);
  if (buf == NULL) {free(vec); return NULL;}

  vec->element_size    = element_size;
  vec->using_length    = 0;
  vec->reserved_length = VECTORV_INIT_BUFFER_SIZE;
  vec->buf             = buf;

  return vec;
}

void    vectorvDelete(VectorV vec)
{
  if (vec == NULL) return;

  free(vec->buf);
  free(vec);

  return;
}

void    vectorvAdd(VectorV vec, void* buf)
{
  if (vec == NULL) return;
  if (buf == NULL) return;

  if (vec->using_length == vec->reserved_length)
  {
    void* new_buf = realloc(vec->buf, vec->reserved_length+(VECTORV_BUFFER_BLOCK_SIZE*vec->element_size));
    if (new_buf == NULL) return;
    
    vec->buf = new_buf;
    vec->reserved_length += VECTORV_BUFFER_BLOCK_SIZE;
  }
  
  memcpy(&(((uint8_t*)vec->buf)[vec->using_length * vec->element_size]), buf, vec->element_size);
  vec->using_length++;

  return;
}

err     vectorvDel(VectorV vec, size_t index)
{
  if (vec == NULL) return VECTORV_ERROR_VECTORISNULL;
  
  
}

// TODO:error handling