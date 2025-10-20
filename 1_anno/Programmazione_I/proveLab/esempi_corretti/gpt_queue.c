#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 30

typedef struct{
    FILE *file;
    char x;
    char y;
}params;

typedef struct node{
    char string[max_len];
    struct node*next;
}node;

typedef struct{
    node*head;
    node*tail;
}Queue;

params readInput(int argc,char*argv[]);
void enqueue(Queue *queue,char string[]);
void buildQueue(Queue *queue,params record);
void printQueue(Queue *queue,params record);
char *dequeue(Queue *queue);
void elab(char *string, params record);

int main(int argc, char*argv[]){

Queue queue;
queue.head = NULL;
queue.tail = NULL;

params record = readInput(argc,argv);
buildQueue(&queue,record);
printQueue(&queue,record);

}

void elab(char *string, params record){
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= record.x && string[i] <= record.y) {
            string[i] = '0';
        }
    }
}

char *dequeue(Queue *queue){
    if (queue->tail == NULL)
    {
        fprintf(stdout,"coda vuota");
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


void printQueue(Queue *queue,params record){
    char *string;
    while ((string = dequeue(queue))!= NULL)
    {
        elab(string,record);
        fprintf(stdout,"%s\n",string);
        free(string);
    }
}

void buildQueue(Queue *queue,params record){
char buffer[max_len];
while (fgets(buffer,max_len,record.file) != NULL)
{
    buffer[strcspn(buffer,"\n")] = '\0';
    enqueue(queue,buffer);
}
fclose(record.file);
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

    if ((*queue).tail == NULL || strcmp((queue->head)->string,string) < 0)
    {
        queue->head = queue->tail = newNode;
    }
    
    else
    {
     queue->tail->next = newNode;
     queue->tail = newNode;
    }
}


params readInput(int argc,char*argv[]){
    if(argc != 4)
    {
        fprintf(stderr,"usage: <txt> <char> <char>");
        exit(-1);
    }
    params record = {0,0,0};

    FILE *file = fopen(argv[1],"r");
    record.file = file;
    if(!file)
    {
        fprintf(stderr,"err in file format!");
        exit(-1);
    }
    char x = argv[2][0];
    char y = argv[3][0];

    record.x = x;
    record.y = y;

    if (x >= y)
    {
        fprintf(stderr,"x char must be <= than y char!");
        exit(-1);
    }
    return record;
}