#ifndef FILE_FILEDATA_H
#define FILE_FILEDATA_H

typedef struct tagFILEDATA
{
  FILE* fp;
  long  fileSize;
  int   sectionSize;
  int   sectionCount;
  char* buffer;
} FILEDATA;

#endif
