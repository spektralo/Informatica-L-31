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
    string saporeMela;

public:
    Mela(string nome, string colore, string stagione, string sapore) : Frutto(nome, colore, stagione), saporeMela(sapore) {}
    string sapore() const override { return saporeMela; }
    string getTipo() const override { return "Mela"; }
};

// Classe derivata Arancia
class Arancia : public Frutto {
    string saporeArancia;

public:
    Arancia(string nome, string colore, string stagione, string sapore) : Frutto(nome, colore, stagione), saporeArancia(sapore) {}
    string sapore() const override { return saporeArancia; }
    string getTipo() const override { return "Arancia"; }
};

// Nodo della lista
template <typename tmpl>
struct Node {
    tmpl info;
    Node* next;
    Node(tmpl data) : info(data), next(nullptr) {}
    ~Node(){}
};

// Classe Lista template
template <typename tmpl>
class Lista {
    Node<tmpl>* head;
    int size;

public:
    Lista() : head(nullptr), size(0) {}
    ~Lista() {
        while (head != nullptr) {
            Node<tmpl>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void headIns(tmpl data) {
        Node<tmpl>* newNode = new Node<tmpl>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    tmpl headExtract() {
        if (isEmpty()) {
            throw runtime_error("Underflow: Lista vuota.");
        }
        Node<tmpl>* temp = head;
        tmpl data = head->info;
        head = head->next;
        
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
            current->info->print();
            current = current->next;
        }
    }

    //La funzione è implementata con la gestione manuale della memoria
    int rimuoviFrutti(const string& tipo) {
        Node<tmpl>* prev = nullptr;
        Node<tmpl>* current = head;
        int rimossi = 0;

        while (current != nullptr) {
            if (current->info->getTipo() == tipo) {
                Node<tmpl>* toDelete = current;
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                current = current->next;
                delete toDelete;
                rimossi++;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return rimossi;
    }
};

int main() {
    Lista<Frutto*> listaFrutti;

    // Inserimento dei frutti nella lista
    listaFrutti.headIns(new Mela("Granny Smith", "Verde", "Autunno", "Aspro"));
    listaFrutti.headIns(new Arancia("Tarocco", "Arancione", "Inverno", "Dolce"));
    listaFrutti.headIns(new Mela("Golden Delicious", "Giallo", "Autunno", "Dolce"));
    listaFrutti.headIns(new Arancia("Navel", "Arancione", "Inverno", "Dolce-Acido"));
    listaFrutti.headIns(new Mela("Fuji", "Rosso", "Autunno", "Dolce"));
    listaFrutti.headIns(new Arancia("Valencia", "Arancione", "Estate", "Acido"));

    // Richiesta del tipo di frutti da rimuovere
    string tipo;
    cout << "Inserisci il tipo di frutti da rimuovere: ";
    cin >> tipo;

    int rimossi = listaFrutti.rimuoviFrutti(tipo);
    cout << "Sono stati rimossi " << rimossi << " frutti dalla lista." << endl;

    // Stampa dei frutti rimanenti
    cout << "Frutti rimanenti nella lista: " << endl;
    listaFrutti.printList();

    return 0;
}
