#include<iostream>
using namespace std;

class Prodotto{
    protected:
    int codice;
    string nome;
    double prezzo;
    string scadenza;
    
    public:
    Prodotto(int codice, string nome, double prezzo, string scadenza) 
    : codice(codice), nome(nome), prezzo(prezzo), scadenza(scadenza){}
    ~Prodotto(){}

    string getNome(){return nome;} string getScadenza(){return scadenza;}
    double getPrezzo(){return prezzo;} int getCodice(){return codice;}

    void stampa(){cout << codice << nome << prezzo << scadenza << endl;}
};

class Sconto{
    protected:
    double percentuale;
    string scadenzaSconto;

    public:
    Sconto(double percentuale, string scadenzaSconto): percentuale(percentuale), scadenzaSconto(scadenzaSconto){}
    ~Sconto(){}
    double getPercentuale(){return percentuale;}
    string getScadenzaSconto(){return scadenzaSconto;}
};

class ProdottoScontato:public Prodotto{
    protected:
    Sconto* ptrSconto;

    public:
    ProdottoScontato(int codice, string nome, double prezzo, string scadenza, Sconto* ptrSconto)
     : Prodotto(codice,nome,prezzo,scadenza), ptrSconto(ptrSconto){}

    double getPrezzoScontato(){
        if(ptrSconto->getScadenzaSconto() < scadenza){
            return prezzo * (ptrSconto->getPercentuale() / 100);
        }   
        else return prezzo;
    }
    
    void printInfo(){
    if(ptrSconto->getScadenzaSconto() > scadenza){
        cout << "Codice: " << codice << ", Nome: " << nome << ", Prezzo: " << prezzo <<
        ", Scadenza: " << scadenza << ", Percentuale: " << ptrSconto->getPercentuale() << endl;}

        else{
        cout << "Codice: " << codice << ", Nome: " << nome << ", Prezzo: " << prezzo <<
        ", Scadenza: " << scadenza << endl;}
    }
};

template<typename tmpl>
struct Node{
    tmpl info;
    Node *next;
    Node(tmpl data) : info(data), next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class stack{
    Node<tmpl>*top;
    int size;

    public:
    stack() : top(nullptr), size(10){}
    ~stack(){
        while (top!=nullptr)
        {
            Node<tmpl>*temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        newNode->next = top;
        top = newNode;
        size++;
    }

    bool isEmpty() const {return top == nullptr;}
    
    int getSize() const {return size;}

    tmpl pop(){
        if(isEmpty()){throw runtime_error("Stack vuoto!");}
        Node<tmpl>*temp = top;
        tmpl info = top->info;
        top = top->next;

        delete temp;
        size--;
        return info;
    }

    void printStack() const {
        Node<tmpl>*current = top;
        while (current!=nullptr)
        {
            current->info->stampa();
            current = current->next;
        }
    }
};

int main(){
stack<Prodotto*> prodotti;
Sconto sconto_uno(20.0,"10/06/2023");
Sconto sconto_due(10.0,"15/06/2023");

prodotti.push(new Prodotto(1,"Latte",1.20,"10/06/2023"));
prodotti.push(new Prodotto(2,"Pane",0.80,"08/06/2023"));
prodotti.push(new Prodotto(3,"Burro",2.50,"15/06/2023"));
prodotti.push(new Prodotto(4,"Marmellata",3.00,"31/12/2023"));
prodotti.push(new ProdottoScontato(5,"Yogurt",1.50,"12/06/2023",&sconto_uno));
prodotti.push(new ProdottoScontato(6,"Succo di Frutta",2.00,"30/06/2023",&sconto_due));

prodotti.printStack();

}