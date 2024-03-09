#include <stdio.h>

int CStringLength(const char* str)
{
  if (str == NULL) return 0;
  
  int length;
  for (length = 0; str[length] != '\0'; length++){}
  return length + 1;
}

void CStringCopy(char* str2, const char* str1, int size)
{
  if (str2 == NULL || str1 == NULL) return;
  for (int index = 0; index < size; index++)
  {
    str2[index] = str1[index];
  }
  return;
}

