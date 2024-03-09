#ifndef FILE_IMAGE_COLOR_H
#define FILE_IMAGE_COLOR_H

#include "binary/ftype.h"

typedef struct tagRGBCOLOR
{
  BYTE red;
  BYTE green;
  BYTE blue;
} RGBCOLOR;

typedef struct tagRGBACOLOR
{
  BYTE red;
  BYTE green;
  BYTE blue;
  BYTE alpha;
} RGBACOLOR;

typedef struct tagsRGBCOLOR{} sRGBCOLOR;
typedef struct tagADOBERGBCOLOR{} ADOBRRGBCOLOR;
typedef struct tagCMYKCOLOR{} CMYKCOLOR;

typedef struct tagXYZCOLOR{} XYZCOLOR;
typedef struct tagxyYCOLOR{} xyYCOLOR;
typedef struct tagCIELUVCOLOR{} CIELUVCOLOR;
typedef struct tagCIELABCOLOR{} CIELABCOLOR;

#endif