#include <iostream>
#include <string>
using namespace std;

// Classe base virtuale Frutto
class Frutto {
protected:
    string nome;
    string colore;
    string stagione;

public:
    Frutto(string nome, string colore, string stagione) : nome(nome), colore(colore), stagione(stagione) {}
    virtual ~Frutto() {}

    string getNome() const { return nome; }
    string getColore() const { return colore; }
    string getStagione() const { return stagione; }

    virtual string sapore() const = 0;
    virtual string getTipo() const = 0;

    void print() const {
        cout << nome << " - " << colore << " - " << stagione << " - " << sapore() << endl;
    }
};

// Classe derivata Mela
class Mela : public Frutto {
protected:
    string saporeMela;

public:
    Mela(string nome, string colore, string stagione, string sapore) : Frutto(nome, colore, stagione), saporeMela(sapore) {}
    string sapore() const override { return saporeMela; }
    string getTipo() const override {return "Mela";} 
    
};

// Classe derivata Arancia
class Arancia : public Frutto {
protected:
    string saporeArancia;

public:
    Arancia(string nome, string colore, string stagione, string sapore) : Frutto(nome, colore, stagione), saporeArancia(sapore) {}
    string sapore() const override { return saporeArancia; }
    string getTipo() const override {return "Arancia";} 
};

// Nodo per la pila
template <typename tmpl>
struct Node {
    tmpl info;
    Node* next;
    Node(tmpl data) : info(data), next(nullptr) {}
    ~Node(){}
};

// Classe Pila template
template <typename tmpl>
class Pila {
    Node<tmpl>* top;
    int size;

public:
    Pila() : top(nullptr), size(0) {}
    ~Pila() {
        while (top != nullptr) {
            Node<tmpl>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(tmpl info) {
        Node<tmpl>* newNode = new Node<tmpl>(info);
        newNode->next = top;
        top = newNode;
        size++;
    }

    tmpl pop() {
        if (isEmpty()) {
            throw runtime_error("Underflow: Pila vuota.");
        }
        Node<tmpl>* temp = top;
        tmpl data = top->info;
        top = top->next;

        delete temp;
        size--;

        return data;
    }

    tmpl peek() const {
        if (isEmpty()) {
            throw runtime_error("Underflow: Pila vuota.");
        }
        return top->info;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void printStack() const {
        Node<tmpl>* current = top;
        while (current != nullptr) {
            current->info->print();
            current = current->next;
        }
    }
};

// Funzione per rimuovere frutti di un certo tipo
template <typename tmpl>
int rimuoviFrutti(Pila<tmpl>& pila, const string& tipo) {
    
    Pila<tmpl> tempPila;
    int rimossi = 0;

    while (!pila.isEmpty()) {
        tmpl frutto = pila.pop();
        if (frutto->getTipo() == tipo) {
            rimossi++;
        } else {
            tempPila.push(frutto);
        }
    }

    while (!tempPila.isEmpty()) {
        pila.push(tempPila.pop());
    }

    return rimossi;
}
    


int main() {
    Pila<Frutto*> pilaFrutti;

    // Inserimento dei frutti nella pila
    pilaFrutti.push(new Mela("Granny Smith", "Verde", "Autunno", "Aspro"));
    pilaFrutti.push(new Arancia("Tarocco", "Arancione", "Inverno", "Dolce"));
    pilaFrutti.push(new Mela("Golden Delicious", "Giallo", "Autunno", "Dolce"));
    pilaFrutti.push(new Arancia("Navel", "Arancione", "Inverno", "Dolce-Acido"));
    pilaFrutti.push(new Mela("Fuji", "Rosso", "Autunno", "Dolce"));
    pilaFrutti.push(new Arancia("Valencia", "Arancione", "Estate", "Acido"));

    // Richiesta del tipo di frutti da rimuovere
    string tipo;
    cout << "Inserisci il tipo di frutti da rimuovere: ";
    cin >> tipo;

    int rimossi = rimuoviFrutti(pilaFrutti, tipo);
    cout << "Sono stati rimossi " << rimossi << " frutti dalla pila." << endl;

    // Stampa dei frutti rimanenti
    cout << "Frutti rimanenti nella pila: " << endl;
    pilaFrutti.printStack();

    return 0;
}
