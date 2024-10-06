#ifndef DATA_LIST_LIST_TYPES_H
#define DATA_LIST_LIST_TYPES_H

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

#endif