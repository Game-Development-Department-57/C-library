#include <stdlib.h>
#include "binary/memory.h"

int main(void)
{
  char* memory = malloc(128);
  for (int i = 0; i < 128; i++) memory[i] = i;
  BinaryDump(memory, 128, 16);
  return 0;
}
