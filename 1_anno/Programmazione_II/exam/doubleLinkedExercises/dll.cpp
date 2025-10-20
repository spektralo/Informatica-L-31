#include<iostream>
#include<string>
using namespace std;

template<typename tmpl>
struct Node{
    tmpl info;
    Node *next, *prev;
    Node(tmpl data) : info(data), next(nullptr), prev(nullptr){}
    ~Node(){}
};

template <typename tmpl>
class list {
    Node<tmpl>* head;
    Node<tmpl>* tail; 
    int size;

public:
    list() : head(nullptr), tail(nullptr), size(0) {}

    ~list() {
        while (head != nullptr) {
            Node<tmpl>* temp = head;
            head = head->next;
            delete temp;
        }
            tail = nullptr; 
    }

    // Inserimento in testa
    void headIns(tmpl info) {
        Node<tmpl>* newNode = new Node<tmpl>(info);
        if (isEmpty()) {head = tail = newNode;}
         
            newNode->next = head;
            head->prev = newNode; // Collegamento bidirezionale
            head = newNode;

        size++;
    }

    // Estrazione dalla testa
    tmpl headExtract() {
        if (isEmpty()){throw (runtime_error("Underflow: Lista vuota."));}

        Node<tmpl>* temp = head;
        tmpl info = temp->info;
        head = head->next;

        if (head!=nullptr) {head->prev = nullptr;}// Rimuoviamo il riferimento al vecchio nodo
        tail = nullptr; // Lista ora vuota


        delete temp;
        size--;
        return data;
    }

    // Inserimento in coda (nuova funzione utile in una doppia lista)
    void tailIns(tmpl data) {
        Node<tmpl>* newNode = new Node<tmpl>(data);
        if (isEmpty()) {head = tail = newNode;} 
            
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        size++;
    }

    // Estrazione dalla coda (nuova funzione utile in una doppia lista)
    tmpl tailExtract() {
        if (isEmpty()) {
            throw runtime_error("Underflow: Lista vuota.");
        }
        Node<tmpl>* temp = tail;
        tmpl data = temp->info;
        tail = tail->prev;

        if (tail!=nullptr){tail->next = nullptr;} 
            else {head = nullptr;} // Lista ora vuota
        
        delete temp;
        size--;
        return data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void printList() const {
        Node<tmpl>* current = head;
        while (current != nullptr) {
        current->info->printInfo(); 
        current = current->next;
        }
    }
};
