#ifndef DATA_STACK_H
#define DATA_STACK_H

#include "binary/ftype.h"

#define STACK_SIZE 512

typedef struct tagSTACK
{
  int length;
  int reserved;
  FBYTE* stack;
} STACK;

int stackFreeSize(STACK* stack);


STACK* stackCreateN(int size);
STACK* stackCreate(void);

void stackDelete(STACK* stack);

int stackPush(STACK* stack, FBYTE data);
int stackPop(STACK* stack, FBYTE* data);

int stackPushN(STACK* stack, void* data, int size);
int stackPopN(STACK* stack, void* data, int size);

int stackPushB(STACK* stack, FBYTE data);
int stackPushW(STACK* stack, FWORD data);
int stackPushD(STACK* stack, FDWORD data);
int stackPushQ(STACK* stack, FQWORD data);
int stackPushF(STACK* stack, float data);
int stackPushDF(STACK* stack, double data);
int stackPushP(STACK* stack, void* data);

int stackPopB(STACK* stack, FBYTE* data);
int stackPopW(STACK* stack, FWORD* data);
int stackPopD(STACK* stack, FDWORD* data);
int stackPopQ(STACK* stack, FQWORD* data);
int stackPopF(STACK* stack, float* data);
int stackPopDF(STACK* stack, double* data);
int stackPopP(STACK* stack, void** data);

int stackLengthGet(STACK* stack);
int stackReservedGet(STACK* stack);

#endif