#include<stdio.h>
int main(){
    int a = 0, b = 0, c = 0;
    printf("Inserisci un valore per A, B e C:");
    scanf("%d %d %d", &a, &b, &c);
    printf("A:%d B:%d C:%d\n", a, b, c);
    printf("Max(a,b,c)= %d", ((a > b && a > c) ? a : (b > c) ? b : c));

    int x = 0, y = 0, z = 0, k = 0;
    printf("Inserisci un valore per X, Y, Z e K:");
    scanf("%d %d %d %d", &x, &y, &z, &k);
    printf("X:%d Y:%d Z:%d K:%d\n", x, y, z, k);
    
    if (x != z && k > 8)
    {
        y = x + z;
        printf("Y:%d", y);
    }
    else if ( x == z && k < 8)
    {
        x = y -z;
        printf("X:%d", x);
    }
    else{
       printf("Value:%d", (x+y+z)/3);
       x = 0, y = 0, z = 0; 
    }

/*
conditional operator used to avoid code 
    max = a;
    if (b > max)
    {
        max = b;
    }
    
    if (c > max)
    {
        max = c;
    }
    
    printf("Max:%d",max);
    */

}
