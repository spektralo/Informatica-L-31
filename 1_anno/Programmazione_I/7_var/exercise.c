#include<stdio.h>
#include<limits.h>
int main(){

    float x = 1.0882e7;
    printf("%.6E",x);
    double y = x * (1.23456e100);
    printf("\n%.6E",y);

    printf("\nX:%f", (x * -1.2345E1000) );
    printf("\nY:%lf",(y * 1.2345E1000) );

    int a = 1020E8, b = 105E10, sum;
    sum = a + b;
    printf("\nIntSum:%d",sum); 
    sum = (long) sum;
    printf("\nLongSum:%lf",sum);

    printf("\nLLONG_MAX:%lu",LLONG_MAX); 
    printf("\nLLONG_MIN:%lu",LLONG_MIN);

    printf("\nsizeof(long):%dbytes",sizeof(long));
    printf("\nsizeof(long_long):%dbytes",sizeof(long long));

    



}