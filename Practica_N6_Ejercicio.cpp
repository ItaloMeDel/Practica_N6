#include <iostream>

using namespace std;

class Alumn{
    private:
        string Name;
        int Age;            // Atributos privados de la clase
        float Average;

    public:
        Alumn(string N = "", int Ag = 0, float Av = 0.0){ // Constructor
            Name = N;
            Age = Ag;
            Average = Av;
        }

        Alumn &SetName(string N){       // Colocar nombre
            Name = N;
            return *this;
        }
        Alumn &SetAge(int A){           // Colocar edad
            Age = A;
            return *this;
        }

        Alumn &SetAverage(float A){     // Colocar promedio
            Average = A;
            return *this;
        }

        string GetName(){               // Obtener nombre
            return Name;
        }

        int GetAge(){                   // Obtener edad
            return Age;
        }

        float GetAverage(){             // Obtener promedio
            return Average;
        }

        void toString(){                // Entregar información
            cout << "\tName: " << Name << endl;
            cout << "\tAge: " << Age << endl;
            cout << "\tAverage: " << Average << endl;
        }
};

ostream &operator << (ostream &Os, Alumn &A){       // Sobrecarga de operador <<<
    A.toString();
    return Os;
}

class Group{
    private:
        string Name;
        Alumn *AlumnList;                   // Atributos privados de clase
        Alumn BestAlumnOfGroup;
        int Amount, Index = 0;

    public:
        Group(string N, int A){                         // Constructor
            Name = N;
            Amount = A;
            AlumnList = new Alumn[Amount];
        }

        void AddAlumn(string N, int Ag, float Av){      // Añadir alumno
            if (Index < Amount){
                Alumn NewAlumn(N, Ag, Av);
                AlumnList[Index] = NewAlumn;
                Index ++;
            }
            else{
                cout << "The group is full. " << endl;
            }

        }

        void SortByAverage(bool Reverse = false){       // Ordenar alumnos por promedio
            bool Controler = true;
            if (Reverse){
                while (Controler){
                    Controler = false;
                    for (int i = 0; i < Index - 1; i++){
                        if (AlumnList[i].GetAverage() < AlumnList[i + 1].GetAverage()){
                            Alumn Aux = AlumnList[i];
                            AlumnList[i] = AlumnList[i + 1];
                            AlumnList[i + 1] = Aux;
                            Controler = true;
                        }
                    }
                }
            }
            else{
                while (Controler){
                    Controler = false;
                    for (int i = 0; i < Index - 1; i++){
                        if (AlumnList[i].GetAverage() > AlumnList[i + 1].GetAverage()){
                            Alumn Aux = AlumnList[i];
                            AlumnList[i] = AlumnList[i + 1];
                            AlumnList[i + 1] = Aux;
                            Controler = true;
                        }
                    }
                }
            }
        }

        void AddAlumn(Alumn &A){                        // Añadir alumno
            if (Index < Amount){
                AlumnList[Index] = A;
                Index++;
            }
            else{
                cout << "The group is full. " << endl;
            }
        }

        void toString(){                                // Entregar información
            cout << "Group name: " << Name << endl << endl;
            for (int i = 0; i < Index; i++){
                cout << AlumnList[i] << endl;
            }
            cout << "Average Group: " << AverageGroup();
        }

        float AverageGroup(){                           // Entregar el promedio grupal
            float AverageGroup;
            for (int i = 0; i < Index; i++){
                AverageGroup += AlumnList[i].GetAverage();
            }
            return AverageGroup/Index;
        }

        Alumn &BestAlumn(){                             // Entregar el mejor alumno
            BestAlumnOfGroup = AlumnList[0];
            for (int i = 1; i < Index; i++){
                if (BestAlumnOfGroup.GetAverage() < AlumnList[i].GetAverage()){
                    BestAlumnOfGroup = AlumnList[i];
                }
            }
            return BestAlumnOfGroup;
        }
};

ostream &operator << (ostream &Os, Group &G){           // Sobrecarga de operador <<
    G.toString();
    return Os;
}

int main(){
    Group Aula205("Aula 205", 5);
    Alumn Juan("Juan Alimaña", 21, 14.35);
    Alumn Pablo("Pablo Benavides", 17, 19.35);
    Aula205.AddAlumn(Juan);
    Aula205.AddAlumn(Pablo);
    Aula205.AddAlumn("Pedro Palotes", 19, 17.5);
    Aula205.AddAlumn("Maria Mercedes", 20, 12.5);
    Aula205.AddAlumn("Jose Peralta", 20, 4.5);
    Aula205.SortByAverage(true);
    cout << Aula205;
    cout << endl << "------------------------------------" << endl;
    Aula205.SortByAverage();
    cout << Aula205;
    cout << endl << "------------------------------------" << endl;
    cout << "Best alumn: " << endl << Aula205.BestAlumn();
}
