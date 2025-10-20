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
    if (queue->head == NULL)   
    {
        fprintf(stderr,"empty queue");
        exit(-1);
    }

    node *temp = queue->head;   
    char *string = strdup(temp->string);    
    queue->head = queue->head->next;    

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













