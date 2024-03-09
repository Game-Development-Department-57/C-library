#include <stdlib.h>

#include "binary/ftype.h"

#define STACK_SIZE 512

typedef struct tagSTACK
{
  int length;
  int reserved;
  FBYTE* stack;
} STACK;

int stackFreeSize(STACK* stack)
{
  return stack->reserved - stack->length;
}


STACK* stackCreateN(int size)
{
  if (size < 0) return NULL;
  STACK* stack = (STACK*) malloc(sizeof(STACK));
  if (stack == NULL) return NULL;
  stack->stack = malloc(size);
  stack->length   = 0;
  stack->reserved = size;
  if (stack->stack == NULL){free(stack); return NULL;}
  return stack;
}

STACK* stackCreate(void)
{
  STACK* stack = (STACK*) malloc(sizeof(STACK));
  if (stack == NULL) return NULL;
  stack->stack = malloc(STACK_SIZE);
  stack->length   = 0;
  stack->reserved = STACK_SIZE;
  if (stack->stack == NULL){free(stack); return NULL;}
  return stack;
}

void stackDelete(STACK* stack)
{
  if(stack == NULL) return;
  free(stack->stack);
  free(stack);
  return;
}

int stackPush(STACK* stack, FBYTE data)
{
  if(stack == NULL) return -1;
  if (stack->length >= stack->reserved) return -1;
  stack->stack[stack->length] = data;
  stack->length++;
  return 0;
}

int stackPop(STACK* stack, FBYTE* data)
{
  if(stack == NULL) return -1;
  if(stack->length <= 0) return -1;
  *data = stack->stack[stack->length];
  stack->length--;
  return 0;
}

int stackPushN(STACK* stack, void* data, int size)
{
  if(stack == NULL) return -1;
  if(stackFreeSize(stack) < size) return -1;
  for (int i = 0; i < size; i++)
    stackPush(stack, ((FBYTE*)data)[i]);
  return 0;
}

int stackPopN(STACK* stack, void* data, int size)
{
  if (stack == NULL) return -1;
  if (stack->length < size) return -1;
  for (int i = 0; i < size; i++)
    stackPop(stack, &((FBYTE*)data)[i]);
  return 0;
}

int stackPushB(STACK* stack, FBYTE data)
{
  stackPushN(stack, &data, 1);
}
int stackPushW(STACK* stack, FWORD data)
{
  stackPushN(stack, &data, 2);
}
int stackPushD(STACK* stack, FDWORD data)
{
  stackPushN(stack, &data, 4);
}
int stackPushQ(STACK* stack, FQWORD data)
{
  stackPushN(stack, &data, 8);
}
int stackPushF(STACK* stack, float data)
{
  stackPushN(stack, &data, 4);
}
int stackPushDF(STACK* stack, double data)
{
  stackPushN(stack, &data, 8);
}
int stackPushP(STACK* stack, void* data)
{
  stackPushN(stack, &data, sizeof(void*));
}

int stackPopB(STACK* stack, FBYTE* data)
{
  stackPopN(stack, data, 1);
}
int stackPopW(STACK* stack, FWORD* data)
{
  stackPopN(stack, data, 2);
}
int stackPopD(STACK* stack, FDWORD* data)
{
  stackPopN(stack, data, 4);
}
int stackPopQ(STACK* stack, FQWORD* data)
{
  stackPopN(stack, data, 8);
}
int stackPopF(STACK* stack, float* data)
{
  stackPopN(stack, data, 4);
}
int stackPopDF(STACK* stack, double* data)
{
  stackPopN(stack, data, 8);
}
int stackPopP(STACK* stack, void** data)
{
  stackPopN(stack, data, sizeof(void*));
}

int stackLengthGet(STACK* stack)
{
  return stack->length;
}

int stackReservedGet(STACK* stack)
{
  return stack->reserved;
}