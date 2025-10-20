#include <iostream>
using namespace std;

bool divisibile(int m, int n) {
	if (m % n) return false;
	else return true;
}

int main() {
	int  a, b;
	cin >> a >> b;
	if (divisibile(a,b)) cout << a << " risulta divisibile per " << b << endl;
	else cout << a << " non risulta divisibile per " << b << endl;
	return 0;
}

//m%n
