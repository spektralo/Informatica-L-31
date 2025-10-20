#include<stdio.h>
int main(){
    float p; 
    printf("\nInserisci un valore per la variabile p:");
    scanf("%f",&p);

    if (p<1)
    {
        printf("Errore");
        
    }
    else if (p>=1)
    {
       p = (int)p+0.5;
    
    }

    int V[(int)p];
    
}