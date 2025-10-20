#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Ordini{
    private:
    int ID;
    float importo;
    string cliente;

    public:
    Ordini(int ID, string cliente, float importo) : ID(ID), cliente(cliente), importo(importo){}
    virtual ~Ordini(){}

    int getID() const {return ID;}
    float getImporto() const {return importo;}
    string getCliente() const {return cliente;}
    void print() { cout << ID << "-" << cliente << "-" << importo << "-" << getPayMethod() << endl; }
    virtual string getPayMethod() const = 0;
};

class CreditCard:public Ordini{
    public:
    CreditCard(int ID, string cliente, float importo) : Ordini(ID,cliente,importo){}
    virtual ~CreditCard(){}

    virtual string getPayMethod() const override{return "Credit Card";}
};

class Paypal:public Ordini{
    public:
    Paypal(int ID, string cliente, float importo) : Ordini(ID,cliente,importo){}
    virtual ~Paypal(){}

    virtual string getPayMethod()const override{return "Paypal";}
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
            current->info->print();
            current = current->next;
        }
    }
};

int main(){
    stack<Ordini*> stackOrdini;
    
    stackOrdini.push(new CreditCard(1057, "Giovanni", 28.59));
    stackOrdini.printStack();
}