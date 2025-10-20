#include <iostream>  
using namespace std;

unsigned lung_string(char* s) {
	unsigned i = 0;
	//scorro il riferimento all'array di carattteri
	while (*(s+i)!= '\0') i++;
	return i;
}

int main () {
char var_str0[10] ="Ciao";
char var_str1[10] = {'C','i','a','o'};
char var_str2[10]= { 'C','i','a','o','\0'};
char var_str3[5]= "Ciao";
char var_str4[]= "Ciao";
cout << var_str0[4] << endl;
cout << var_str1[4] << endl;
cout << var_str2[4] << endl;
cout << var_str3[4] << endl;
cout << var_str4[4] << endl;
cout << lung_string(var_str0) << endl;
cout << lung_string(var_str1) << endl;
cout << lung_string(var_str2) << endl;
cout << lung_string(var_str3) << endl;
cout << lung_string(var_str4) << endl;
cout << var_str0 << endl;
cout << var_str1 << endl;
cout << var_str2 << endl;
cout << var_str3 << endl;
cout << var_str4 << endl;
	return 0;
}

// in quinta posizione hanno tutte il carattere vuoto '\0'.
// hanno tutti la stessa lunghezza?


