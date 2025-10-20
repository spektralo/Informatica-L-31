#include <iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	if ( x >= y ) 
		if ( y >= z) cout << " maggiore: " << x << endl;
		else if (x > z) cout << " maggiore: " << x << endl;
		     else cout << " maggiore:  " << z << endl;
	else if ( y >= z) cout << " maggiore: " << y << endl;
		 else cout << " maggiore: " << z << endl;
	return 0;
}

//ricerca del max


