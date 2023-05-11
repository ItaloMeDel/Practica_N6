#include <iostream>

using namespace std;

struct Node{
    double FirstValue;    // Posición
    double SecondValue;
    Node *Next = NULL;
    Node(double FV, double SV){
        FirstValue = FV;
        SecondValue = SV;
    }
};

// Base de los nodos


class Vector2D{
    private:
        Node *Head = NULL;
    
    public:
        Node *GetHead(){
            return Head;
        }

        void append(double FV, double SV){
            Node *NewNode = new Node(FV, SV);
            if(Head == NULL){
                Head = NewNode;
            }
            else{
                Node *AuxNode1 = Head;
                Node *AuxNode2 = NULL;
                while (not(AuxNode1 == NULL)){
                    AuxNode2 = AuxNode1;
                    AuxNode1 = AuxNode1 -> Next;
                }
                AuxNode2 -> Next = NewNode;
            }
        }

        void clear(){
            Head = NULL;
        }

        void remove(double FR, double SR){
            Node *AuxNode1 = Head;
            Node *AuxNode2;
            if (Head == NULL){
                cout << "Empty list" << endl;
            }
            else{
                while ((not((AuxNode1 -> FirstValue == FR) and (AuxNode1 -> SecondValue == SR))) or (AuxNode1 == NULL)){
                    AuxNode2 = AuxNode1;
                    AuxNode1 = AuxNode1 -> Next;
                }
                if (AuxNode1 -> FirstValue == FR){
                    AuxNode2 -> Next = AuxNode1 -> Next;
                    delete AuxNode1;
                }
            }
        }
};

ostream &operator << (ostream &Os, Vector2D V){
    Node *AuxNode = V.GetHead();
    bool Regulator = true;
    cout << "[";
    while(not(AuxNode == NULL)){
        if (Regulator){
            cout << "[" << AuxNode -> FirstValue << ", " << AuxNode -> SecondValue << "]";
            Regulator = false;
        }
        else{
            cout << ", " << "[" << AuxNode -> FirstValue << ", " << AuxNode -> SecondValue << "]";
        }
        AuxNode = AuxNode -> Next;
    }
    cout << "]";
    return Os;
}

Vector2D operator + (Vector2D &V1, Vector2D &V2){
    Vector2D NewVector;
    Node *AuxFirstNode = V1.GetHead();
    Node *AuxSecondNode = V2.GetHead();

    while (not((AuxFirstNode == NULL) and (AuxSecondNode == NULL))){
        if (AuxFirstNode == NULL){
            double FirstValue = AuxSecondNode -> FirstValue;
            double SecondValue = AuxSecondNode -> SecondValue;
            NewVector.append(FirstValue,  SecondValue);
            AuxSecondNode = AuxSecondNode -> Next;
        }
        else if (AuxSecondNode == NULL){
            double FirstValue = AuxFirstNode -> FirstValue;
            double SecondValue = AuxFirstNode -> SecondValue;
            NewVector.append(FirstValue,  SecondValue);
            AuxFirstNode = AuxFirstNode -> Next;
        }
        else{
            double FirstValue = AuxFirstNode -> FirstValue + AuxSecondNode -> FirstValue;
            double SecondValue = AuxFirstNode -> SecondValue + AuxSecondNode -> SecondValue;
            NewVector.append(FirstValue,  SecondValue);
            AuxFirstNode = AuxFirstNode -> Next;
            AuxSecondNode = AuxSecondNode -> Next;
        }
    }
    return NewVector;
}

Vector2D operator - (Vector2D &V1, Vector2D &V2){
    Vector2D NewVector;
    Node *AuxFirstNode = V1.GetHead();
    Node *AuxSecondNode = V2.GetHead();

    while (not((AuxFirstNode == NULL) and (AuxSecondNode == NULL))){
        if (AuxFirstNode == NULL){
            double FirstValue = AuxSecondNode -> FirstValue * (-1);
            double SecondValue = AuxSecondNode -> SecondValue * (-1);
            NewVector.append(FirstValue,  SecondValue);
            AuxSecondNode = AuxSecondNode -> Next;
        }
        else if (AuxSecondNode == NULL){
            double FirstValue = AuxFirstNode -> FirstValue;
            double SecondValue = AuxFirstNode -> SecondValue;
            NewVector.append(FirstValue,  SecondValue);
            AuxFirstNode = AuxFirstNode -> Next;
        }
        else{
            double FirstValue = AuxFirstNode -> FirstValue - AuxSecondNode -> FirstValue;
            double SecondValue = AuxFirstNode -> SecondValue - AuxSecondNode -> SecondValue;
            NewVector.append(FirstValue,  SecondValue);
            AuxFirstNode = AuxFirstNode -> Next;
            AuxSecondNode = AuxSecondNode -> Next;
        }
    }
    return NewVector;
}

