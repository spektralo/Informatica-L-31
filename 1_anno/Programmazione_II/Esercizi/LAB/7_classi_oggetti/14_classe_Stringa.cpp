/* 
Implementare una classe Stringa.
Ogni oggetto della classe rappresenta una stringa di caratteri.
Gli attributi sono la lunghezza della stringa e la stringa di caratteri attuale.
Aggiungere costruttori, distruttori, funzioni di accesso e funzioni per visualizzare, 
- aggiunger una funzione carattere(int i) che restituisca 
il carattere situato nell' indice i della stringa
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Stringa {
private:
	int lunghezza;                            // lunghezza della stringa
	char *ptrStringa;       //puntatore al primo carattere della stringa
	void setStringa(char *s);    //funzione che imposta la stringa
public:
	Stringa(char *s = "");                  // costruttore default
	Stringa(Stringa &s);                   // costruttore di copia
	~Stringa();                                           // distruttore
	int getLunghezza();    //restituisce la lunghezza della stringa
	void Visualizza();
	char Carattere(int);
	int Lunghezza(); 
};

// la lunghezza è 0 oppure lunghezza di s
Stringa::Stringa(char *s) :lunghezza(s != NULL ? strlen(s) : 0) {
	cout << "costruttore di default: " << s << endl;
	setStringa(s);       // utilizzata per creare l'istanza dell'oggetto
}

// funzione alla base dell'inizializzazione della classe
void Stringa::setStringa(char * s) {
	ptrStringa = new char[lunghezza + 1];
	if (s != 0) strcpy(ptrStringa, s); //se s punta una stringa la copio
	else  ptrStringa[0] = '\0';     //altrimenti copio una stringa vuota
}

//costruttore di copia
Stringa::Stringa(Stringa & s) : lunghezza(s.lunghezza) {
	cout << "costruttore di copia: " << s.ptrStringa << endl;
	setStringa(s.ptrStringa);// ancora per creare l'istanza dell'oggetto
}

Stringa::~Stringa() {
	cout << "distruttore: " << ptrStringa << endl;
	delete [] ptrStringa;
}

int Stringa::getLunghezza() {
	return lunghezza;
}



void Stringa::Visualizza() {
	cout << ptrStringa << endl;
}

char Stringa::Carattere(int i) {
	if (i<lunghezza) return *(ptrStringa+i);
	else return '@';
}

int main() {
	//"PROVA 1" viene considerato come un array di caratteri
	Stringa prova1("PROVA 1");
	prova1.Visualizza();
	cout << prova1.Carattere(3) << endl;
	cout << prova1.getLunghezza() << endl;
	
	cout << "\n\n-----------------------\n" << endl;
	Stringa prova2("ALTRA PROVA");
	prova2.Visualizza();
	cout << prova2.Carattere(15) << endl;
	cout << prova2.getLunghezza() << endl;
	
	cout << "\n\n-----------------------\n" << endl;
	Stringa prova3;
	prova3.Visualizza();
	cout << prova3.Carattere(15) << endl;
	cout << prova3.getLunghezza() << endl;
	
	cout << "\n\n-----------------------\n" << endl;
	Stringa prova4(prova2);
	prova4.Visualizza();
	cout << prova4.Carattere(1) << endl;
	cout << prova4.getLunghezza() << endl;
	return 0;
}

