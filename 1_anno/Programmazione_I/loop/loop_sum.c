#include<stdio.h>
int main(){
    int sum = 0;
    int count = 0;
    for (int num = 1; sum <= 99; num+=2)
    {
        if (num%3==0)
        {
            num+=2;
        }
        sum = sum + num;
        count++;
        printf("\n%d'Somma:%d",count,sum);
    }
    printf("\nSomma totale:%d",sum);
}