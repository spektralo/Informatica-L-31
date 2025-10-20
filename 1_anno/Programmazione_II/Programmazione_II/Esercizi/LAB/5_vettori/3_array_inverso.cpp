// 6.10
#include <iostream>
using namespace std;

int vettore[10] = {34,56,43,23,21,67,89,55,44,33};
int invertito[10];

int main() {

	for (int i=0; i<10; i++) invertito[i] = vettore[9-i];	
	for (int i=0; i<10; i++) cout << invertito[i] << ' ';
	cout << endl;
	return 0;
}
