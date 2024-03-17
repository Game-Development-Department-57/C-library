#ifndef FILE_RIFFFORMAT_H
#define FILE_RIFFFORMAT_H

#include <stdio.h>
#include "binary/ftype.h"

typedef struct tagRIFFCHUNK RIFFCHUNK;

typedef struct tagRIFFCHUNK
{
  RIFFCHUNK*  parent; /* parent chunk pointer */
  RIFFCHUNK** chunks; /* nest chunk array */
  FDWORD      id;     /* chunk id */
  FDWORD      format; /* chunk format */
  FDWORD      size;   /* chunk length */
  long        fp;     /* file seek */
  void*       ptr;    /* data buffer pointer */
} RIFFCHUNK;

typedef struct tagRIFF
{
  FILE*      fp;      /* file pointer */
  RIFFCHUNK* data;    /* chunk data */
} RIFF;

#endif