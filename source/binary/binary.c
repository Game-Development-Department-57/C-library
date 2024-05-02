int binaryCmp(void* a, void* b, int size)
{
  for (int i = 0; i < size; i++)
    if (((unsigned char*) a)[i] != ((unsigned char*) b)[i]) return 0;
  return 1;
}

int binarySet(void* ptr, int var, int size)
{
  for (int i = 0; i < size; i++)
    ((unsigned char*) ptr)[i] = (unsigned char)var;
  return 1;
}

int binaryCpy(void* a, void* b, int size)
{
  for (int i = 0; i < size; i++)
    ((unsigned char*) a)[i] = ((unsigned char*) b)[i];
  return 1;
}


typedef struct tagBITCHAR
{
  char bits[9];
} BITCHAR;

BITCHAR binaryByteToBitchar(unsigned char byte)
{
  BITCHAR bit;
  bit.bits[8] = 0x00;
  for(int i = 0; i < 8; i++){bit.bits[i] = 0x30 + (byte & (0x80 >> i));}
  return bit;
}

unsigned char binaryBitcharToByte(BITCHAR bit)
{
  unsigned char byte = 0;
  for (int i = 0; i < 8; i++){byte += ((bit.bits[i] - 0x30) * (0x80 >> i));}
  return byte;
}
