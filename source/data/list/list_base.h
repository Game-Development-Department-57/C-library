#ifndef DATA_LIST_LIST_BASE_H
#define DATA_LIST_LIST_BASE_H


#include "list_types.h"


Index     listIndexConvert(List list, Index index);
Index     listIndexConvertP(List list, Index index);
Index     listIndexConvertN(List list, Index index);
int       listIsBegin(List list, Index index);
int       listIsEnd(List list, Index index);
int       listIndexRange(List list, Index index);
LISTNODE* listNodeCreate(void);
LISTNODE* listAccess(List list, Index index);


#endif
