#include <stdio.h>
#include "error.h"

#define ERROR_MSG_NEGATIVE "negative."
#define ERROR_MSG_SUCCESS  "success."

int n(int num)
{
  ERROR error;
  if (num < 0)
  {
    error.ret = num;
    error.id  = 1;
    error.buffer = NULL;
    error.message = ERROR_MSG_NEGATIVE;
    errorSet(error);
    return num;
  }
  error.ret = num;
  error.id = 0;
  error.buffer = NULL;
  error.message = ERROR_MSG_SUCCESS;
  errorSet(error);
  return num;
}

int main(void)
{
  n(-2);
  ERROR error = errorGet();
  printf("%s\n", error.message);
}