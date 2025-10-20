#include <iostream>
using namespace std;

// Struttura Nodo: rappresenta un nodo di una lista collegata
template <class T>
struct Node {
    T value;          // Valore del nodo
    Node<T>* next;    // Puntatore al nodo successivo
};

// Classe Lista: rappresenta una lista collegata generica
template <class T>
class LinkedList {
public:
    LinkedList() : head(nullptr) {} // Costruttore
    ~LinkedList();                 // Distruttore
    void print() const;            // Stampa il contenuto della lista
    void insert(T value);          // Inserisce un valore in testa alla lista
    Node<T>* getHead() const { return head; } // Restituisce il nodo di testa
    Node<T>* search(T value) const;          // Cerca un valore nella lista

    // Sovraccarico dell'operatore << per stampare la lista
    friend ostream& operator<<(ostream& out, const LinkedList& list) {
        Node<T>* current = list.head;
        while (current != nullptr) {
            out << " " << current->value << "\t";
            current = current->next;
        }
        return out;
    }

private:
    Node<T>* head; // Nodo di testa della lista
};

// Distruttore della lista
template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current->next;
        delete current;
        current = temp;
    }
}

// Metodo per stampare la lista
template <class T>
void LinkedList<T>::print() const {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << " " << current->value << "\t";
        current = current->next;
    }
}

// Metodo per inserire un valore in testa alla lista
template <class T>
void LinkedList<T>::insert(T value) {
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

// Metodo per cercare un valore nella lista
template <class T>
Node<T>* LinkedList<T>::search(T value) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Classe LGraph: rappresenta un grafo diretto con liste di adiacenza
template <class H>
class LGraph {
private:
    int capacity;       // Numero massimo di nodi
    int nodeCount;      // Numero effettivo di nodi
    int edgeCount;      // Numero effettivo di archi
    H** nodes;          // Array di puntatori ai nodi
    LinkedList<int>** adjacencyList; // Array di liste di adiacenza

    // Trova l'indice di un nodo dato il suo valore
    int findIndex(H value) const {
        for (int i = 0; i < nodeCount; i++) {
            if (*nodes[i] == value) return i;
        }
        return -1; // Nodo non trovato
    }

public:
    LGraph(int capacity);         // Costruttore
    ~LGraph();                    // Distruttore
    LGraph<H>* addNode(H value);  // Aggiunge un nodo al grafo
    LGraph<H>* addEdge(H from, H to); // Aggiunge un arco tra due nodi
    void print() const;           // Stampa il grafo
};

// Costruttore della classe LGraph
template <class H>
LGraph<H>::LGraph(int capacity)
    : capacity(capacity), nodeCount(0), edgeCount(0) {
    nodes = new H*[capacity];
    adjacencyList = new LinkedList<int>*[capacity];
    for (int i = 0; i < capacity; i++) {
        nodes[i] = nullptr;
        adjacencyList[i] = new LinkedList<int>();
    }
}

// Distruttore della classe LGraph
template <class H>
LGraph<H>::~LGraph() {
    for (int i = 0; i < capacity; i++) {
        delete nodes[i];
        delete adjacencyList[i];
    }
    delete[] nodes;
    delete[] adjacencyList;
}

// Aggiunge un nodo al grafo
template <class H>
LGraph<H>* LGraph<H>::addNode(H value) {
    if (nodeCount == capacity) return this; // Capacità massima raggiunta
    if (findIndex(value) >= 0) return this; // Nodo già presente
    nodes[nodeCount] = new H(value);
    nodeCount++;
    return this;
}

// Aggiunge un arco tra due nodi
template <class H>
LGraph<H>* LGraph<H>::addEdge(H from, H to) {
    int fromIndex = findIndex(from);
    int toIndex = findIndex(to);
    if (fromIndex < 0 || toIndex < 0) return this; // Nodo non trovato
    if (!adjacencyList[fromIndex]->search(toIndex)) {
        adjacencyList[fromIndex]->insert(toIndex);
        edgeCount++;
    }
    return this;
}

// Stampa il grafo
template <class H>
void LGraph<H>::print() const {
    for (int i = 0; i < nodeCount; i++) {
        cout << "(" << i << ", " << *nodes[i] << ")" << " : ";
        cout << *adjacencyList[i];
        cout << endl;
    }
}
