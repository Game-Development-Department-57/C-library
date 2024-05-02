#include <stdio.h>

#define LINE_LENGTH 16

void memoryOctDump(void* memory, int length)
{
  unsigned char* dump = (unsigned char*) memory;
  
  /* フォーマットの調整 */
  printf("      ");
  for (int i = 0; i < LINE_LENGTH; i++)
  {
    if (i == 8) printf(" ");
    printf("%02X ", i);
  }
  printf("\n");
  
  /* 実データの出力 */
  for (int index = 0; index < length; )
  {
    printf("%04X: ", index); /* フォーマットの調整 */
    for (int i = 0; i < LINE_LENGTH; i++)
    {
      if ((index + i) == length) break;
      if (i == 8) printf(" ");
      printf("%03o ", (unsigned int)dump[index + i]);
    }
    printf("\n");
    index += LINE_LENGTH;
  }
  
  return;
}

/* 16進数でバイナリ表示を行います */
void memoryHexDump(void* memory, int length)
{
  unsigned char* dump = (unsigned char*) memory;
  
  /* フォーマットの調整 */
  printf("      ");
  for (int i = 0; i < LINE_LENGTH; i++)
  {
    if (i == 8) printf(" ");
    printf("%02X ", i);
  }
  printf("\n");
  
  /* 実データの出力 */
  for (int index = 0; index < length; )
  {
    printf("%04X: ", index); /* フォーマットの調整 */
    for (int i = 0; i < LINE_LENGTH; i++)
    {
      if ((index + i) == length) break;
      if (i == 8) printf(" ");
      printf("%02X ", (unsigned int)dump[index + i]);
    }
    printf("\n");
    index += LINE_LENGTH;
  }
  
  return;
}