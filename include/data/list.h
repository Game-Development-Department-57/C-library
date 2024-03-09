#ifndef LIST_H
#define LIST_H

typedef struct tagLISTHEADER LISTHEADER; /* リストのヘッダー */
typedef struct tagLISTCONT   LISTCONT;   /* リストの要素 */
typedef           LISTHEADER LIST;       /* ヘッダーがリストの実体 */

int listLength(LIST* list);
int listRenge(LIST* list, int index);
int listConvertIndex(int index);
int listPConvertIndex(int index);
int listNConvertIndex(int index);
int listIsBegin(LIST* list, int index);
int listIsEnd(LIST* list, int index);

LISTCONT* listAlloc(void* item);
LISTCONT* listAccess(LIST* list, int index);
LIST* listNew(void);

LIST* listCreate(void* item);
int listAdd(LIST* list, void* item);
int listDel(LIST* list, int index);
void* listItemGet(LIST* list, int index);
int listItemSet(LIST* list, int index, void* item);

#endif