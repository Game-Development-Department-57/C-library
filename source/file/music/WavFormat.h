#include "binary/ftype.h"

#pragma pack(1)
typedef struct tagWAVEHEADER
{
  FDWORD RIFFChunkID;
  FDWORD RIFFChunkDataSize;
  FDWORD WAVEType;
  FDWORD WAVEChunkID;
  FDWORD WAVEChunkDataSize;
  FWORD  WAVECompressionCode;
  FWORD  WAVENumberOfChannels;
  FDWORD WAVESampleRate;
  FDWORD WAVEAverageBytesPerSecond;
  FWORD  WAVEBlockAlign;
  FWORD  WAVESignificantBitsPerSample;
} WAVEHEADER;
#pragma pack()
