#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 100

typedef struct{
    FILE *file;
    int k;
} input;

typedef struct{
    char string[max_len];
    struct node *next;
} node;


input readInput(int argc, char*argv[]);
void pushWord(node**head, char string[]);
void buildStack(node**head, input record);
void printStack(node**head, input record);
void popWord(node**head);
void sortWord(char string[]);


int main(int argc, char *argv[]){

    node* head = NULL;
    input newInput = readInput(argc,argv);
    buildStack(&head,newInput);
    printStack(&head,newInput);
    
}


void popWord(node**head){
    //DA DEFINI
}

void sortWord(char str[]){
    int i, j;
    int n = strlen(str);

    // Controlla se la lunghezza della stringa è maggiore di 10
    if (n > 10) {
        char temp;

        // Bubble sort per ordinare la stringa
        for (i = 0; i < n-1; i++) {
            for (j = i+1; j < n; j++) {
                if (str[i] > str[j]) {
                    // Scambia i caratteri
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
        }
    }
}

void printStack(node**head,input record)
{
     node* temp = *head;
        while (temp != NULL)
        {  
            sortWord(temp->string);
            fprintf(stdout,"%s", temp->string);
            temp = temp->next;
        }      
        printf("\n");
}


void pushWord(node**head, char string[]){
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode==NULL)
    {
        fprintf(stderr,"allocazione fallita!");
        exit(-1);
    }

    strcpy(newNode->string, string);

    newNode->next = (*head);    //Inserimento solo in testa nello stack
    (*head) = newNode;

}

void buildStack(node**head, input record){
    char buffer[max_len];
    while (fgets(buffer,max_len,record.file) != NULL)
    {
        buffer[strcspn(buffer,"\n")] = '\0';
        pushWord(head,buffer);
    } 
    fclose(record.file);
}


input readInput(int argc, char *argv[]){
    if (argc != 3)
    {
        fprintf(stderr,"parametri errati!");
        exit(-1);
    }    

    input newInput = {0,0};

    FILE *file = fopen(argv[1],"r");
    newInput.file = file;

    if(file == NULL){
        fprintf(stderr,"file vuoto!");
        exit(-1);
    }

    int k = atoi(argv[2]);
    newInput.k = k;

    if (k < 5 || k > 15)
    {
        fprintf(stderr,"k deve essere compreso tra 5 e 15!");
        exit(-1);
    }
    
    return newInput;

}