#ifndef DATA_FORMAT_INTEGER_INTEGER_H
#define DATA_FORMAT_INTEGER_INTEGER_H

#include "data/INTEGER/INTEGERTYPE.h"


INTEGER8*    integer8Create(void);
INTEGER16*   integer16Create(void);
INTEGER32*   integer32Create(void);
INTEGER64*   integer64Create(void);
INTEGER128*  integer128Create(void);
INTEGER256*  integer256Create(void);
INTEGER512*  integer512Create(void);
INTEGER1024* integer1024Create(void);

void integer8Delete(INTEGER8* integer8);
void integer16Delete(INTEGER16* integer16);
void integer32Delete(INTEGER32* integer32);
void integer64Delete(INTEGER64* integer64);
void integer128Delete(INTEGER128* integer128);
void integer256Delete(INTEGER256* integer256);
void integer512Delete(INTEGER512* integer512);
void integer1024Delete(INTEGER1024* integer1024);

#endif