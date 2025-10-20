#include<stdio.h>
int main(){
    int a, b;
    printf("Inserisci due valori per A e B:");
    scanf("%d %d",&a, &b);

        printf("\nLa somma tra A e B e': %4.2e",(double)(a + b));
        printf("\nLa media tra A e B e': %4.2e",(double)((a+b)/2));
        printf("\nIl max tra A e B e': %4.2e",(double) (a>b ? a:b));
}