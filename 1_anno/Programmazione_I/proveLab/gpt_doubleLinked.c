#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 30

typedef struct {
    FILE *file;
    float F;
}params;


typedef struct{
    float num;
    char str[max_len];
}record;


typedef struct node{
    record data;
    struct node*next;
    struct node*prev;
}node;

params readInput(int argc, char*argv[]);
void insertRecord(node**head,node**tail,record data);
void buildList(node**head,node**tail,params input);
void printList(node*head);


int main(int argc, char*argv[]){
    node *head = NULL;
    node*tail = NULL;

    params record = readInput(argc,argv);
    buildList(&head,&tail,record);
    printList(head);
}

void printList(node*head){
    node *temp = head;
    while (temp != NULL)
    {
        fprintf(stdout,"%s %.4f\n",temp->data.str,temp->data.num);
        temp = temp->next;
    }
}

void buildList(node**head,node**tail,params input){
    record data;
    while (fscanf(input.file,"%f %s",&data.num, data.str) == 2)
    {
        insertRecord(head,tail,data);
    }
    fclose(input.file);
}

void insertRecord(node**head,node**tail,record data){
    node*newNode = (node*)malloc(sizeof(node));
    if(!newNode){
        fprintf(stderr,"err in node allocation");
        exit(-1);
    }
    
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(*head == NULL)
    {
        *head = *tail = newNode;
    }

    else
    {
        node*current = *head;
        while (current->next != NULL && strcmp(current->data.str,data.str) < 0)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            newNode->prev = *tail;
            (*tail)->next = newNode;
            *tail = newNode;
        }

        if (current == *head)
        {
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        }
        else
        {
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        
    }
}

params readInput(int argc, char*argv[]){
    if(argc != 3){
    fprintf(stderr,"usage: <.txt> <float>");
    exit(-1);
    }

    params record = {0,0};

    FILE *file = fopen(argv[1],"r");
    record.file = file;
    if(!file)
    {
        fprintf(stderr,"err in file format!");
        exit(-1);
    }

    float F = atof(argv[2]);
    record.F = F;
    if( F < 1.0 || F > 20.0)
    {
        fprintf(stderr,"float must be in 1.0-20.0 range");
        exit(-1);
    }
    return record;
}