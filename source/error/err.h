#ifndef ERROR_ERR_H
#define ERROR_ERR_H

typedef int err;



#define errMaskSign      0x80000000
#define errMaskReserved  0x7f000000
#define errMaskRecordA   0x00fff000
#define errMaskRecordB   0x00000fff
#define errShiftSign     31
#define errShiftReserved 24
#define errShiftRecordA  12
#define errShiftRecordB  0


inline int errGetSign(err id);
inline int errGetReserved(err id);
inline int errGetRecordA(err id);
inline int errGetRecordB(err id);

/* inline err.c begin */
int errGetSign(err id)
{
  return (id & errMaskSign) >> errShiftSign;
}

int errGetReserved(err id)
{
  return (id & errMaskReserved) >> errShiftReserved;
}

int errGetRecordA(err id)
{
  return (id & errMaskRecordA) >> errShiftRecordA;
}

int errGetRecordB(err id)
{
  return (id & errMaskRecordB) >> errShiftRecordB;
}
/* inline err.c end */


#endif