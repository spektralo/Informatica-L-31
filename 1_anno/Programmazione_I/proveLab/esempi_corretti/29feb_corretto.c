#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30

typedef struct {
    char nome[MAX_LEN];
    char cognome[MAX_LEN];
    int eta;
} Record;

typedef struct Node {
    Record record;
    struct Node* next;
} Node;

typedef struct {
    FILE *file;
    int x;
    int y;
} InputParams;

InputParams readInput(int argc, char *argv[]);
void insertRecord(Node** head, Record record);
void buildList(Node** head, InputParams input);
void printList(Node* head);
void removeByAge(Node** head, int x, int y);



int main(int argc, char *argv[]) {
    Node* head = NULL;
    InputParams inputParams = readInput(argc, argv);

    buildList(&head, inputParams);
    printf("Lista completa:\n");
    printList(head);

    removeByAge(&head, inputParams.x, inputParams.y);
    printf("\nLista dopo la rimozione:\n");
    printList(head);
}


InputParams readInput(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso corretto: <programma> <input.txt> <x> <y>\n");
        exit(-1);
    }

    InputParams input;
    input.file = fopen(argv[1], "r");
    if (!input.file) {
        fprintf(stderr, "Errore nell'apertura del file\n");
        exit(-1);
    }

    input.x = atoi(argv[2]);
    input.y = atoi(argv[3]);

    if (input.x >= input.y || input.x < 10 || input.y > 60) {
        fprintf(stderr, "x deve essere minore di y e entrambi devono essere nell'intervallo [10, 60]\n");
        exit(-1);
    }

    return input;
}

void insertRecord(Node** head, Record record) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Errore nell'allocazione del nodo!\n");
        exit(-1);
    }
    newNode->record = record;
    newNode->next = NULL;

    if (*head == NULL || strcmp(record.cognome, (*head)->record.cognome) < 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && strcmp(current->next->record.cognome, record.cognome) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void buildList(Node** head, InputParams input) {
    char nome[MAX_LEN], cognome[MAX_LEN];
    int eta;
    while (fscanf(input.file, "%s %s %d", nome, cognome, &eta) == 3) {
        Record record;
        strcpy(record.nome, nome);
        strcpy(record.cognome, cognome);
        record.eta = eta;
        insertRecord(head, record);
    }
    fclose(input.file);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s %s %d\n", temp->record.nome, temp->record.cognome, temp->record.eta);
        temp = temp->next;
    }
}

void removeByAge(Node** head, int x, int y) {
    Node *current = *head, *prev = NULL;

    while (current != NULL) {
        if (current->record.eta >= x && current->record.eta <= y) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            Node *temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}