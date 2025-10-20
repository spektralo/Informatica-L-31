#include <stdio.h> 
#include <stdlib.h>

//FIBONACCI 

long fibo(int n){
  printf("\n fibo(%d)", n);
  if(n<=1)
    return 1;
  return fibo(n-1) + fibo(n-2); 
}

int main(int argc, char *argv[]){
  if(argc<2){
    printf("\n No argument!");
    return -1; 
  }

    for(int i=0; i<argc; i++)
	printf("\n %s", argv[i]); 

    return 0;  


  long result = fibo(atoi(argv[1])); 
    printf("\n result: %ld", result);
}
