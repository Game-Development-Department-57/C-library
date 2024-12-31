#ifndef DATA_LIST_LIST_ERROR_H
#define DATA_LIST_LIST_ERROR_H

#include "error/err.h"

#define LIST_ERROR_UNDEFINED  0x00000001
#define LIST_ERROR_SUCCESS    0x00000000
#define LIST_ERROR_ERROR      0x80000000
#define LIST_ERROR_LISTNULL   0x80001000
#define LIST_ERROR_ALLOCNULL  0x80001001
#define LIST_ERROR_ACCESSNULL 0x80001002
#define LIST_ERROR_OUTOFRANGE 0x80002000

#endif