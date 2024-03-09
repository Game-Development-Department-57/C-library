#include <stdlib.h>
#include "list.h"

typedef struct tagLISTHEADER
{
  int       length;
  LISTCONT* begin;
  LISTCONT* end;
} LISTHEADER;

typedef struct tagLISTCONT
{
  void*     item;
  LISTCONT* prev;
  LISTCONT* next;
} LISTCONT;

typedef LISTHEADER LIST;


int listLength(LIST* list)
{
  if (list == NULL) return -1;
  return list->length;
}

int listRenge(LIST* list, int index)
{
  if (   ( index   < listLength(list))
      && (-index-1 < listLength(list)))
    return 0;
  return -1;
}

int listConvertIndex(int index)
{
  return -index-1;
}

int listPConvertIndex(int index)
{
  return (index < 0) ? listConvertIndex(index) : index;
}

int listNConvertIndex(int index)
{
  return (index > -1) ? listConvertIndex(index) : index;
}

int listIsBegin(LIST* list, int index)
{
  return list->begin == listAccess(list, index);
}

int listIsEnd(LIST* list, int index)
{
  return list->end   == listAccess(list, index);
}



LISTCONT* listAlloc(void* item)
{
  LISTCONT* cont = (LISTCONT*) malloc(sizeof(LISTCONT));
  if (cont == NULL) return NULL;
  
  cont->item = item;
  cont->prev = NULL;
  cont->next = NULL;
  
  return cont;
}

LISTCONT* listAccess(LIST* list, int index)
{
  int       now;
  LISTCONT* cont;

  if (listRenge(list, index))
    return NULL;

  if (index < 0)
  {
    now  = -1;
    cont = list->end;
    for (; now > index; now--)
      cont = cont->prev;
  } else
  {
    now  = 0;
    cont = list->begin;
    for (; now < index; now++)
      cont = cont->next;
  }
  
  return cont;
}

LIST* listNew(void)
{
  LIST* list = (LIST*) malloc(sizeof(LIST));
  if (list == NULL) return NULL;
  
  list->length = 0;
  list->begin  = NULL;
  list->end    = NULL;
  
  return list;
}

LIST* listCreate(void* item)
{
  LIST* list = listNew();
  if (list == NULL) return NULL;
  
  LISTCONT* cont = listAlloc(item);
  if (cont == NULL) 
  {
    free(list);
    return NULL;
  }

  list->length = 1;
  list->begin  = cont;
  list->end    = cont;
  
  return list;
}

int listAdd(LIST* list, void* item)
{
  LISTCONT* next = listAlloc(item);
  if (next == NULL) return -1;
  
  LISTCONT* prev = listAccess(list, -1);
  prev->next = next;
  next->prev = prev;
  list->length++;
  list->end = next;
  return 0;
}

int listDel(LIST* list, int index)
{
  LISTCONT* cont = listAccess(list, index);
  if (cont == NULL) return -1;
  cont->prev->next = cont->next;
  cont->next->prev = cont->prev;
  list->length--;
  if (list->begin == cont) list->end   = cont->prev;
  if (list->end   == cont) list->begin = cont->next;
  free(cont);
  
  return 0;
}

void* listItemGet(LIST* list, int index)
{
  LISTCONT* cont = listAccess(list, index);
  if (cont == NULL) return NULL;
  return cont->item;
}

int listItemSet(LIST* list, int index, void* item)
{
  LISTCONT* cont = listAccess(list, index);
  if (cont == NULL) return -1;
  cont->item = item;
  return 0;
}