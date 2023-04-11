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

enum ReturnCode{
  SUCCESS,
  NULL_PTR,
  DIV_ZERO
};

typedef double t_mx3x3[3][3];

int mx3x3_add_to(MX3_IN_OUT t_mx3x3* pmx, MX3_IN t_mx3x3* pmadd);   // *pmx = *pmx + *pmadd;
int mx3x3_sub_to(MX3_IN_OUT t_mx3x3* pmx, MX3_IN t_mx3x3* pmsub);   // *pmx = *pmx - *pmsub;
int mx3x3_mul_to(MX3_IN_OUT t_mx3x3* pmx, MX3_IN t_mx3x3* pmmul);   // *pmx = (*pmx) * (*pmmul);
int mx3x3_transp_to(MX3_IN_OUT t_mx3x3* pmx);                       // *pmx = (*pmx)^T;
int mx3x3_inv_to(MX3_IN_OUT t_mx3x3* pmx);                          // *pmx = (*pmx)^(-1);
int mx3x3_div_to(MX3_IN_OUT t_mx3x3* pmx, MX3_IN t_mx3x3* pmdiv);   // *pmx = (*pmx)*[(*pmdiv)^(-1)];
int mx3x3_mul_to_c(MX3_IN_OUT t_mx3x3* pmx, FTYPE fc);             // *pmx = (*pmx)*fc;

int mx3x3_sum(MX3_OUT t_mx3x3* pmx_res, MX3_IN t_mx3x3* pmxl, MX3_IN t_mx3x3* pmxr);    // *pmx_res = *pmxl + *pmxr
int mx3x3_sub(MX3_OUT t_mx3x3* pmx_res, MX3_IN t_mx3x3* pmxl, MX3_IN t_mx3x3* pmxr);    // *pmx_res = *pmxl - *pmxr
int mx3x3_mul(MX3_OUT t_mx3x3* pmx_res, MX3_IN t_mx3x3* pmxl, MX3_IN t_mx3x3* pmxr);    // *pmx_res = (*pmxl) * (*pmxr)
int mx3x3_transp(MX3_OUT t_mx3x3* pmx_res, MX3_IN t_mx3x3* pmx);                        // *pmx_res = [(*pmx)^(T)]
int mx3x3_inv(MX3_OUT t_mx3x3* pmx_res, MX3_IN t_mx3x3* pmx);                           // *pmx_res = [(*pmx)^(-1)]
int mx3x3_div(MX3_OUT t_mx3x3* pmx_res, MX3_IN t_mx3x3* pmxl, MX3_IN t_mx3x3* pmxr);    // *pmx_res = (*pmxl) * [(*pmxr)^(-1)]
int mx3x3_mul_c(MX3_OUT t_mx3x3* pmx_res, MX3_IN t_mx3x3* pmxl, FTYPE fc);          // *pmx_res = *pmxl * fc

int mx3x3_set_skew_0(MX3_OUT t_mx3x3* pmx, FTYPE pfvec[3]);        // skew symetric MX
int mx3x3_set_skew_1(MX3_OUT t_mx3x3* pmx, FTYPE pfvec[3]);        // skew + I

double mx3x3_get_det(MX3_IN t_mx3x3* pmx);
int mx3x3_get_cofactor(MX3_OUT t_mx3x3* pmx_res, MX3_IN t_mx3x3* pmx);

//------------------------------------------------------------------------------
// Print mx
void pprint(MX3_IN t_mx3x3 mx);

#endif // MATRIX3X3_MATH_H
