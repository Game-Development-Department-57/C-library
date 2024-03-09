#include <stdio.h>

/* 16進数でバイナリ表示を行います */
void BinaryDump(unsigned char* memory, int length, int line_length)
{
  /* フォーマットの調整 */
  printf("      ");
  for (int i = 0; i < line_length; i++)
  {
    if (i == 8) printf(" ");
    printf("%02X ", i);
  }
  printf("\n");
  
  /* 実データの出力 */
  for (int index = 0; index < length; )
  {
    printf("%04X: ", index); /* フォーマットの調整 */
    for (int i = 0; i < line_length; i++)
    {
      if ((index + i) == length) break;
      if (i == 8) printf(" ");
      printf("%02X ", memory[index + i]);
    }
    printf("\n");
    index += line_length;
  }
  
  return;
}