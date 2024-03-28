#include <stdlib.h>
#include "list_types.h"

Index     listIndexConvert(Index index)
{
  return -index-1;
}

Index     listIndexConvertP(Index index)
{
  return (index < 0) ? -index-1 : index;
}

Index     listIndexConvertN(Index index)
{
  return (index < 0) ? index : -index-1;
}

int       listIndexRange(List list, Index index)
{
  return (-list->length-1 < index) && (index < list->index);
}

int       listIsBegin(List list, Index index)
{
  return 0 == listIndexConvetP(index);
}

int       listIsEnd(List list, Index index)
{
  return list->length-1 == listIndexConvetP(index);
}

LISTNODE* listNodeCreate(void)
{
  return (LISTNODE*) malloc(sizeof(LISTNODE));
}

LISTNODE* listAccess(List list, Index index)
{
  if (!listIndexRange(list, index)) return NULL;
  
  LISTNODE* now;
  if (index < 0)
  {
    now = list->end;
    for (; -1 > index; index++)
      now = now->prev;
  }else
  {
    now = list->begin;
    for (; index > 0; index--)
      now = now->next;
  }
  
  return now;
}