#include <stdio.h>
#include "list.h"

int main(void)
{
  printf("This is test1\n");
  
  wrap_alloc_init(WRAP_ALLOC_LOG_OUT_FILE);
  wrap_log_header();
  
  List list = listCreate();
  listAdd(list, NULL);
  listDel(list, 0);
  listDelete(list);
  list = NULL;
  
  wrap_alloc_fini();
  return 0;
}