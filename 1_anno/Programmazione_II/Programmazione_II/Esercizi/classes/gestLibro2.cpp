#include<iostream>
using namespace std;

class Libro{
    protected:
int codice;
string titolo;
double prezzo;
int annoPub;

    public:
    Libro(int codice, string titolo, double prezzo, int annoPub)
    : codice(codice), titolo(titolo), prezzo(prezzo), annoPub(annoPub){}
    ~Libro(){}
    
    int getCodice(){return codice;} string getTitolo(){return titolo;}
    double getPrezzo(){return prezzo;}  int getAnnoPub(){return annoPub;}

    void stampa(){cout<<codice<<titolo<<prezzo<<annoPub<<endl;}
};

class Sconto{
    public:
    int percentuale, annoLimite;

    Sconto(int percentuale, int annoLimite)
    :percentuale(percentuale), annoLimite(annoLimite){}
    virtual ~Sconto(){}
    int getPercentuale(){return percentuale;}
    int getAnnoLimite(){return annoLimite;}
};

class LibroScontato:public Libro{
    protected:
    Sconto* sconto;

    public:
    LibroScontato(int codice, string titolo, double prezzo, int annoPub, Sconto* sconto)
    :Libro(codice,titolo,prezzo,annoPub), sconto(sconto){}
    virtual ~LibroScontato(){}

    double getPrezzoScontato(){
        if(getAnnoPub() <= sconto->getAnnoLimite()){
            return (prezzo/sconto->percentuale) * 100;
        }   else return prezzo;
    }

    void stampaScontato(){
        if(getAnnoPub()<=sconto->getAnnoLimite()){
         cout<<codice<<titolo<<prezzo<<annoPub<<sconto->percentuale<<endl;
        } else stampa();
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
stack<Libro*> Libreria;
int y;
Sconto sconto_uno(50,1900);
Sconto sconto_due(30,1950);

Libreria.push(new Libro(101,"Il Signore degli Anelli",25.00,1954));
Libreria.push(new LibroScontato(103,"Il Piccolo Principe",10.00,1943,&sconto_due));
Libreria.push(new LibroScontato(105,"I Promessi Sposi",18.00,1827,&sconto_uno));

Libreria.printStack();
}
