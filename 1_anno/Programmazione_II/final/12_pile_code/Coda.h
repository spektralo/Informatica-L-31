#include <iostream>
using namespace std;
 
// Definisce la capacità predefinita di una queue
#define SIZE 1000
 
// Una classe per memorizzare una queue
class Coda
{
    int *arr;       // array per memorizzare gli elementi della queue
    int capacity;   // capacità massima della queue
    int front;      // front punta all'elemento front nella queue (se presente)
    int rear;       // back punta all'ultimo elemento nella queue
    int count;      // dimensione attuale della queue
 
public:
    Coda(int size = SIZE);     // costruttore
    ~Coda();                   // distruttore
 
    int dequeue();//estrai dalla coda
    void enqueue(int x); //inserisci in coda
    int peek();// get elemento anteriore
    int size();// get size della coda
    bool isEmpty(); //coda vuota
    bool isFull(); //coda piena
};
 
// Costruttore per inizializzare una queue
Coda::Coda(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
 
// Distruttore per liberare la memoria assegnata alla queue
Coda::~Coda() {
    delete[] arr;
}


// Funzione di utilità per restituire la dimensione della queue
int Coda::size() {
    return count;
}
 

 
// Funzione di utilità per verificare se la queue è piena o meno
bool Coda::isFull() {
    return (size() == capacity);
}


// Funzione di utilità per verificare se la queue è vuota o meno
bool Coda::isEmpty() {
    return (size() == 0);
}
 
// Funzione di utilità per rimuovere dalla queue l'elemento anteriore
int Coda::dequeue()
{
    // verifica la presenza di un flusso di queue insufficiente
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n" << endl; 
    }
 
    //elemento in uscita
    int x = arr[front];
    cout << "Removing " << x << endl;


	//aggiorno indice elemento anteriore
    front = (front + 1) % capacity;
        
    //aggiorno la lunghezza della cosa
    count--;
 
    return x;
}
 
// Funzione di utilità per aggiungere un elemento alla queue
void Coda::enqueue(int item)
{
    // controlla l'overflow della queue
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n"<< endl; 
    }
 
    cout << "Inserting " << item << endl;
 
 	//aggiorno indice elemento posteriore
    rear = (rear + 1) % capacity;
    //aggiunge elemento alla coda
    arr[rear] = item;
    count++;
}
 
// Funzione di utilità per restituire l'elemento anteriore della queue
int Coda::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n"<< endl; 
    }
    
    //gete elemento anteriore
    return arr[front];
}
