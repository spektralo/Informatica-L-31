#include <iostream>
using namespace std;

class Studente {
protected:
    string matricola, nome, cognome;
    float media;

public:
    Studente(string matricola, string nome, string cognome, float media)
        : matricola(matricola), nome(nome), cognome(cognome), media(media) {}
    virtual ~Studente() {}

    string getMatricola() const { return matricola; }
    string getNome() const { return nome; }
    string getCognome() const { return cognome; }
    float getMedia() const { return media; }
    virtual float getImportoBorsa() const { return 0.0; } // Metodo virtuale

    virtual void stampa() const {
        cout << "\nMatricola: " << getMatricola() << ", Nome: " << getNome()
             << ", Cognome: " << getCognome() << ", Media: " << getMedia();
    }

    friend ostream& operator<<(ostream& os, const Studente& stud) {
        stud.stampa();
        return os;
    }
};

class BorsaDiStudio {
protected:
    float importo;
    string durata;

public:
    BorsaDiStudio(float importo, string durata) : importo(importo), durata(durata) {}
    float getImporto() const { return importo; }
    virtual ~BorsaDiStudio(){}
};

class StudenteBorsista : public Studente {
protected:
    BorsaDiStudio* borsa;

public:
    StudenteBorsista(string matricola, string nome, string cognome, float media, BorsaDiStudio* borsa)
        : Studente(matricola, nome, cognome, media), borsa(borsa) {}

    virtual ~StudenteBorsista(){}

    float getImportoBorsa() const override { return borsa->getImporto(); }

     void stampa() const override {
        Studente::stampa();
        cout << ", Borsa di: " << getImportoBorsa() << " euro";
    }
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

    tmpl dequeue() {
        if (front == nullptr) { throw runtime_error("Underflow, coda vuota!"); }
        Node<tmpl>* temp = front;
        tmpl info = front->info;
        front = front->next;
        if (front == nullptr) { back = nullptr; }
        delete temp;
        size--;
        return info;
    }

    bool isEmpty() const { return size == 0; }

    void printQueue() const {
        Node<tmpl>* current = front;
        while (current != nullptr) {
            current->info->stampa();
            current = current->next;
        }
    }

    void checkIns() {
        Node<tmpl>* current = front;
        float totImporto = 0.0;
        
        while (current != nullptr) {
            if (current->info->getMedia() < 25) {
                cout << "Rimosso: " << current->info->getMatricola() << " - " << current->info->getNome() << endl;
                dequeue();
            } else {
                totImporto += current->info->getImportoBorsa();
            }
            current = current->next;
        }
        
        printQueue();
        cout << "\n" << "Totale importo: " << totImporto << " euro" << endl;
    }
};

int main() {
    BorsaDiStudio borsa_uno(880, "2025");
    BorsaDiStudio borsa_due(500, "2025");
    BorsaDiStudio borsa_tre(600, "2025");

    queue<Studente*> studenti;
    studenti.enqueue(new Studente("1001", "Mario", "Rossi", 25.5));
    studenti.enqueue(new StudenteBorsista("1002", "Anna", "Verdi", 28.0, &borsa_uno));
    studenti.enqueue(new Studente("1003", "Luca", "Bianchi", 26.0));
    studenti.enqueue(new Studente("1004", "Sara", "Neri", 27.5));
    studenti.enqueue(new StudenteBorsista("1005", "Marco", "Gialli", 24.0, &borsa_due));
    studenti.enqueue(new StudenteBorsista("1006", "Laura", "Marroni", 29.0, &borsa_tre));

    studenti.checkIns();
}
