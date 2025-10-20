#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 30

typedef struct{
    FILE *file;
    int k;
}params;

typedef struct node{
    char string[max_len];
    struct node *next;
}node;



params readInput(int argc, char *argv[]);
void pushWord(node**top, char string[]);
void buildStack(node**top,params record);
char *popWord(node**top);
void sortWord(char *string, params record);
void printStack(node**top,params record);

int main(int argc, char*argv[]){
    node *top = NULL;

    params record = readInput(argc,argv);
    buildStack(&top,record);
    printStack(&top,record);
}

void sortWord(char *string, params record){
    int n = strlen(string);
    if (n >= record.k)
        {
        char temp;

        // Bubble sort per ordinare la stringa
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (string[i] > string[j]) {
                    // Scambia i caratteri
                    temp = string[i];
                    string[i] = string[j];
                    string[j] = temp;
                }
            }
        }
    }
}
    

void printStack(node**top,params record){
    char *string;
    while ((string = popWord(top)) != NULL)
    {
        sortWord(string,record);
        fprintf(stdout,"%s\n",string);
        free(string);
    }
}

char *popWord(node**top){
    if (*top == NULL)
    {
        fprintf(stderr,"**STACK IS EMPTY**");
        exit(-1);
    }
        node *temp = *top;
        char *string = strdup(temp->string);

        *top = (*top)->next;
        
        
        free(temp);
        return string;
}

void buildStack(node**top,params record){
    char buffer[max_len];
    while (fgets(buffer,max_len,record.file) != NULL)
    {
        buffer[strcspn(buffer,"\n")] = '\0';
        pushWord(top,buffer);
    }
    fclose(record.file);
}

void pushWord(node**top, char string[]){
    node *newNode = (node*)malloc(sizeof(node));
    if (!newNode)
    {
        fprintf(stderr,"error in node allocation!");
        exit(-1);
    }
    
    strcpy(newNode->string,string);
    newNode->next = NULL;

    newNode->next = *top;
    *top = newNode;
    
}

params readInput(int argc,char *argv[]){
    if (argc != 3)
    {
        fprintf(stderr,"usage: <txt> <int>");
        exit(-1);
    }

    params record = {0,0};

    FILE *file = fopen(argv[1],"r");
    record.file = file;
    if (!file)
    {
        fprintf(stderr,"error in file format!");
        exit(-1);
    }

    int k = atoi(argv[2]);
    record.k = k;
    if ( k < 5 || k > 15)
    {
        fprintf(stderr,"k must be in 5-15");
        exit(-1);
    }

    return record;
}