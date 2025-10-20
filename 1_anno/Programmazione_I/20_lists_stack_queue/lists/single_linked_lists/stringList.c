#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
typedef struct{
    char str[size];
    struct node *next;
}node;

void insertAtHead(node**, char[]);
void printList(node*);
void searchedString(node**, char[]);


int main(int argc, char *argv[]){

    node *head = NULL;
    insertAtHead(&head,"saragozza");
    insertAtHead(&head,"asdrubale");
    insertAtHead(&head,"toni");
    searchedString(&head,"toni");

    printList(head);


}

void searchedString(node**head, char searchedString[]){
    node *current = *head;

    while (current != NULL)
    {
        if (strlen(current->str) == strlen(searchedString))
        {
            printf("\nstringa trovata:%s",current->str);
        }
        current = current->next;
    }
}


void printList(node*p){
     printf("\n");

    while (p != NULL) 
    {
        printf("|%s| ->",p->str);
        p = p->next;
    }
    printf("NULL");
}


void insertAtHead(node**head, char string[]){
    node *nuovo = (node*)malloc(sizeof(node));
    if (nuovo == NULL)
    {
        fprintf(stdout,"err in mem alloc!");
        exit(-1);
    }
        strcpy(nuovo->str, string);
        nuovo->next = (*head);

        (*head) = nuovo;
}
