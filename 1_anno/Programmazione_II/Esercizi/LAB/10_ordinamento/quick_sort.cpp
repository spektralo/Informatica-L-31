#include <bits/stdc++.h>
using namespace std;
 
// Questa funzione prende come pivot l'ultimo elemento,
// posiziona il pivot, e mette tutti gli elementi + piccoli alla sua sinistra
// e tutti gli elementi + grandi alla sua destra
int partition(int arr[], int low, int high)
{
    // Seleziono il pivot
    int pivot = arr[high];
 
    // Indice associato all'ultimo elemento tra gli elementi 
    // più piccoli del pivot (all'inizio è null)
    int i = (low - 1);
 
 	//Scorro gli elementi dell'array
    for (int j = low; j <= high - 1; j++) {
 
        // Se l'elemento è più piccolo del pivot
        if (arr[j] < pivot) {
 
            // Incremento l'indice dell'elemento più piccolo
            i++;
            //ed eseguo lo swap tra l'elemento corrente ed il primo dell'array 
		  //contenente gli elementi più grandi del pivot
            swap(arr[i], arr[j]);
        }
    }
    //alla fine del for inverto l'ultimo elemento ed il primo dell'array 
    //contenente gli elementi più grandi del pivot
    swap(arr[i + 1], arr[high]);
    
    //il valore i+1 mi indica l'indice alla destra del quale ci sono valori maggiori rispetto
    // al valore che si trova in i+i ed a sinistra minori
    return (i + 1);
}
 
// low è l'indice sinistro del subarray e high è l'indice destro del subarray da ordinare */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
 
        // pi mi indica l'indice alla destra del quale ci sono valori maggiori rispetto
    	// al valore che si trova in i+i ed a sinistra minori
        int pi = partition(arr, low, high);
 
        // Ordino separatamente gli elementi + piccoli
        // e quelli più grandi
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
 
 // FUNZIONE PRINT
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}


// Codice di prova
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    cout << "Given array is \n";
    printArray(arr, N);
    
    quickSort(arr, 0, N - 1);
    cout << "\nSorted array: " << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    return 0;
}
