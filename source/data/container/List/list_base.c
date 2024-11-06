#include <stdlib.h>
#include "list_std.h"

Index     listIndexConvert(List list, Index index)
{
  return (index < 0) ? list->length + index : index - list->length;
}

Index     listIndexConvertP(List list, Index index)
{
  return (index < 0) ? list->length + index : index;
}

Index     listIndexConvertN(List list, Index index)
{
  return (index < 0) ? index : index - list->length;
}

int       listIndexRange(List list, Index index)
{
  return (-list->length-1 < index) && (index < list->length);
}

int       listIsBegin(List list, Index index)
{
  return listIndexConvertP(list, index) == 0;
}

int       listIsEnd(List list, Index index)
{
  return listIndexConvertP(list, index) == list->length-1;
}

LISTNODE* listNodeCreate(void)
{
  return (LISTNODE*) malloc(sizeof(LISTNODE));
}

LISTNODE* listAccess(List list, Index index)
{
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
