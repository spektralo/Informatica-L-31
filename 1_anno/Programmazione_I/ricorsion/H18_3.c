#include<stdio.h>
#include<stdlib.h>
int arrsSum(int*,int);
void arrFill(int*, int);
void arrPrint(int*,int);
int arrSum(int*,int);

int main(){

    int array[1], size;
    printf("\nsize:");
    scanf("%d",&size);
    arrFill(array,size);
    arrPrint(array,size);
    
    int sum =arrSum(array,size);
    printf("\nsum:%d",sum);
}


int arrSum(int* array, int size){
   if (size <= 0) {
        return 0;
    } else {
        // Caso ricorsivo: somma l'ultimo elemento all'array meno l'ultimo elemento
        return array[size - 1] + arrSum(array, size - 1);
    }
}
    

void arrFill(int* array, int size){
    for (int i = 0; i < size; i++)
    {
        array[i] = rand()%(10-1+1)+1;
    }
}

void arrPrint(int* array, int size){
    for (int i = 0; i < size; i++)
    {
        printf("\narr[%d], value:%d",i,array[i]);
    }
}