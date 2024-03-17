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

  fread(&riff->data->id,     4, 1, riff->fp);
  fread(&riff->data->size,   4, 1, riff->fp);
  riff->data->fp = ftell(riff->fp);
  fread(&riff->data->format, 4, 1, riff->fp);

  if (!riffIdCheck(riff->data->id, "RIFF"))
  {
    free(riff->data);
    return;
  }

  STACK* stack;
  stack = stackCreate();
  RIFFCHUNK* chunk = riff->data->chunks;
  do
  {
    do
    {
      ;
    }while(riffChunkSize(chunk) != chunk->parent->size);
  }while(stackLengthGet(stack) != 0);
}