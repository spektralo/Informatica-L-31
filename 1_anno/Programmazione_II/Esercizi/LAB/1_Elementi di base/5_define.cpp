#include <iostream>
using namespace std;

/*La direttiva #define serve a definire una MACRO, ovvero un simbolo.
La sintassi è: #define  nome_macro  valore_macro (convenzionalmente i nomi delle macro vengono scritti con delle lettere MAIUSCOLE).
Il preprocessore legge la definizione della MACRO e, ogni volta che ne incontra il nome all'interno del file sorgente 
SOSTITUISCE al simbolo il corrispondente valore, SENZA verificare la correttezza sintattica dell'espressione risultante.
*/

#define collaudo "Prova ad immaginare"

int main() {
	//array di char di lunghezza 20(?)
	char frase[35] = "cosa viene scritto a schermo";
	cout << collaudo << endl;
	cout << "se sei in grado, \n";
	cout << frase << endl;
}
