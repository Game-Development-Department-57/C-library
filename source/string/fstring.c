/* 
date:2023-12-15
name:fstring.c
make:Fujiwara
path:string.fstring
 */

#include <stdio.h>
#include <stdlib.h>

#include "cstring.h"
#include "fstring_error.h"
/*
#define FSTRING_SCCESS          1
#define FSTRING_ERROR           0
#define FSTRING_ARGUMENT_ERROR -1
#define FSTRING_OUT_OF_RANGE   -2
*/




typedef struct tagFString
{
  int   size;       // 使用済み領域
  int   reserved;   // 予約済み領域
  char* string;     // 実体へのポインタ bufferを使う場合はbufferのポインタ
  char  buffer[16]; // 長さ16未満の領域
} FString;


int FStringReservedSize(int size)
{
  return 16 * (size / 16 + 1);
}

char* FStringAlloc(int size)
{
  return malloc(sizeof(char) * FStringReservedSize(size));
}

FString* FStringInit(int size)
{
  if (size < 0) return NULL;
  
  FString* string = (FString*) malloc(sizeof(FString));
  if (string == NULL) return NULL;
  
  if (size < 16)
  {
    string->size = size;
    string->reserved = 16;
    string->string = string->buffer;
    return string;
  }
  
  int reserved = FStringReservedSize(size);
  string->size = size;
  string->reserved = reserved;
  string->string = (char*) malloc(sizeof(char) * reserved); // FStringAlloc(size);
  if (string->string == NULL)
  {
    free(string);
    return NULL;
  }
  
  return string;
}

void FStringDelete(FString* string)
{
  if (string == NULL) return;
  
  if (string->reserved > 16)
    free(string->string);
  free(string);
  return;
}

FString* FStringSet(char* str)
{
  int size = CStringLength(str);
  FString* string = FStringInit(size);
  if (string == NULL) return NULL;
  
  CStringCopy(string->string, str, size);
  
  return string;
}

int FStringReset(FString* string, char* str)
{
  if (str == NULL) return FSTRING_ERROR;
  
  if (string == NULL)
  {
    string = FStringSet(str);
    return FSTRING_SCCESS;
  }
  
  int size = CStringLength(str);
  if (string->reserved < size)
  {
    char* buffer;
    if (string->string == string->buffer){
      buffer = FStringAlloc(size);
      if (buffer == NULL) return FSTRING_ERROR;
      CStringCopy(buffer, string->string, size);
    }
    else
    {
      buffer = realloc(string->string, size);
      if (buffer == NULL) return FSTRING_ERROR;
    }
    
    string->string = buffer;
  }
  
  CStringCopy(string->string, str, size);
  return FSTRING_SCCESS;
}

int FStringResize(FString* string, int target_size)
{
  char* ptr = realloc(string->string, FStringReservedSize(target_size));
  if (ptr == NULL) return FSTRING_ERROR;
  string->string = ptr;
  return FSTRING_SCCESS;
}

int FStringAutoResize(FString* string)
{
  char* ptr = realloc(string->string, FStringReservedSize(CStringLength(string->string)));
  if (ptr == NULL) return FSTRING_ERROR;
  string->string = ptr;
  return FSTRING_SCCESS;
}

int FStringFill(FString* string, char charactor)
{
  int length = CStringLength(string->string);
  for (int index = 0; index < length; index++) string->string[index] = charactor;
  return FSTRING_SCCESS;
}