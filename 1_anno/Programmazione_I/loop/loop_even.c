#include<stdio.h>
#define lenght 100000
int main(){
    int num = 0;
    int sum = 0;

    for (num = 1000; num >= 1; num-=2)
    {
        printf("\nRitroso:%d",num);
        sum = sum + num;
        if (sum >= lenght)
        {
            printf("\nLimite raggiunto!");
            break;
        }
        
    }
    printf("\nSomma:%d",sum);
}