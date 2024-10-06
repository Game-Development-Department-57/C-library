#include <stdio.h>
#include "list.h"

int main(void)
{
  printf("This is test4\n");
  
  wrap_alloc_init("listTest4AllocLog.txt");
  wrap_log_header();
  
  List list = listCreate();
  for (int i = 0; i < 10000; i++)
    listAdd(list, (void*)i);
  List new_list = listCopy(list);
  listDelete(list);
  listAdd(new_list, &new_list);
  printf("stdout: %p\n", listGet(list, -1));
  listDelete(new_list);
  list     = NULL;
  new_list = NULL;
  
  wrap_alloc_fini();
  return 0;
}