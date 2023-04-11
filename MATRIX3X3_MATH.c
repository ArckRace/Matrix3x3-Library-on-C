#include "MATRIX3X3_MATH.h"
#include <math.h>

#define MXSIZE 3


int mx3x3_add_to(t_mx3x3* pmx, t_mx3x3* pmadd){
  if (!pmx | !pmadd){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx)[i][j] = (*pmx)[i][j] + (*pmadd)[i][j];
        }
    }
  return SUCCESS;
}

int mx3x3_sub_to(t_mx3x3* pmx, t_mx3x3* pmsub){
  if (!pmx | !pmsub){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx)[i][j] = (*pmx)[i][j] - (*pmsub)[i][j];
        }
    }
  return SUCCESS;

}

int mx3x3_mul_to(t_mx3x3* pmx, t_mx3x3* pmmul){
  if (!pmx | !pmmul){
      return NULL_PTR;
    }
  t_mx3x3 mxMul;
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mxMul[i][j] = 0;
          for (int k =0; k < MXSIZE; k++){
              mxMul[i][j] += (*pmx)[i][k] * (*pmmul)[k][j];
            }
        }
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx)[i][j] = mxMul[i][j];
        }
    }
  return SUCCESS;
}

int mx3x3_transp_to(t_mx3x3* pmx){
  if (!pmx){
      return NULL_PTR;
    }
  t_mx3x3 mxTrans;
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mxTrans[j][i] = (*pmx)[i][j];
        }
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx)[i][j] = mxTrans[i][j];
        }
    }
  return SUCCESS;
}

int mx3x3_inv_to(t_mx3x3* pmx){
  if (!pmx){
      return NULL_PTR;
    }
  t_mx3x3 CoFactor;
  FTYPE det = 0;
  det = mx3x3_get_det(pmx);
  mx3x3_get_cofactor(&CoFactor,pmx);
  mx3x3_transp_to(&CoFactor);
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx)[i][j] = (1 / det) * CoFactor[i][j];
        }
    }
  return SUCCESS;
}

int mx3x3_div_to(t_mx3x3* pmx, t_mx3x3* pmdiv){
  if (!pmx | !pmdiv){
      return NULL_PTR;
    }
  mx3x3_inv_to(pmdiv);
  t_mx3x3 mxMul;
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          mxMul[i][j] = 0;
          for (int k =0; k < MXSIZE; k++){
              mxMul[i][j] += (*pmx)[i][k] * (*pmdiv)[k][j];
            }
        }
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx)[i][j] = mxMul[i][j];
        }
    }
  return SUCCESS;
}

int mx3x3_mul_to_c(t_mx3x3* pmx, double fc){
  if (!pmx){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx)[i][j] *= fc;
        }
    }
  return SUCCESS;
}

int mx3x3_sum(t_mx3x3* pmx_res, t_mx3x3* pmxl, t_mx3x3* pmxr){
  if (!pmx_res | !pmxl | !pmxr){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx_res)[i][j] = (*pmxl)[i][j] + (*pmxr)[i][j];
        }
    }
  return SUCCESS;
}

int mx3x3_sub(t_mx3x3* pmx_res, t_mx3x3* pmxl, t_mx3x3* pmxr){
  if (!pmx_res | !pmxl | !pmxr){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx_res)[i][j] = (*pmxl)[i][j] - (*pmxr)[i][j];
        }
    }
  return SUCCESS;

}

int mx3x3_mul(t_mx3x3* pmx_res, t_mx3x3* pmxl, t_mx3x3* pmxr){
  if (!pmx_res | !pmxl | !pmxr){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx_res)[i][j] = 0;
          for (int k =0; k < MXSIZE; k++){
              (*pmx_res)[i][j] += (*pmxl)[i][k] * (*pmxr)[k][j];
            }
        }
    }
  return SUCCESS;
}

int mx3x3_transp(t_mx3x3* pmx_res, t_mx3x3* pmx){
  if (!pmx_res | !pmx){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx_res)[j][i] = (*pmx)[i][j];
        }
    }
  return SUCCESS;
}

