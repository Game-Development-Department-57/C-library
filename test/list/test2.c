#include <stdio.h>
#include "list.h"

int main(void)
{
  printf("This is test2\n");
  
  wrap_alloc_init("listTest2AllocLog.txt");
  wrap_log_header();
  
  List list = listCreate();
  for (int i = 0; i < 10000; i++)
    listAdd(list, (void*)i);
  for (int i = 0; i < 10000; i++)
    listDel(list, 0);
  listDelete(list);
  list = NULL;
  
  wrap_alloc_fini();
  return 0;
}