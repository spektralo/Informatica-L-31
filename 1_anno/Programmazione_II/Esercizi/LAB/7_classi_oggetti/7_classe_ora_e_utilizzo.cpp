/* 
- Creare una classe "ora" che abbia attributi di tipo int per ore, minuti e secondi. 
- Un costruttore inizializzerà  questi dati tutti a 0, mentre un altro li inizializzerà a valori predefiniti. 
- Una funzione dovrà  visualizzare l'ora in formato 11:59:59.
- Un'altra funzione sommerà  due oggetti di tipo ora passati come argomenti, assegnadoli ad un terzo oggetto "ora".
- Una funzione principale main() deve creare due oggetti inizializzati e un terzo che non lo sia. 
- Sommare i due valori inizializzati e lasciare il risultato nell'oggetto non inizializzato. 
- Da ultimo visualizzare il valore risultante.
*/

#include <iostream>  
using namespace std;

class ora {
private:
	int ore, min, sec;
public:
	ora() {ore=0; min=0, sec=0;};
	ora(int o, int m, int s) {ore=o; min=m, sec=s;};
	void visualizza(){cout << ore << ':' << min <<':' << sec;};
	void somma(ora o1, ora o2){
		sec = (o1.sec+o2.sec)%60;
		min = ((o1.sec+o2.sec) / 60 + o1.min + o2.min)%60;
		ore = (((o1.sec+o2.sec) / 60 + o1.min +o2.min) / 60 + o1.ore +o2.ore)%24;
	};
};

int main() {
	ora x;
	ora y(10,20,30), z(20,30,50);
	x.somma(y,z);
	x.visualizza();
	return 0;
}
