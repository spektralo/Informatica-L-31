#include<iostream>
using namespace std;

class Studente{
    protected:
    int matricola;
    string nome, cognome;
    double media;

    public:
    Studente(int matricola, string nome, string cognome, double media)
    :matricola(matricola),nome(nome),cognome(cognome),media(media){}
    virtual ~Studente(){}

    virtual double getImporto(){return 0;}
    int getMatricola()const{return matricola;} string getNome()const{return nome;}
    string getCognome()const{return cognome;} double getMedia()const{return media;}

    virtual void stampaInfo(ostream &os) const {
        os << "Matricola: " << getMatricola()
           << ", Nome: " << getNome()
           << ", Cognome: " << getCognome()
           << ", Media: " << getMedia();
    }

    friend ostream &operator <<(ostream &os, Studente &stud){
        stud.stampaInfo(os);
        return os;
    }
};

class BorsaStudio{
    protected:
    double importo;
    int durata;

    public:
    BorsaStudio(double importo, int durata)
    :importo(importo),durata(durata){}
    ~BorsaStudio(){}

    double getImporto()const{return importo;} int getDurata()const{return durata;}
    void setImporto(double imp){importo = imp;} void setDurata(int dur){durata = dur;}

    void stampaInfo(ostream &os){
        os << "Importo: " << getImporto() << ", durata: " << getDurata(); 
    }
};

class StudenteBorsista:public Studente{
    protected:
    BorsaStudio *borsa;

    public:
    StudenteBorsista(int matricola, string nome, string cognome, double media, BorsaStudio *borsa)
    :Studente(matricola,nome,cognome,media),borsa(borsa){}

    double getImporto()override{
        return borsa->getImporto();
    }

    void stampaInfo(ostream &os) const override {
        Studente::stampaInfo(os);
        os << ", Borsa: " << borsa->getImporto() << " euro";
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
    stack() : top(nullptr), size(0){}
    ~stack(){
        while(top!=nullptr){
            Node<tmpl>*temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty()const{return top == nullptr;}

    void push(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        newNode->next = top;
        top = newNode;
        size++;
    }

    tmpl pop(){
        if(isEmpty()){throw runtime_error("Pila vuota");}
        Node<tmpl>*temp = top;
        tmpl info = top->info;
        top = top->next;

        delete temp; size--; return info;
    }

    void printStack(ostream &os) {
        Node<tmpl>* current = top;
        int count = 1;
        while (current != nullptr) {
            os << "[" << count << "] ";
            current->info->stampaInfo(os);
            os << endl;
            current = current->next;
            count++;
        }
    }

    double totImporto()const{
        Node<tmpl>*current = top;
        double totImporto = 0.0;
        while (current!=nullptr)
        {
            if(current->info->getImporto() > 0){
                totImporto += current->info->getImporto();
            }
            current = current->next;
        }
        cout << "Totale importo borse di studio: " << totImporto << endl;
        return totImporto;
    }

    void removeByMedia(){
        stack<tmpl> tempStack;
        while (!isEmpty())
        {
            tmpl elemento = pop();
            if(elemento->getMedia() >= 25.0){
                tempStack.push(elemento);
            }
            else {
                cout << "Rimosso studente: " <<  elemento->getMatricola() << ", nome: " << elemento->getNome() << 
                ", cognome: " << elemento->getCognome() << endl;
                delete elemento;}
        }
        while(!tempStack.isEmpty()){
            push(tempStack.pop());
        }
    }
};



int main(){

    stack<Studente*>studenti;
    BorsaStudio *borsaUno = new BorsaStudio(880,60);
    BorsaStudio *borsaDue = new BorsaStudio(600, 48);

    Studente *studenteUno = new Studente(1001,"Mario", "Rossi",25.5);
    Studente *studenteDue = new StudenteBorsista(1002,"Anna", "Verdi",28.0, borsaUno);
    Studente *studenteTre = new Studente(1003,"Luca", "Bianchi",26.0);
    Studente *studenteQuattro = new Studente(1004,"Sara", "Neri",27.5);
    Studente *studenteCinque = new Studente(1005,"Marco", "Gialli",24.5);
    Studente *studenteSei = new StudenteBorsista(1006,"Laura", "Marroni",29,borsaDue);

    studenti.push(studenteUno); studenti.push(studenteDue); studenti.push(studenteTre);
    studenti.push(studenteQuattro); studenti.push(studenteCinque); studenti.push(studenteSei);

    studenti.removeByMedia();
    studenti.printStack(cout);
    studenti.totImporto();
    return 0;
}