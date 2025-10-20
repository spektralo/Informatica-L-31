#include<stdio.h>
#define DIM 10

int main(){
    char nome[DIM], cognome[DIM];
    printf("\nInserisci il tuo nome:");
    for (int i = 0; i < DIM; i++)
    {
        scanf("%c",&nome[i]);
    }
        printf("\nInserisci il tuo cognome:");

    for (int i = 0; i < DIM; i++)
    {
        scanf("%c",&cognome[i]);
    }

    printf("Primo carattere nome:%c - Ultimo carattere:%c",nome[0] ,nome[DIM-1]);
    
}