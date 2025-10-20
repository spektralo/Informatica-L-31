#include<iostream>
#include <array> //libreria per gli array
#include<vector>
using namespace std;

int main(int argc, const char** argv) {
    const size_t size = 10;
    array <int, size> arr; // syntax : array<type,size>nome;
for (int i = 0; i < size; i++)
{
    //arr[i]=i;     equivalenti
    //arr.at(i) = i;
}
for (int i = 0; i < arr.size(); i++){
    cout << arr.at(i) << endl;
}

for (int value : arr)  //type specifier can be omitted with auto keyword: for(auto value : arr):
{
    cout << value << endl;
}

for(array<int,size>::iterator it=arr.begin(); it !=arr.end(); it++) 
{
    cout<< *it << " " << distance(arr.begin(), it) << endl; 
}

    vector<int>vec(size);
    for(int i = 0; i < vec.size(); i++){
        vec.at(i) = i + 2;
    }

    vec.push_back(123);
    vec.pop_back();
    vec.clear();
    cout << vec.size() << endl;

    for(auto i : vec){
        cout << i <<endl;}

    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        cout << *it << " " << distance(vec.begin(), it) << endl;
    }




    return 0;
}