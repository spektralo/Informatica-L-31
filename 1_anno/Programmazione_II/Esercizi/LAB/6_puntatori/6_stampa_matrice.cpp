#include <iostream>
using namespace std;

/*int main() {
	unsigned mt[4][5] = {11,12,13,14,15,21,22,23,24,25,31,32,33,34,35,41,42,43,44,45};
	for (int f = 0; f < 4; f++) {
		for (int c = 0; c < 5; c++) 
			cout << mt[f][c] << ' ';
		cout << "\n";
	}
}*/


int main() {
	unsigned mt[4][5] = {11,12,13,14,15,21,22,23,24,25,31,32,33,34,35,41,42,43,44,45};
	for (int f = 0; f < 4; f++) {
		for (int c = 0; c < 5; c++) 
			cout << *(*(mt+f)+c) << ' ';
		cout << "\n";
	}
}




/*

Il nome di un vettore è il puntatore al primo elemento del vettore. 

Per un vettore di vettori (matrice):
*(mt+f) puntatore al primo elemento della riga "f" della matrice 
(al variare di f punta alla prima/seconda/...riga)

*(*(mt+f)+c) puntatore al primo elemento della colonna "c" della riga "f*/
