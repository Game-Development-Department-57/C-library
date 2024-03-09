typedef struct tagERROR
{
  int          ret;
  unsigned int id;
  void*        buffer;
  char*        message;
} ERROR;

static ERROR error;

__attribute__((constructor))
void errorInit(void)
{
  error.ret     = 0;
  error.id      = 0;
  error.buffer  = NULL;
  error.message = NULL;

  return;
}

void errorSet(ERROR err)
{
  error.ret     = err.ret;
  error.id      = err.id;
  error.buffer  = err.buffer;
  error.message = err.message;

  return;
}

ERROR errorGet(void)
{
  return error;
}