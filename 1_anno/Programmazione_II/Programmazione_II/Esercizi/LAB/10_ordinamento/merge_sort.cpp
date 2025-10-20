#include <iostream>
using namespace std;
 
// Esegue il merging di 2 subarray.
// Il primo � [begin..mid]
// Il secondo � arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Crea 2 array temporanei
    int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copia i dati sugli array temporanei
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, // Indice iniziale del primo subarray
        indexOfSubArrayTwo = 0; // Indice iniziale del secondo subarray
    int indexOfMergedArray = left; // Indice iniziale dell'array merged
 
    // Esegue il merge degli array temporanei in array[left..right]
    while (indexOfSubArrayOne < subArrayOne  && indexOfSubArrayTwo < subArrayTwo) 
    {

        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
	   {
            array[indexOfMergedArray]  = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else 
	   {
            array[indexOfMergedArray]  = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        

        indexOfMergedArray++;
    }
    // Copia gli elementi rimanenti di left sull'array merged se ne esistono
    while (indexOfSubArrayOne < subArrayOne) 
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copia gli elementi rimanenti di right sull'array merged se ne esistono
    while (indexOfSubArrayTwo < subArrayTwo) 
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin � l'indice sinistro del subarray e end � l'indice destro del subarray da ordinare */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    int mid = begin + (end - begin) / 2; //elemento medio
    mergeSort(array, begin, mid); //primo sottoarray
    mergeSort(array, mid + 1, end); //secondo sottoarray
    merge(array, begin, mid, end);
}
 
// FUNZIONE PRINT
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
// Codice di esempio
int main()
{
	//array da ordinare
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    
    
    float arr_size = sizeof(arr) / sizeof(arr[0]);
 	/*cout << sizeof(arr);  //24 byte
 	cout << "\n";
 	cout << sizeof(arr[0]); // 4byte
 	cout << "\n";
 	cout << arr_size;       //6
 	cout << "\n";*/
    cout << "Given array is \n";
    printArray(arr, arr_size);
 	
 	//Eseguo il merge passando gli indici (0,5)
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
 
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
