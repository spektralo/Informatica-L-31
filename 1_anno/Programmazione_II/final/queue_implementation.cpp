#include<iostream>
using namespace std;

#define dim 1000

class queue{
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

    public:
    queue(int size = dim);
    ~queue();

    void enqueue(int data);
    int dequeue();
    int peek();
    int getSize();
    bool isEmpty();
    bool isFull();
    
};

queue::queue(int size){
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

queue::~queue() {
    delete[] arr;
}

int queue::getSize(){
    return count;
}

bool queue::isFull(){
    return (getSize() == capacity);
}

bool queue::isEmpty(){
    return (getSize() == 0);
}

void queue::enqueue(int elem){
    if (isFull()){ cout << "Overflow!" << endl;}
        
        cout << "Inserting" << elem << endl;
        rear = (rear + 1) % capacity; //new back index

        arr[rear] = elem;
        count++;
}

int queue::dequeue(){
    if(isEmpty()){cout << "Underflow!" << endl;}

        int x = arr[front];
        cout << "Removing" << x << endl;

        front = (front + 1) % capacity;
        count--;

        return x;
}

int queue::peek(){
    if (isEmpty){cout << "Underflow!" << endl;}

        return arr[front];
}