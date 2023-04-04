#include "MATRIX3X3_MATH.h"
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  matrix A,B;
  for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
          A[i][j] = rand() % 10;
        }
    }
  for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
          B[i][j] = 0;
        }
    }


  // mx3MulScalar(A,3);
   pprint(A);
   mx3Inv(A);
   pprint(A);
 // mx3GetDet(A, &det1);
 // mx3Tran(A);
 // pprint(A);
 // mx3GetDet(A, &det2);

  return 0;
}
