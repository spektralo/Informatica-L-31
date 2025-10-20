#include<stdio.h>
#include<stdlib.h>
#define dim 20
void fillArr(char*, int);

int main(){
char array[dim];
int size;

printf("\narray size:");
scanf("%d",&size);

printf("\nInserisci gli elementi:");
fillArr(array,size);


}

void fillArr(char *arr, int size){
    
    int *arrEnd= (arr+(size-1));
    while (arr <= arrEnd)
    {
        arr = rand()%(122-97+1)+97;
        arr++;
        
    }

    /* void printArr(char *arr, int size){
        int *arrEnd= (arr+size-1);
    while (arr <= arrEnd)
    {
        printf("\nelements:%d",*(arr++));
    }
        
    } */
    
    
}