int mx3x3_inv(t_mx3x3* pmx_res, t_mx3x3* pmx){
  if (!pmx_res | !pmx){
      return NULL_PTR;
    }
  t_mx3x3 CoFactor;
  FTYPE det = 0;
  det = mx3x3_get_det(pmx);
  mx3x3_get_cofactor(&CoFactor,pmx);
  mx3x3_transp_to(&CoFactor);
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx_res)[i][j] = (1 / det) * CoFactor[i][j];
        }
    }
  return SUCCESS;
}

int mx3x3_div(t_mx3x3* pmx_res, t_mx3x3* pmxl, t_mx3x3* pmxr){
  if (!pmx_res | !pmxl | !pmxr){
      return NULL_PTR;
    }
  mx3x3_inv_to(pmxr);
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx_res)[i][j] = 0;
          for (int k =0; k < MXSIZE; k++){
              (*pmx_res)[i][j] += (*pmxl)[i][k] * (*pmxr)[k][j];
            }
        }
    }
  return SUCCESS;
}

int mx3x3_mul_c(t_mx3x3* pmx_res, t_mx3x3* pmxl, FTYPE fc){
  if (!pmx_res | !pmxl){
      return NULL_PTR;
    }
  for (int i = 0; i < MXSIZE; i++){
      for (int j = 0; j < MXSIZE; j++){
          (*pmx_res)[i][j] = (*pmxl)[i][j] * fc;
        }
    }
  return SUCCESS;
}

int mx3x3_set_skew_0(t_mx3x3* pmx, FTYPE pfvec[3]){
  if (!pmx | !pfvec){
      return NULL_PTR;
    }
  (*pmx)[0][0] = 0;
  (*pmx)[0][1] = -pfvec[2];
  (*pmx)[0][2] = pfvec[1];
  (*pmx)[1][0] = pfvec[2];
  (*pmx)[1][1] = 0;
  (*pmx)[1][2] = -pfvec[0];
  (*pmx)[2][0] = -pfvec[1];
  (*pmx)[2][1] = pfvec[0];
  (*pmx)[2][2] = 0;
  return SUCCESS;
}

int mx3x3_set_skew_1(t_mx3x3* pmx, FTYPE pfvec[3]){
  if (!pmx | !pfvec){
      return NULL_PTR;
    }
  (*pmx)[0][0] = 1;
  (*pmx)[0][1] = -pfvec[2];
  (*pmx)[0][2] = pfvec[1];
  (*pmx)[1][0] = pfvec[2];
  (*pmx)[1][1] = 1;
  (*pmx)[1][2] = -pfvec[0];
  (*pmx)[2][0] = -pfvec[1];
  (*pmx)[2][1] = pfvec[0];
  (*pmx)[2][2] = 1;

  return SUCCESS;
}

double mx3x3_get_det(MX3_IN t_mx3x3* pmx){
  if (!pmx){
      return NULL_PTR;
    }
  FTYPE a[3],b[3],as,bs,det;
  as = 0;
  bs = 0;
  a[0] = (*pmx)[0][0] * (*pmx)[1][1] * (*pmx)[2][2];
  a[1] = (*pmx)[1][0] * (*pmx)[2][1] * (*pmx)[0][2];
  a[2] = (*pmx)[0][1] * (*pmx)[1][2] * (*pmx)[2][0];
  b[0] = (*pmx)[2][0] * (*pmx)[1][1] * (*pmx)[0][2];
  b[1] = (*pmx)[1][0] * (*pmx)[2][2] * (*pmx)[0][1];
  b[2] = (*pmx)[0][0] * (*pmx)[1][2] * (*pmx)[2][1];
  for (int i = 0; i < MXSIZE; i++){
      as += a[i];
      bs += b[i];
    }
  det = as - bs;
  return det;
}

int mx3x3_get_cofactor(t_mx3x3* pmx_res, t_mx3x3* pmx){
  if (!pmx | !pmx_res){
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
                          n[k][l] = (*pmx)[i][j];
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
          (*pmx_res)[a][b] = pow(-1,a+b) * (n[0][0] * n[1][1] - n[0][1] * n[1][0]);
          k = 0;
        }
    }
  return SUCCESS;
}

void pprint(t_mx3x3 mx){
  for (int i = 0; i < MXSIZE; ++i){
      for (int j = 0; j < MXSIZE; ++j){
          printf("%f\t",mx[i][j]);
        }
      printf("\n");
    }
}
