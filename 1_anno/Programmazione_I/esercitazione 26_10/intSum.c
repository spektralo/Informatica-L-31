#include<stdio.h>
#include<limits.h>
int main(){
    int a = INT_MAX, b = INT_MAX;
    int z = (long) a+b;
    printf("\n x=%ld", z);
}