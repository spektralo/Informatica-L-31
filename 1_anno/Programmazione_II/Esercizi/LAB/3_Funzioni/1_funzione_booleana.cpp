#include <iostream>
using namespace std;

bool Cifra (char c) {
	if (c >= 48 && c <= 57) return true;
	return false;
} 

int main() {
	char  carattere;
	//int  carattere;
	cin >> carattere;
	if (Cifra(carattere)) cout << carattere << ": hai digitato una cifra\n";
	else cout << carattere << ": non hai digitato una cifra\n";
	return 0;
}

//cast a char


