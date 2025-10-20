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

    bool isEmpty() const {return head == nullptr;}
    int getSize() const {return size;}

    void insert(tmpl data){
        Node<tmpl>*newNode = new Node<tmpl>(info);
        newNode->next = head;
        head = newNode;
        size++;
    }

    tmpl extract(){
        if(isEmpty()){throw runtime_error("Underflow: lista vuota!");}
            Node<tmpl>* temp = head;
            tmpl info = head->info;
            head = head->next;

            delete temp; size--; return info;
    }

    void printList(){
        Node<tmpl>*current = head;
        while(current!=nullptr){
            current->info->printInfo();
            current = current->next;
        }
    }
};
    

int main(){
    return 0;
}