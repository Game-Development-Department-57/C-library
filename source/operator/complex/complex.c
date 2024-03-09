/* 
date:2023-10-17
name:complex.c
make:Fujiwara
path:operator/complex
 */




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


/*
(a + bi) ± (c + di) = (a ± c) + (b ± d)i
(a + bi)(c + di) = (ac − bd) + (bc + ad)i
(a + bi)/(c + di) = (ac + bd)/(c^2 + d^2) + (bc - ad)/(c^2 + d^2)i

(a + bi) * (a - bi) = 0
*/

/*
#define complexInit(complex_, real_, imaginary_) \
do{\
  complex_.real = (real_);\
  complex_.imaginary = (imaginary_);\
}while(0)
 */

/*(a + bi) ± (c + di) = (a ± c) + (b ± d)i*/
complexd complexAdd2d(complexd a, complexd b)
{
    complexd result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

/*(a + bi) ± (c + di) = (a ± c) + (b ± d)i*/
complexd complexSub2d(complexd a, complexd b)
{
    complexd result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

/*(a + bi)(c + di) = (ac − bd) + (bc + ad)i*/
complexd complexMul2d(complexd a, complexd b)
{
    complexd result;
    result.real = (a.real * b.real) - (a.imaginary * b.imaginary);
    result.imaginary = (a.imaginary * b.real) + (a.real * b.imaginary);
    return result;
}

/*(a + bi)/(c + di) = (ac + bd)/(c^2 + d^2) + (bc - ad)/(c^2 + d^2)i*/
complexd complexDiv2d(complexd a, complexd b)
{
    complexd result;
    result.real = ((a.real * b.real) + (a.imaginary * b.imaginary)) / ((b.real * b.real) + (b.imaginary * b.imaginary));
    result.imaginary = ((a.imaginary * b.real) + (a.real * b.imaginary)) / ((b.real * b.real) + (b.imaginary * b.imaginary));
    return result;
}

/*(a + bi) * (a - bi) = 0*/
complexd complexConjugate1d(complexd a)
{
    a.imaginary = -a.imaginary;
    return a;
}

double complexAbsolute1d(complexd a)
{
    return pow((a.real * a.real) + (a.imaginary * a.imaginary), 0.5);
}

void complexPrint1d(complexd a)
{
    printf("(%lf + %lfi)", a.real, a.imaginary);
}

void complexPrintln1d(complexd a)
{
    printf("(%lf + %lfi)\n", a.real, a.imaginary);
}

