#include <iostream>
using namespace std;

bool Perfetto (int n) {
	int i, acc = 0;
	for (i=1; i<n; i++) 
	if (n % i == 0) 
	acc += i;
	return (acc == n);
}

int main() {
	int  intero;
	cin >> intero;
	if (Perfetto(intero)) cout << intero << ": numero perfetto\n";
	else cout << intero << ": numero non perfetto\n";
	return 0;
}

//Un numero perfetto è un numero che è uguale alla somma dei suoi divisori positivi, escludendo il numero stesso
// 6 è divisibile per 6,3,2,1 - 3+2+1=6
// 28 è divisibile per 28,14,7,4,2,1 - 14+7+4+2+1=28

//if individua il divisore
// da notare la mancanza di parentesi alla riga 6

