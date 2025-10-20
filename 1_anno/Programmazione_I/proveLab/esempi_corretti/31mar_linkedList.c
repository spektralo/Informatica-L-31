#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_len 100

typedef struct{
    FILE *input;
    int k;
} record;

typedef struct node{
    char str[max_len];
    struct node *next;
} node;

void insertWord(node**,char string[]);
void buildList(node**,record);
void printList(node*);
void elab(node*head, record);
record readInput(int argc, char*argv[]);


int main(int argc, char *argv[]){
    node *head = NULL;
    record input = readInput(argc,argv);
    buildList(&head,input);
    elab(head,input);
    printList(head);

}

void elab(node*head, record record){
    int count = 0;
    node *current = head;
    while (current != NULL)
    {
        if (strlen(current->str) >= record.k)
        {
            count++;
        }
        current = current->next;
    }
    printf("\nnum record >= %d: %d\n",record.k,count);
    printf("\n");
}


void insertWord(node**head, char string[]){
    node *newNode = (node*)malloc(sizeof(node));  //alloco la memoria per il nuovo nodo
    if (newNode == NULL)
    {
        fprintf(stdout,"err in mem alloc!"); //controllo se allocazione è fallita
        exit(-1);
    }
        strcpy(newNode->str, string); //inizializzo i parametri del nuovo nodo
        newNode->next = NULL;
    
    //LOGICA DI INSERIMENTO IN LISTA

    if (*head == NULL || strcmp((*head)->str, newNode->str) > 0 ) 
    {  
        newNode->next = *head;      //inserimento in testa, lista vuota
        *head = newNode;
    } 

    else

     {
        node *current = *head;  //ricerca posizione inserimento, quello in testa viene già gestito sopra !!!
        while (current->next != NULL && strcmp(current->next->str, newNode->str) < 0) 
        {
            current = current->next;
        }
    
            newNode->next = current->next;  //inserimento tra due nodi
            current->next = newNode;
    }        
}

void printList(node *p){
    while (p != NULL)   //scorro la lista fino a che il next di P è == NULL (fine lista)
    {
        fprintf(stdout,"|%s| ->",p->str); //stampo contenuto
        p = p->next;    //scorro nodi
    }
    printf("NULL");
}
 
void buildList(node**head,record istanza){
   char buffer[max_len];    //buffer temporaneo per contenere le stringhe lette
    while (fgets(buffer, max_len, istanza.input) != NULL)   //ciclo che scorre il contenuto del file di input (var_destinazione.lunghezza_stringa.file_input)
     {
        buffer[strcspn(buffer, "\n")] = '\0';   //sostituzione del carattere newLine(\n) con il
                                                //carattere di terminazione stringa (\0), per garantire una corretta formattazione
        insertWord(head, buffer);  //funzione di inserimento del nodo in lista    
    }
}

record readInput(int argc,char* argv[]){
    if (argc != 3){
        printf("\nusage: <.txt> <int>");
        exit(-1);
    }

    record newRec = {0,0};

    FILE *input = fopen(argv[1],"r");
    newRec.input = input;
    
    
    if(!input){
        fprintf(stderr,"\nfile not valid!");
        exit(-1);
    }

    int k = atoi(argv[2]);
    newRec.k = k;

    if (k < 7 || k > 13)
    {
        fprintf(stderr,"\nint must be in 7-13!");
        exit(-1);
    }
    
    return newRec;
}




    







