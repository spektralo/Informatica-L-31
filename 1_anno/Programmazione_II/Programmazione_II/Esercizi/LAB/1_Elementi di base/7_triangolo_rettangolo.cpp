#include <iostream>

// contiene la funzione sqrt
#include <cmath> 
using namespace std;

int main() {
	float a, b, i;
	cout << "Inserisci i cateti del triangolo rettangolo: ";
	cin >> a >> b;
	i = sqrt( a * a + b * b );
	cout << " cateto 1  = " << a << endl;
	cout << " cateto 2  = " << b << endl;
	cout << " ipotenusa = " << i << endl;
	return 0;
}


