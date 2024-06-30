#ifndef DATA_LIST_LIST_H
#define DATA_LIST_LIST_H


#include "list_std.h"


err     listInsert(List list, Index index, Item item);
List    listSplit(List list, Index index);
List    listJoin(List a, List b);
List    listSlice(List list, Index begin, Index end);


#endif