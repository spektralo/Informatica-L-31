#include<stdio.h>
int main(){
	double a = 20.0, *ptrA=&a;
	short unsigned b = 10, *ptrB=&b;
	char c = 'c', *ptrC=&c;	

	printf("\n(A)valore:%f indirizzo:%p",a,ptrA);
	printf("\n(B)valore:%d indirizzo:%p",b,ptrB);

}
