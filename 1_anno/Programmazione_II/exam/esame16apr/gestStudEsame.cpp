#include<iostream>
using namespace std;

class Studente{
    protected:
    string matricola, nome, cognome;
    float media;

    public:
    Studente(string matricola, string nome, string cognome, float media)
    :matricola(matricola),nome(nome),cognome(cognome),media(media){}
    virtual ~Studente(){}

    string getMatricola()const{return matricola;} float getMedia()const{return media;}
    string getNome()const{return nome;} string getCognome()const{return cognome;}

    virtual float getImportoBorsa()const{return 0.0;}

    virtual void stampaInfo(ostream &os)const{
        os << "Matricola: " << getMatricola() << ", nome: " << getNome() <<
        ", cognome: " << getCognome() << ", media: " << getMedia() << endl;
    }

    friend ostream &operator <<(ostream &os, Studente &stud){
        stud.stampaInfo(os);
        return os;
    }
};

class BorsaStudio{
    protected:
    float importo;
    int durata;

    public:
    BorsaStudio(float importo):importo(importo){}
    ~BorsaStudio(){}

    float getImporto()const{return importo;} int getDurata()const{return durata;}
};

class StudenteBorsista:public Studente{
    protected:
    BorsaStudio *borsa;

    public:
    StudenteBorsista(string matricola, string nome, string cognome, float media, BorsaStudio *borsa)
    :Studente(matricola, nome, cognome, media),borsa(borsa){}

    float getImportoBorsa()const override{return borsa->getImporto();}

    void stampaInfo(ostream &os)const{
        Studente::stampaInfo(os);
        os << ", borsa di " << getImportoBorsa() << endl;
    }

    friend ostream &operator <<(ostream &os, StudenteBorsista &stud){
        stud.stampaInfo(os);
        return os;
    }
};

/*IMPLEMENTAZIONE LISTA
    template<typename tmpl>
struct Node{
    tmpl info;
    Node *next;
    Node(tmpl data) : info(data), next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class list{
    Node<tmpl>*head;
    int size;
    
    public:
    list():head(nullptr),size(0){}
    ~list(){
        while (head!=nullptr)
        {
            Node<tmpl>*temp = head;
            head = head->next;
            delete temp;
        }
    }

    int getSize()const{return size;}

    bool isEmpty()const{return size == 0;}

    void insert(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        newNode->next = head;
        head = newNode;
        size++;
    }

    tmpl extract(){
        if(isEmpty()){throw runtime_error("Lista vuota!");}
        Node<tmpl>*temp = head;
        tmpl info = head->info;
        head = head->next;

        delete temp; size--; return info; 
    }

    void deleteByMedia(){
        list<tmpl> tempList;
        while(!isEmpty()){
            tmpl elemento = extract();
            if (elemento->getMedia() >= 25.0)
            {
                tempList.insert(elemento);
            }
            else{delete elemento;}
        }
        while(!tempList.isEmpty()){
            insert(tempList.extract());
        }
    }

    void getTotImporto(){
        float totale;
        Node<tmpl> *current = head;
        while (current!=nullptr)
        {
            totale += current->info->getImportoBorsa();
            current = current->next;
        }
        cout << "\nTotale degli importi delle borse di studio: " << totale;
    }

    void printList(ostream &os){
        Node<tmpl>*current = head;
        while(current!=nullptr){
            current->info->stampaInfo(os);
            current = current->next;
        }
    }
};

FINE IMPLEMENTAZIONE LISTA*/

/*IMPLEMENTAZIONE STACK

template<typename tmpl>
struct Node{
    tmpl info;
    Node *next;
    Node(tmpl data):info(data),next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class stack{
    Node<tmpl>*top;
    int size;

    public:
    stack():top(nullptr),size(0){}
    ~stack(){
        while(top!=nullptr){
            Node<tmpl>*temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty()const{return size == 0;}

    void push(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        newNode->next = top;
        top = newNode;
        size++;
    }

    tmpl pop(){
        if(isEmpty()){throw runtime_error("Underflow, stack vuoto!");}
        Node<tmpl>*temp = top;
        tmpl info = top->info;
        top = top->next;

        delete temp; size--; return info;
    }

    void printStack(ostream &os){
        Node<tmpl>*current = top;
        while (current!=nullptr)
        {
            current->info->stampaInfo(os);
            current = current->next;
        }
    }

    void getTotImporto(){
        float totale = 0.0;
        Node<tmpl> *current = top;
        while (current!=nullptr)
        {
            totale += current->info->getImportoBorsa();
            current = current->next;
        }
        cout << "\nTotale degli importi delle borse di studio: " << totale;
    }

    void deleteByMedia(){
        stack <tmpl> tempStack;
        while(!isEmpty()){
            tmpl elemento = pop();
            if(elemento->getMedia() >= 25.0){
                tempStack.push(elemento);
            }
            else{delete elemento;}
        }

        while(!tempStack.isEmpty()){
            push(tempStack.pop());
        }
    }
};
FINE IMPLEMENTAZIONE */




