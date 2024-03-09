#include <stdio.h>

#include "string/cstring.h"
#include "string/fstring.h"


int main(void)
{
  FString* string = FStringSet("Hello, World!\n");
  printf("length:%d\nstring:%s\n", CStringLength(string->string), string->string);
  int error_code = FStringReset(string, "Hello, World!\nThis is C language.\n");
  printf("error code:%d\n", error_code);
  printf("length:%d\nstring:%s\n", CStringLength(string->string), string->string);
  return 0;
}
