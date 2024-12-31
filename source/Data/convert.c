long DoubleToInt(double a)
{
  return (long) a;
}

double LongToDouble(long a)
{
  return (double) a;
}

union tagBitLD
{
  long   L;
  double D;
};

long BitDoubleToLong(double a)
{
  union tagBitLD ld;
  ld.D = a;
  return ld.L;
}

double BitLongToDouble(long a)
{
  union tagBitLD ld;
  ld.L = a;
  return ld.D;
}