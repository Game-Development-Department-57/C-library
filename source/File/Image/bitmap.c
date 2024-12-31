#include <stdio.h>
#include <stdlib.h>

//#include "file/image/bitmapformat.h"
#include "bitmapformat.h"

long floord(double a)
{
  return (a < 0) ? (long) a - 1 : (long) a;
}

int bitmapLineSize(BITMAP* bmp)
{
  BITMAPINFOHEADER* info = (BITMAPINFOHEADER*) bmp->info;
  return floord((info->width * info->pixelBit + 31) / 32) * 4;
}

int bitmapHeightGet(BITMAP* bmp)
{
  BITMAPINFOHEADER* info = (BITMAPINFOHEADER*) bmp->info;
  return info->height;
}

int bitmapWidthGet(BITMAP* bmp)
{
  BITMAPINFOHEADER* info = (BITMAPINFOHEADER*) bmp->info;
  return info->width;
}

int bitmapImageSizeGet(BITMAP* bmp)
{
  BITMAPINFOHEADER* info = (BITMAPINFOHEADER*) bmp->info;
  return info->imageSize;
}


BITMAP* bitmapHeaderLoad(FILE* fp)
{
  BITMAP* bmp = (BITMAP*) malloc(sizeof(BITMAP));
  if (bmp == NULL) return NULL;
  bmp->header = (void*) malloc(sizeof(BITMAPHEADER));
  if (bmp->header == NULL)
  {
    free(bmp);
    return NULL;
  }
  bmp->info = (void*) malloc(sizeof(BITMAPINFOHEADER));
  if (bmp->info == NULL)
  {
    free(bmp->header);
    free(bmp);
    return NULL;
  }
  
  fseek(fp, 0, SEEK_SET);
  fread(bmp->header, sizeof(BITMAPHEADER), 1, fp);
  int size;
  fread(&size, 4, 1, fp);
  if (size != 40) return NULL; // errorライブラリを追加予定
  fseek(fp, -4, SEEK_CUR);
  fread(bmp->info, 40, 1, fp);
  return bmp;
}