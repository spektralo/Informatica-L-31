#include<stdio.h>
#include<stdlib.h>
#define size 10

int main(){

    int source[size], dest[size];
    int *sourceP = source, *destP = dest, *endP = &source[size-1];


    for (int i = 0; i < size; i++)
    {
        unsigned int nums = rand()%(100-10+1)+10; //numeri rand range 10 - 100
        *(sourceP+i) = nums; //assegno un int rand ad ogni indice dell'array sorgente, corrisponde a &source[i]
        *(destP+i) = 0; // inizializzo gli elementi dell'array destinazione a 0
    }

    for (int i = 0; i < size; i++)
    {
        printf("\nsource[%d], value:%d",i,*(sourceP+i)); //stampa gli elementi dell'array sorgente
    }
    printf("\n\n");

    printf("\nDestination before copy:");
    for (int i = 0; i < size; i++)
    {
        printf("\ndestination[%d], value:%d",i,*(destP+i)); //stampa gli elementi dell'array destinazione prima della copia
                                                            //inizializzati a zero     
    }

    while (sourceP <= endP) //ciclo che itera fino a che il puntatore all'array sorgente è minore
                            // del puntatore che punta all'ultimo indice dell'array sorgente
    {
        *destP = *sourceP; //assegno all'indice puntato da destP il valore dell'indice dell'array sorgente        
                            //puntato da sourceP
        destP++ ;sourceP++; //incremento gli indici
    } 
    
    printf("\n\n");
    printf("\nDestination after copy:");
    for (int i = 0; i < size; i++)
    {
        printf("\ndestination[%d], value:%d",i,*(destP+i)); //stampa elementi dell'array destinazione dopo la copia degli elementi
    }






}