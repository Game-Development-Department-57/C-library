#ifndef FILE_IMAGE_BITMAP_BITMAPFORMAT_H
#define FILE_IMAGE_BITMAP_BITMAPFORMAT_H

/* 
date:2024/11/21
name:BitmapFormat
make:AQ(MK)
path:File.Image.BITMAP.BitmapFormat
 */

typedef struct tagBITMAPFILEHEADER
{
  DBWORD  type;
  DBDWORD size;
  DBWORD  reserved1;
  DBWORD  reserved2;
  DBDWORD offset;
} BITMAPFILEHEADER, BitmapFileHeader;

typedef struct tagBITMAPCOREHEADER
{
  DBDWORD size;
  DBWORD  width;
  DBWORD  height;
  DBWORD  planeNum;
  DBWORD  pixelSize;
} BITMAPCOREHEADER, BitmapCoreHeader;

typedef struct tagBITMAPINFOHEADER
{
  DBDWORD size;
  DBDWORD width;
  DBDWORD hight;
  DBWORD  planeNum;
  DBWORD  pixelSize;
  DBDWORD complexType
  DBDWORD imageDataSize;
  DBLONG  holizontal;
  DBLONG  vertical;
  DBDWORD colorUsed
  DBDWORD colorImportant
} BITMAPINFOHEADER, BitmapInfoHeader;

//typedef struct tagBITMAPV4HEADER{} BITMAPV4HEADER, BitmapV4Header;
//typedef struct tagBITMAPV5HEADER{} BITMAPV5HEADER, BitmapV5Header;


typedef struct tagBITMAPBITFIELD
{
  DBDWORD colorMaskR;
  DBDWORD colorMaskG;
  DBDWORD colorMaskB;
} BITMAPBITFIELD, BitmapBitField;

typedef struct tagBITMAPTRIPLECOLORPALLET
{
  DBBYTE blue;
  DBBYTE green;
  DBBYTE red;
} BITMAPTRIPLECOLORPALLET, BitmapTripleColorPallet;


typedef struct tagBITMAPQUADCOLORPALLET
{
  DBBYTE blue;
  DBBYTE green;
  DBBYTE red;
  DBBYTE reserved;
} BITMAPQUADCOLORPALLET, BitmapQuadColorPallet;

#endif
