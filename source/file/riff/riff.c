#include <stdlib.h>
#include "riffformat.h"

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