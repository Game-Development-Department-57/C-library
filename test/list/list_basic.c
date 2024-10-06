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
  if (list == NULL) return LIST_ERROR_LISTNULL;
  
  LISTNODE* list_node = listNodeCreate();
  if (list_node == NULL) return LIST_ERROR_ALLOCNULL;
  
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
  if (list == NULL) return LIST_ERROR_LISTNULL;
  if (!listIndexRange(list, index)) return LIST_ERROR_OUTOFRANGE;
  
  LISTNODE* list_node = listAccess(list, index);
  if (list_node == NULL) return LIST_ERROR_ACCESSNULL;
  
  if (listIsBegin(list, index)) list->begin           = list_node->next;
  else                          list_node->prev->next = list_node->next;
  if (listIsEnd(list, index))   list->end             = list_node->prev;
  else                          list_node->next->prev = list_node->prev;
  
  
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
  if (list == NULL) return LIST_ERROR_LISTNULL;
  LISTNODE *next, *now;
  
  now = list->begin;
  for (Index index = 0; index < list->length; index++)
  {
    next = now->next;
    free(now);
    now = next;
  }
  
  list->length = 0;
  
  return LIST_ERROR_SUCCESS;
}

err     listFill(List list, Item item)
{
  if (list == NULL) return LIST_ERROR_LISTNULL;
  
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
  if (list == NULL) return NULL;
  if (!listIndexRange(list, index)) return NULL;
  LISTNODE* list_node = listAccess(list, index);
  if (list_node == NULL) return NULL;
  return list_node->item;
}

err     listSet(List list, Index index, Item item)
{
  if (list == NULL) return LIST_ERROR_LISTNULL;
  if (!listIndexRange(list, index)) return LIST_ERROR_OUTOFRANGE;
  LISTNODE* list_node = listAccess(list, index);
  if (list_node == NULL) return LIST_ERROR_ACCESSNULL;
  list_node->item = item;
  return LIST_ERROR_SUCCESS;
}

int     listLength(List list)
{
  if (list == NULL) return -1;
  return list->length;
}

List listCopy(List list)
{
  if (list == NULL) return NULL;
  
  List list_ = listCreate();
  for (int i = 0; i < list->length; i++)
    listAdd(list_, listGet(list, i));
  
  return list_;
}
