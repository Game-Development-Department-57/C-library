#include <stdlib.h>

#include "data/ftype.h"

typedef struct tagList
{
  struct tagList* header;
  struct tagList* end;
  int size;
  FBYTE* object;
} List;

List* ListInit(int size)
{
  List* list = (List*) malloc(sizeof(List));
  if (list == NULL) return NULL;

  FBYTE* object = (FBYTE*) malloc(sizeof(FBYTE) * size);
  if (object == NULL)
  {
    free(list);
    return NULL;
  }

  list->header = NULL;
  list->end    = NULL;
  list->object = object;
  list->size   = size;

  return list;
}

int ListAdd(List* list)
{
  List* list_ = ListInit(list->size);
  if (list_ == NULL) return 0;

  list->end     = list_;
  list_->header = list;

  return 1;
}

