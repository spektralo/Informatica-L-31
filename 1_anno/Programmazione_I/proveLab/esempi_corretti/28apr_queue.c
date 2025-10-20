#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 100

typedef struct{
    FILE *file;
    char a, b;
}input;

typedef struct Node{
    char string[max_len];
    struct Node *next;
}Node;

typedef struct{
    Node *front;
    Node *rear;
}queue;


input readInput(int argc, char *argv[]);
void enqueue(queue *Q, char *string);
char *dequeue(queue *Q);
void printQueue(queue *Q, input record);
void elab(char *string, input record);
void buildQueue(queue *Q, input record);

int main(int argc, char *argv[]){

    input record = readInput(argc,argv);

    queue Q;
    Q.front = Q.rear = NULL;

    buildQueue(&Q,record);
    printQueue(&Q,record);

}

void elab(char *string, input record){
     for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= record.a && string[i] <= record.b) {
            string[i] = '0';
        }
    }
}

void printQueue(queue *Q, input record){
    char *string;
    while ((string = dequeue(Q)) != NULL)
    {
        elab(string,record);
        printf("%s\n",string);
        free(string);
    }
}

char *dequeue(queue *Q){
    if (Q->front == NULL)
    {
        return NULL;
    }
    Node *temp = Q->front;
    char *result =  strdup(temp->string);
    Q->front = Q->front->next;

    if (Q->front == NULL)
    {
        Q->rear = NULL;
    }
    free(temp);
    return result;
}

void buildQueue(queue *Q, input record){
    char buffer[max_len];
    while (fgets(buffer,sizeof(buffer),record.file))
    {
        buffer[strcspn(buffer,"\n")] = '\0';
        enqueue(Q,buffer);
    }
    fclose(record.file);
}

void enqueue(queue *Q, char *string){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr,"err in node allocation!");
        exit(-1);
    }

    strcpy(newNode->string,string);
    newNode->next = NULL;
    
    if (Q->rear == NULL) //caso coda vuota
    {
        Q->front = Q->rear = newNode;
    }
        else    //inserimento in coda
        {
            Q->rear->next = newNode;
            Q->rear = newNode;
        }
}


input readInput(int argc, char *argv[]){
    if (argc != 4)
    {
        fprintf(stderr,"usage: <file> <char> <char>");
        exit(-1);
    }

    input record = {0,0,0};

    FILE *file = fopen(argv[1],"r");
    

    if (!file)
    {
        fprintf(stderr,"error in file format!");
        exit(-1);
    }

    record.file = file;

    char a = argv[2][0];
    char b = argv[3][0];

    if (a >= b )
    {
        fprintf(stderr,"a must be >= than b!");
        exit(-1);
    }
    record.a = a;
    record.b = b;

return record;
}