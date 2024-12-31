#ifndef DATA_BASE_TYPES_H
#define DATA_BASE_TYPES_H

/* 
date   :2024/11/21
name   :types.h
make   :AQ(MK)
package:Data.Base.types
 */

#ifdef _WIN64
typedef unsigned char       DBBYTE;
typedef unsigned short      DBWORD;
typedef unsigned int       DBDWORD;
typedef unsigned long long DBQWORD;
typedef signed char         DBCHAR;
typedef signed short       DBSHORT;
typedef signed int           DBINT;
typedef signed long long    DBLONG;
#else
typedef unsigned char       DBBYTE;
typedef unsigned short      DBWORD;
typedef unsigned int       DBDWORD;
typedef unsigned long      DBQWORD;
typedef signed char         DBCHAR;
typedef signed short       DBSHORT;
typedef signed int           DBINT;
typedef signed long         DBLONG;
#endif

#endif
