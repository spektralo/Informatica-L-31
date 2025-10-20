#include<iostream>
#include<string>
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
    Node*next;
    Node(tmpl data) : info(data), next(nullptr){}
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
        Node<tmpl>*newNode = new Node<tmpl>(info);
        if (back!=nullptr){ back->next = newNode;}
        back = newNode;
            if(front == nullptr){front = newNode;}
            size++;
    }

    bool isEmpty() const {return front == nullptr;}

    int getSize() const { return size; }

    tmpl dequeue(){
        if(isEmpty()){throw runtime_error("Coda vuota!");}
            Node<tmpl>*temp = front;
            tmpl info = front->info;
            front = front->next;

            if(front == nullptr){back = nullptr;}
            delete temp; size--; return info;
    }

    void printQueue const (){
        Node<tmpl>*current = front;
        while(current!=nullptr){
            current->info->print();
            current = current->next;
        }
    }
};










/*
template<typename tmpl>
struct Node{
    tmpl info;
    Node*next;
    Node(tmpl data) : info(data), next(nullptr) {}
    ~Node(){}
};

template<typename tmpl>
class list{
    Node<tmpl>*head;
    int size;

    public:
    list() : head(nullptr), size(0){}
    ~list(){
        while(head!=nullptr){
            Node<tmpl>*temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        newNode->next = head;
        head = newNode;
        size++;
    }

    bool isEmpty(){return head == nullptr;}

    tmpl extract(){
        if(isEmpty()){throw runtime_error("coda vuota!");}
        Node<tmpl>*temp = head;
        tmpl info = temp->info;
        head = head->next;

        size--; return info; delete temp;
    }

    void printList(){
        Node<tmpl>*current = head;
        while (current!=nullptr)
        {
            current->info->print();
            current = current->next;
        }
    }
};
/* 























/* 
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
    stack() : top(nullptr), size(0){}
    ~stack(){while (top!=nullptr)
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
        if(isEmpty()){throw runtime_error("coda vuota!");}
        Node<tmpl>*temp = top;
        tmpl info = top->info;
        top = top->next;

        size--; return info; delete temp;
    }

    void printStack(){
        if(isEmpty()){throw runtime_error("coda vuota!");}
        Node<tmpl>*current = top;
        while(current!=nullptr){
            current->info->print();
            current = current->next;
        }
        
    }
};
*/


/* 
template<typename tmpl>
struct Node{
    tmpl info;
    Node*next;
    Node(tmpl data) : info(data), next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class queue{
    Node<tmpl>*front;
    Node<tmpl>*back;
    int size;

    public:
    queue() : front(nullptr), back(nullptr), size(0){}
    ~queue(){
        while (front!=nullptr)
        {
            Node<tmpl>*temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        if (back!=nullptr){back->next = newNode;}
            back = newNode;
        if (front == nullptr)
        {
            front = newNode;
        }
        size++;
    }

    bool isEmpty(){return front == nullptr;}

    tmpl dequeue(){
        if(isEmpty()){throw runtime_error("Coda vuota!");}
        Node<tmpl>*temp = front;
        tmpl info = front->info;
        front = front->next;

        if (front == nullptr){back = nullptr;}
        return info; delete temp; size--;
    }

    void getFront(){
        if(isEmpty()){throw runtime_error("Coda vuota!");}
        return front->info;
    }

    void printQueue(){
        Node<tmpl>*current = front;
        while (current!=nullptr)
        {
            current->info->print();
            current = current->next;
        }
    }
};
*/

int main(){
    queue <Libro*> libreria;
    libreria.enqueue(new Romanzo("Harry Potter","J.K Rowling",2007));
    libreria.enqueue(new Romanzo("Il Cigno Nero","Nassim Taleb",2021));
    libreria.dequeue();
    libreria.printQueue();
    return 0;
}