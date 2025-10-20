#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 30

typedef struct {
    FILE *file;
    int x;
    int y;
}record;


typedef struct node{
    char str[max_len];
    struct node*next;
}node;



record readInput(int argc, char*argv[]);
void insertRecord(node**head,char str[]);
void buildList(node**head,record input);
void removeByAge(node**head,record input);
void printList(node**head);

int main(int argc, char*argv[]){

    node*head = NULL;
    record newRecord = readInput(argc,argv);

    buildList(&head,newRecord);
    removeByAge(&head,newRecord);
    printList(&head);

}

void removeByAge(node**head, record input) {
    node *current = *head;
    node *prev = NULL;

    while (current != NULL) {
        int len = strlen(current->str);
        if (len < input.x || len > input.y) {
            if (prev == NULL) {
                *head = current->next; // Se stai rimuovendo la testa
            } else {
                prev->next = current->next; // Bypass del nodo corrente
            }
            node *temp = current;
            current = current->next;
            free(temp); // Libera la memoria del nodo corrente
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void printList(node**head){
    node *temp = *head;
    while (temp != NULL)
    {
        fprintf(stdout,"%s\n",temp->str);
        temp = temp->next;
    }
}

void buildList(node**head,record input){
    char buffer[max_len];
    while (fgets(buffer,max_len,input.file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        insertRecord(head,buffer); 
    }
    fclose(input.file);
}

void insertRecord(node**head,char str[]){
    node*newNode = (node*)malloc(sizeof(node));
    if(!newNode){
        fprintf(stderr,"err in node allocation!");
        exit(-1);
    }

    strcpy(newNode->str,str);
    newNode->next = NULL;

    if (*head == NULL || strcmp((*head)->str,newNode->str) > 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        node*current = *head;
        while(current->next != NULL && strcmp(current->next->str,newNode->str) < 0 )
        {
        current = current->next;
        }
            newNode->next = current->next;
            current->next = newNode;
    }
}

record readInput(int argc, char*argv[]){
    if(argc != 4){
        fprintf(stderr,"usage: <.txt> <int> <int>");
        exit(-1);
    }
    record newRecord = {0,0,0};

    FILE *file = fopen(argv[1],"r");
    newRecord.file = file;
    if(!file){
        fprintf(stderr,"err in file format");
        exit(-1);
    }

    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    newRecord.x = x;
    newRecord.y = y;

    if ( (x > y) || (x < 10) || (y > 60) )
    {
        fprintf(stderr,"x must be < than y, and ints must be in 10-60 range!");
        exit(-1);
    }
    return newRecord;
}