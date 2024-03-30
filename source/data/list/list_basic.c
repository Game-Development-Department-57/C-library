#include <stdlib.h>



#include "list_std.h"
#include "list_base.h"



List    listCreate(void)
{
  List list = (List) malloc(sizeof(LIST));
  if (list == NULL) return NULL;
  
  list->length = 0;
  list->begin  = NULL;
  list->end    = NULL;
  
  return list;
}

void    listDelete(List list)
{
  if (list == NULL) return;
  
  LISTNODE *next, *now;
  
  now = list->begin;
  for (Index index = 0; index < list->length; index++)
  {
    next = now->next;
    free(now);
    now = next;
  }
  
  free(list);
  
  return;
}

err     listAdd(List list, Item item)
{
  if (list == NULL) return -1;
  
  LISTNODE* list_node = listNodeCreate();
  if (list_node == NULL) return -1;
  
  if (list->length == 0)
  {
    list->begin     = list_node;
    list->end       = list_node;
    list_node->prev = NULL;
    list_node->next = NULL;
  }else
  {
    list_node->prev = list->end;
    list_node->next = NULL;
    list->end->next = list_node;
    list->end       = list_node;
  }
  
  list_node->item = item;
  list->length++;
  
  return LIST_ERROR_SUCCESS;
}

err     listDel(List list, Index index)
{
  if (list == NULL) return LIST_ERROR_NULL;
  if (!listIndexRange(list, index)) return LIST_ERROR_NODE_NULL;
  
  LISTNODE* list_node = listAccess(list, index);
  if (list_node == NULL) return LIST_ERROR_ERROR;
  
  list_node->prev->next = list_node->next;
  list_node->next->prev = list_node->prev;
  
  if (listIsBegin(list, index)) list->begin = list_node->next;
  if (listIsEnd(list, index))   list->end   = list_node->prev;
  
  free(list_node);
  
  list->length--;
  if (list->length == 0)
  {
    list->begin = NULL;
    list->end   = NULL;
  }
  
  return LIST_ERROR_SUCCESS;
}

err     listCrean(List list)
{
  LISTNODE *next, *now;
  
  now = list->begin;
  for (Index index = 0; index < list->length; index++)
  {
    next = now->next;
    now->item = NULL;
    now = next;
  }
  
  return LIST_ERROR_SUCCESS;
}

err     listFill(List list, Item item)
{
  LISTNODE *next, *now;
  
  now = list->begin;
  for (Index index = 0; index < list->length; index++)
  {
    next = now->next;
    now->item = item;
    now = next;
  }
  
  return LIST_ERROR_SUCCESS;
}

Item    listGet(List list, Index index)
{
  LISTNODE* list_node = listAccess(list, index);
  if (list_node == NULL) return NULL;
  return list_node->item;
}

err     listSet(List list, Index index, Item item)
{
  LISTNODE* list_node = listAccess(list, index);
  if (list_node == NULL) return LIST_ERROR_ERROR;
  list_node->item = item;
  return LIST_ERROR_SUCCESS;
}

int     listLength(List list)
{
  return list->length;
}

List listCopy(List list)
{
  List l = (List) malloc(sizeof(LIST));
  if (l == NULL) return NULL;
  
  l->length = list->length;
  if (l->length == 0)
  {
    l->begin = NULL;
    l->end   = NULL;
    return l;
  }
  
  LISTNODE *now, *node_now, *node_last;
  long      i, length;
  now       = list->begin;
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
