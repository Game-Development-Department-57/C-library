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


#define errGetSign(id)     ((id & errMaskSign)     >> errShiftSign)
#define errGetReserved(id) ((id & errMaskReserved) >> errShiftReserved)
#define errGetRecordA(id)  ((id & errMaskRecordA)  >> errShiftRecordA)
#define errGetRecordB(id)  ((id & errMaskRecordB)  >> errShiftRecordB)
#define errSetSign(id)     (id << errShiftSign)
#define errSetReserved(id) (id << errShiftReserved)
#define errSetRecordA(id)  (id << errShiftRecordA)
#define errSetRecordB(id)  (id << errShiftRecordB)

#define errSetAll(sign, reserved, recorda, recordb) \
(errSetSign(sign) + errSetReserved(reserved) + errSetRecordA(recorda) + errSetRecordB(recordb))


#endif