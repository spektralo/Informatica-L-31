#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 100

typedef struct{
    FILE *file;
    int k;
} input;

typedef struct node{
    char string[max_len];
    struct node *next;
}node;



input readInput(int argc, char*argv[]);
void pushWord(node**head, char string[]);
void buildStack(node**head, input record);
void printStack(node**head,input record);
void popWord(node**head, char string[],input record);
void sortWord(char str[],input record);

int main(int argc, char *argv[]){

    node *head = NULL;
    input newInput = readInput(argc,argv);
    buildStack(&head,newInput);
    printStack(&head,newInput);

}

void popWord(node**head, char string[],input record){
     node *temp = *head;
     while (temp != NULL)
        {
            sortWord(temp->string,record);
            fprintf(stdout,"\n%s", temp->string);
            temp = temp->next;
        }      
        free(temp->string);
        free(temp);

        fprintf(stdout,"\nstack vuoto!");
}

void printStack(node**head,input record){
    popWord(head,(*head)->string,record);
}

void sortWord(char str[],input record){
    int n = strlen(str);
    // Controlla se la lunghezza della stringa è maggiore di 10
    if (n >= record.k) {
        char temp;

        // Bubble sort per ordinare la stringa
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (str[i] > str[j]) {
                    // Scambia i caratteri
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
        }
    }
}

void buildStack(node**head, input record){
    char buffer[max_len];
    while (fgets(buffer,max_len,record.file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        pushWord(head,buffer);
    }
}


void pushWord(node**head,char string[]){
    node *newNode = (node*)malloc(sizeof(node));
    if (!newNode)
    {
        fprintf(stderr,"allocazione fallita!");
        exit(-1);
    }

    strcpy(newNode->string,string);
    newNode->next = (*head);

    (*head) = newNode;
}

input readInput(int argc, char*argv[]){
    if (argc != 3)
    {
        fprintf(stderr,"usage: <.txt> <int>!");
        exit(-1);
    }

    input record = {0,0};

    FILE *file = fopen(argv[1],"r" );
    record.file = file;
    if (!file)
    {
        fprintf(stderr,"file vuoto!");
        exit(-1);
    }
    
    int k = atoi(argv[2]);
    record.k = k;
    if (k < 5 || k > 15)
    {
        fprintf(stderr,"k deve essere in 5-15!");
        exit(-1);
    }
    
    return record;
}