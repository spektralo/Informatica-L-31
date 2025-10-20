#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    if (argc != 5)
    {
        printf(" 4 args required!\n");
        exit(1);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    float alpha = atoi(argv[3]);
    float beta = atoi(argv[4]);


    if ((a < 5 || a > 20) || (b < 5 || b > 20))
    {
     printf("args value(int) must be in 5-20 range!\n");
     exit(1);   
    }

    if ((alpha < 10 || alpha > 20) || (beta < 1 || beta > 5))
    {
     printf("args value(double) must be in 10-20 and 1-5 range!\n");
     exit(1);   
    }
    
        for(int i = 1; i < argc; i++){
            printf("args[%d], value: %s\n",i,argv[i]);
            return 0;
}
