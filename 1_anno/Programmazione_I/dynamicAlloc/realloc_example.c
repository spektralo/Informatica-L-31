#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    int *ptr = (int*)malloc(2*sizeof(int));

    if (ptr == NULL)
    {
        printf("\nMemory not available");
        exit(1);
    }
    
    printf("Enter the two integers:");
    for (int i = 0; i < 2; i++)
    {
        scanf("%d",ptr+i);
    }
    
    ptr = (int*)realloc(ptr, 4*sizeof(int)); /*La funzione realloc(*ptr, size_t size) ci permette di
    reallocare la memoria precedentemente allocata, e quindi aumentare o diminuire la dimensione del blocco
    specificando la nuova dimensione nel secondo parametro (size_t size) */
    
    for (i = 2; i < 4; i++)
    {
        printf("Enter another two integers:");
        scanf("%d",ptr+i);
    }

    for (i = 0; i < 4; i++)
    {
        printf("%d",*(ptr+i));
    }
    
    
    



}