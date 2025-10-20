#include <iostream>
using namespace std;

int main() {
	int prima_opzione = 2;
	switch (++prima_opzione)
	{
		case 1: cout << "Agnello arrosto\n"; break;
		case 2: cout << "Cotoletta abbacchio\n"; break;
		case 3: cout << "Bistecca\n";
		case 4: cout << "Dolce di pasticcio\n"; break;
		default: cout << "Buon appetito\n";
	}
	return 0;
}

// output? 
// ++prima_opzione sullo swith
//  prima_opzione=2


