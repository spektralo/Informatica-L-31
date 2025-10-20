#include<iostream>
using namespace std;

class Camera{
    protected:
    int numCamera;
    double prezzoNotte;
    bool occupata;

    Camera(int numCamera, double prezzoNotte, bool occupata) : numCamera(numCamera), prezzoNotte(prezzoNotte), occupata(occupata) {}
    ~Camera(){}

    virtual void mostraInfo() const { cout << numCamera << prezzoNotte << occupata <<  endl;}

    void occupaCamera(){ 
        cout<< "La camera è stata occupata "<< endl;
        occupata = true;
    }

    bool disponibile() const {
        if(occupata == false){
            cout << "La camera è disponibile" << endl;
            return true;}
    }

    friend std::ostream& operator << (std::ostream& os, const Camera& cam ){
        os << cam.numCamera << cam.prezzoNotte << cam.occupata;
        return os;
    };
};

class CameraSingola:public Camera{
    public:
    CameraSingola(int numCamera, double prezzoNotte, bool occupata) : Camera(numCamera, prezzoNotte, occupata){}
    ~CameraSingola(){}

    

};


int main(){

    return 0;
}