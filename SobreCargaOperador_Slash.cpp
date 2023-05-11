#include <iostream>
#include <cmath>
using namespace std;

class ParOrd{
    private:
        int const X;
        int const Y;
    public:
        ParOrd(int NX, int NY):X(NX), Y(NY){}  
        int GetX(){
            return X;
        }

        int GetY(){
            return Y;
        }
};

double operator / (ParOrd A, ParOrd B){
    double Result = (A.GetX() - B.GetX()) * (A.GetX() - B.GetX()) + (A.GetY() - B.GetY()) * (A.GetY() - B.GetY());
    Result = sqrt(Result);
    return Result;
}

int main(){
    ParOrd A(0, 0);
    ParOrd B(3, 4);
    double C = A / B;
    cout << C << endl;
