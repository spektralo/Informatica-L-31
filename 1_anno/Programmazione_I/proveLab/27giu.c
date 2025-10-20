#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 100


typedef struct{
    FILE *file;
    float F;
}input;


typedef struct Node{
    char P[max_len];
    float V;
    struct Node *next;
    struct Node *prev;
}Node;


input readInput(int argc, char*argv[]);
void insertRecord(Node**head, Node**tail, char *P, float V);
void buildList(Node**head,Node**tail,input record);
void printList(Node*head);
void elab(Node*head, input record);

int main(int argc, char*argv[]){

    Node *head = NULL, *tail = NULL;
    input record = readInput(argc,argv);
    buildList(&head,&tail,record);
    elab(head,record);
    printList(head);

}


void elab(Node*head, input record){
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        if (current->V >= record.F)
        {
            count++;
        }
        current = current->next;
    }
    printf("\nnum record >= %.4f: %d\n",record.F,count);
    printf("\n");
}


void printList(Node *head) {
    Node *current = head;
    printf("** HEAD **\n");
    while (current != NULL) {
        printf("%s: %.4f\n", current->P, current->V);
        current = current->next;
    }
    printf("** TAIL **");
}


void buildList(Node**head,Node**tail,input record){
    char parola[max_len];
    float valore;
    
    while (fscanf(record.file, "%f\n", &valore) == 1)
    {
        if (fgets(parola, max_len, record.file) != NULL)
        {
            parola[strcspn(parola, "\n")] = '\0';
            insertRecord(head,tail,parola,valore);
        }
            else
                {
                fprintf(stderr,"err in file format!");
                exit(-1);
                }
    }
}


void insertRecord(Node**head, Node**tail, char *P, float V ){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr,"err in mem alloc!");
        exit(-1);
    }
    
    strncpy(newNode->P, P, max_len);
    newNode->V = V;
    newNode->prev = newNode->next = NULL;

    if (*head == NULL) //caso lista vuota
    {
        *head = *tail = newNode;
    }
        else
            {
            Node *current = *head; 

            while (current != NULL && strcmp(current->P, P) < 0)
            {
                current = current->next; 
                //caso lista non vuota, cerca dove posizionare newNode
            }

            if (current == NULL) //caso inserimento in coda
            {
                newNode->prev = *tail;
                (*tail)->next = newNode;
                *tail = newNode;
            }

            else if (current == *head) //caso inserimento in testa
            {
                newNode->next = *head;
                (*head)->prev = newNode;
                *head = newNode;
            }

            else    //caso inserimento tra due nodi
            {   
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
}

input readInput(int argc, char*argv[]){
    if (argc != 3)
    {
        fprintf(stderr,"usage: <file.txt> <float>");
        exit(-1);
    }

    input record = {0,0};
    FILE *file = fopen(argv[1],"r");

    record.file = file;
    if (!file)
    {
        fprintf(stderr,"err in file!");
        exit(-1);
    }
    
    float F = atof(argv[2]);
    record.F = F;
    
    if (F < 1.0 || F > 20.0)
    {
        fprintf(stderr,"float must be in (1.0 - 20.0) range!");
        exit(-1);
    }
 return record;   
}