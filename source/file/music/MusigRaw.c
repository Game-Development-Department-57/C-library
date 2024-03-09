#include <stdlib.h>
#include "file/music/MusicRawFormat.h"

MusicRaw* MusicRawInit(void)
{
  MusicRaw* music = (MusicRaw*) malloc(sizeof(MusicRaw));
  if (music == NULL) return NULL;
  
  music->Header = (MusicRawHeader*) malloc(sizeof(MusicRawHeader));
  if (music->Header == NULL) { free(music); return NULL; }
  
  music->Header->SamplingRate     = 44100;
  music->Header->QuantizationRate = 8;
  music->Header->DataLength       = 0;
  music->Header->Flags            = 0x00000000;
  
  return music;
}

int MusicRawData
