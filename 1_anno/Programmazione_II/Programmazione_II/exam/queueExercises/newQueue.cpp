#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Ordine{
    private:
    int numOrdine, quantita;
    string cliente;

    public:
    Ordine(int numOrdine, string cliente, int quantita) : numOrdine(numOrdine), cliente(cliente), quantita(quantita) {}
    virtual ~Ordine(){}

    int getNumOrdine() const {return numOrdine;}
    int getQuantita() const {return quantita;}
    string getCliente() const {return cliente;}
    virtual string getCategoria() const = 0;

    void print(){cout << "Numero Ordine: " << numOrdine << " - " << "Cliente: " << cliente << " - " << "Quantita: " << quantita << " - " <<"Categoria: " << getCategoria() <<endl;}
};

class PiattoCaldo:public Ordine{
    public:
    PiattoCaldo(int numOrdine, string cliente, int quantita) : Ordine(numOrdine, cliente, quantita){};
    virtual ~PiattoCaldo(){}

    virtual string getCategoria() const override{return "Piatto Caldo";}
};

class PiattoFreddo:public Ordine{
    PiattoFreddo(int numOrdine, string cliente, int quantita) : Ordine(numOrdine, cliente, quantita){}
    virtual ~PiattoFreddo(){}
    virtual string getCategoria() const override{return "Piatto Freddo";}
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
        if (back != nullptr)
        {
            back->next = newNode;
        }
        back = newNode;

        if (front == nullptr)
        {
            front = newNode;
        }
        size++;
    }

    bool isEmpty(){return front == nullptr;}

    tmpl dequeue(){
        if (isEmpty()){throw runtime_error("Coda vuota!");}
        Node<tmpl>*temp = front;
        tmpl info = front->info;
        front = front->next;

        if (front == nullptr)
        {
            back = nullptr;
        }
        delete temp;
        size--;
        return info;
    }

    void getFront(){
        if (isEmpty())
        {
            cout<<"coda vuota!"<<endl;
        }
        return front->info;
    }

    void printQueue(){
        Node<tmpl>*current = front;
        while (current !=nullptr)
        {
            current->info->print();
            current = current->next;
        }
    }
};

int main(){
    queue<Ordine*> codaOrdini;
    codaOrdini.enqueue(new PiattoCaldo(13,"Andrea",2));
    codaOrdini.printQueue();

    return 0;
}