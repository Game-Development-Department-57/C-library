#include <stdio.h>
#include "list.h"

int main(void)
{
  printf("This is test3\n");
  
  wrap_alloc_init("listTest3AllocLog.txt");
  wrap_log_header();
  
  List list = listCreate();
  for (int i = 0; i < 10000; i++)
    listAdd(list, (void*)i);
  listCrean(list);
  for (int i = 0; i < 100; i++)
    listAdd(list, NULL);
  listDelete(list);
  list = NULL;
  
  wrap_alloc_fini();
  return 0;
}