#include <iostream>
using namespace std;
class Circle;

class Information{
    private:
        string Owner;
    public:
        Information(string O){
            Owner = O;
        }
        double GetRadius(Circle &);
};

class Circle{
    private:
        double Radius, Diameter;
    public:
        Circle (double D){
            Radius = D/2;
            Diameter = D;
        }

        void SetDiameter(double D){
            Diameter = D;
        }

        double GetDiameter(){
            return Diameter;
        }

        void SetRadius(double R){
            Radius = R;
        }
        double GetRadius(){
            return Radius;
        }
        friend double Information::GetRadius(Circle &);
};

double Information::GetRadius(Circle &C){
    return C.GetRadius();
}

double Calculate(Circle &C){
    return C.GetRadius() * C.GetRadius() *3.1416;
}

int main(){
    Circle C01(15.4);
    Circle C02(20.4);
    Information I("Juan Alimaña");
    cout << I.GetRadius(C01) << endl;
    cout << I.GetRadius(C02) << endl;
    cout << Calculate(C01);
    return 0;
}
