#ifndef DATA_VECTOR_H
#define DATA_VECTOR_H

typedef struct tagVECTOR
{
  size_t length;
  size_t reserved;
  char*  vector;
  char   buffer[32];
} VECTOR, *Vector;

Vector vectorCreate(void);
void   vectorDelete(Vector vec);
err    vectorAdd(Vector vec, Item item);
err    vectorDel(Vector vec, Index index);
err    vectorCrean(Vector vec);
err    vectorFill(Vector vec, Item item);
Item   vectorGet(Vector vec, Index index);
err    vectorSet(Vector vec, Index index, Item item);
Index  vectorLength(Vector vec);
Vector vectorCopy(Vector vec);

#endif