Vector2D operator * (Vector2D &V1, Vector2D &V2){
    Vector2D NewVector;
    Node *AuxFirstNode = V1.GetHead();
    Node *AuxSecondNode = V2.GetHead();

    while (not((AuxFirstNode == NULL) and (AuxSecondNode == NULL))){
        if (AuxFirstNode == NULL){
            double FirstValue = 0;
            double SecondValue = 0;
            NewVector.append(FirstValue,  SecondValue);
            AuxSecondNode = AuxSecondNode -> Next;
        }
        else if (AuxSecondNode == NULL){
            double FirstValue = 0;
            double SecondValue = 0;
            NewVector.append(FirstValue,  SecondValue);
            AuxFirstNode = AuxFirstNode -> Next;
        }
        else{
            double FirstValue = AuxFirstNode -> FirstValue * AuxSecondNode -> FirstValue;
            double SecondValue = AuxFirstNode -> SecondValue * AuxSecondNode -> SecondValue;
            NewVector.append(FirstValue,  SecondValue);
            AuxFirstNode = AuxFirstNode -> Next;
            AuxSecondNode = AuxSecondNode -> Next;
        }
    }
    return NewVector;
}

Vector2D operator / (Vector2D &V1, Vector2D &V2){
    Vector2D NewVector;
    Node *AuxFirstNode = V1.GetHead();
    Node *AuxSecondNode = V2.GetHead();

    while (not((AuxFirstNode == NULL) and (AuxSecondNode == NULL))){
        if (AuxFirstNode == NULL){
            double FirstValue = 0;
            double SecondValue = 0;
            NewVector.append(FirstValue,  SecondValue);
            AuxSecondNode = AuxSecondNode -> Next;
        }
        else if (AuxSecondNode == NULL){
            double FirstValue = 0;
            double SecondValue = 0;
            NewVector.append(FirstValue,  SecondValue);
            AuxFirstNode = AuxFirstNode -> Next;
        }
        else{
            double FirstValue = AuxFirstNode -> FirstValue / AuxSecondNode -> FirstValue;
            double SecondValue = AuxFirstNode -> SecondValue / AuxSecondNode -> SecondValue;
            NewVector.append(FirstValue,  SecondValue);
            AuxFirstNode = AuxFirstNode -> Next;
            AuxSecondNode = AuxSecondNode -> Next;
        }
    }
    return NewVector;
}

int main(){
    Vector2D V;
    Vector2D V2;
    V.append(1, 2);
    V.append(3, 4);
    V.append(3, 4);
    V.append(1, 12);
    V2.append(5, 6);
    V2.append(1, 2);
    V2.append(5, 6);

    Vector2D NewAdditionVector;
    Vector2D NewSubstractionVector;
    Vector2D NewMultiplicationVector;
    Vector2D NewDivisionVector;
    NewAdditionVector = V + V2;
    NewSubstractionVector = V - V2;
    NewMultiplicationVector = V * V2;
    NewDivisionVector = V / V2;


    cout << "------------ Suma de Vectores -----------" << endl << endl;
    cout << V << endl;
    cout << V2 << endl;
    cout << NewAdditionVector << endl << endl;
    cout << "----------- Resta de Vectores ----------" << endl << endl;
    cout << V << endl;
    cout << V2 << endl;
    cout << NewSubstractionVector << endl << endl;
    cout << "------ Multiplicacion de Vectores ------" << endl << endl;
    cout << V << endl;
    cout << V2 << endl;
    cout << NewMultiplicationVector << endl << endl;
    cout << "--------- Division de Vectores ---------" << endl << endl;
    cout << V << endl;
    cout << V2 << endl;
    cout << NewDivisionVector << endl << endl;
}
