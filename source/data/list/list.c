#include <stdlib.h>

#include "list_std.h"
#include "list_base.h"
#include "list_basic.h"

err     listInsert(List list, Index index, Item item)
{
  if (list == NULL) return LIST_ERROR_LISTNULL;
  if (!listIndexRange(list, index)) return LIST_ERROR_OUTOFRANGE;
  
  LISTNODE* node = listNodeCreate();
  if (node == NULL) return LIST_ERROR_ALLOCNULL;
  
  LISTNODE* next   = listAccess(list, index);
  node->item       = item;
  
  node->prev       = next->prev;
  node->next       = next;
  next->prev->next = node;
  next->prev       = node;
  list->length++;
  
  return LIST_ERROR_SUCCESS;
}

List    listSplit(List list, Index index)
{
  if (list == NULL)                 return NULL;
  if (!listIndexRange(list, index)) return NULL;
  
  List list_ = listCreate();
  if (list_ == NULL) return NULL;
  
  index = listIndexConvertP(list, index);
  list_->begin  = listAccess(list, index);
  list_->end    = list->end;
  list_->length = list->length - index;
  list->end     = listAccess(list, index-1);
  list->length  = index;
  
  return list_;
}

List    listJoin(List a, List b)
{
  if (a == NULL) return NULL;
  if (b == NULL) return NULL;
  
  List list = listCreate();
  if (list == NULL) return NULL;
  for (int i = 0; i < a->length; i++)
    listAdd(list, listGet(a, i));
  for (int i = 0; i < b->length; i++)
    listAdd(list, listGet(b, i));
  
  return list;
}

List    listSlice(List list, Index begin, Index end)
{
  if (list == NULL) return NULL;
  if (!listIndexRange(list, begin)) return NULL;
  if (!listIndexRange(list, end)) return NULL;
  
  List list_ = listCreate();
  if (list_ == NULL) return NULL;
  
  begin = listIndexConvertP(list, begin);
  end   = listIndexConvertP(list, end);
  
  for (int i = begin; i < end; i++)
    listAdd(list_, listGet(list, i));
  
  return list_;
}


List listCopyDeep(List list)
{
  if (list == NULL) return NULL;
  
  List list_ = listCreate();
  for (int i = 0; i < list->length; i++)
    listAdd(list_, listGet(list, i));
  
  return list_;
}

List listCopyShallow(List list)
{
  if (list == NULL) return NULL;
  
  List list_ = listCreate();
  if (list_ == NULL) return NULL;
  list_->length = list->length;
  list_->begin  = list->begin;
  list_->end    = list->end;
  
  return list_;
}


Index listFind(List list, Item item)
{
  for (long i = 0; i < list->length; i++)
  {
    if (listGet(list, i) == item)
      return (Index)i;
  }
  return (Index) -1;
}

err listReverse(List list)
{
  if (list == NULL) return LIST_ERROR_LISTNULL;
  
  Item temp;
  long max_index = list->length / 2;
  for (long i = 0; i < max_index; i++)
  {
    temp = listGet(list, i);
    listSet(list, i, listGet(list, -i-1));
    listSet(list, -i-1, temp);
  }
  
  return LIST_ERROR_SUCCESS;
}