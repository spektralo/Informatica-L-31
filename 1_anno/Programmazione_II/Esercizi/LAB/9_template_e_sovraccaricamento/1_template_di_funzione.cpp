#include <iostream>  
using namespace std;


//TEMPLATE DI FUNZIONE	
template <typename T> int confronta(T &v1, T &v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main() {
	int int1, int2;
	cin >> int1 >> int2;
	cout << "il primo risulta essere " ;
	if (!(confronta(int1, int2))) cout << " uguale al secondo\n";
	if ((confronta(int1, int2))== -1) cout << " minore del secondo\n";
	if ((confronta(int1, int2))== 1) cout << " maggiore del secondo\n";
	float f1, f2;
	cin >> f1 >> f2;
	cout << "il primo risulta essere " ;
	if (!(confronta(f1, f2))) cout << " uguale al secondo\n";
	if ((confronta(f1, f2))== -1) cout << " minore del secondo\n";
	if ((confronta(f1, f2))==1) cout << " maggiore del secondo\n";
	char c1, c2;
	cin >> c1 >> c2;
	cout << "il primo risulta essere " ;
	if (!(confronta(c1, c2))) cout << " uguale al secondo\n";
	if ((confronta(c1, c2))== -1) cout << " minore del secondo\n";
	if ((confronta(c1, c2))== 1) cout << " maggiore del secondo\n";
	/*int a1;
	char a2;
	cin >> a1 >> a2;
	cout << "il primo risulta essere " ;
	if (!(confronta(a1, a2))) cout << " uguale al secondo\n";
	if ((confronta(a1, a2))== -1) cout << " minore del secondo\n";
	if ((confronta(a1, a2))== 1) cout << " maggiore del secondo\n";
	return 0;*/
}

//cosa succede se decommento?
