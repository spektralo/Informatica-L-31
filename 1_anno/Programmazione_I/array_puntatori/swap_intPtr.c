#include<stdio.h>
int main(){
    int num_a, num_b;
    int *pA = &num_a, *pB = &num_b;
    printf("Inserisci un numero a:");
    scanf("%d",&num_a);

    printf("\nInserisci un numero b:");
    scanf("%d",&num_b);

    printf("\nA = %d, B = %d",*pA,*pB);
    pA = &num_b;
    pB = &num_a;
    printf("\nSwitch - A = %d, B = %d",*pA,*pB);
}