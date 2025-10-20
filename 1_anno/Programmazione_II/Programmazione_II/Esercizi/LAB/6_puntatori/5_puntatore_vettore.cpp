#include <iostream>
using namespace std;


int main() {
	int vettore[10]={1,2,3,4,5,6,7,8,9,10};
	for (int i=1; i<10; i=i+2) 
		cout << *(vettore +i) << ' ';
	return 0;
}

//output?


