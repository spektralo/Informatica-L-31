#include<iostream>
using namespace std;

class Veicolo{
private:
    string marca, modello;
    int anno;

public:
Veicolo(string marca, string modello, int anno) : marca(marca), modello(modello), anno(anno){}
virtual ~Veicolo(){}

string getMarca(){return marca;}
string getModello(){return modello;}
int getAnno(){return anno;}

void print() { cout << marca << "-" << modello << "-" << anno << "-" << tipo() << endl; }
virtual string tipo() const = 0;
};

class Auto:public Veicolo{
public:
    Auto(string marca, string modello, int anno) : Veicolo(marca,modello,anno){}
    string tipo() const override{return "Auto";}
};

class Moto:public Veicolo{
public:
    Moto(string marca, string modello, int anno) : Veicolo(marca,modello,anno){}
    string tipo() const override{return "Auto";}
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
public:
    Node<tmpl>*top;
    int size;

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
    tmpl info = top->info;
    top = top->next;

    delete temp;
    size--;

    return info;
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

int main(int argc, char const *argv[])
{
    stack<Veicolo*> stackVeicoli;
    stackVeicoli.push(new Auto("Fiat", "Panda", 2020));
    stackVeicoli.push(new Moto("Kawasaki", "Ninja", 2019));
    stackVeicoli.push(new Auto("Tesla", "Model 3", 2021));
    stackVeicoli.push(new Moto("Yamaha", "R1", 2018));
    stackVeicoli.push(new Auto("BMW", "Serie 5", 2022));
    stackVeicoli.push(new Moto("Ducati", "Panigale", 2020));

    stackVeicoli.printStack();
    return 0;
}
