//SINGLE LINKED LIST
void insertWord(node **head, char string[]) {
    // Alloca memoria per un nuovo nodo e verifica che l'allocazione sia avvenuta con successo.
    node *newNode = (node *)malloc(sizeof(node));    
    if (!newNode) {
        // Se l'allocazione fallisce, stampa un messaggio di errore e termina il programma.
        fprintf(stderr, "error in node allocation!");
        exit(-1);
    }

    // Copia la stringa fornita come argomento nel nuovo nodo e inizializza il puntatore 'next' a NULL.
    strcpy(newNode->string, string);     
    newNode->next = NULL;

    // Verifica se la lista è vuota (head è NULL) o se la stringa da inserire deve essere posta all'inizio.
    if (*head == NULL || strcmp((*head)->string,string) < 0) { 
        // Inserisce il nuovo nodo in testa alla lista.
        newNode->next = *head;
        *head = newNode;
    } else {
        // Se il nuovo nodo non deve essere inserito in testa, cerca la posizione corretta per l'inserimento.
        node *current = *head;
        while (current->next != NULL && strcmp(current->string, string) < 0) {
            // Scorre la lista fino a trovare il punto in cui inserire il nuovo nodo.
            current = current->next;
        }

        // Inserisce il nuovo nodo nella posizione corretta nella lista.
        newNode->next = current->next;
        current->next = newNode;
    }   
}

/*
Spiegazione Dettagliata

Allocazione del Nuovo Nodo:
La funzione inizia allocando memoria per un nuovo nodo utilizzando malloc. 
Se l'allocazione fallisce, viene stampato un messaggio di errore e il programma termina con exit(-1).

Inizializzazione del Nuovo Nodo:
La stringa passata come argomento viene copiata nel campo string del nuovo nodo.
Il puntatore next del nuovo nodo viene inizializzato a NULL poiché non è ancora collegato ad altri nodi.

Verifica della Lista Vuota o Inserimento in Testa:
La funzione controlla se la lista è vuota (*head == NULL) o se la stringa del nuovo nodo deve essere
inserita in testa rispetto alla stringa del nodo attuale.

Se la condizione è vera, il nuovo nodo viene inserito in testa alla lista:
Il puntatore next del nuovo nodo viene impostato per puntare al vecchio nodo di testa.
Il puntatore head viene aggiornato per puntare al nuovo nodo.

Ricerca della Posizione Corretta per l'Inserimento:
Se il nuovo nodo non deve essere inserito in testa, la funzione scorre la lista per trovare il punto giusto in cui inserirlo:
Un ciclo while viene utilizzato per attraversare la lista fino a quando non viene trovato un nodo
con una stringa lessicograficamente maggiore o uguale a quella del nuovo nodo, o fino a quando non si raggiunge la fine della lista.

Inserimento del Nodo nella Lista:
Una volta trovata la posizione corretta, il nuovo nodo viene inserito:
Il puntatore next del nuovo nodo viene impostato per puntare al nodo successivo nella lista.
Il puntatore next del nodo corrente viene aggiornato per puntare al nuovo nodo.

Uso della Funzione
La funzione insertWord è utile quando si vuole mantenere una lista singolarmente collegata ordinata mentre si inseriscono nuovi elementi. 
*/

//DOUBLE LINKED LIST

