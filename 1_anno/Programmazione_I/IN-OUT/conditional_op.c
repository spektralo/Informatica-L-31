#include<stdio.h>
int main(){
     int a = 1203, b = 1249, c = 10, k;
    //printf("\nMax(a,b,c):%d",(a > b)?((a > c)?a:c):((b > c)?b:c));
    printf("\nInserisci un valore intero per K:");
    scanf("%d",&k);
    if (a != c && k > 8){
    b = a + c;
    printf("\nvalueOfB:%d",b);
    }
    
    else if( a == c && k < 8){
        a = c-b;
        printf("\nvalueOfA:%d",a);
    }
    
    else 
    printf("\n(a+b+c)/3:%d",((a+b+c)/3));
        a = 0, b = 0, c = 0; 
}
