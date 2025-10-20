#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<float.h>

int main(){
    float x = 10882000;
    printf("X=%.6E",x); //valore di X in notazione scientifica
    double y =  x *(1.23456 * pow(10,100));
    printf("\nY=%.6E",y); //valore di Y in notazione scientifica

  double min_over =  x * -(1e300 *1e300);
  printf("\n%+f - negativeOverflow!",min_over);

  double pos_over = y * 1e300; 
   printf("\n%+f - Overflow!",pos_over);

   int num1 = INT_MAX, num2 = INT_MAX, sum = 0;
   sum= num1 + num2;
   printf("\nSomma(INT_MAX+INT_MAX): %d",sum);
   long long_sum= INT_MAX+INT_MAX;
   printf("\nSomma var long(INT_MAX+INT_MAX): %ld",long_sum);

    int ll_limits= sizeof(long long); 
    printf("\n long long limits: %d",ll_limits);

    int l_limits = sizeof(long);
    printf("\n long limits: %d",l_limits);
    


}