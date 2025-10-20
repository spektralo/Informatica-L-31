#include<iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>

/*
T avg(T arr[], T size){
    T media;
    T pivot;
    for (int i = 0; i < size; i++)
    {
        pivot = arr[i];
        media = pivot;
    }
    return (media / size);
}
*/


/*
T sum(T x, T y){
    return x + y;
}

*/

T find(T arr[], int size, T elem){
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] == elem)
        {
            std::cout << "elem found at index: " << i << std::endl;
        }
    }
}



int main(int argc, char const *argv[])
{
    /*
    std::cout << sum<int>(5,10) << std::endl;
    std::cout << sum<float>(4.2,18) << std::endl;
    int arr[] = {10,27,36};
    std::cout << avg<int>(arr,3) << std::endl;    
    */
    int arr[] = {10,20,57,89};
    find(arr,4,89);
    return 0;
}