/* IMPLEMENTAZIONE CODA

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

    void deleteByMedia(){
       queue<tmpl> tempQueue;
       while (!isEmpty())
       {
        tmpl elemento = dequeue();
        if (elemento->getMedia() >= 25.0){
            tempQueue.enqueue(elemento);
        }
            else{delete elemento;}
            }
            while(!tempQueue.isEmpty()){
                enqueue(tempQueue.dequeue());
       }
    }

    void getTotImporto(){
        float totale;
        Node<tmpl> *current = front;
        while (current!=nullptr)
        {
            totale += current->info->getImportoBorsa();
            current = current->next;
        }
        cout << "\nTotale degli importi delle borse di studio: " << totale;
    }

tmpl getFront(){
    if(front == nullptr){throw runtime_error("Coda vuota!");}
    return front->info;
}

bool isEmpty() const {return size == 0;}

void printQueue(ostream &os) const {
    Node<tmpl>* current = front;
    while(current!=nullptr){
        current->info->stampaInfo(os);
        current = current->next;
        }
    }
};

FINE IMPLEMENTAZIONE CODA*/



int main(){

/*IMPLEMENTAZIONE STACK
    stack<Studente*> pilaStudenti;

    BorsaStudio *borsaUno = new BorsaStudio(880);
    BorsaStudio *borsaDue = new BorsaStudio(500);
    BorsaStudio *borsaTre = new BorsaStudio(600);

    pilaStudenti.push(new Studente("1001", "Mario", "Rossi", 25.5));
    pilaStudenti.push(new StudenteBorsista("1002", "Anna", "Verdi", 28.0, borsaUno));
    pilaStudenti.push(new Studente("1003", "Luca", "Bianchi", 26.0));
    pilaStudenti.push(new Studente("1004", "Sara", "Neri", 27.5));
    pilaStudenti.push(new StudenteBorsista("1005", "Marco", "Gialli", 24.0, borsaDue));
    pilaStudenti.push(new StudenteBorsista("1006", "Laura", "Marroni", 29.0, borsaTre));

    pilaStudenti.printStack(cout);

    pilaStudenti.deleteByMedia();
    cout << "\n\nRimossi studenti con media < 25.0\n";
    pilaStudenti.printStack(cout);

    pilaStudenti.getTotImporto();

    return 0;
/*


/*IMPLEMENTAZIONE LISTA
 list<Studente*> listaStudenti;

    BorsaStudio *borsaUno = new BorsaStudio(880);
    BorsaStudio *borsaDue = new BorsaStudio(500);
    BorsaStudio *borsaTre = new BorsaStudio(600);
    
    listaStudenti.insert(new Studente("1001", "Mario", "Rossi", 25.5));
    listaStudenti.insert(new StudenteBorsista("1002", "Anna", "Verdi", 28.0, borsaUno));
    listaStudenti.insert(new Studente("1003", "Luca", "Bianchi", 26.0));
    listaStudenti.insert(new Studente("1004", "Sara", "Neri", 27.5));
    listaStudenti.insert(new StudenteBorsista("1005", "Marco", "Gialli", 24.0, borsaDue));
    listaStudenti.insert(new StudenteBorsista("1006", "Laura", "Marroni", 29.0, borsaTre));
    
    listaStudenti.printList(cout);
    
    listaStudenti.deleteByMedia();
    cout << "\n\n" << "Rimossi studenti con media < 25.0" << endl;
    listaStudenti.printList(cout);
    
    listaStudenti.getTotImporto();    
*/
   


/*CODA
queue<Studente*> codaStudenti;

    BorsaStudio *borsaUno = new BorsaStudio(880);
    BorsaStudio *borsaDue = new BorsaStudio(500);
    BorsaStudio *borsaTre = new BorsaStudio(600);

    codaStudenti.enqueue(new Studente("1001","Mario","Rossi",25.5));
    codaStudenti.enqueue(new StudenteBorsista("1002","Anna","Verdi",28.0,borsaUno));
    codaStudenti.enqueue(new Studente("1003","Luca","Bianchi",26.0));
    codaStudenti.enqueue(new Studente("1004","Sara","Neri",27.5));
    codaStudenti.enqueue(new StudenteBorsista("1005","Marco","Gialli",24.0,borsaDue));
    codaStudenti.enqueue(new StudenteBorsista("1006","Laura","Marroni",29.0,borsaTre));

    codaStudenti.printQueue(cout);
    
    codaStudenti.deleteByMedia();
    cout << "\n\n" << "Rimossi studenti con media < 25.0" << endl;
    codaStudenti.printQueue(cout);
    codaStudenti.getTotImporto();    
*/
}


