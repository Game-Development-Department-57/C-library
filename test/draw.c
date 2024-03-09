#include "draw/draw/draw.h"

int main(void)
{
  drawRawImage* image = drawInit((drawSize) {20, 20});
  drawAllFill(image, (drawColor) {0x00, 0x00, 0xff, 0xff});
  
  return 0;
}
