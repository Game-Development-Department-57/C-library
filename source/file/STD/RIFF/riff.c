#include <stdlib.h>
#include "data/list/list.h"
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

RIFFCHUNK* riffChunkCreate(void)
{
  return (RIFFCHUNK*)malloc(sizeof(RIFFCHUNK));
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
  
  List chunk_list = listCreate();
  if (chunk_list == NULL){free(riff->data); return;}
  RIFFCHUNK* chunk  = riff->data;
  FILE*      fp     = riff->fp;
  while (1)
  {
    if (feof(fp)) break;
    
    RIFFCHUNK* temp_chunk = riffChunkCreate();
    FDWORD id = riffGetId(riff);
    if (riffIsSPChunk(id))
    {
      temp_chunk->id = id;
      fread(&temp_chunk->format, 4, 1, fp);
      fread(&temp_chunk->size, 4, 1, fp);
      listAdd(chunk_list, temp_chunk);
    }else
    {
      temp_chunk->id = id;
      fread(&temp_chunk->size, 4, 1, fp);
      listAdd(chunk_list, temp_chunk);
    }
  }
  
  RIFFCHUNK* parent = riff->data;
  while (1)
  {
    if (listLength(list) == 0) break;
    RIFFCHUNK* temp_chunk = listPop();
    if (riffIsSPChunk(temp_chunk->id))
    {
      
    }else
    {
      
    }
  }
}