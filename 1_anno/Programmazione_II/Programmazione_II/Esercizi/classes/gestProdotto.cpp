#include<iostream>
using namespace std;

class Animale{
    protected:
    string nome, razza;
    int eta;

    public:
    Animale(string nome, string razza, int eta) : nome(nome), razza(razza), eta(eta){}
    virtual ~Animale(){}
    string getNome(){return nome;}
    
    virtual string verso() const = 0;
    void stampaInfo(){ cout<< nome << razza << eta << verso() << endl;}
};

class Cane:public Animale{
    public:
    Cane(string nome, string razza, int eta) : Animale(nome,razza,eta){}
    virtual ~Cane(){}
    virtual string verso() const override{return "Bau Bau";}
};

class Gatto:public Animale{
    public:
    Gatto(string nome, string razza, int eta) : Animale(nome,razza,eta){}
    virtual ~Gatto(){}
    virtual string verso() const override{return "Miao Miao";}
};

template<typename tmpl>
struct Node{
    tmpl info;
    Node *next;
    Node(tmpl data) : info(data), next(nullptr) {}
    ~Node(){}
};

template<typename tmpl>
class queue{
    Node<tmpl>*front;
    Node<tmpl>*back;
    int size;

    public:
    queue() : front(nullptr), back(nullptr), size(0) {}
    ~queue(){
        while (front!=nullptr)
        {
            Node<tmpl>*temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(tmpl info){
        Node<tmpl>* newNode = new Node<tmpl>(info);
        if(back != nullptr){back->next = newNode;}
            back = newNode;

            if(front == nullptr){front = newNode;}
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

tmpl getFront(){
    if(front == nullptr){throw runtime_error("Coda vuota!");}
    return front->info;
}

bool isEmpty() const {return size == 0;}

void printQueue() const {
    Node<tmpl>* current = front;
    while(current!=nullptr){
        current->info->stampaInfo();
        current = current->next;
        }
    }

    void search(){
        string r;
        cout << "Inserisci il nome da cercare: " << endl;
        cin >> r;

    Node<tmpl>* current = front;
    while(current!=nullptr){
        if (current->info->getNome() == r)
        {
            cout << "Nome trovato: " << current->info->getNome() << endl;
            cout << "\nIl verso di" << current->info->getNome() <<" e' " << current->info->verso() << endl;
        }
        current = current->next;
        }
    }
};

int main(){
queue<Animale*> animali;
animali.enqueue(new Cane("Fido", "Labrador", 3));
animali.search();

}