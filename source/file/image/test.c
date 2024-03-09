#include <stdio.h>
#include "bitmap.h"
#include "binary/memory.h"

int main(void)
{
  FILE* fp = fopen("sample.bmp", "rb");
  BITMAP* bmp = bitmapHeaderLoad(fp);
  if (bmp == NULL)
  {
    printf("no.\n");
  }else
  {
    printf("header\n");
    BinaryDump((unsigned char*)bmp->header, 14, 16);
    printf("info\n");
    BinaryDump((unsigned char*)bmp->info, 40, 16);
    printf("line size :%d\n", bitmapLineSize(bmp));
    printf("image size:%d\n", bitmapImageSizeGet(bmp));
    printf("image size:%d\n", bitmapHeightGet(bmp) * bitmapLineSize(bmp));
  }
  return 0;
}
