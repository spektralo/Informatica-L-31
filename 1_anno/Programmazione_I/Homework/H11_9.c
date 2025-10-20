#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    int persone, uova = 4;
    float farina = 0.3, zucchero = 0.1;
    int risp;

    printf("Inserisci il numero di persone:");
    scanf("%d",&persone);
    printf("Se tra le persone sono presenti diabetici digita 1:");
    scanf("%d",&risp);
    if (risp == 1)
    {
        float fruttosio = ((zucchero * 2)/3);
        printf("Dosaggio per diabetici: (Farina:%f, Uova:%d, Fruttosio:%f)",farina,uova,fruttosio);
    } 
    
    if (persone < 2 && persone > 16)
    {
        printf("Numero di persone non adeguato!");
        exit(0);
    }
    if (persone <=2 && persone >= 4)
    {
     printf("Dosaggio base: (Farina:%f, Uova:%d, Zucchero:%f)",farina,uova,zucchero);
    }
     else if(persone <= 5 && persone >= 8)
        {
            farina = farina * 2.5;
            zucchero = zucchero * 1.5;
            uova = uova * 2.5;
            printf("Dosaggio medio: (Farina:%f, Uova:%d, Zucchero:%f)",farina,uova,zucchero);
        }       
        else if(persone <= 9 && persone >= 16)
        {
            farina = (farina + (farina * 2.5));
            zucchero = (zucchero + (zucchero * 2.5));
            uova = (uova + (uova * 2.5));
            printf("Dosaggio grande: (Farina:%f, Uova:%d, Zucchero:%f)",farina,uova,zucchero);
        }
}