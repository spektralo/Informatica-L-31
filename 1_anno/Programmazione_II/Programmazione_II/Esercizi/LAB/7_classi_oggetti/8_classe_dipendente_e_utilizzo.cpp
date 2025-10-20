/* 
- Creare una classe chiamata "impiegato" che contenga come attributi il cognome e il numero di impiegato, 
e come funzioni  Leggeredati() e Vederedati() che importi i dati dalla tastiera e li visualizzi su
schermo, rispettivamente.

- Scrivere un programma che utilizzi la classe, creando un array di tipo impiegato, riempiendolo 
con dati corrispondenti a X impiegati con X inserito dall'utente. 
Una volta riempito l'array, visualizzare i dati di tutti gli impiegati.
*/

#include <iostream>  
using namespace std;

class impiegato {
private:
	char cognome[20];
	unsigned numero;
public:
	void LeggereDati(){
		cout << "INSERISCI COGNOME E NUMERO DIPENDENTE: " << endl;
		cin >> cognome >> numero;
	};
	void VedereDati(){cout << cognome << ' ' << numero << endl;};
};

int main() {
	
	int num_dipendenti;
	cout << "INSERISCI IL NUMERO DI DIPENDENTI: " << endl;
	cin >> num_dipendenti;
	
	impiegato dipendenti[num_dipendenti];
	for (int i=0; i<num_dipendenti; i++) dipendenti[i].LeggereDati();
	cout << "LISTA DIPENDENTI: " << endl;
	for (int i=0; i<num_dipendenti; i++) dipendenti[i].VedereDati();
	return 0;
}
