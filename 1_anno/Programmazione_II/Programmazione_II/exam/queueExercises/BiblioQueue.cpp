#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Libro{
    private:
    string titolo, autore;
    int anno;

    public:
    Libro(string titolo, string autore, int anno) : titolo(titolo), autore(autore), anno(anno){}
    virtual ~Libro(){}

    string getTitolo(){return titolo;}
    string getAutore(){return autore;}
    int getAnno(){return anno;}

    void print(){cout<<"Titolo: "<<titolo<< "-" << "Autore: "<< autore << "-" << "Anno: " << anno << "Genere: " << getGenere() << "\n"<<endl;}
    virtual string getGenere() const = 0;
};

class Romanzo:public Libro{
    public:
    Romanzo(string titolo, string autore, int anno) : Libro(titolo,autore,anno){}
    virtual ~Romanzo(){}

    virtual string getGenere() const override{return "Romanzo";}
};

class Saggio:public Libro{
    public:
    Saggio(string titolo, string autore, int anno) : Libro(titolo,autore,anno){}
    virtual ~Saggio(){}

    virtual string getGenere() const override{return "Saggio";}
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
        current->info->print();
        current = current->next;
        }
    }
};


int main(){
    queue <Libro*> libreria;
    libreria.enqueue(new Romanzo("Harry Potter","J.K Rowling",2007));
    libreria.enqueue(new Romanzo("Il Cigno Nero","Nassim Taleb",2021));
    
    libreria.printQueue();
    return 0;
}