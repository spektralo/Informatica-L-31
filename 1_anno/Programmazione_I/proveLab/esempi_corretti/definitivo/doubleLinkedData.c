#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 30


typedef struct{
    FILE *file;
    float F;
}params;

typedef struct{
    float value;
    char string[max_len];
}data;

typedef struct node{
    data data;
    struct node *next;
    struct node *prev;
}node;


params readInput(int argc, char *argv[]);
void insertRecord(node**head,node**tail,data data);
void buildList(node**head,node**tail,params record);
void elab(node **head,params record);
void printList(node**head);


int main(int argc, char*argv[]){

    node *head = NULL;
    node *tail = NULL;

    params record = readInput(argc,argv);
    buildList(&head,&tail,record);
    elab(&head,record);
    printList(&head);

}

void printList(node**head){
    node *current = *head;
    printf("** HEAD **\n");
    while (current != NULL) {
        printf("%s %.4f\n", current->data.string, current->data.value);
        current = current->next;
    }
    printf("** TAIL **");
}


void elab(node **head,params record){
    int count = 0;
    node *current = *head;

    while (current->next != NULL)
    {
        if (current->data.value >= record.F)
        {
            count++;
        }
        
        current = current->next;
    }
    fprintf(stdout,"\noccurrencies >= %.2f :%d\n",record.F,count);
}


void buildList(node**head,node**tail,params record){
    data data;
    while (fscanf(record.file,"%f %s",&data.value,data.string) == 2)
    {
        insertRecord(head,tail,data);
    }
fclose(record.file);
}


void insertRecord(node**head,node**tail,data data){
    node *newNode = (node*)malloc(sizeof(node));
    if (!newNode)
    {
        fprintf(stderr,"err in mem alloc!");
        exit(-1);
    }
    
    newNode->data = data;
    newNode->prev = newNode->next = NULL;

    if (*head == NULL) //caso lista vuota
    {
        *head = *tail = newNode;
    }
        else
            {

            node *current = *head; 
            while (current->next != NULL && strcmp(current->data.string, data.string) < 0)
            {
                current = current->next; 
                //cerca dove posizionare il newNode
            }

            if (current == NULL)    //inserimento in coda alla lista del newNode
            {
                newNode->prev = *tail;
                (*tail)->next = newNode;
                 *tail = newNode;
            }

            else if (current == *head)  //inserimento in testa alla lista del newNode
            {
                newNode->next = *head;
                (*head)->prev = newNode;
                 *head = newNode;
            }

            else    //inserimento del newNode tra due nodi esistenti
            {
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
}

params readInput(int argc, char *argv[]){
    if (argc != 3)
    {
        fprintf(stderr,"usage: <txt> <float>");
        exit(-1);
    }
    
    params record = {0,0};

    FILE *file = fopen(argv[1],"r");
    record.file = file;
    if(!file)
    {
        fprintf(stdout,"error in file format!");
        exit(-1);
    }

    float F = atof(argv[2]);
    record.F = F;
    if (F < 1.0 || F > 20.0)
    {
        fprintf(stderr,"F must be in 1.0 - 20-0");
        exit(-1);
    }
    return record;
}