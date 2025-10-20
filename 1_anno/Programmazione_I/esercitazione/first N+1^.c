#include <stdio.h>
int main(){
    int N = 0, M = 0, P = 1, count = 0;
    printf("Inserisci un valore di N:");
    scanf("%d",&N);
    while (M<=N)
    {
        printf("\nP:%d",P);
        P = P * 2;
        M++;
        count++;
    }
    printf("\nNumero di iterazioni:%d",count);
}