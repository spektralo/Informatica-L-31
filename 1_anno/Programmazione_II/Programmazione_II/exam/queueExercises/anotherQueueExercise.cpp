#include <iostream>
#include <stdexcept>
using namespace std;

class Veicolo {
private:
    string marca, modello;
    int anno;

public:
    Veicolo(string marca, string modello, int anno) : marca(marca), modello(modello), anno(anno) {}
    virtual ~Veicolo() {}

    string getMarca() { return marca; }
    string getModello() { return modello; }
    int getAnno() { return anno; }

    void print() { cout << marca << "-" << modello << "-" << anno << "-" << tipo() << endl; }
    virtual string tipo() const = 0;
};

class Auto : public Veicolo {
public:
    Auto(string marca, string modello, int anno) : Veicolo(marca, modello, anno) {}
    string tipo() const override { return "Auto"; }
};

class Moto : public Veicolo {
public:
    Moto(string marca, string modello, int anno) : Veicolo(marca, modello, anno) {}
    string tipo() const override { return "Moto"; }
};

template <typename tmpl>
struct Node {
    tmpl info;
    Node* next;
    Node(tmpl data) : info(data), next(nullptr) {}
};

template <typename tmpl>
class queue {
    Node<tmpl>* front;
    Node<tmpl>* back;
    int size;

public:
    queue() : front(nullptr), back(nullptr), size(0) {}
    ~queue() {
        while (front != nullptr) {
            Node<tmpl>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(tmpl info) {
        Node<tmpl>* newNode = new Node<tmpl>(info);
        if (back != nullptr) {
            back->next = newNode;
        }
        back = newNode;
        if (front == nullptr) {
            front = newNode;
        }
        size++;
    }

    tmpl dequeu() {
        if (front == nullptr) { throw runtime_error("Underflow, coda vuota!"); }
        Node<tmpl>* temp = front;
        tmpl info = front->info;
        front = front->next;
        if (front == nullptr) { back = nullptr; }
        delete temp;
        size--;
        return info;
    }

    tmpl getFront() {
        if (front == nullptr) { throw runtime_error("Coda vuota"); }
        return front->info;
    }

    bool isEmpty() const { return size == 0; }

    void printQueue() const {
        Node<tmpl>* current = front;
        while (current != nullptr) {
            current->info->print();
            current = current->next;
        }
    }
};

/* ------DA IMPLEMENTARE FUNZIONE DI TYPE EXTRACT-------*/



int main() {
    queue<Veicolo*> codaVeicoli;

    codaVeicoli.enqueue(new Auto("Fiat", "Panda", 2020));
    codaVeicoli.enqueue(new Moto("Kawasaki", "Ninja", 2019));
    codaVeicoli.enqueue(new Auto("Tesla", "Model 3", 2021));
    codaVeicoli.enqueue(new Moto("Yamaha", "R1", 2018));
    codaVeicoli.enqueue(new Auto("BMW", "Serie 5", 2022));
    codaVeicoli.enqueue(new Moto("Ducati", "Panigale", 2020));

    codaVeicoli.printQueue();

    // Deallocazione dei veicoli
    while (!codaVeicoli.isEmpty()) {
        delete codaVeicoli.dequeu();
    }

    return 0;
}
