#include<stdio.h>
int main(){
    int array[10];
    int *arrP = array;  //arrP punta al primo elemento dell'array[0]
    printf("Inserisci 10 elementi nell'array:");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",(arrP+i)); // (arrP + i) is equivalent to &arr[i]
    }

    for (int i = 0; i < 10; i++)
    {
        printf("\nelemento indice[%d]:%d",i,*(arrP+i)); // *(arrP + i) is equivalent to arr[i]
    }
}