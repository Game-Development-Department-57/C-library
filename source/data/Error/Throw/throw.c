typedef struct tagTHROW
{
  int   flag;
  int   id;
  char* msg;
  char* name;
  char* func;
  void* free;
} THROW, Throw;

static THROW throw;
static int   mode;

void  throwSet(int flag, int id, char* msg, char* name, char* func, char* free)
{
  if (!mode) return;
  throw.flag = flag;
  throw.id   = id;
  throw.msg  = msg;
  throw.name = name;
  throw.func = func;
  throw.free = free;
  return;
}

Throw throwGet(void)
{
  if (!(mode & 0x00000001)) return (Throw){0, 0, "", "", "", ""};
  return throw;
}

int   throwCheck(void)
{
  if (throw.flag & 0x00000001) return 1;
  return 0;
}

int   throwOn(void)
{
  mode = 1;
  return 1;
}

int   throwOff(void)
{
  mode = 0;
  return 0;
}

int   throwGetShadow(Throw* throw_)
{
  *throw_ = throw;
  return 0;
}