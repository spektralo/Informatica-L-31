#include<stdio.h>
#include<stdlib.h>
#define LENGHT 10
int main(){
    int A[LENGHT];
    double D[LENGHT];
    int *ptrA = A;
    double *ptrD = D;

    for (int i = 0; i < LENGHT; i++)
    {
        A[i]=rand()%(50-10+1)+10;
        D[i]= (90 * rand()/RAND_MAX)+1.25;
    }

    for (int i = 1; i <= LENGHT; i+=2)
    {
        printf("\nElemento[%d] di D (Valore:%3.2lf, Indirizzo:%p)",i,D[i],(void *)(ptrD+i));   
    }
    printf("\n");
    
    for (int i = 0; i < LENGHT; i+=2)
    {
        printf("\nElemento[%d] di A (Valore:%d, Indirizzo:%p)",i,A[i],(void *)(ptrA+i));

    }
    
    

}