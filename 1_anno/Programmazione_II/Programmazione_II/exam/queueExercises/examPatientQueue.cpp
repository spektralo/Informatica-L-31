#include <iostream>
#include <string>

class Patient
{
    private:
        size_t id;
        std::string name;
        std::string condition;

    public:
        Patient(size_t id) : id(id), name("Nome Sconosciuto"), condition("Condizione Sconosciuta") {}
        Patient(size_t id, std::string name) : id(id), name(name), condition("Condizione Sconosciuta") {}
        Patient(size_t id, std::string name, std::string condition) : id(id), name(name), condition(condition) {}

        void print()
        {
            std::cout << "----- PAZIENT " << this->id << " -----\n";
            std::cout << "Name: " << this->name << std::endl;
            std::cout << "Condition: " << this->condition << std::endl;
            std::cout << "----- PAZIENT " << this->id << " -----\n\n";
        }
};

enum Priority {
    RED, GREEN
};

class Node
{
    public:
        Patient* patient;
        Priority priority;
        Node* next;

        Node(Patient* patient, Priority priority) : patient(patient), priority(priority), next(nullptr) {}
        Node(Patient* patient, Priority priority, Node* next) : patient(patient), priority(priority), next(next) {}
        ~Node() { delete this->patient; }

};

class Queue
{
    private:
        Node* head;
        Node* tail;

    public:
        Queue() : head(nullptr), tail(nullptr) {}
        ~Queue()
        {
            if(this->head == nullptr) return;

            Node* curr = this->head;
            while(curr->next != nullptr)
            {
                Node* oldCurr = curr;
                curr = curr->next;

                delete oldCurr;
            }

            if(curr != nullptr) delete curr;
        }

        void enqueue(Patient* patient, Priority priority)
        {
            if(this->head == nullptr)
            {
                this->head = new Node(patient, priority);
                this->tail = this->head;
                return;
            }

            if(priority == RED)
            {
                if(this->head->priority == GREEN)
                {
                    Node* oldHead = this->head;
                    this->head = new Node(patient, priority, oldHead);
                    return;
                }

                Node* prev = nullptr;
                Node* curr = this->head;
                while(curr->next != nullptr)
                {
                    prev = curr;
                    curr = curr->next;

                    if(curr->priority == GREEN)
                    {
                        break;
                    }
                }

                prev->patient->print();
                
                prev->next = new Node(patient, priority, curr);
                return;
            }

            this->tail->next = new Node(patient, priority);
            this->tail = this->tail->next;
        }

        void dequeue()
        {
            if(this->head == nullptr)
            {
                std::cout << "Cannot dequeue if queue is empty.\n";
                return;
            }

            this->head->patient->print();
            
            Node* oldHead = this->head;
            this->head = this->head->next;

            delete oldHead;
        }
};

int main(int argc, char** argv)
{
    Patient* patients[5];
    patients[0] = new Patient(4814, "Gintonic", "Cirrosi");
    patients[1] = new Patient(4829, "Sex on the Beach", "Cirrosi");
    patients[2] = new Patient(4920, "Bloody Mary", "Cirrosi");
    patients[3] = new Patient(4985, "Angelo Azzurro", "Cirrosi");
    patients[4] = new Patient(4999, "Margarita", "Cirrosi");

    Queue* queue = new Queue();
    queue->enqueue(patients[0], GREEN);
    queue->enqueue(patients[1], GREEN);
    queue->enqueue(patients[2], RED);
    queue->enqueue(patients[3], GREEN);
    queue->enqueue(patients[4], RED);

    // 1. Bloody Mary
    // 2. Margarita
    // 3. Gintonic
    // 4. Sex on the Beach
    // 5. Angelo Azzurro

    for(int i = 0; i < 5; i++)
        queue->dequeue();
}