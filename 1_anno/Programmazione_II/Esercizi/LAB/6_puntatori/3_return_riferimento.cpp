#include <iostream>
using namespace std;

float& componente(float *v, int k) {
	return v[k-1];
}

int main() {
	float v[5];
	//riempimento array
	for (int k = 1; k <= 5; k++) 
		//v è il puntatore al primo elemento dell'array v, k valore da 1 a 5
		componente(v,k) = k;
		
	//stampa valore dell'array riempito	
	for (int i = 0; i < 5; i++) cout << "v[" << i<< "] = " 
	                                 << v[i] << endl;
}

//output?


