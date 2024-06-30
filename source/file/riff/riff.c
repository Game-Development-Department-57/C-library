#include <stdlib.h>
#include "data/stack.h"
#include "riffformat.h"
#include "binary/ftype.h"
#include "binary/binary.h"

int riffIdCheck(FDWORD id, char* cmp)
{
  return binaryCmp(&id, cmp, 4);
}

int riffChunkSize(RIFFCHUNK* chunk);

FDWORD riffGetId(RIFF* riff)
{
  FILE* fp = riff->fp;
  FDWORD id;
  fread(&id, 4, 1, fp);
  fseek(fp, -4, SEEK_CUR);
  return id;
}

int riffIsSPChunk(FDWORD id)
{
  return riffIdCheck(id, "RIFF") || riffIdCheck(id, "LIST");
}


RIFF* riffCreate(const char* name)
{
  FILE* fp = NULL;
  if (name != NULL){
    fp = fopen(name, "rb");
    if (fp == NULL) return NULL;
  }
  
  RIFF* riff = (RIFF*) malloc(sizeof(RIFF));
  if (riff == NULL){fclose(fp); return NULL;}
  
  riff->fp   = fp;
  riff->data = NULL;
  
  return riff;
}

void riffRead(RIFF* riff)
{
  if (riff == NULL) return;
  if (riff->fp == NULL) return;

  riff->data = (RIFFCHUNK*) malloc(sizeof(RIFFCHUNK));
  if (riff->data == NULL) return;

  FDWORD id;
  fread(&id, 4, 1, riff->fp);
  fseek(riff->fp, -4, SEEK_CUR);
  if (!riffIdCheck(id, "RIFF"))
  {
    free(riff->data);
    return;
  }

  STACK* stack;
  stack = stackCreate();
  RIFFCHUNK* chunk  = riff->data;
  FILE*      fp     = riff->fp;
  RIFFCHUNK* parent = NULL;
  do
  {
    do
    {
      fread(&chunk->id,   4, 1, fp);
      fread(&chunk->size, 4, 1, fp);
      chunk->seek = ftell(fp);
      chunk->ptr  = NULL;
      if (riffIsSPChunk(chunk->id))
      {
        fread(&chunk->format, 4, 1, fp);
        chunk->parent = parent;
        
      }else
      {
        
      }
    }while(riffChunkSize(chunk) != chunk->parent->size);
  }while(stackLengthGet(stack) != 0);
}