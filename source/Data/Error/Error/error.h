#ifndef ERROR_ERROR_H
#define ERROR_ERROR_H

typedef struct tagERROR
{
  int          ret;
  unsigned int id;
  void*        buffer;
  char*        message;
} ERROR;

static ERROR error;

void errorSet(ERROR err);
ERROR errorGet(void);

#endif