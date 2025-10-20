#include <iostream>
using namespace std;
  
// template di funzione per l'ordinamento bubblesort
//<class T> mi permette di "astrarre" la classe degli elementi di a[]
template <class T> void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              swap(a[j], a[j - 1]);
}
  
int main() {
    //int a[5] = {10, 50, 30, 40, 20};
    char a[5] = {'x', 'z', 'y', 'a', 'b'};
    int n = sizeof(a) / sizeof(a[0]); 
    //bubbleSort<int>(a, n);
    bubbleSort<char>(a, n);
    cout << " Vettore ordinato : ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
  return 0;
}
