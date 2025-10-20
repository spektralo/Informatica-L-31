#include<stdio.h>
int main(){
int n, i, num, max;
	
	do {
		printf("Quanti numeri inserire?: ");
		scanf("%d", &n);
	}while (n<=0);
	
	for(i=0;i<n;i++)
	{
		printf("Numero %d:", i+1);
		scanf("%d", &num);
		if(i==0) max=num;
		if(num>max) max=num;
	}
	
	printf("Il valore massimo e': %d\n", max);
    
    
}