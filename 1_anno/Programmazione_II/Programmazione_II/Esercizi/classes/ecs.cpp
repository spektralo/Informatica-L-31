#include<iostream>
#include<string>
using namespace std;

class Frutto{
    protected:
    string nome, colore, stagione;

    public:
    Frutto(string nome, string colore, string stagione) : nome(nome), colore(colore), stagione(stagione){}
    ~Frutto(){}

    string getNome(){return nome;}
    string getColore(){return colore;}
    string getStagione(){return stagione;}

    void stampaInfo(){cout<<nome<<colore<<stagione<<sapore()<<endl;}
    virtual string sapore() = 0;

};

class Mela:public Frutto{
    public:
    Mela(string nome, string colore, string stagione) : Frutto(nome,colore,stagione){}
    ~Mela(){}
    
    virtual string sapore() override{
        if (getNome() == "Granny Smith"){ return "Aspro";}
         if(getNome() == "Golden Delicious"){return "Dolce";}
             if(getNome() == "Fuji"){return "Dolce";}
                else return "sapore sconosciuto";
     }
};

class Arancia:public Frutto{
    public:
    Arancia(string nome, string colore, string stagione) : Frutto(nome,colore,stagione){}
    ~Arancia(){}
    
    virtual string sapore() override{
       if (getNome() == "Tarocco"){ return "Dolce";}
        if(getNome() == "Navel"){return "Dolce-Acido";}
            if(getNome() == "Valencia"){return "Acido";}
                else return "sapore sconosciuto";
    }
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
};

int main(){
    queue<Frutto*> frutta;
    frutta.enqueue(new Mela("Granny Smith", "Verde","Autunno"));
    frutta.enqueue(new Mela("Golden Delicious", "Giallo","Autunno"));
    frutta.printQueue();
    return 0;
}