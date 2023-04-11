#include "MATRIX3X3_MATH.h"
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  t_mx3x3 A,B,C;
  for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
          A[i][j] = rand()%10;
        }
    }
  for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
          B[i][j] = 1;
        }
    }

  mx3x3_inv(&C,&A);
  pprint(C);

  return 0;
}
