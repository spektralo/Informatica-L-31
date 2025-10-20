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
    Node*prev;
    Node(tmpl data) : info(data), next(nullptr), prev(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class doubleLinked{
    Node<tmpl>*head;
    Node<tmpl>*tail;
    int size;

    public:
    doubleLinked() : head(nullptr), tail(nullptr), size(0){}
    ~doubleLinked(){
        while(head!=nullptr){
            Node<tmpl>*temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
    
    bool isEmpty() const {return head == nullptr;}

    int getSize() const{ return size;}

    void headIns(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
            if(isEmpty()){head = tail = newNode;}
                else{
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
        size++;
    }

    void tailIns(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        if(isEmpty()){head = tail = newNode;}
            else{
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }

    tmpl headExtract(){
        if(isEmpty()){throw runtime_error("Underflow: lista vuota!");}
            Node<tmpl>*temp = head;
            tmpl info = head->info;
            head = head->next;

            if(head!=nullptr){head->prev = nullptr;}
                else{tail = nullptr;}

                delete temp; size--; return info;
    }

    
     tmpl tailExtract() {
        if (isEmpty()) {throw runtime_error("Lista vuota!");}

        Node<tmpl>* temp = tail;
        tmpl info = temp->info;
        tail = tail->prev;

        if (tail != nullptr) {tail->next = nullptr;}
         else {head = nullptr;}

        delete temp;
        size--;
        return info;
    }

    void printList() const{
        Node<tmpl>*current = head;
        while (current!=nullptr)
        {
            current->info->print();
            current = current->next;
        }
    }
};
    
int main(int argc, const char** argv) {
    doubleLinked<Libro*> libreria;

    libreria.headIns(new Romanzo("Harry Potter"," J.K Rowling", 2006 ));
    libreria.tailIns(new Saggio("Il Cigno Nero", "Nicholas Taleb", 2020));
    libreria.headIns(new Romanzo("Pensieri", "Marco Aurelio", 2012));
    libreria.tailIns(new Saggio("Libro a caso", "Naleb", 2020));

    libreria.headExtract();
    libreria.tailExtract();

    libreria.printList();
    
    int size = libreria.getSize();
    cout << "\nDimensione: "<<size;
    return 0;
}