#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 30

typedef struct{
    FILE *file;
    int a;
    int b;
}params;

typedef struct{
    char codice[max_len];
    char prodotto[max_len];
    int prezzo;
}Record;

typedef struct node{
    Record record;
    struct node*next;
}node;


params leggiInput(int argc, char*argv[]);
void inserisciRecord(node**head,Record record);
void creaLista(node**head,params input);
void stampaLista(node*head);
void rimuoviPerPrezzo(node**head,int x, int y);

int main(int argc, char*argv[]){
    node*head = NULL;
    params input = leggiInput(argc,argv);
    creaLista(&head,input);

    printf("\n**LISTA**\n");
    stampaLista(head);

    rimuoviPerPrezzo(&head,input.a,input.b);
    printf("\n**LISTA (dopo cancellazione)**\n");
    stampaLista(head);
}

void rimuoviPerPrezzo(node**head,int x, int y){
    node *current = *head, *prev = NULL;
    while (current != NULL)
    {
        if (current->record.prezzo >= x && current->record.prezzo <= y) 
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

void stampaLista(node*temp){
    while(temp != NULL){
        fprintf(stdout,"%s %s %d\n",temp->record.codice,temp->record.prodotto,temp->record.prezzo);
        temp = temp->next;
    }
}

void inserisciRecord(node**head,Record record){
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        fprintf(stderr, "Errore nell'allocazione del nodo!\n");
        exit(EXIT_FAILURE);
    }

    newNode->record = record;
    newNode->next = NULL;

    if (*head == NULL || strcmp(record.codice, (*head)->record.codice) < 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        node* current = *head;
        while (current->next != NULL && strcmp(current->next->record.codice, record.codice) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


void creaLista(node**head,params input){
    Record record;
    while (fscanf(input.file, "%s %s %d", record.codice, record.prodotto, &record.prezzo) == 3) {
        inserisciRecord(head, record);
    }
    fclose(input.file);
}


params leggiInput(int argc, char*argv[]){
    if (argc != 4)
    {
        fprintf(stderr,"usage: <.txt> <int> <int>");
        exit(-1);
    }
    
    params input = {0,0,0};
    
    FILE *file = fopen(argv[1],"r");
    input.file = file;
    if(!file){
        fprintf(stderr,"err in file format!");
        exit(-1);
    }

    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    input.a = a;
    input.b = b;

    if ( (a > b) || ( a < 5) || (a > 50) || (b < 5) || ( b > 50 ))
    {
        fprintf(stderr,"a must be lesser than b && ints must be in 5-50!");
        exit(-1);
    }
    return input;
}