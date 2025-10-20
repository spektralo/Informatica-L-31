/*
Si richiede di scrivere un programma in C++ che gestisca dinamicamente un array e consenta all'utente
di inserire valori nell'array uno alla volta. L'inserimento dei valori deve essere interrotto quando l'utente
inserisce il valore zero. Durante l'inserimento, il programma deve verificare se c'� spazio sufficiente
nell'array. Nel caso in cui lo spazio disponibile stia per esaurirsi, il programma deve riallocare un nuovo
array di dimensioni leggermente maggiori rispetto all'array attuale e copiare gli elementi inseriti fino a
quel momento nel nuovo array.
� Il programma deve inizializzare un array dinamico con una dimensione iniziale pari a 3.
� Deve chiedere all'utente di inserire valori nell'array uno alla volta, terminando l'inserimento quando
l'utente inserisce il valore zero.
� Durante l'inserimento, il programma deve verificare se c'� spazio sufficiente nell'array. Se non c'�
spazio, deve riallocare un nuovo array di dimensioni leggermente maggiori rispetto all'array attuale
e copiare gli elementi inseriti fino a quel momento nel nuovo array.
� Alla fine dell'inserimento, il programma deve stampare gli elementi dell'array.
*/

/*
  BONUS: Usare un array di caratteri. Verificare che la stringa costituita dai caratteri dell'array sia palindroma.
*/


#include <iostream>

using namespace std;


void resize(char*& arr, size_t& oldcapacity, const size_t& newcapacity)
{
	char* newarr = new char[newcapacity];
	for (int i = 0; i < oldcapacity; i++)	
		newarr[i] = arr[i];
	
	delete[] arr;
	arr = newarr;
	oldcapacity = newcapacity;
}

void insert(char* &arr, size_t &capacity, size_t &size, const int &value, const size_t &increment)
{
	if (capacity == size)	
	  resize(arr, capacity, capacity+increment);		
	
	arr[size] = value;
	size++;	
}

bool checkPalindrom(const char* arr, const size_t size)
{
	if (size <= 1)
		return false;

	for (int i = 0; i < size / 2; i++)
		if (arr[i] != arr[size - 1 - i])
			return false;
	return true;
}

int main()
{
	size_t size = 0;
	size_t capacity = 3;
	const size_t increment = 3;
	char* arr = new char[capacity];
	char val;
	while (cin >> val && val!='0')	
		insert(arr, capacity, size, val, increment);	
	
	for (int i = 0; i < size; i++)	
		cout << arr[i] << endl;
	
	bool palindrom = checkPalindrom(arr, size);
	cout << (palindrom ? "Stringa palindroma": "Stringa non palindroma") << endl;	
	
}