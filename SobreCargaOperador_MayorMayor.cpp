//Sobrecarga de >> 
#include <iostream>
using namespace std;

class numero{
    private:
        int num;
    public:
        numero(int num){
            this -> num = num;
        }
        int GetNumero(){
            return num;
        }
};
int operator >> (numero n1, numero n2){
    int mayor;
    if (n1.GetNumero() > n2.GetNumero()){
        mayor = n1.GetNumero();
    }
    else if (n1.GetNumero() < n2.GetNumero()){
        mayor = n2.GetNumero();
    }
    return mayor;
}

int main(){
    numero n1(40);
    numero n2(45);
    int respuesta = n1 >> n2;
    cout << respuesta << endl;
    return 0;
}
