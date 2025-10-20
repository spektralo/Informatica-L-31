#include <iostream>
#include <string>
#include <memory>
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
        std::cout << nome << " - " << colore << " - " << stagione << " - " << sapore() << std::endl;
    }
};

// Classe derivata Mela
class Mela : public Frutto {
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

// Nodo per la classe template Coda
template <typename tmpl>
struct Node {
    tmpl info; //variabile template info
    Node* next; //puntatore a nodo successivo
    Node(tmpl data) : info(data), next(nullptr) {} //costruttore nodo con inizializzazione parametro data
    ~Node(){} //distruttore
};

// Classe template Coda
template <typename tmpl>
class queue {
    Node<tmpl>* front; //puntatore a front
    Node<tmpl>* back; //puntatore back
    int size; //dim coda
    
public:
    queue() : front(nullptr), back(nullptr), size(0) {} //costruttore coda
    ~queue() { //distruttore
        while (front != nullptr) { //mentre front non è vuoto
            Node<tmpl>* temp = front; //nodo ausiliare temp
            front = front->next; //aggiorno puntatore front al nodo successivo (front->next)
            delete temp; //elimino nodo ausiliare
        }
    }

    void enqueue(tmpl info) {
        Node<tmpl>* newNode = new Node<tmpl>(info); //dichiaro e inizializzo un newNode con info come parametro (new Node<tmpl>(info) )
        if (back != nullptr) { //se back  non è vuoto
            back->next = newNode; //aggiorno il puntatore back->next al newNode
        }

        back = newNode; //se invece back è vuoto, newNode diventa il back della coda
        if (front == nullptr) { //se il front è vuoto, 
            front = newNode; //front della coda diventa il newNode
        }
        size++; //incremento la dimensione della coda
    }

    tmpl dequeue() {
        if (front == nullptr) {
            throw runtime_error("Underflow: Coda vuota."); //controllo se la coda è vuota
        }
        Node<tmpl>* temp = front; //nodo ausiliare front
        tmpl info = front->info; //conservo le info in una variabile tmpl info
        front = front->next; //aggiorno puntatore front al successivo di front

        if (front == nullptr) { //se il front è vuoto anche il back diventerà vuoto
            back = nullptr;
        }
        delete temp; //elimino nodo ausiliare
        size--; //decremento la dimensione della coda
        return info; //restituisco le info
    }

    tmpl getFront() const {
        if (front == nullptr) {
            throw runtime_error("Coda vuota."); //controllo se la coda è vuota
        }
        return front->info; //se non è vuota, restituisco le info del front
    }

    bool isEmpty() const {
        return size == 0; //funzione di supporto, equivalente a if( back || front == 0(la coda è vuota))
    }

    void printQueue() const {
        Node<tmpl>* current = front; //nodo ausiliare per scorrere la coda
        while (current != nullptr) { //finche la coda non è vuota, scorro
            current->info->print(); //stampo le info del nodo corrente
            current = current->next; //aggiorno puntatore current al successivo current->next
        }
    }
};

// Funzione ricorsiva per rimuovere frutti di un certo tipo
template <typename tmpl>
int rimuoviFrutti(queue<tmpl>& queue, const string& tipo) {
    if (queue.isEmpty()) return 0;

    tmpl frutto = queue.dequeue();
    int rimossi = rimuoviFrutti(queue, tipo);

    if (frutto->getTipo() != tipo) {
        queue.enqueue(frutto);
    } else {
        rimossi++;
    }

    return rimossi;
}

int main() {
    queue<shared_ptr<Frutto>> codaFrutti;

    // Inserimento dei frutti nella coda
    codaFrutti.enqueue(make_shared<Mela>("Granny Smith", "Verde", "Autunno", "Aspro"));
    codaFrutti.enqueue(make_shared<Arancia>("Tarocco", "Arancione", "Inverno", "Dolce"));
    codaFrutti.enqueue(make_shared<Mela>("Golden Delicious", "Giallo", "Autunno", "Dolce"));
    codaFrutti.enqueue(make_shared<Arancia>("Navel", "Arancione", "Inverno", "Dolce-Acido"));
    codaFrutti.enqueue(make_shared<Mela>("Fuji", "Rosso", "Autunno", "Dolce"));
    codaFrutti.enqueue(make_shared<Arancia>("Valencia", "Arancione", "Estate", "Acido"));

    // Richiesta del tipo di frutti da rimuovere
    string tipo;
    cout << "Inserisci il tipo di frutti da rimuovere: ";
    cin >> tipo;

    int rimossi = rimuoviFrutti(codaFrutti, tipo);
    cout << "Sono stati rimossi " << rimossi << " frutti dalla coda." << endl;

    // Stampa dei frutti rimanenti
    cout << "Frutti rimanenti nella coda: " << endl;
    codaFrutti.printQueue();

    return 0;
}
