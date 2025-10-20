#include<stdio.h>
int main(){
    int N = 0, i = 0, S = 0, count = 0;
    printf("\nInserisci un valore di N:");
    scanf("%d",&N);
    while (i<N)
    {
        i++;
        S=S+i;
        count++;
    }
    printf("La somma dei primi N numeri e'%d \nNumero di iterazioni:%d",S,count);
    
}