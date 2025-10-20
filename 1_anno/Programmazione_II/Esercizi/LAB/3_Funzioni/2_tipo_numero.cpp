// 5.3

#include <iostream>
using namespace std;

char Positivo(int i) {
	if (i >= 0 ) return 'P';
	return 'N';
} 

int main() {
	int  intero;
	cin >> intero;
	cout << intero << ": " << Positivo(intero) << endl;
	return 0;
}

//0.5?
//return 'Pos' (?)


