#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct node *prev;
    struct node *next;
} node;


void insertAtBeg(node**,int);
void reversePrintList(node*);
void printList(node*);
void deleteNode(node**,int);
void insertEnd(node**,int);

int main(int argc, char*argv[]){

    node *head = NULL;
    insertAtBeg(&head,39);
    insertAtBeg(&head,72);

    printList(head);
    reversePrintList(head);
}




void printList(node*p){
    printf("\nList:");
    while (p != NULL)
    {
        printf("|%d| ->",p->data);
        p = p->next;
    }
    printf("NULL");
}

void reversePrintList(node*p){
    printf("\n");
   if (p == NULL) return;
   while (p->next != NULL)
   {
        p = p->next;
   }
    
    printf("ReverseList:");
    while (p != NULL)
    {
        printf("|%d| ->",p->data);
        p = p->prev;
    }
    
   printf("NULL");
}

void deleteNode(node**head,int key){


}

void insertAtBeg(node**head, int data){
    node * newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
    {
        fprintf(stderr,"\nError in allocation!");
        exit(-1);
    }

    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;

     if ((*head) != NULL)
     {
        (*head)->prev = newNode; }

    (*head) = newNode;
}

