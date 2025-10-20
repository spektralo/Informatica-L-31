#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct node *next;
} node;


void headIns(node**,int);
void tailIns(node**,int);
void printList(node*);
void deleteNode(node**,int);
void searchNode(node**,int);



int main(){

    node* head = NULL;
    headIns(&head,39);
    headIns(&head,47);
    tailIns(&head,96);
    tailIns(&head,88);
    printList(head);

}

void searchNode(node**head, int searchedNode){
    node *current = *head;

    while (current != NULL)
    {
        if (current->data == searchedNode)
        {
            printf("\nnodo trovato:%d",current->data);
        }
        current = current->next;
    }
}


void deleteNode(node**head, int dato){
    node *tmp = *head;      
    node *prev = NULL;      

    if (tmp != NULL && tmp->data == dato)   //1*caso, il dato da eliminare si trova in testa
    {
        *head = tmp->next;      //sposto la testa al prossimo nodo
        printf("\nnodo eliminato:%d",tmp->data);
        free(tmp);          //libero lo spazio in memoria occupato dal nodo da eliminare
    }

    while (tmp != NULL && tmp->data != dato) //2*caso, il dato da eliminare si trova in mezzo alla lista
    {
        prev = tmp;         
        tmp = tmp->next;    
    }
    
    if (tmp == NULL)
    {
        printf("\nno instance found");
    }
    
    prev->next = tmp->next;   
    printf("\nnodo eliminato:%d",tmp->data); 
    free(tmp);
}
 
void headIns(node **head, int data){
    node *newNode = (node*)malloc(sizeof(node));

    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;   
}

void tailIns(node**head,int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if ((*head)==NULL)
    {
        (*head) = newNode;
        return;
    }

    while ((*head)->next != NULL)
    {
    (*head) =(*head)->next; }

    (*head)->next = newNode;
}



void printList(node *p){
    printf("\n");

    while (p != NULL) //ciclo fino a che il puntatore p (testa) non incontra la fine della lista puntando a NULL
    {
        printf("|%d| ->",p->data); //stampo il dato del nodo
        p = p->next; //sposto il puntatore al nodo successivo
    }
    printf("NULL"); //se il puntatore incontra la fine della lista (NULL) ritornerà NULL
}