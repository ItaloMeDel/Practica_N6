#include <iostream>

using namespace std;

class Alumno{
    private:
        double nota;

    public:
        Alumno(double nota){
            this -> nota = nota;
        }
        double GetNota(){
            return nota;
        }
};

double operator * (Alumno A, Alumno B){
    double promedio = (A.GetNota() + B.GetNota()) / 2;
    return promedio;
}

int main(){
    Alumno Al1(20);
    Alumno Al2(14);
    double Mayor = Al1 * Al2;
    cout << Mayor << endl;
}