void insertRecord(Node **head, Node **tail, char *P, float V) {
    // Alloca memoria per un nuovo nodo e verifica che l'allocazione sia avvenuta con successo.
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        // Se l'allocazione fallisce, stampa un messaggio di errore e termina il programma.
        fprintf(stderr, "err in mem alloc!");
        exit(-1);
    }

    // Inizializza i parametri del nodo (P e V in questo caso) e inizializza i puntatori 'prev' e 'next' a NULL.
    strncpy(newNode->P, P, max_len); 
    newNode->V = V;
    newNode->prev = newNode->next = NULL;

    // Verifica se la lista è vuota. Se lo è, imposta il nuovo nodo come unico elemento della lista (sia head che tail).
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        // Altrimenti, cerca la posizione corretta per inserire il nuovo nodo.
        Node *current = *head; 
        while (current->next != NULL && strcmp(current->P, P) < 0) {
            // Scorre la lista fino a trovare il punto di inserimento corretto per il nuovo nodo.
            current = current->next;
        }

        if (current == NULL)
            { 
            // Caso in cui il nuovo nodo deve essere inserito in coda alla lista.
            newNode->prev = *tail;
            (*tail)->next = newNode;
            *tail = newNode;
            } 
        
        else if (current == *head) 
            {
            // Caso in cui il nuovo nodo deve essere inserito in testa alla lista.
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
            }

        else 
            {
            // Inserisce il nuovo nodo tra due nodi esistenti.
            newNode->next = current->next;
            newNode->prev = current;
            current->prev->next = newNode;
            current->prev = newNode;
            }
        }
}
/*
Spiegazione Dettagliata

Allocazione del Nuovo Nodo:
La funzione alloca memoria per un nuovo nodo utilizzando malloc. Se l'allocazione fallisce, viene stampato un messaggio di errore e il programma termina con exit(-1).
Inizializzazione del Nuovo Nodo:

La stringa P fornita viene copiata nel campo P del nuovo nodo utilizzando strncpy. Il valore V viene assegnato al campo V del nuovo nodo.
I puntatori prev e next del nuovo nodo vengono inizializzati a NULL poiché il nodo non è ancora collegato ad altri nodi.

Verifica della Lista Vuota:

Se la lista è vuota (head è NULL), il nuovo nodo viene impostato come unico elemento della lista. In questo caso, sia head che tail puntano al nuovo nodo.
Inserimento del Nodo in Posizione Corretta:

Se la lista non è vuota, la funzione cerca la posizione corretta per inserire il nuovo nodo in ordine lessicografico basato su P.

Inserimento in Coda:
Se il ciclo raggiunge la fine della lista (current->next == NULL) e il nuovo nodo deve essere inserito dopo l'ultimo nodo attuale, viene aggiunto in coda.

Inserimento in Testa:
Se il nuovo nodo deve essere inserito prima del nodo attuale (in testa alla lista), viene aggiornato il puntatore head per puntare al nuovo nodo.

Inserimento tra Due Nodi Esistenti:
Se il nuovo nodo deve essere inserito tra due nodi esistenti, vengono aggiornati i puntatori prev e next dei nodi vicini per includere il nuovo nodo nella lista.

Uso della Funzione
La funzione insertRecord è utile per mantenere una lista doppiamente collegata ordinata mentre si inseriscono nuovi elementi.
*/



//INSERT IN STACK

void pushWord(node **head, char string[]) {
    // Alloca memoria per un nuovo nodo e verifica che l'allocazione sia avvenuta con successo.
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        // Se l'allocazione fallisce, stampa un messaggio di errore e termina il programma.
        fprintf(stderr, "allocazione fallita!");
        exit(-1);
    }

    // Copia la stringa fornita nel campo 'string' del nuovo nodo.
    strcpy(newNode->string, string);

    // Imposta il puntatore 'next' del nuovo nodo per puntare all'attuale testa della lista.
    newNode->next = (*head);

    // Aggiorna la testa della lista per farla puntare al nuovo nodo, rendendolo il primo elemento della lista.
    (*head) = newNode;
}
/*Spiegazione Dettagliata

Allocazione del Nuovo Nodo:
La funzione inizia allocando memoria per un nuovo nodo utilizzando malloc.
Se l'allocazione non riesce, viene stampato un messaggio di errore e il programma termina immediatamente con exit(-1).

Inizializzazione del Nuovo Nodo:
La stringa passata come argomento viene copiata nel campo string del nuovo nodo.
Questo assicura che il nuovo nodo contenga la stringa che deve essere aggiunta alla lista.

Inserimento del Nuovo Nodo in Testa:
Il campo next del nuovo nodo viene impostato per puntare all'attuale testa della lista, cioè al nodo che era in cima alla lista prima dell'inserimento.
La testa della lista (*head) viene poi aggiornata per puntare al nuovo nodo. Questo rende il nuovo nodo il primo elemento della lista.

Uso della Funzione
La funzione pushWord è utile quando si desidera aggiungere rapidamente un elemento all'inizio di una lista singolarmente collegata.
Questo tipo di inserimento è particolarmente efficiente poiché non richiede lo scorrimento della lista.

Esempio di utilizzo: Se hai una lista con i nodi [node1 -> node2 -> NULL] e chiami pushWord(&head, "newNode")
il risultato sarà una lista con i nodi [newNode -> node1 -> node2 -> NULL].*/


