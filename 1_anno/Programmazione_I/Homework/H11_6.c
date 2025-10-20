#include<stdio.h>
int main(){
    char nome[10], cognome[10];
    printf("\nInserisci il tuo nome e cognome: ");
    scanf( "%10[^\n] %10[^\n]", nome, cognome);
    
    printf("\nIl primo e ultimo carattere del nome sono: '%s' e '%s'",&nome[0],&nome[9]);
    

}