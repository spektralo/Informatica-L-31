#include <iostream>
using namespace std;

int main() {
	int velocita = 120;
	float consumo;
	if (velocita > 80) consumo = 10.00;
	else if (velocita > 100) consumo = 12.00;
	else if (velocita > 120) consumo = 15.00;
	cout << consumo;	
	return 0;
}

// qual'è l'output?

