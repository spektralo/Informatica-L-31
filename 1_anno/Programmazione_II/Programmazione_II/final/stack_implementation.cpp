#include<iostream>
using namespace std;

typedef int elemType;

class Nodo{
protected:
    elemType info;
    Nodo *next;

public:

    Nodo(){}
    ~Nodo(){}
    Nodo(elemType data){info = data; next = NULL;}
    elemType get(){return info;}
    void put(elemType data){info = data;}
    Nodo* getNext(){return next;}
    void putNext(Nodo* node){next = node;}
};

/*---------------------------------------------------*/

class stack{
protected:
    Nodo * node;

public:
    stack(){node = NULL;}
    ~stack(){}
    bool isEmpty(){return !node;}
    elemType getTop(){if(node) return node->get();}
    void push(elemType data);
    void deleteElem();
    elemType pop();
};

/*---------------------------------------------------*/

stack::~stack(){
    Nodo *p;
        while (node != 0)
        {
            p = node;
            p = p->getNext();
            delete p; 
        }
}


void stack::push(elemType data){
    Nodo *newNode;
    newNode = new Nodo(data);

        if(node){newNode->putNext(node);}
            node = newNode;
}


void stack::deleteElem(){
    Nodo * p;
    if(node){
        p = node;
        p = p->getNext();
        delete p;
    }
}

elemType stack::pop(){

    elemType info;
    info = getTop();

    deleteElem();
    return info;
}

/*--------------------------------------------------*/