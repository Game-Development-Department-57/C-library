#ifndef CONTAINER_TYPES_H
#define CONTAINER_TYPES_H

#include <stddef.h>

typedef int    err;
typedef void*  ContainerHeader; //コンテナのポインタ
typedef size_t Index;
typedef void*  Item;

typedef struct tagBASECONTAINERINTERFACE
{
  ContainerHeader (*Create) (void);
  void            (*Delete) (ContainerHeader);
  err             (*Add)    (ContainerHeader, Item);
  err             (*Del)    (ContainerHeader, Index);
  err             (*Crean)  (ContainerHeader);
  err             (*Fill)   (ContainerHeader, Item);
  Item            (*Get)    (ContainerHeader, Index);
  err             (*Set)    (ContainerHeader, Item);
  Index           (*Length) (ContainerHeader);
  ContainerHeader (*Copy)   (ContainerHeader);
} BASECONTAINERINTERFACE, *BaseContainerInterface;

typedef struct tagEXCONTAINERINTERFACE
{
  Index           (*Find)        (ContainerHeader, Item);
  err             (*Reverse)     (ContainerHeader);
  ContainerHeader (*CopyDeep)    (ContainerHeader);
  ContainerHeader (*CopyShallow) (ContainerHeader);
} EXCONTAINERINTERFACE, *ExContainerInterface;

typedef struct tagBASECONTAINERSORTINTERFACE
{
} BASECONTAINERSORTINTERFACE, *BaseContainerSortInterface;

typedef struct tagEXCONTAINERSORTINTERFACE
{
} EXCONTAINERSORTINTERFACE, *ExContainerSortInterface;

typedef struct tagBASECONTAINERSEARCHINTERFACE
{
} BASECONTAINERSEARCHINTERFACE, *BaseContainerSearchInterface;

typedef struct tagEXCONTAINERSEARCHINTERFACE
{
} EXCONTAINERSEARCHINTERFACE, *ExContainerSearchInterface;


#endif
