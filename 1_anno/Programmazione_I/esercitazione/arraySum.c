#include<stdio.h>
int main(){
int S = 0, i = 0, array[10];

    while (i<array[10])
    {
        S = S + array[i];
        i+=2;
    }
    printf("\nLa somma degli elementi con indice pari e' %d",S);
}