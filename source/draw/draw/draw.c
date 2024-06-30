/* 
date:2023-11-11
name:draw.c
path:library/draw/draw/draw.c
made:Fujiwara
 */

/*
* RawImage構造体
* Init関数
* Delete関数
* Fill関数
* AllFill関数
* Pointing関数
* Triangle関数
* Quadrangle関数
* TriangleSide関数
* QuadrangleSide関数
* Cut関数
* Scaling関数
 */





#include <stdlib.h>
#include "binary/binary.h" /* library/binary/binary.h */
#include "binary/ftype.h"





typedef struct tagDrawColor
{
  FBYTE Red;
  FBYTE Green;
  FBYTE Blue;
  FBYTE Alpha;
} drawColor;

typedef struct tagDrawRawImage
{
  int        x;
  int        y;
  drawColor* image;
} drawRawImage;

typedef struct tagDrawPoint
{
  int x;
  int y;
} drawPoint, drawSize;





/* int drawImageIndex(drawRawImage image, FDWORD x, FDWORD y) */
#define drawImageIndex(image_, x_, y_) (image_->x * y_ + x_)





drawRawImage* drawInit(drawSize size)
{
  drawRawImage* image = (drawRawImage*) malloc(sizeof(drawRawImage));
  image->x = size.x;
  image->y = size.y;
  image->image = (drawColor*) malloc(sizeof(drawColor) * (size.y * size.x));
  
  return image;
}

void drawDelte(drawRawImage* image)
{
  free(image->image);
  free(image);
  
  return;
}

void drawFill(drawRawImage* image, drawPoint point , drawSize size, drawColor color)
{
  for (int index_y = point.y; index_y < (point.y + size.y); index_y++)
  {
    for (int index_x = point.x; index_x < (point.x + size.x); index_x++)
    {
      image->image[drawImageIndex(image, index_x, index_y)] = color;
    }
  }
  
  return;
}

void drawAllFill(drawRawImage* image, drawColor color)
{
  for (int index_y = 0; index_y < image->y; index_y++)
  {
    for (int index_x = 0; index_x < image->x; index_x++)
    {
      image->image[drawImageIndex(image, index_x, index_y)] = color;
    }
  }
  
  return;
}

void drawPointing(drawRawImage* image, drawPoint point, drawColor color)
{
  image->image[drawImageIndex(image, point.x, point.y)] = color;
  
  return;
}

void drawTriangle(drawRawImage* image, drawPoint point1, drawPoint point2, drawPoint point3, drawColor color)
{
  return;
}

void drawQuadrangle(drawRawImage* image, drawPoint point1, drawPoint point2, drawPoint point3, drawPoint point4, drawColor color)
{
  return;
}

void drawTriangleSide(drawRawImage* image, drawPoint point1, drawPoint point2, drawPoint point3, int width, drawColor color)
{
  return;
}

void drawQuadrangleSide(drawRawImage* image, drawPoint point1, drawPoint point2, drawPoint point3, drawPoint point4, int width, drawColor color)
{
  return;
}

drawRawImage* drawCut(drawRawImage* image, drawPoint point1, drawPoint point2)
{
  return image;
}

drawRawImage* drawScaling(drawRawImage* image, drawPoint point1)
{
  return image;
}
