#include <stdlib.h>



#include "list_base.h"
#include "list_types.h"
#include "list_error.h"



List*   listCreate(void)
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
  
  LISTNODE* next, now;
  
  now = list->begin;
  for (Index index = 0; index < list->length; index++)
  {
    next = now->next;
    free(now);
  }
  
  return;
}

int     listAdd(List list, Item item)
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
  list->lnegth++;
  
  return LIST_ERROR_SUCCESS;
}

int     listDel(List list, Index index)
{
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

int     listAdds(List list, Item* item){}

int     listDels(List list, Index* index){}

int     listCrean(List list){}

int     listFill(List list, Item){}

Item    listGet(List list, Index index){}

int     listSet(List list, Index index, Item item){}

int     listLength(List list){}


int     listInsert(List list, Index index, Item item){}