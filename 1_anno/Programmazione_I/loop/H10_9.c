#include<stdio.h>
#include<stdlib.h>
int main(){
    int N = 1;
    float A = 1, B = 1;
    printf("\nInserisci due decimali >0 e diversi per A e B, e un intero >1 per N:");
    scanf("%f %f %d",&A,&B,&N);

    if (A == B || A == 0 || B == 0 || A > B || N == 0)
    {
        printf("Parametri non validi!");
        exit(0);
    }

    int sumRound = (A + B) + 0.5;
    printf("Somma arrotondata:%d",sumRound);
    
}