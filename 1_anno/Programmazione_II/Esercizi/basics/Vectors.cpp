#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;

void func(vector<int> vec);


int main(int argc, const char** argv) {

    vector <int> nums = {10,20,30}; //declaration and allocation

   /*
    nums.pop_back(); //remove element at end of vector
    nums.push_back(40); //add element at end of vector

    nums.insert(nums.begin(), 5);
    nums.insert(nums.begin() + 1, 0);   //functions to add an element

    nums.erase(nums.begin() + 1);       //function to delete an element
    nums.clear(); //clear the vector completely
   */ 
    
    func(nums);

    return 0;
}


void func(vector <int> vec){

    for (int numero : vec )
    {
        std::cout << numero << std::endl;  
    }
}