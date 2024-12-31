#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include "err.h"
#include "vectorv_base.h"
#include "vectorv_type.h"
#include "vectorv_error.h"


int vectorvInRange(VectorV vec, size_t index)
{
  size_t max_index = vec->using_length / vec->element_size;
  if (index < 0) return 0;
  if (max_index <= index) return 0;
  return 1;
}

void* vectorvAccess(VectorV vec, size_t index)
{
  return (void*)&(((uint8_t*)vec->buf)[vec->element_size * index]);
}

/*
要求:
全ての引数が正しいこと
関数:
インデックスの範囲
要素へのアクセス(ポインタの返却)
*/
