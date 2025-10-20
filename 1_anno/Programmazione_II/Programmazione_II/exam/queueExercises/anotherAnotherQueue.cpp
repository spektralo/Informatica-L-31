#include<iostream>
#include<string>
using namespace std;

template<typename tmpl>
struct Node{
    tmpl info;
    Node*next;
    Node(tmpl data) : info(data), next(nullptr){}
    ~Node(){}
};

template<typename tmpl>
class queue{
   Node<tmpl>*front, *back;
   int size;

   public:
   queue() : front(nullptr), back(nullptr), size(0){}
   ~queue(){
        while(front!=nullptr){
            Node<tmpl>*temp = front;
            front = front->next;
            delete temp;
        }
   }

   bool isEmpty() const {return front == nullptr;}

   void enqueue(tmpl info){
    Node<tmpl>*newNode = new Node<tmpl>(info);
    if(back!=nullptr){back->next = newNode;}
        else{back = newNode;}

        if(front == nullptr){front = newNode;}
        size++;
    }

    tmpl dequeue(){
        if(isEmpty()){throw runtime_error("Underflow: coda vuota!");}
        Node<tmpl>*temp = front;
        tmpl info = front->info;
        front = front->next;

        if(front==nullptr){back = nullptr};

        delete temp; size--; return info;
    }


};
