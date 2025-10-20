#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Ticket{
    private:
    int ID, priorita;
    string richiedente;

    public:
    Ticket(int ID, int priorita, string richiedente) : ID(ID), priorita(priorita), richiedente(richiedente){}
    virtual ~Ticket(){}
    int getID() const{return ID;}
    int getPriorita() const{return priorita;}
    string getRichiedente() const{return richiedente;}

    virtual string getTipo() const = 0;

    void printInfo(){
        cout << "ID: " << ID << " - " << "Priorita: " << priorita << " - " << "Richiedente: " << richiedente << " - " <<"Tipo: " << getTipo() <<endl;
    }
};

class Hardware:public Ticket{
    public:
    Hardware(int ID, int priorita, string richiedente) : Ticket(ID, priorita, richiedente){}
    virtual ~Hardware(){}
    virtual string getTipo() const override{return "Hardware";}
};

class Software:public Ticket{
    public:
    Software(int ID, int priorita, string richiedente) : Ticket(ID, priorita, richiedente){}
    virtual ~Software(){}
    virtual string getTipo() const override{return "Software";}
};

template<typename tmpl>
struct Node{
    tmpl info;
    Node *next;
    Node(tmpl data) : info(data), next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class queue{
    Node<tmpl>*front;
    Node<tmpl> *back;
    int size;

    public:
    queue() : front(nullptr), back(nullptr), size(0){}
    ~queue(){
        Node<tmpl>* temp = front;
        front = front->next;
        delete temp;
    }

    void enqueue(tmpl info){
        Node<tmpl>* newNode = new Node<tmpl>(info);
        if(back != nullptr){back->next = newNode;}
            back = newNode;

            if (front == nullptr){ front = newNode;}
            size++;
    } 

    tmpl dequeue(){
        if(front == nullptr){throw runtime_error("Coda vuota!");}
        Node<tmpl>* temp = front;
        tmpl info = front->info;
        front = front->next;
        if (front == nullptr){back = nullptr;}
        
        delete temp;
        size--;
        return info;
    }

    bool isEmpty() const{return size == 0;}

    void printQueue(){
        Node<tmpl>* current = front;
        while (current != nullptr)
        {
            current->info->printInfo();
            current = current->next;
        }
    }

    tmpl getFront(){
        if(front == nullptr){throw runtime_error("Coda vuota!");}
        return front->info;
    }
};


int main(){

    queue <Ticket*> codaTicket;
    codaTicket.enqueue( new Hardware(101, 3, "Alice"));
    codaTicket.enqueue( new Software(102, 1, "Bob"));

    codaTicket.printQueue();
    return 0;
}