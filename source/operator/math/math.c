long factrial(long num)
{
  long result = 1;
  for (int count = 1; count <= num; count++)
  {
    result *= count;
  }
  return result;
}

