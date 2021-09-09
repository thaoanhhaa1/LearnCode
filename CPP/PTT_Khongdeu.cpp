#include <iostream>
#include <algorithm>

using namespace std;

class Phanso
{
private:
    int Tuso, Mauso;
public:
    Phanso()
    {
        this->Tuso = 1;
        this->Mauso = 1;
    }
    Phanso(int a, int b)
    {
        this->Tuso = a;
        this->Mauso = b;
    }
    void Nhap(int x)
    {
        this->Tuso = x;
        this->Mauso = 1;
    }
    friend Phanso Rutgon(Phanso a)
    {
        if (a.Tuso < 0 && a.Mauso < 0)
        {
            a.Tuso *= (-1);
            a.Mauso *= (-1);
        }
        else if (a.Mauso < 0 && a.Tuso >= 0)
        {
            a.Tuso *= (-1);
            a.Mauso *= (-1);
        }
        int UC = __gcd(abs(a.Tuso),abs(a.Mauso));
        a.Tuso /= UC;
        a.Mauso /= UC;
        return a;
    }
    friend Phanso operator+(Phanso a, Phanso b)
    {
        Phanso tam;
        tam.Tuso = b.Tuso * a.Mauso + a.Tuso * b.Mauso;
        tam.Mauso = a.Mauso * b.Mauso;
        tam = Rutgon(tam);
        return tam;
    }
    friend Phanso operator-(Phanso a, Phanso b)
    {
        Phanso tam;
        tam.Tuso = - b.Tuso * a.Mauso + a.Tuso * b.Mauso;
        tam.Mauso = a.Mauso * b.Mauso;
        tam = Rutgon(tam);
        return tam;
    }
    friend Phanso operator/(Phanso a, Phanso b)
    {
        Phanso tam;
        tam.Tuso = a.Tuso * b.Mauso;
        tam.Mauso = a.Mauso * b.Tuso;
        tam = Rutgon(tam);
        return tam;
    }
    friend Phanso operator*(Phanso a, Phanso b)
    {
        Phanso tam;
        tam.Tuso = a.Tuso * b.Tuso;
        tam.Mauso = a.Mauso * b.Mauso;
        tam = Rutgon(tam);
        return tam;
    }
    friend ostream& operator<<(ostream& os, Phanso a)
    {
        if (a.Mauso != 1)
            os<<a.Tuso<<"/"<<a.Mauso;
        else
            os<<a.Tuso;
        return os;
    }
    friend istream& operator>>(istream& is, Phanso &a)
    {
        is>>a.Tuso>>a.Mauso;
    }
};

void ChuyenPS(Phanso PS[], int P[], int n)
{
    for (int i = 0; i < n; i++)
        PS[i].Nhap(P[i]);
}

void NhapN(int &n)
{
    cout<<"Nhap n: ";
    cin>>n;
}

void NhapDay(int X[], int Y[], int n)
{
    cout<<"Nhap day x\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Nhap x["<<i<<"]: ";
        cin>>X[i];
    }
    cout<<"Nhap day y\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Nhap y["<<i<<"]: ";
        cin>>Y[i];
    }
}

int main()
{
    int n;
    NhapN(n);
    int X[n], Y[n];
    cout<<"Nhap day x: ";
    for (int i = 0; i < n; i++)
        cin>>X[i];
    cout<<"Nhap day y: ";
    for (int i = 0; i < n; i++)
        cin>>Y[i];
    //n = sizeof(X) /sizeof(X[0]);
    //NhapDay(X,Y,n);
    Phanso T(1,1), x;
    cout<<"Nhap x: ";
    cin>>x;
    Phanso PSX[n], PSY[n-1][n];
    ChuyenPS(PSX,X,n);
    ChuyenPS(PSY[0],Y,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (i > 0)
                PSY[i][j] = (PSY[i-1][j+1] - PSY[i-1][j]) / (PSX[j+i] - PSX[j]);
            cout<<PSY[i][j]<<" ";
        }
        cout<<endl;
    }
    Phanso kq = PSY[0][0];
    for (int i = 1; i < n; i++)
    {
        Phanso tam = PSY[i][0];
        for (int j = 0; j < i; j++)
            tam = tam*(x-PSX[j]);
        kq = kq + tam;
    }
    cout<<"Ket qua: "<<kq;
}