#include <iostream>  
#include <cstring>  
using namespace std;

int main () {
	char var_str1[]= "Ciao";
	char var_str2[]= " e arrivederci";
	//concatenazione (strcat dalla libreria cstring)
	strcat(var_str1, var_str2);
	cout << var_str1 << endl;
	cout << var_str2 << endl;
	return 0;
}

// Output di var_str1?
// E di var_str2?





