#include<stdio.h>
int main(){
    int N = 0, M = 0, count=0;
    printf("\nInserisci un valore di N:");
    scanf("%d",&N);
    while (M<N)
    {
        M++;
        count++;
        printf("\nValori da 1 a N:%d",M);
    }
    printf("\nNumero di iterazioni:%d",count);

}