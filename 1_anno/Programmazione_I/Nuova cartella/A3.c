#include<stdio.h>
int main(){
    int N, M, num;
    printf("\nInserisci un valore di N:");
    scanf("%d",&N);
    printf("\nInserisci un valore di M:");
    scanf("%d",&M);
    for (int i = 0; i < N && i<M; i++){
        do
        {
            num=i;
            num=num+2;
            printf("valori:%d",num);
        } while (i<N);
        do
        {
            num=M;
            num=num+1;
        } while (i<M);
    }
}