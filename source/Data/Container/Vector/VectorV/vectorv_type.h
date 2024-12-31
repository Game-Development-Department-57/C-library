#ifndef 
#define 

#define VECTORV_BUFFER_BLOCK_SIZE 16
#define VECTORV_INIT_BUFFER_SIZE  16

typedef struct tagVECTORV
{
  size_t element_size;
  size_t using_length;
  size_t reserved_length;
  void*  buf;
} VECTORV, *VectorV;

#endif
