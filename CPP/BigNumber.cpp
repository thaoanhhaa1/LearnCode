#include <iostream>
#include <conio.h>

using namespace std;

struct BigNumber {
    char Num[100];
    bool SignBit; //Số âm hoặc dương
    int Size; //Số lượng chữ số
};

istream& operator>>(istream &is, BigNumber &a){
    char temp;
    a.Size = -1;
    is>>temp;
    if (temp =='-')
        a.SignBit = false;
    else {
        a.SignBit = true;
        a.Num[++a.Size] = temp;
    }
    cout<<temp;
    while (true){
        temp = _getch();
        if (temp == ' ' || temp == 13){
            cout<<temp;
            return is;
        }
        cout<<temp;
        a.Num[++a.Size] = temp;
    }
    cout<<temp;
    return is;
}

ostream& operator<<(ostream &os, BigNumber a){
    if (!a.SignBit)
        os<<'-';
    for (int i = 0; i <= a.Size; i++)
        os<<a.Num[i];
    return os;
}

int SoSanh(BigNumber a, BigNumber b){ // 1: lớn hơn, 0: bằng, -1: bé hơn
    if (a.Size > b.Size)
        return 1;
    if (a.Size < b.Size)
        return -1;
    for (int i = a.Size; i >= 0; i--)
        if (a.Num[i] > b.Num[i])
            return 1;
        else if (a.Num[i] < b.Num[i])
            return -1;
    return 0;
}

int main(){
    BigNumber a, b;
    cout<<"Nhap a: ";
    cin>>a>>b;
    cout<<"Xuat a: ";
    cout<<a<<" "<<b;
}