template<typename tmpl>
struct Node{
    tmpl info;
    Node *next;
    Node(tmpl data):info(data),next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class list{
    Node<tmpl>*head;
    int size;

    public:
    list():head(nullptr),size(0){}
    ~list(){
        while(head!=nullptr){
            Node<tmpl>*temp = head;
            temp = temp->next;
            delete temp;
        }
    }

    bool isEmpty()const{return head == nullptr;}

    void insert(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        newNode->next = head;
        head = newNode;
        size++;
    }

    tmpl extract(){
        if(isEmpty()){throw runtime_error("Lista vuota!");}
        Node<tmpl>*temp = head;
        tmpl info = head->info;
        head = head->next;

        delete temp;
        size--;
        return info;
    }

    void deleteByMedia(){
        list<tmpl> tempList;
        if(!isEmpty()){
            tmpl elemento = extract();
            if(elemento->getDurata < 20){
                tempList.enqueue(elemento);
            }
            else delete elemento;

            while(!tempList.isEmpty()){
                enqueue(tempList.dequeue());
            }
        }
    }

    void printList(ostream &os){
        Node<tmpl>*current = head;
        while (current!=nullptr)
        {
            current->info->stampaInfo(os);
            current = current->next;
        }
    }
};


template<typename tmpl>
struct Node{
    tmpl info;
    Node *next;
    Node(tmpl data):info(data), next(nullptr){}
    Node(){}
};

template<typename tmpl>
class stack{
    Node<tmpl>*top;
    int size;

    public:
    stack() : top(nullptr), size(0){}
    ~stack(){
        while(top!=nullptr){
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

    tmpl pop(){
        if(isEmpty()){throw runtime_error("Stack vuoto!");}
        Node<tmpl>*temp = top;
        tmpl info = top->info;
        top = top->next;

        delete temp; size--; return info;
    }

    void deleteByMedia(){
        stack<tmpl> tempStack;
        if(!isEmpty()){
            tmpl elemento = pop();
            if(elemento->getMedia() > 25.0){
                tempStack.push(elemento);
            }
            else delete elemento;
    
            while(!tempStack.isEmpty()){
                push(tempStack.pop());
            }
        }
    }

    void printStack(ostream &os){
        Node<tmpl>*current = top;
        while(current!=nullptr){
            current->info->stampaInfo(os);
            current = current->next;
        }
    }
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
    Node<tmpl>*front, *back;
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

    bool isEmpty()const{return front == nullptr;}

    void enqueue(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        if(back != nullptr){
            back->next = newNode;
            back = newNode;
        }
        if(front == nullptr){front = newNode;}
        size++;
    }

    tmpl dequeue(){
        if(isEmpty()){throw runtime_error("Coda vuota!");}
        Node<tmpl>*temp = front;
        tmpl info = front->info;
        front = front->next;

        if(front == nullptr){back == nullptr;}

        delete temp; size--; return info;
    }

    void deleteByMedia(){
        queue<tmpl> tempQueue; // creo coda temporanea
        if(!isEmpty()){ //controlle che non sia vuota
            tmpl elemento = dequeue();  //ottengo elemento tmpl dalla coda con pop
            if(elemento->getTotImporto < 200){ //verifica di condizione su elemento estratto
                tempQueue.enqueue(elemento); //se verificata, metto in coda temporanea
            }
            else delete elemento; //altrimenti elimino

            while(!tempQueue.isEmpty()){ //
                enqueue(tempQueue.dequeue());
            }
        }
    }

    void printQueue(ostream &os)const{
        Node<tmpl>*current = front;
        while(current!=nullptr){
            current->info->stampaInfo(os);
            current = current->next;
        }
    }


};

template<typename tmpl>
struct Node{
    tmpl info;
    Node *next;
    Node(tmpl data): info(data), next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class queue{
    Node<tmpl>*front,*back;
    int size;

    public:
    queue():front(nullptr),back(nullptr),size(0){}
    ~queue(){
        while(front!=nullptr){
            Node<tmpl>*temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty()const{return front == nullptr;}

    void enqueue(tmpl info){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        if(back != nullptr){
            back->next = newNode;
            back = newNode;
        }

        if(front == nullptr){front = newNode;}
        size++;
    }

    tmpl dequeue(){
        if(isEmpty()){throw runtime_error("Coda vuota!");}
        Node<tmpl>*temp = front;
        tmpl info = front->info;
        front = front->next;

        if(front == nullptr){back = nullptr}
    }
};
