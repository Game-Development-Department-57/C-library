#ifndef FILE_IMAGE_BITMAPFILEFORMAT_H
#define FILE_IMAGE_BITMAPFILEFORMAT_H

#include "binary/ftype.h"

#pragma pack(1)

typedef struct tagBITMAPHEADER
{
  FWORD  type;        /* file type */
  FDWORD size;        /* file size */
  FWORD  reserved1;   /* reserved */
  FWORD  reserved2;   /* reserved */
  FDWORD imageOffset; /* image data offset */
} BITMAPHEADER;

typedef struct tagBITMAPCOREHEADER{} BITMAPCOREHEADER;

typedef struct tagBITMAPINFOHEADER
{
  FDWORD headerSize;     /* header size */
  FDWORD width;          /* width */
  FDWORD height;         /* height */
  FWORD  planes;         /* plane number */
  FWORD  pixelBit;       /* bits per pixel */
  FDWORD compression;    /* compression type */
  FDWORD imageSize;      /* image data size */
  FDWORD xResolution;    /* x resolution */
  FDWORD yResolution;    /* y resolution */
  FDWORD colorIndex;     /* color pallet index */
  FDWORD colorImportant; /* color important index */
} BITMAPINFOHEADER;

typedef struct tagRGBTRIPLE
{
  FBYTE blue;
  FBYTE green;
  FBYTE red;
} RGBTRIPLE;

typedef struct tagRGBQUAD
{
  FBYTE blue;
  FBYTE green;
  FBYTE red;
  FBYTE alpha;
} RGBQUAD;


typedef struct tagBBITFIELD
{
  FDWORD mask;
} BITFIELD;

typedef struct tagBITMAP
{
  BITMAPHEADER* header;
  void*         info;
  BITFIELD*     bitField;
  void*         colorPallet;
  void*         imageData;
} BITMAP;

#pragma pack()

#endif