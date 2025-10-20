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
    struct node*next;
}node;

typedef struct{
    node *head;
    node *tail;
}Queue;


params readInput(int argc,char*argv[]);
void enqueue(Queue *queue,char string[]);



int main(int argc,char*argv[]){
    Queue queue;
    queue.head = queue.tail = NULL;

    params record = readInput(argc,argv);
    
}

char *dequeue(Queue *queue){
    if (queue->head == NULL)
    {
        fprintf(stderr,"coda vuota");
        exit(-1);
    }
    node *temp = queue->head;
    char *string = strdup(temp->string);

    queue->head =queue->head->next;
    if (queue->head == NULL)
    {
        queue->tail = NULL;
    }
    
    free(temp);
    return string;
}

void enqueue(Queue *queue,char string[]){
    node *newNode = (node*)malloc(sizeof(node));
    if (!newNode)
    {
        fprintf(stderr,"error in node allocation!");
        exit(-1);
    }

    strcpy(newNode->string,string);
    newNode->next = NULL;

    if (queue->tail == NULL)
    {
        queue->head = queue->tail = newNode;
    }
    
    queue->tail->next = newNode;
    queue->tail = newNode;
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