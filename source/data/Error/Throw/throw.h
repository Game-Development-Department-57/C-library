#ifndef THROW_H
#define THROW_H

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

void  throwSet(int flag, int id, char* msg, char* name, char* func, char* free);
Throw throwGet(void);
int   throwCheck(void);
int   throwOn(void);
int   throwOff(void);
int   throwGetShadow(Throw* throw_);


#define throwTry           if (throwOn())
#define throwCatch(throw_) if (!(throwOff() + throwGetShadow(&throw_)))
#define throwCatchNonArg() if (!throwOff())


#endif