#include<iostream>
#include<memory>
#include<string>
using namespace std;

class Animale{
    private:
    string nome, razza;
    int eta;

    public:
    Animale(string nome, string razza, int eta) : nome(nome), razza(razza), eta(eta){}
    ~Animale(){}

    string getNome() const {return nome;}
    string getRazza() const {return razza;}
    int getEta() const {return eta;}

    virtual string getFamiglia() const = 0;
    void printInfo(){cout<<nome<<razza<<eta<<getFamiglia()<<endl;}
};

class Cane:public Animale{
    public:
    Cane(string nome, string razza, int eta) : Animale(nome,razza,eta){}
    ~Cane(){}
    virtual string getFamiglia()const override{return "Canidi";}
};

class Gatto:public Animale{
    public:
    Gatto(string nome, string razza, int eta) : Animale(nome,razza,eta){}
    ~Gatto(){}
    virtual string getFamiglia()const override{return "Felini";}
};

template<typename tmpl>
struct Node{
    tmpl info;
    Node*next;
    Node(tmpl data) : info(data), next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class list{
    Node<tmpl>*head;
    int size;

    public:
    list() : head(nullptr), size(0){}
    ~list(){
        while (head!=nullptr)
        {
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

    int getSize() const { return size; }

    bool isEmpty() const {return head == nullptr;}

    tmpl extract(){
        if(isEmpty()){throw runtime_error("Lista vuota!");}
        Node<tmpl>*temp = head;
        tmpl info = head->info;
        head = head->next;

        delete temp;
        size--;
        return info;
    }

    void printList() const {
        Node<tmpl>*current = head;
        while (current!=nullptr)
        {
            current->info->printInfo();
            current = current->next;
        }
    }

};

int main(){

    list<Animale*> rifugio;
    rifugio.insert(new Cane("Bob","Chihuahua", 4));
    rifugio.insert(new Gatto("Yuuki","Persiano",7));
    rifugio.printList();
    
    return 0;
}