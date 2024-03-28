#ifndef DATA_LIST_LIST_BASE_H
#define DATA_LIST_LIST_BASE_H


#include "list_types.h"


Index     listIndexConvet(Index index);
Index     listIndexConvetP(Index index);
Index     listIndexConvetN(Index index);
int       listIndexRange(List list, Index index);
LISTNODE* listNodeCreate(void);
LISTNODE* listAccess(List list, Index index);


#endif
