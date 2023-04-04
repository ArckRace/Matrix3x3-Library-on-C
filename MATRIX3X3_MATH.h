#ifndef MATRIX3X3_MATH_H
#define MATRIX3X3_MATH_H

#include <stdio.h>

#ifndef MX3_OUT
 //marker for output parameter
#define MX3_OUT /**/
#endif

#ifndef MX3_IN
 //marker for input parameter
#define MX3_IN /**/
#endif

#ifndef MX3_IN_OUT
 //marker for input/output parameter
#define MX3_IN_OUT /**/
#endif

#ifndef FTYPE
 //marker for type
#define FTYPE double
#endif

typedef enum enumReturnCode{
  SUCCESS,
  NULL_PTR,
  DIV_ZERO
} ReturnCode;

typedef double matrix[3][3];


// Basic math operations
int mx3MulScalar(MX3_IN matrix mx, FTYPE val);         // Умножение матрицы на скаляр
int mx3Sum(MX3_IN matrix l_mx, MX3_IN matrix r_mx);     // Сложение двух матриц
int mx3Sub(MX3_IN matrix l_mx, MX3_IN matrix r_mx);     // Разность двух матриц
int mx3Mul(MX3_IN matrix l_mx, MX3_IN matrix r_mx);     // Перемножение матриц
int mx3GetDet(MX3_IN matrix mx, FTYPE *det);           // Нахождения определителя матрицы
int mx3GetMinor(MX3_IN matrix mx, MX3_OUT matrix mxOut);

// Extra math operations
int mx3Tran(MX3_IN matrix mx);                          // Транспонирование матрицы
int mx3Inv(MX3_IN matrix mx);                           // Возведение матрицы в (-1) степень
int mx3HatMatrix(FTYPE vector[3], MX3_OUT matrix mx);  // Составление кососимметрической матрицы из вектора

// Print matrix
void pprint(MX3_IN matrix mx);

#endif // MATRIX3X3_MATH_H
