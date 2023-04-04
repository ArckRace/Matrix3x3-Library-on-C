#include "MATRIX3X3_MATH.h"
#include <math.h>

#define MXSIZE 3

int mx3MulScalar(matrix mx, FTYPE val){
  if (!mx){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mx[i][j] *= val;
        }
    }
  return SUCCESS;
}

int mx3Sum(matrix mxL, matrix mxR){
  if (!mxL | !mxR){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mxL[i][j] = mxL[i][j] + mxR[i][j];
        }
    }
  return SUCCESS;
}

int mx3Sub(matrix mxL, matrix mxR){
  if (!mxL | !mxR){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mxL[i][j] = mxL[i][j] - mxR[i][j];
        }
    }
  return SUCCESS;
}

int mx3Mul(matrix mxL, matrix mxR){
  if (!mxL | !mxR){
      return NULL_PTR;
    }
  matrix mxMul;
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mxMul[i][j] = 0;
          for (int k =0; k < MXSIZE; k++){
              mxMul[i][j] += mxL[i][j] * mxR[k][j];
            }
          mxL[i][j] = mxMul[i][j];
        }
    }
  return SUCCESS;
}

int mx3GetDet(matrix mx, FTYPE *det){
  if (!mx){
      return NULL_PTR;
    }
  FTYPE a[3],b[3],as,bs;
  as = 0;
  bs = 0;
  a[0] = mx[0][0] * mx[1][1] * mx[2][2];
  a[1] = mx[1][0] * mx[2][1] * mx[0][2];
  a[2] = mx[0][1] * mx[1][2] * mx[2][0];
  b[0] = mx[2][0] * mx[1][1] * mx[0][2];
  b[1] = mx[1][0] * mx[2][2] * mx[0][1];
  b[2] = mx[0][0] * mx[1][2] * mx[2][1];
  for (int i = 0; i < MXSIZE; i++){
      as += a[i];
      bs += b[i];
    }
  *det = as - bs;
  printf("%f\n", *det);
  return SUCCESS;
}

int mx3Tran(matrix mx){
  if (!mx){
      return NULL_PTR;
    }
  matrix mxTrans;
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mxTrans[j][i] = mx[i][j];
        }
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mx[i][j] = mxTrans[i][j];
        }
    }
  return SUCCESS;
}

int mx3GetMinor(matrix mx, matrix mxOut){
  if (!mx | !mxOut){
      return NULL_PTR;
    }
  FTYPE n[2][2];
  int k = 0;
  int l = 0;
  for (int a = 0; a < MXSIZE; a++){
      for (int b = 0; b < MXSIZE; b++){
          for (int i = 0; i < MXSIZE; i++){
              if (i != a){
                  for (int j = 0; j < MXSIZE; j++){
                      if (j != b){
                          n[k][l] = mx[i][j];
                          if(l < 1) {
                              l++;
                            } else{
                              l = 0;
                              k++;
                            }
                        }
                    }
                }
            }
          mxOut[a][b] = pow(-1,a+b) * (n[0][0] * n[1][1] - n[0][1] * n[1][0]);
          k = 0;
        }
    }
  return SUCCESS;
}

int mx3Inv(matrix mx){
  if (!mx){
      return NULL_PTR;
    }
  matrix CoFactor;
  FTYPE det = 0;
  mx3GetDet(mx, &det);
  mx3GetMinor(mx,CoFactor);
  mx3Tran(CoFactor);
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mx[i][j] = (1 / det) * CoFactor[i][j];
        }
    }
  return SUCCESS;
}

int mx3HatMatrix(FTYPE vector[3], matrix mx){
  if (!mx | !vector){
      return NULL_PTR;
    }
  mx[0][0] = 0;
  mx[0][1] = -vector[2];
  mx[0][2] = vector[1];
  mx[1][0] = vector[2];
  mx[1][1] = 0;
  mx[1][2] = -vector[0];
  mx[2][0] = -vector[1];
  mx[2][1] = vector[0];
  mx[2][2] = 0;
  return SUCCESS;
}

void pprint(matrix mx){
  for (int i = 0; i < MXSIZE; ++i){
      for (int j = 0; j < MXSIZE; ++j){
          printf("%f\t",mx[i][j]);
        }
      printf("\n");
    }
}
