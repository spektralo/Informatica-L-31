
/* Scrivere una classe Ora_giorno che consenta di scrivere l'ora del giorno (in ore
e minuti) su 24 ore. La classe deve sovraccaricare gli operatori ++ e -- per incremen-
tare ore e minuti.
*/

#include <iostream>  
using namespace std;

class Ora_giorno {
private:
	int o;
	int m;
	int s;
public:
	Ora_giorno() {s = 0; m = 0; o = 0;} // inizializza a 00:00:00
	void visualizza() {cout << o << ' ' << m << ' ' << s;};;
	void legge(){cin >> o >> m >> s;};
	Ora_giorno operator++ () {
		s++;
		if (s > 59) {s -= 60; ++m;}
		if (m > 59) {m -= 60; ++o;}
		return * this;
	};
	Ora_giorno operator-- () {
		s--;
		if (s < 0) {s = 59; --m;}
		if (m < 0) {m = 59; --o;}
		return * this;
	};
};


int main() {
	Ora_giorno t;
	cout << "\nLettura dell'ora (hh mm ss) : ";
	t.legge();
	cout << "l'orologio segna: ";
	t.visualizza();
	++t;
	cout << "\ndopo l'incremento, t = ";
	t.visualizza();
	--t;
	cout << "\ndopo il decremento, t = ";
	t.visualizza();
}