//INSERT IN QUEUE

void enqueue(queue *Q, char *string) {
    // Alloca memoria per un nuovo nodo e verifica che l'allocazione sia avvenuta con successo.
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        // Se l'allocazione fallisce, stampa un messaggio di errore e termina il programma.
        fprintf(stderr, "err in node allocation!");
        exit(-1);
    }

    // Copia la stringa fornita nel campo 'string' del nuovo nodo.
    strcpy(newNode->string, string);
    
    // Imposta il puntatore 'next' del nuovo nodo a NULL poiché sarà l'ultimo elemento della coda.
    newNode->next = NULL;

    // Verifica se la coda è vuota (rear è NULL).
    if (Q->tail == NULL) {
        // Se la coda è vuota, sia il front che il rear puntano al nuovo nodo.
        Q->head = Q->tail = newNode;
    } else {
        // Se la coda non è vuota, aggiungi il nuovo nodo alla fine (dopo rear).
        Q->tail->next = newNode;
        // Aggiorna rear per puntare al nuovo nodo, che ora è l'ultimo elemento.
        Q->tail = newNode;
    }
}
/* 
Spiegazione Dettagliata

La funzione inizia allocando memoria per un nuovo nodo utilizzando malloc. 
Se l'allocazione fallisce, viene stampato un messaggio di errore e il programma termina con exit(-1).

Inizializzazione del Nuovo Nodo:
La stringa passata come argomento viene copiata nel campo string del nuovo nodo.
Il campo next del nuovo nodo viene impostato a NULL poiché questo nodo sarà inserito in coda (sarà l'ultimo elemento della coda).

Inserimento del Nuovo Nodo nella Coda:
La funzione verifica se la coda è vuota controllando se Q->tail è NULL.

Coda Vuota: Se la coda è vuota (cioè tail è NULL), il nuovo nodo diventa sia il primo (head) che l'ultimo (tail) elemento della coda.

Coda Non Vuota: Se la coda non è vuota, il nodo corrente in coda (Q->tail) deve collegarsi al nuovo nodo attraverso il puntatore next. 
Successivamente, rear viene aggiornato per puntare al nuovo nodo, mantenendo così l'integrità della coda.

Uso della Funzione
La funzione enqueue è tipicamente utilizzata per aggiungere elementi a una coda (struttura FIFO - First In, First Out).
In particolare, l'elemento inserito sarà sempre posizionato alla fine della coda.*/

char *dequeue(Queue *queue) {
    // Controlla se la coda è vuota, cioè se la coda non ha elementi.
    if (queue->tail == NULL) {
        // Se la coda è vuota, stampa un messaggio di errore.
        fprintf(stdout, "coda vuota");
        // Termina il programma con un codice di uscita -1.
        exit(-1);
    }

    // Memorizza temporaneamente il puntatore al nodo in testa alla coda.
    node *temp = queue->head;
    // Duplica la stringa contenuta nel nodo in testa, per poterla restituire.
    char *string = strdup(temp->string);
    // Sposta la testa della coda al nodo successivo.
    queue->head = queue->head->next;

    // Se dopo la rimozione la coda è diventata vuota (cioè, non ci sono più nodi),
    // aggiorna anche il puntatore alla coda (tail) a NULL.
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    // Libera la memoria occupata dal nodo appena rimosso dalla coda.
    free(temp);

    // Restituisce la stringa duplicata, che era contenuta nel nodo rimosso.
    return string;
}


