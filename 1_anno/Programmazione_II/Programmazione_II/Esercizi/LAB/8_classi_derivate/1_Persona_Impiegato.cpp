/* Definire una classe base persona che contenga un'anagrafica generale comune a tutte le persone 
(nome, indirizzo, data di nascita). 
-Progettare una gerarchia di classi che contempli la classi impiegato
*/

#include <iostream>  
using namespace std;

#define MAX 2

struct data {
	short unsigned giorno;
	short unsigned mese;
	short unsigned anno;
};

class Persona {
protected: // private impedirebbe l'ereditarietà  alla classe impiegato
	char nome[30];
	char indirizzo[30];
	data nascita;
public:
	Persona();
	~Persona(){cout << "elimino la persona "<< nome <<"\n";};
	void Visualizza();
};

Persona::Persona(){
	cout << "Come si chiama la persona?\n";
	cin.getline(nome,29);
	cout << "Dove abita?\n";
	cin.getline(indirizzo,29);
	cout << "Giorno di nascita (gg/mm/aaaa)?\n";
	cin >> nascita.giorno >> nascita.mese >> nascita.anno;
}

void Persona::Visualizza() {
	cout << "La persona si chiama " << nome << ", abita a "
	     << indirizzo ;
	cout << " nata/o il giorno " << nascita.giorno << '/'
	     << nascita.mese << '/' << nascita.anno << endl;
}

class Impiegato : public Persona {
private:
	short unsigned id;
	char ruolo;
public:
	Impiegato();
	~Impiegato(){cout << "elimino l'impiegato " << nome <<"\n";};
	void VisualizzaImpiegato();
};

Impiegato::Impiegato() {
	cin.ignore();
	cout << "ID dell'impiegato?\n";
	cin >> id;
	cout << "Ruolo dell'impiegato (A,B,C,D)?\n";
	cin >> ruolo;
	cin.ignore();
}

void Impiegato::VisualizzaImpiegato() {
	cout << "L'impiegato si chiama " << nome << ", abita a "
	     << indirizzo ;
	cout << " nato/a il giorno " << nascita.giorno << '/'
	     << nascita.mese << '/' << nascita.anno << endl;
	cout << "ID dell'impiegato: " << id
		 << " ruolo: " << ruolo << endl;
}

int main() {
  Impiegato impiegati[MAX];
  for (int i=0; i<MAX; i++) 
  	impiegati[i].Visualizza();
  return 0;
}
