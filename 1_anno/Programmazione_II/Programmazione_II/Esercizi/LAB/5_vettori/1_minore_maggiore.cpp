#include <iostream>
using namespace std;

int main() {
	int minore = 70, maggiore = -70;
	int temperature[1];
	for (int i=0; i<1; i++) {
		cin >> temperature[i];
		if (temperature[i] > maggiore) 
			maggiore = temperature[i];
		if (temperature[i] < minore) 
			minore = temperature[i];
	}
		cout << "La temperatura maggiore raggiunta: " << maggiore << endl;
		cout << "La temperatura minore raggiunta: " << minore << endl;
	return 0;
}

// A cosa servono le inizializzazioni alla riga 5? 
// Inserendo una unica temperatura=0 cosa succede? e con temperatura=80?
