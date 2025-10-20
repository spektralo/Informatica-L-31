#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 30

typedef struct{
    FILE *file;
    int x;
    int y;
}params;
 
typedef struct{
    char nome[max_len];
    char cognome[max_len];
    int eta;
}data;

typedef struct node{
    data data;
    struct node *next;
}node;




params readInput(int argc, char *argv[]);
void insertWord(node**head,data data);
void buildList(node**head,params record);
void printList(node**head);
void removeByAge(node**head,params record);


int main(int argc, char *argv[]){
    node *head = NULL;

    params record = readInput(argc,argv);
    buildList(&head,record);
    fprintf(stdout,"\n**COMPLETE LIST**\n");
    printList(&head);
    removeByAge(&head,record);
    fprintf(stdout,"\n**LIST AFTER ELIM**\n");
    printList(&head);
}


void removeByAge(node**head,params record){
    node *current = *head;
    node *prev = NULL;

    while (current->next != NULL) 
        {
        if (current->data.eta >= record.x && current->data.eta <= record.y) 
            {
            if (prev == NULL) 
            {
                *head = current->next;
            } 

            else
            {
                prev->next = current->next;
            }

            node *temp = current;
            current = current->next;

            free(temp);
            } 
            
        else
         {
            prev = current;
            current = current->next;
        }
    }
}


void printList(node**head){
    node *current = *head;
    while (current->next != NULL)
    {
        fprintf(stdout," %s %s %d\n",current->data.nome,current->data.cognome,current->data.eta);
        current = current->next;
    }
    
}

void buildList(node**head,params record){
    data data;
    while (fscanf(record.file,"%s %s %d",data.nome,data.cognome,&data.eta) == 3)
    {
        insertWord(head,data);
    }
fclose(record.file);
}


void insertWord(node**head,data data){
    node *newNode = (node*)malloc(sizeof(node));
    if(!newNode)
    {
        fprintf(stderr,"error in node allocation!");
        exit(-1);
    }
    newNode->data = data;
    newNode->next = NULL;


    if (*head == NULL || strcmp((*head)->data.cognome,data.cognome) < 0 )
    {
        newNode->next = *head;
        *head = newNode;
    }

    else
    {
        node *current = *head;
        while (current->next != NULL && strcmp(current->data.cognome, data.cognome) < 0)
        {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
    }
}


params readInput(int argc, char *argv[]){
    if (argc != 4)
    {
        fprintf(stderr,"usage: <txt <int> <int>");
        exit(-1);
    }

    params record = {0,0,0};

    FILE *file = fopen(argv[1],"r");
    record.file = file;
    if(!file)
    {
        fprintf(stderr,"error in file format!");
        exit(-1);
    }
    
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    record.x = x;
    record.y = y;

    if ( x > y || x < 10 || x > 60 || y < 10 || y > 60)
    {
        fprintf(stderr,"x must be lesser than y, integers must be in (10-60)");
        exit(-1);
    }
    return record;
}