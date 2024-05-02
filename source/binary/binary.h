#ifndef F_BINARY_H
#define F_BINARY_H

int binaryCmp(void* a, void* b, int size);
int binarySet(void* ptr, int var, int size);
int binaryCpy(void* a, void* b, int size);


typedef struct tagBITCHAR
{
  char bits[9];
} BITCHAR;

BITCHAR binaryByteToBitchar(unsigned char byte);
unsigned char binaryBitcharToByte(BITCHAR bit);

#endif
