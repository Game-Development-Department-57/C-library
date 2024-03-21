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
