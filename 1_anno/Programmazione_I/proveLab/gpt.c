#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 10
#define MAX_PRODUCT_LEN 30

typedef struct {
    char codice[MAX_CODE_LEN];
    char prodotto[MAX_PRODUCT_LEN];
    int quantita;
} Record;

typedef struct Node {
    Record record;
    struct Node* next;
} Node;

typedef struct {
    FILE* file;
    int m;
    int n;
} InputData;

InputData leggiInput(int argc, char* argv[]);
void inserisciRecord(Node** head, Record record);
void creaLista(Node** head, InputData input);
void stampaLista(Node* head);
void rimuoviPerQuantita(Node** head, int m, int n);

int main(int argc, char* argv[]) {
    Node* head = NULL;
    InputData input = leggiInput(argc, argv);

    creaLista(&head, input);
    printf("Lista ordinata:\n");
    stampaLista(head);

    rimuoviPerQuantita(&head, input.m, input.n);
    printf("\nLista ordinata dopo la rimozione dei record con quantità in [%d, %d]:\n", input.m, input.n);
    stampaLista(head);

    return 0;
}

InputData leggiInput(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: <nome_file> <int m> <int n>\n");
        exit(EXIT_FAILURE);
    }

    InputData input;
    input.file = fopen(argv[1], "r");
    if (!input.file) {
        fprintf(stderr, "Errore nell'apertura del file\n");
        exit(EXIT_FAILURE);
    }

    input.m = atoi(argv[2]);
    input.n = atoi(argv[3]);

    if (input.m >= input.n || input.m < 5 || input.m > 50 || input.n < 5 || input.n > 50) {
        fprintf(stderr, "m deve essere minore di n e compreso tra 5 e 50\n");
        exit(EXIT_FAILURE);
    }

    return input;
}

void inserisciRecord(Node** head, Record record) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Errore nell'allocazione del nodo!\n");
        exit(EXIT_FAILURE);
    }

    newNode->record = record;
    newNode->next = NULL;

    if (*head == NULL || record.quantita < (*head)->record.quantita) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->record.quantita < record.quantita) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void creaLista(Node** head, InputData input) {
    Record record;
    while (fscanf(input.file, "%s %s %d", record.codice, record.prodotto, &record.quantita) == 3) {
        inserisciRecord(head, record);
    }
    fclose(input.file);
}

void stampaLista(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s %s %d\n", temp->record.codice, temp->record.prodotto, temp->record.quantita);
        temp = temp->next;
    }
}

void rimuoviPerQuantita(Node** head, int m, int n) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->record.quantita >= m && current->record.quantita <= n) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}
