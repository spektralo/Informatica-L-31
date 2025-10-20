#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, const char** argv) {
    ifstream fileRead("C:/Users/HP/Desktop/Programmazione II/test.txt");
    ofstream fileWrite("C:/Users/HP/Desktop/Programmazione II/input.txt");
    string messaggio = "Stringa di prova";
    fileWrite << messaggio;

    char c;
    string S;

    if (fileRead.is_open()){
        cout << "Ok" << endl;
    }
    else fileRead.close();

    while(fileRead.good())
    {
        fileRead.get(c);
        cout << c;
    }

    /*
    while (fileRead.get(c))
    {
        cout << c;
    }

    while (fileRead >> (S)) 
    {
        cout << S;
    }

    while(getline(fileRead,S))
    {
        cout << S << endl;
    }
    
     */


    return 0;
 }