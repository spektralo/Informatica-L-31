#include <iostream>
#include <string>
using namespace std;

template<typename tmpl>
struct Node {
    tmpl info;
    Node* next, *prev;
    Node(tmpl data) : info(data), next(nullptr), prev(nullptr) {}
    ~Node() {}
};

template<typename tmpl>
class doubleLinked {
    Node<tmpl>* head;
    Node<tmpl>* tail;
    int size;

public:
    doubleLinked() : head(nullptr), tail(nullptr), size(0) {}

    ~doubleLinked() {
        while (head != nullptr) {
            Node<tmpl>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    bool isEmpty() const { return head == nullptr; }

    int getSize() const { return size; }

    void headIns(tmpl info) {
        Node<tmpl>* newNode = new Node<tmpl>(info);

        if (isEmpty()) {head = tail = newNode;}
         else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void tailIns(tmpl info) {
        Node<tmpl>* newNode = new Node<tmpl>(info);

        if (isEmpty()) {head = tail = newNode;}
         else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    tmpl headExtract() {
        if (isEmpty()) {throw runtime_error("Lista vuota!");}

        Node<tmpl>* temp = head;
        tmpl info = temp->info;
        head = head->next;

        if (head != nullptr) {head->prev = nullptr;}
         else {tail = nullptr;}

        delete temp;
        size--;
        return info;
    }

    tmpl tailExtract() {
        if (isEmpty()) {throw runtime_error("Lista vuota!");}

        Node<tmpl>* temp = tail;
        tmpl info = temp->info;
        tail = tail->prev;

        if (tail != nullptr) {tail->next = nullptr;}
         else {head = nullptr;}

        delete temp;
        size--;
        return info;
    }

    void printList() const {
        Node<tmpl>* current = head;
        while (current != nullptr) {
            current->info->printInfo();
            current = current->next;
        }
    }
};
