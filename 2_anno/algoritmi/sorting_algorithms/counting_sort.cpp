#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& A, vector<int>& B, int k) {
    int n = A.size();
    vector<int> C(k + 1, 0);  // array C[0..k] inizializzato a 0

    // 1°step: conto le occorrenze di ciascun valore in A
    for (int j = 0; j < n; j++) {
        C[A[j]] = C[A[j]] + 1;
    }

    // 2°step: calcola il numero cumulativo di elementi
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    // 3°step: costruzione dell'array ordinato B (versione stabile)
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}

int main() {
    // Esempio di utilizzo

    vector<int> A = {2, 5, 3, 0, 2, 3, 0, 3}; //array da ordinare
    int k = 5;  // valore massimo presente nell'array

    vector<int> B(A.size()); //array di output

    cout << "Array disordinato: ";
     for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }

    countingSort(A, B, k); //applico algoritmo

    cout << "\nArray ordinato: ";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
