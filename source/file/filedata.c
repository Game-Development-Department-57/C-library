#include <stdio.h>
#include <sdlib.h>
#include "file/filedata.h"

FILEDATA* filedataOpen(const char* name, const char* mode)
{
  FILE* fp = fopen(name, mode);
  if (fp == NULL) return NULL;
  
  FILEDATA* fd = (FILEDATA*) malloc(sizeof(FILEDATA));
  if (fd == NULL)
  {
    fclose(fp);
    return NULL;
  }
  
  fd->fp           = fp;
  fseek(fp, 0, SEEK_END);
  fd->fileSize     = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  fd->sectionSize  = 512;
  fd->sectionCount = 0;
  fd->buffer       = NULL;
  
  return fd;
}

int filedataClose(FILEDATA* fd)
{
  free(fd->buffer);
  fclose(fd->fp);
  free(fd);
  
  return 0;
}

int filedataLoad(FILEDATA* fd, int location)
{
  
}