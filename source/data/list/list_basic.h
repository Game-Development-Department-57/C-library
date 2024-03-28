#ifndef DATA_LIST_LIST_BASIC_H
#define DATA_LIST_LIST_BASIC_H

typedef struct tagLIST     LIST;
typedef struct tagLISTNODE LISTNODE;
typedef LIST* List;
typedef long  Index;
typedef void* Item;

typedef struct tagLIST
{
  long      length;
  LISTNODE* begin;
  LISTNODE* end;
} LIST;

typedef struct tagLISTNODE
{
  Item      item;
  LISTNODE* prev;
  LISTNODE* next;
} LISTNODE;


List*   listCreate(void);
void    listDelete(List list);
int     listAdd(List list, Item item);
int     listDel(List list, Index index);
int     listAdds(List list, Item* item);
int     listDels(List list, Index* index);
int     listCrean(List list);
int     listFill(List list, Item);
Item    listGet(List list, Index index);
int     listSet(List list, Index index, Item item);
int     listLength(List list);

int     listInsert(List list, Index index, Item item);

#endif