#include<stdio.h>
int main(){
    double a = 1;
    short unsigned b = 2;
    char c = 'c';
    double *ptr_a = &a;
    short unsigned *ptr_b = &b;
    char *ptr_c = &c;

    printf("\na:%f, b:%u, c:%c", a, b, c);
    printf("\na:%f, b:%u, c:%c", *ptr_a, *ptr_b, *ptr_c);
}