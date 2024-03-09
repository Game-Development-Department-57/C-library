#ifndef FILE_IMAGE_BITMAP_H
#define FILE_IMAGE_BITMAP_H

#include <stdio.h>
#include <stdlib.h>

//#include "file/image/bitmapformat.h"
#include "bitmapformat.h"

long floord(double a);

int bitmapLineSize(BITMAP* bmp);

int bitmapHeightGet(BITMAP* bmp);

int bitmapWidthGet(BITMAP* bmp);

int bitmapImageSizeGet(BITMAP* bmp);


BITMAP* bitmapHeaderLoad(FILE* fp);


#endif
