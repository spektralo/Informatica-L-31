#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 30

typedef struct{
    FILE *file;
    int N;
    char a, b;
}params;

typedef struct node{
    char string[max_len];
    struct node *next;
}node;


params readInput(int argc,char *argv[]);


int main(int argc, char *argv[]){

    node *top = NULL;
    params record = readInput(argc,argv);

    
}


params readInput(int argc,char *argv[]){
    if(argc != 5)
    {
        fprintf(stderr,"usage: <txt> <int> <char> <char>");
        exit(-1);
    }
    params record = {0,0,0,0};
    
    FILE *file = fopen(argv[1],"r");
    record.file = file;
    if(!file)
    {
        fprintf(stderr,"error in file format!");
        exit(-1);
    }

    int N = atoi(argv[2]);
    record.N = N;
    if ( N < 5 || N > 10)
    {
        fprintf(stderr,"N must be in 5-10");
        exit(-1);
    }
    
    char a = argv[3][0];
    char b = argv[4][0];
    record.a = a;
    record.b = b;

    if ( ( a < 'a' || a > 'z') || ( b < 'a' || b > 'z') )
    {
        fprintf(stderr,"a and b must be in (a-z)");
        exit(-1);
    }
    return record;
}