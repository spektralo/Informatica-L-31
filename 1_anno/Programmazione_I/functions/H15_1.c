#include<stdio.h>
void absolute(int, int, int*);
int fill(int);

int main(){
int a = 0, b = 0, num = 5;
int *x = &num;

printf("Inserisci un int:");
scanf("%d",&a);

printf("Inserisci un int:");
scanf("%d",&b);


absolute(a,b,x);

}

    void absolute( int a, int b, int *x){
    int result = a * b;
    *x = result;
    printf("\nmul:%d",result);
    printf("\nValore nella locazione di memoria[%p]:%d",(void*)x, *x);
}
