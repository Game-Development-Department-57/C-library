#ifndef DATA_FORMAT_INTEGER_INTEGERTYPE_H
#define DATA_FORMAT_INTEGER_INTEGERTYPE_H

typedef struct tagINTEGER8
{
  signed char      integer;
} INTEGER8;

typedef struct tagINTEGER16
{
  signed short     integer;
} INTEGER16;

typedef struct tagINTEGER32
{
  signed int       integer;
} INTEGER32;

typedef struct tagINTEGER64
{
  signed long long integer;
} INTEGER64;

typedef struct tagINTEGER128
{
  signed long long integer[2];
} INTEGER128;

typedef struct tagINTEGER256
{
  signed long long integer[4];
} INTEGER256;

typedef struct tagINTEGER512
{
  signed long long integer[8];
} INTEGER512;

typedef struct tagINTEGER1024
{
  signed long long integer[16];
} INTEGER1024;

#endif