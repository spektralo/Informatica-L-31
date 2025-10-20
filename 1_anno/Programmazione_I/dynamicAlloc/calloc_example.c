#include<stdio.h>
#include<stdlib.h>
int main(){
    int i, n;


    printf("Enter the number of integers: "); 
    scanf("%d", &n);
    int *ptr = (int *)calloc(10, sizeof(int));
    /*la funzione calloc(size_t n,size_t size) rispetto alla classica malloc,
     alloca dinamicamente piu blocchi di memoria(n) di grandezza (size)
     e inoltre, inizializza tutti i blocchi a 0; */

    if(ptr == NULL) {
    printf("Memory not available."); 
    exit(1);
    }

    for(i = 0; i < n; i++) {
    printf("Enter an integer: ");
    scanf("%d", ptr + i);
    }

    for(i = 0; i < n; i++){
    printf("%d ", *(ptr+i));
    return 0;
    }
}
