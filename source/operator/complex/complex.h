#include <stdio.h>
#include <math.h>


typedef struct
{
    int real;
    int imaginary;
} complexi;

typedef struct
{
    float real;
    float imaginary;
} complexf;

typedef struct
{
    double real;
    double imaginary;
} complexd, complex;

#define complexInit(complex_, real_, imaginary_) \
do{\
  complex_.real = (real_);\
  complex_.imaginary = (imaginary_);\
}while(0)

complexd complexAdd2d(complexd a, complexd b);
complexd complexSub2d(complexd a, complexd b);
complexd complexMul2d(complexd a, complexd b);
complexd complexDiv2d(complexd a, complexd b);
complexd complexConjugate1d(complexd a);
double complexAbsolute1d(complexd a);
void complexPrint1d(complexd a);
void complexPrintln1d(complexd a);
