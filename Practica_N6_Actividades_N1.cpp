#include <iostream>

using namespace std;

class Note{
    private:
        double Value;

    public:
        Note(double V){
            Value = V;
        }

        void SetValue(double V){
            Value = V;
        }

        double GetValue(){
            return Value;
        }
};

class Student{
    private:
        string Name, Code, DNI; 
        int Age, Size = 0;
        double Average = 0;
        Note *Notes[100] = {NULL};

        void CalculateAverage(){
            double A = 0;
            for (int i = 0; i < Size; i++){
                A += Notes[i] -> GetValue();
                Average = A / Size;
            }
        }

    public:
        Student(string N, string C, string D, int A){
            Name = N;
            Code = C;
            DNI = D;
            Age = A;
        }


        void SetName(string N){
            Name = N;
        }

        string GetName(){
            return Name;
        }

        void SetCode(string C){
            Code = C;
        }

        string GetCode(){
            return Code;
        }

        void SetAge(int A){
            Age = A;
        }

        int GetAge(){
            return Age;
        }

        void SetDNI(string D){
            DNI = D;
        }

        string GetDNI(){
            return DNI;
        }

        double GetAverage(){
            return Average;
        }

        bool AddNote(double N){
            if (((N < 20) and (N > 0)) and (Size < 100)){
                Notes[Size] = new Note(N);
                Size++;
                CalculateAverage();
                return true;
            }
            return false;
        }

};

bool operator < (Student &A, Student &B){
    return A.GetAverage() < B.GetAverage();
}

bool operator > (Student &A, Student &B){
    return A.GetAverage() > B.GetAverage();
}

void Sort(Student **S, int size, bool Reverse = false){
    bool Controler = true;
    if (Reverse){
        while (Controler){
            Controler = false;
            for (int i = 0; i < size - 1; i++){
                if (S[i] -> GetAverage() < S[i + 1] -> GetAverage()){
                    Student *Aux = S[i];
                    S[i] = S[i + 1];
                    S[i + 1] = Aux;
                    Controler = true;
                }   
            }
        }
    }
    else{
        while (Controler){
            Controler = false;
            for (int i = 0; i < size - 1; i++){
                if (S[i] -> GetAverage() > S[i + 1] -> GetAverage()){
                    Student *Aux = S[i];
                    S[i] = S[i + 1];
                    S[i + 1] = Aux;
                    Controler = true;
                }
            }
        }
    }
}





int main(){
    system("cls");
    Student **Aula205 = new Student*[2];
    Aula205[0] = new Student("Italo Medina", "20123546", "78964412", 17);
    Aula205[1] = new Student("Pedro Palotes", "78962863", "79621456", 18);

    Aula205[0] -> AddNote(14.2);
    Aula205[1] -> AddNote(12.6);
    Aula205[1] -> AddNote(13.6);
    Aula205[0] -> AddNote(5);
    Aula205[0] -> AddNote(19.2);

    Sort(Aula205, 2);
    for (int i = 0; i < 2; i++){
        cout << "\nNombre: " << Aula205[i] -> GetName() << "\nPromedio: " << Aula205[i] -> GetAverage() << endl;
    }
    cout << endl << endl;
    
    Sort(Aula205, 2, true);
    for (int i = 0; i < 2; i++){
        cout << "\nNombre: " << Aula205[i] -> GetName() << "\nPromedio: " << Aula205[i] -> GetAverage() << endl;
    }

    system("pause");
    delete Aula205;
}   
