#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Per favore, immetta un numero positivo n:";
	cin >> n;
	if (n < 0)
	{
		cout << "Numero negativo. Provi di nuovo .\n";
		cin >> n;
	}
	else
	cout << "Grazie! n= " << n << endl;
}

// output(?)
