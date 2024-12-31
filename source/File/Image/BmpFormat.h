#include "data/ftype.h"
// #include "../../data/ftype.h"

typedef struct tagBITMAPCOREHEADER
{
  FDWORD bcSize;
  FWORD  bcWidth;
  FWORD  bcHeight;
  FWORD  bcPlanes;
  FWORD  bcBitCount;
} BITMAPCOREHEADER;

typedef struct tagBITMAPINFOHEADER
{
  FDWORD biSize;
  FINT   biWidth;
  FINT   biHeight;
  FWORD  biPlanes;
  FWORD  biBitCount;
  FDWORD biCompression;
  FDWORD biSizeImage;
  FLONG  biXPelsPerMeter;
  FLONG  biYPelsPerMeter;
  FDWORD biClrUsed;
  FDWORD biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagBITMAPV4HEADER
{
  ;
} BITMAPV4HEADER;

typedef struct tagBITMAPV5HEADER
{
  ;
} BITMAPV5HEADER;

typedef struct tagBITMAPHEADER
{
  int type;
  union tagBITMAPHEADERS
  {
    BITMAPCOREHEADER* Core;
    BITMAPINFOHEADER* Info;
    BITMAPV4HEADER*   V4;
    BITMAPV5HEADER*   V5;
  };
} BITMAPHEADER;

typedef struct tagBITMAPBITFIELD
{
  FDWORD Red;
  FDWORD Green;
  FDWORD Blue;
} BITMAPBITFIELD;

typedef struct tagRGBTRIPLE
{
  FBYTE Red;
  FBYTE Green;
  FBYTE Blue;
} RGBTRIPLE;

typedef struct tagRGBQUAD
{
  FBYTE Red;
  FBYTE Green;
  FBYTE Blue;
  FBYTE Alpha;
} RGBQUAD;

typedef struct tagBITMAPCOLORPALETTE
{
  int type;
  union tagBITMAPCOLORPALETTES
  {
    RGBTRIPLE* Triple;
    RGBQUAD*   Quad;
  };
} BITMAPCOLORPALETTE;

typedef struct tagBITMAPFILEHEADER
{
  BITMAPHEADER       info;
  BITMAPBITFIELD     field;
  BITMAPCOLORPALETTE pallete;
} BITMAPFILEHEADER;