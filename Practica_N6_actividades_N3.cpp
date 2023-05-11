#include <iostream>

using namespace std;


class AccBank{
    private:
        friend class Bank;
        string NumAccount, Owner;
        double Balance;

        void SetNumAccount(string NA){
            NumAccount = NA;
        }

        string GetNumAccount(){
            return NumAccount;
        }

        void SetOwner(string O){
            Owner = O;
        }

        string GetOwner(){
            return Owner;
        }

        void SetBalance(double B){
            Balance = B;
        }

        double GetBalance(){
            return Balance;
        }

    public:
        AccBank(string NA, string O, double B){
            NumAccount = NA;
            Owner = O;
            Balance = B;
        }

};


class Bank{
    private:
        static double InteresRate;
        string Name;
        double Balance;

    public:
        Bank(string N, double B){
            Name = N;
            Balance = B;
        }
        void MakeDeposit(AccBank &AC, double B){
            if(AC.GetBalance() > B){
                AC.SetBalance(AC.GetBalance() - (B + B * InteresRate));
                Balance += B;
            }
            else{
                cout << "Insufficient Balance" << endl;
            }
        }

        void MakeWithdrawal(AccBank &AC, double B){
            AC.SetBalance(AC.GetBalance() + B);
        }

        void SetName(string N){
            Name = N;
        }

        string GetName(){
            return Name;
        }

        void SetBalance(double B){
            Balance = B;
        }

        double GetBalance(){
            return Balance;
        }

        double GetAccBalance(AccBank &AC){
            return AC.GetBalance();
        }
};

double Bank::InteresRate = 0.18;

int main(){
    AccBank Acc01("109284732828", "Juan Alimaña", 10000.12);
    Bank BBVA("BBVA", 92898923.23);
    BBVA.MakeDeposit(Acc01, 900);
    cout << BBVA.GetAccBalance(Acc01);
    return 0;
}
