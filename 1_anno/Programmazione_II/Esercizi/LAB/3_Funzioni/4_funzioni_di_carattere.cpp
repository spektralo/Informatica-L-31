#include <iostream>
using namespace std;

bool Vocale(char c) {
	if (isalnum(c) && !isdigit(c)) 
		c = toupper(c);
	return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U');;
}

int main() {
	char  lettera;
	cin >> lettera;
	if (Vocale(lettera)) cout << lettera << ": vocale\n" ;
	else cout << lettera << " altro \n" ;
	return 0;
}

// isalnum(x): alfanumerico (numeri e letere)
// isdigit(x): numerico
// toupper(x) x in upper case (evito i 5 controlli sulle vocali minuscole)
