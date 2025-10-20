#include <iostream>
using namespace std;

int main() {
	float voto;
	cin >> voto;
	//switch (voto)
	if (voto < 5) cout << "Insufficiente\n";
	else if (voto < 6.5) cout << "Sufficiente\n";
		 else if (voto < 8.5) cout << "Buono\n";
		      else if (voto < 10) cout << "Distinto\n";
		           else if (voto == 10) cout << "Distinto\n";
		                else cout << "voto fuori scala\n";
	return 0;
}


//output con voto=8.5(?)

