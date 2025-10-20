#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Animale{
    private:
    string nome, specie;
    int eta;

    public:
    Animale(string nome, string specie, int eta) : nome(nome), specie(specie), eta(eta){}
    ~Animale(){}
    string getNome(){return nome;}
    string getSpecie(){return specie;}
    int getEta(){return eta;}
    void printInfo(){cout<<nome <<specie <<eta <<Alimentazione() <<endl;}

    virtual string Alimentazione() const = 0;
    
};

class Cane:public Animale{
    public:
    Cane(string nome,string specie, int eta): Animale(nome,specie,eta){}
    virtual ~Cane(){}
    virtual string Alimentazione() const override{return "Onnivoro";}
};

class Gatto:public Animale{
    public:
    Gatto(string nome, string specie, int eta) : Animale(nome,specie,eta){}
    virtual ~Gatto(){}
    virtual string Alimentazione() const override{return "Carnivoro";}
};

template<typename tmpl>
struct Node{
    tmpl info;
    Node*next;
    Node(tmpl data) : info(data), next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class stack{

    Node<tmpl>*top;
    int size;

    public:
    stack(): top(nullptr), size(0){}
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

    bool isEmpty(){return top == nullptr;}

    tmpl pop(){
        if(isEmpty()){throw runtime_error("Stack vuoto");}
        Node<tmpl>*temp = top;
        tmpl info = top->info;
        top = top->next;

        delete temp;
        size--;
        return info;
    }

    void printStack(){
        Node<tmpl>* current = top;
        while(current != nullptr){
            current->info->printInfo();
            current = current->next;
        }
    }
};

int main(){
    stack <Animale*> rifugioAnimali;
    rifugioAnimali.push(new Cane("Bobby","Labrador",3));
    rifugioAnimali.push(new Gatto("Yuuki", "Persiano", 3));
    rifugioAnimali.pop();
    rifugioAnimali.printStack();

    return 0;
}