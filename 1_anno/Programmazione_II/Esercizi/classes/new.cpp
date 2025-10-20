#include<iostream>
using namespace std;

class Prodotto{
    protected:
    int codice;
    string nome;
    float prezzo;
    long scadenza;

    public:
    Prodotto(int codice, string nome, float prezzo, long scadenza)
    :codice(codice),nome(nome),prezzo(prezzo),scadenza(scadenza){}
    virtual ~Prodotto(){}

    int getCodice()const{return codice;}
    string getNome()const{return nome;}
    float getPrezzo()const{return prezzo;}
    long getScadenza()const{return scadenza;}

    virtual void stampaInfo()const{
        cout << "Codice: " << getCodice() << ", Nome: " << getNome()
        << ", Prezzo" << getPrezzo() << ", Scadenza: " << getScadenza() << endl;
    }

    friend std::ostream &operator <<(std::ostream &os, Prodotto &prod){
        prod.stampaInfo();
        return os;
    }
};

class ProdottoScontato:public Prodotto{
    protected:
    Sconto *sconto;

    public:
    ProdottoScontato(int codice, string nome, float prezzo, long scadenza, Sconto* sconto)
    :Prodotto(codice,nome,prezzo,scadenza), sconto(sconto){}
    virtual ~ProdottoScontato(){}

    void getPrezzoScontato(int dCurr){
        if(sconto->getScadSconto() < dCurr){
            cout << "Prezzo scontato: " << (sconto->getSconto() * Prodotto::getPrezzo()) / 100;
        }
    }

    void stampaInfo()const override{
        Prodotto::stampaInfo();
        cout << ", scadenza del" << sconto->getSconto()
        << "valido fino al " << sconto->getScadSconto() << endl;
    }
};

class Sconto{
    protected:
    int percentuale;
    long scadSconto;

    public:
    Sconto(int percentuale, int scadSconto)
    : percentuale(percentuale),scadSconto(scadSconto){}
    ~Sconto(){}

    int getSconto()const{return percentuale;}
    long getScadSconto()const{return scadSconto;}
};

template<typename tmpl>
struct Node{
    tmpl info;
    Node*next;
    Node(tmpl data) : info(data),next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class stack{
    Node<tmpl>*top;
    int size;

public:
stack() : top(nullptr), size(0){}

~stack(){
    while (top != nullptr)
    {
        Node<tmpl>* temp = top;
        top = top->next;
        delete temp;
    }
}

void push(tmpl info){
    Node<tmpl>* newNode = new Node<tmpl>(info);
    newNode->next = top;
    top = newNode;
    size++;
}

bool isEmpty(){return top == nullptr;}

tmpl pop(){
    if(isEmpty()){throw runtime_error("Pila vuota!");}
    Node<tmpl>*temp = top;
    tmpl data = top->info;
    top = top->next;

    delete temp;
    size--;
    return data;
    }

void printStack(){
    Node<tmpl>*current = top;
    while (current != nullptr)
    {
        current->info->print();
        current = current->next;
    }
  }
};

int main(int argc, const char** argv) {
    
    return 0;
}