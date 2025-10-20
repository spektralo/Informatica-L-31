#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 30


typedef struct{
    FILE *file;
}params;

typedef struct node{
    char string[max_len];
    struct node *next;
}node;

typedef struct{
    node *head;
    node *tail;
}Queue;


/*** PROTOTIPI FUNZIONI ***/
params readInput(int argc,char *argv[]);
void enqueue(Queue *queue,char string[]);
char *dequeue(Queue *queue);
void buildQueue(Queue *queue, params record);
void printQueue(Queue *queue);


int main(int argc, char *argv[]){
    Queue queue;
    queue.head = queue.tail = NULL;

    params record = readInput(argc,argv);
    buildQueue(&queue,record);
    printQueue(&queue);
}


void printQueue(Queue *queue){
    char *string;
    while ((string = dequeue(queue)) != NULL)
    {
        fprintf(stdout,"%s\n",string);
        free(string);
    }
}

void buildQueue(Queue *queue, params record){
    char buffer[max_len];
    while (fgets(buffer,max_len,record.file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        enqueue(queue,buffer);
    }
    fclose(record.file);
}


char *dequeue(Queue *queue){
    if (queue->head == NULL)    //controllo se la testa della lista è già vuota, se lo è esco.
    {
        fprintf(stderr,"empty queue");
        exit(-1);
    }

    node *temp = queue->head;   //nodo temporaneo che punta alla testa della coda;
    char *string = strdup(temp->string);    //duplico la stringa del nodo temporaneo prima di rimuoverlo
    queue->head = queue->head->next;    //aggiorno il puntatore di testa facendolo puntare al suo successivo

    if(queue->head == NULL) //controllo di nuovo se la lista si è svuotata
    {
        queue->tail = NULL; //aggiorno il puntatore della coda
    }

    free(temp); //dealloco il nodo
    return string; //ritorno la stringa del nodo eliminato
}

void enqueue(Queue *queue,char string[]){
    node *newNode = (node*)malloc(sizeof(node)); //alloco un nuovo nodo
    if (!newNode)
    {
        fprintf(stderr,"error in node allocation!");
        exit(-1);
    }

    strcpy(newNode->string,string); //inizializzo stringa del nodo
    newNode->next = NULL;   //inizializzo puntatore next del nodo

    if (queue->tail == NULL)    //controllo se la coda è vuota
    {
        queue->head = queue->tail = newNode;    //testa e coda diventano il nuovo nodo
    }
    
    else    //se la coda non è vuota allora
    {
        queue->tail->next = newNode;    // il successivo della coda diventa il nuovo nodo
        queue->tail = newNode;  // il nuovo nodo diventa la fine della coda
    }
}

params readInput(int argc,char *argv[]){
    if (argc != 2)
    {
        fprintf(stderr,"usage: <txt>");
        exit(-1);
    }

    params record = {0};

    FILE *file = fopen(argv[1],"r");
    record.file = file;
    if (!file)
    {
        fprintf(stderr,"error in file format!");
        exit(-1);
    }
    return record;
}













