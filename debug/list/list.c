#include <stdlib.h>

#include "list_std.h"
#include "list_base.h"
#include "list_basic.h"

err     listInsert(List list, Index index, Item item)
{
  if (list == NULL) return LIST_ERROR_LISTNULL;
  if (!listIndexRange(list, index)) return LIST_ERROR_OUTOFRANGE;
  
  LISTNODE* node = listNodeCreate();
  if (node == NULL) return LIST_ERROR_ACCESSNULL;
  
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
  
  LISTNODE* node = listAccess(list, index);
  if (node == NULL) return NULL;
  List      list_ = listCreate();
  if (list_ == NULL) return NULL;
  
  list_->begin  = node;
  list_->end    = list->end;
  list->end     = node->prev;
  list_->length = list->length - listIndexConvertP(index);
  list->length  = listIndexConvertP(index);
  
  list_->begin->prev = NULL;
  list_->end->next   = NULL;
  
  return list_;
}

List    listJoin(List a, List b)
{
  if (a == NULL) return NULL;
  if (b == NULL) return NULL;
  
  a->end->next = b->begin;
  b->begin     = a->end;
  a->end       = b->end;
  a->length   += b->length;
  
  free(b);
}

List    listSlice(List list, Index begin, Index end)
{
  if (list == NULL) return NULL;
  if (!listIndexRange(list, begin)) return NULL;
  if (!listIndexRange(list, end)) return NULL;
  
  List l = (List) malloc(sizeof(LIST));
  if (l == NULL) return NULL;
  
  l->length = listIndexConvertP(end) - listIndexConvertP(begin);
  if (l->length == 0)
  {
    l->begin = NULL;
    l->end   = NULL;
    return l;
  }
  
  LISTNODE *now, *node_now, *node_last;
  long      i, length;
  now       = listAccess(list, begin);
  node_now  = NULL;
  node_last = NULL;
  i         = 0;
  length    = l->length-1;
  
  node_now = listNodeCreate();
  if (node_now == NULL) goto exception;
  node_now->item = now->item;
  node_now->prev = node_last;
  node_last = node_now;
  now       = now->next;
  l->begin  = node_now;
  
  for (; i < length; i++)
  {
    node_now = listNodeCreate();
    if (node_now == NULL) goto exception;
    node_now->item = now->item;
    node_now->prev = node_last;
    
    node_last = node_now;
    now       = now->next;
  }
  
  l->end = node_now;
  
  return l;
  
  
  exception:
  LISTNODE* next;
  now = NULL; // 再利用
  now = l->begin;
  for (long index = 0; index < i; index++)
  {
    next = now->next;
    free(now);
    now = next;
  }
  free(l);
  
  return NULL;
}
