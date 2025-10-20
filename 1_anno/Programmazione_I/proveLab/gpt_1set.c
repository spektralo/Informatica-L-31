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

params readInput(int argc,char *argv[]);
void insertWord(node**head,char string[]);
void buildList(node**head, params record);
void printList(node**head);
void elab(node**head,params record);

int main(int argc, char *argv[]){
    node *head = NULL;
    params record = readInput(argc,argv);
    buildList(&head,record);
    elab(&head,record);
    printList(&head);
    
}

void elab(node**head,params record){
    int count = 0;
    node *temp = *head;
    while (temp->next != NULL)
    {
        if (strlen(temp->string) >= record.k)
        {
            count++;
        }
        temp = temp->next;
    }
    fprintf(stdout,"stringhe >= %d = %d\n",record.k,count);
}

void printList(node**head){
    node *temp = *head;
    while (temp->next != NULL)
    {
        fprintf(stdout,"%s\n",temp->string);
        temp = temp->next;
    }
}

void buildList(node**head, params record){
    char buffer[max_len];
    while (fgets(buffer,max_len,record.file) != NULL)
    {
        buffer[strcspn(buffer,"\n")] = '\0';
        insertWord(head,buffer);
    }
    fclose(record.file);
}

void insertWord(node**head,char string[]){
    node *newNode = (node*)malloc(sizeof(node));
    if(!newNode){
        fprintf(stderr,"error in node allocation!");
        exit(-1);
    }

    strcpy(newNode->string,string);
    newNode->next = NULL;

    if (*head == NULL || strcmp(string, (*head)->string) < 0)
    {
        newNode->next = *head;
        *head = newNode;
    }

    else
    {
        node *current = *head;
        while (current->next != NULL && strcmp(current->string, string) < 0)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
}


params readInput(int argc, char *argv[]){
    if(argc != 3){
        fprintf(stderr,"usage: <.txt> <int>");
        exit(-1);
    }

    params record = {0, 0};

    FILE *file = fopen(argv[1],"r");
    record.file = file;

    if(!file){
        fprintf(stderr,"err in file format!");
        exit(-1);
    }

    int k = atoi(argv[2]);
    record.k = k;

    if( k < 7 || k > 13){
        fprintf(stderr,"int must be in 7-13!");
        exit(-1);
    }

    return record;
}