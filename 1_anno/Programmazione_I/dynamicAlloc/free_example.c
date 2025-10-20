#include<stdio.h>
#include<stdlib.h>

int *input() {
     int *ptr, i;
    ptr = (int *)malloc (5* sizeof (int)); 
    printf("Enter 5 numbers: "); 

    for (i=0; i<5; i++){
    scanf("%d", ptr+i);
    }
    return ptr;
}

int main(){

    int i, sum = 0;
    int *ptr = input();

    for ( i = 0; i < 5; i++)
    {
        sum += *(ptr+i);
    }

    printf("\nSum is:%d",sum);
    free(ptr); /*La funzione free(*ptr) ci permette di liberare il blocco
                di memoria precedentemente allocato, passando il puntatore
                al blocco di memoria come parametro(ptr*); */
    ptr = NULL;
    return 0;
}