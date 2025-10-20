#include<iostream>
#include<array>
using namespace std;

int riempiArray(array<int, 10> &arr, int &value, size_t &pos){
    if(pos>=0 && pos<arr.size())
    {
    arr.at(pos) = value;
    return 0; }

    return 1;
}

int main(int argc, const char** argv) {

    const size_t size = 10;
    array<int,size> arr;

    cout << "Inserisci 10 valori" << endl;
    /*
    for (int i = 0; i < size; i++)
    {
        cin >> arr.at(i);  //o implementare la funzione riempiArray (che non funziona)
    }
    */
    
    for (auto i : arr){
    cout << i << endl;
}
    return 0;
}