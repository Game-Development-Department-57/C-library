#include <stdlib.h>

typedef struct tagQUEUE
{
  size_t bufferSize;
  size_t contentSize;
  void*  queuePointer;
  void*  basePointer;
  void*  buffer;
} QUEUE;

typedef QUEUE* Queue;

Queue queueCreate(size_t buffer_size, size_t content_size)
{
  Queue queue = (Queue) malloc(sizeof(QUEUE));
  if (queue == NULL) return NULL;
  
  queue->buffer = (void*) malloc(buffer_size);
  if (queue->buffer == NULL)
  {
    free(queue);
    return NULL;
  }
  
  queue->bufferSize  = buffer_size;
  queue->contentSize = content_size;
}