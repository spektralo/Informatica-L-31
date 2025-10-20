#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct {
    int N;
    char a;
    char b;
}record;

typedef struct{
    char x;
    struct node*next;
} node;


record readInput(int argc, char*argv[]);
char genVowel();
char genConsonant();
void push(node**head,char x);
void fillStack(record instance, node**head);
void printStack(node*);

int main(int argc, char *argv[]){

    node *head = NULL;
    record newRecord = readInput(argc,argv);
    fillStack(newRecord,&head);
    printStack(head);


}

void fillStack(record instance, node**head){
    for (int i = 0; i < instance.N; i++) {
        char x = '1' + rand() % 9; // Genera un carattere tra '1' e '9'
        int numOps = x - '0'; // Converti il carattere in numero

        for (int j = 0; j < numOps; j++) {
            char c;
            if (numOps <= 4) {
                c = genVowel();
            } else {
                c = genConsonant();
            }
            
            if (c == instance.a) {
                push(head, '*');
            } else if (c == instance.b) {
                push(head, '?');
            } else {
                push(head, c);
            }
        }
        
        push(head, x); // Inserisci x alla fine
    }
}

void push(node**head,char x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->x = x;
    newNode->next = *head;
    *head = newNode;
}

void printStack(node *top) {
    node *current = top;
    printf("** TOP->");
    while (current != NULL) {
        printf("%c", current->x);
        printf(" ");
        current = current->next;
    }
    printf("<-BOTTOM **");
}

char genVowel(){
    char vowels[] = "aeiou";

    return vowels[rand() % 5 ];

}

char genConsonant(){
    char consonant[] = "bcdfghjklmnpqrstvwxyz";

    return consonant[rand() % 21];
}


record readInput(int argc, char*argv[]){
    if (argc != 4)
    {
        fprintf(stderr,"parametri errati!");
        exit(-1);
    }

    record parametri = {0, 0, 0};

    int N = atoi(argv[1]);
    parametri.N = N;

    if (N < 5 || N > 10)
    {
        fprintf(stderr,"N deve essere in 5-10");
        exit(-1);
    }

    char a = argv[2][0];
    char b = argv[3][0];

    parametri.a = a;
    parametri.b = b;
    
    if ( (a < 'a' || a > 'z') || (b < 'a' || b > 'z') ) 
    {
        fprintf(stderr,"chars must be in 'a'-'z'!");
        exit(-1);
    }
    
    return parametri;
}
