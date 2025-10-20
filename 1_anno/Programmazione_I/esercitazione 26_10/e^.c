#include<stdio.h>
#include<math.h>
int main(){
    float x = 1.0882;
    double y = 0;
    
    x = x * pow(10, 8);
    printf("%8.6e", x);
}