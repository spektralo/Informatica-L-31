#include<iostream>
using namespace std;

int ContaVocali(const string& input){
    
    return 0;
}

int main(int argc, const char** argv) {
    string S = "culo";
    double A = 5.7;
    cout << A << endl;
    int B = int(A);
    cout << B << endl;
    cout << S.at(0) << endl;
    S.clear();
    S = "Matteo Renzi";
    cout << S <<endl;
    cout << S.find("Renzi") << endl;
    cout << S.size() << endl;
    cout << S.length() << endl;
    cout << S.substr(0, 6);
    return 0;
}