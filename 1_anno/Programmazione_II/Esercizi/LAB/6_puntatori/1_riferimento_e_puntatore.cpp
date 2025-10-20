#include <iostream>
using namespace std;

int main() {
	int n = 33;
	// r ed n sono uguali (stesso indirizzo stesso valore)
	int &r = n;
	//riferimenti
	cout << "&n = " << &n << ", &r = " << &r << endl;
	//valori
	cout << "n = " << n << ", r = " << r << endl;
	
		
	int c=5;
	int* p;
	//puntiamo p all'indirizzo di c
	p= &c;
	// p è puntatore
	cout << "p:" << p << endl;
	// *p dereferenzia il puntatore (accedendo al valore)
	cout << "*p:" << *p << endl;
	cout << "&p:" << &p << endl;
	cout << "c:" << c << endl;
	cout << "&c:" << &c << endl;


}

//Un riferimento, analogamente a un puntatore, archivia l'indirizzo di un oggetto 
//che si trova in un'altra posizione in memoria. A differenza di un puntatore, 
//dopo l'inizializzazione non è possibile impostare un riferimento in modo che 
//indichi un oggetto diverso o che sia impostato su Null


