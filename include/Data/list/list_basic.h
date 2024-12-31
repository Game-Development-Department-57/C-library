#ifndef DATA_LIST_LIST_BASIC_H
#define DATA_LIST_LIST_BASIC_H

#include "list_std.h"


List    listCreate(void);
void    listDelete(List list);
err     listAdd(List list, Item item);
err     listDel(List list, Index index);
err     listCrean(List list);
err     listFill(List list, Item item);
Item    listGet(List list, Index index);
err     listSet(List list, Index index, Item item);
int     listLength(List list);
List    listCopy(List list);


#endif