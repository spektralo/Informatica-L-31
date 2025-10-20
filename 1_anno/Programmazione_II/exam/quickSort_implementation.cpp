//#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    // Seleziono il pivot
    int pivot = arr[r];
    int i = (l - 1);
 
 	//Scorro gli elementi dell'array
    for (int j = l; j <= r - 1; j++) {
 
        // Se l'elemento � pi� piccolo del pivot
        if (arr[j] < pivot) {
 
          
            i++;
           
            swap(arr[i], arr[j]);
        }
    }
 
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}


// low � l'indice sinistro del subarray e high � l'indice destro del subarray da ordinare */
void quickSort(int arr[], int l, int r)
{
    if (l < r) {
 
        // pi mi indica l'indice alla destra del quale ci sono valori maggiori rispetto
    	// al valore che si trova in i+i ed a sinistra minori
        int p = partition(arr, l, r);
 
        // Ordino separatamente gli elementi + piccoli
        // e quelli pi� grandi
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}
 