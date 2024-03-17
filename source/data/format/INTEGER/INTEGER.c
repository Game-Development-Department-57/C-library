#include <stdlib.h>
#include "data/format/INTEGER/INTEGERTYPE.h"

/* test: てすと */
/*
睦月ってかわいいよね
 by ロリコン
*/
/*
フォント名： にゃしぃフォント改二(にゃしぃフォント)
作者      ： マルセ
サイト名  ： よく飛ばない鳥
サイトurl ： http://marusexijaxs.web.fc2.com/
*/

INTEGER8* integer8Create(void)
{
  return (INTEGER8*) malloc(sizeof(INTEGER8));
}

INTEGER16* integer16Create(void)
{
  return (INTEGER16*) malloc(sizeof(INTEGER16));
}

INTEGER32* integer32Create(void)
{
  return (INTEGER32*) malloc(sizeof(INTEGER32));
}

INTEGER64* integer64Create(void)
{
  return (INTEGER64*) malloc(sizeof(INTEGER64));
}

INTEGER128* integer128Create(void)
{
  return (INTEGER128*) malloc(sizeof(INTEGER128));
}

INTEGER256* integer256Create(void)
{
  return (INTEGER256*) malloc(sizeof(INTEGER256));
}

INTEGER512* integer512Create(void)
{
  return (INTEGER512*) malloc(sizeof(INTEGER512));
}

INTEGER1024* integer1024Create(void)
{
  return (INTEGER1024*) malloc(sizeof(INTEGER1024));
}


void integer8Delete(INTEGER8* integer8)
{
  free(integer8);
}

void integer16Delete(INTEGER16* integer16)
{
  free(integer16);
}

void integer32Delete(INTEGER32* integer32)
{
  free(integer32);
}

void integer64Delete(INTEGER64* integer64)
{
  free(integer64);
}

void integer128Delete(INTEGER128* integer128)
{
  free(integer128);
}

void integer256Delete(INTEGER256* integer256)
{
  free(integer256);
}

void integer512Delete(INTEGER512* integer512)
{
  free(integer512);
}

void integer1024Delete(INTEGER1024* integer1024)
{
  free(integer1024);
}