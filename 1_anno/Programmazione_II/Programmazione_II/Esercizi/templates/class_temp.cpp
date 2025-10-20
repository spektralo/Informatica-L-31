#include <iostream>
using namespace std;

template<typename T>
class Box {
private:
    T value; // Valore generico

public:
    // Costruttore
    Box(T val) : value(val) {}

    // Metodo per ottenere il valore
    T get() {
        return value;
    }

    // Metodo per impostare un nuovo valore
    void set(T val) {
        value = val;
    }
};

int main() {
    // Testa la classe Box
    Box<int> intBox(42);  // Crea una Box per un intero
    std::cout << "Int Box: " << intBox.get() << std::endl;

    Box<std::string> strBox("Ciao");  // Crea una Box per una stringa
    std::cout << "String Box: " << strBox.get() << std::endl;

    // Cambia i valori nella Box
    intBox.set(99);
    strBox.set("Mondo");
    std::cout << "Int Box (dopo set): " << intBox.get() << std::endl;
    std::cout << "String Box (dopo set): " << strBox.get() << std::endl;

    return 0;
}

