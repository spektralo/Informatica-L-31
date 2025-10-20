
#include <iostream>
using namespace std;

int cerca(double* v, int m, double k) {
	for (int j=0; j<m; j++)
		if (*v == k)//verifico che a quell'indirizzo (derefenziando) c'è un valore pari a quello cercato
			return j+1;
		else v++;//incremento v che essendo un puntatore mi manda all'indirizzo successivo
	return 0;
}

int main() {
	double elemento;
	double vettore[10]={0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	cout << "Che elemento vuoi cercare?\n";
	cin >> elemento;
	cout << "si trova all'indirizzo " << cerca(vettore,10,elemento) << endl;
	return 0;
}

// e se volessi la posizione piuttosto che l'indirizzo?


// return j+1, e int al posto di double*


