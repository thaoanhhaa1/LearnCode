#include <iostream>
#include <string.h>

using namespace std;

struct Date
{
    int d, m, y;
};


class Thucpham
{
private:;
    Date NSX, HSD;
public:
    void NhapNSX()
    {
        cout<<"Nhap ngay san xuat: ";
        cin>>NSX.d>>NSX.m>>NSX.y;
    }
    void NhapHSD()
    {
        cout<<"Nhap han su dung: ";
        cin>>HSD.d>>HSD.m>>HSD.y;
    }
    void Nhap()
    {
        NhapNSX();
        NhapHSD();
    }
    void XuatNSX()
    {
        cout<<"Ngay san xuat: "<<NSX.d<<"/ "<<NSX.m<<"/ "<<NSX.y<<endl;
    }
    void XuatHSD()
    {
        cout<<"Han su dung: "<<HSD.d<<"/ "<<HSD.m<<"/ "<<HSD.y<<endl;
    }
    void Xuat()
    {
        XuatNSX();
        XuatHSD();
    }
};

class Sanpham : public Thucpham
{
private:
    string MaSP, TenSP;
    int Soluong;
    float Dongia, Thanhtoan;
public:
    void NhapSP()
    {
        cin.ignore();
        cout<<"Nhap ma san pham: ";
        getline(cin,MaSP);
        cout<<"Nhap ten san pham: ";
        getline(cin,TenSP);
        cout<<"Nhap so luong: ";
        cin>>Soluong;
        cout<<"Nhap don gia: ";
        cin>>Dongia;
        Thucpham::Nhap();
        //cin.ignore();
    }
    void XuatSP()
    {
        cout<<"Ma san pham: "<<MaSP<<endl;
        cout<<"Ten san pham: "<<TenSP<<endl;
        cout<<"So luong san pham: "<<Soluong<<endl;
        cout<<"Don gia: "<<Dongia<<endl;
        Thanhtoan = Dongia*Soluong;
        cout<<"Thanh toan: "<<Thanhtoan<<endl;
        Thucpham::Xuat();
    }
    bool operator>(Sanpham b)
    {
        return (this->Thanhtoan > b.Thanhtoan);
    }
    bool operator==(string a)
    {
        int n1 = this->TenSP.size(), n2 = a.size();
        if (n1 != n2)
            return false;
        for (int i = 0; i < n1; i++)
            if (this->TenSP[i] != a[i]) 
                return false;
        return true;
    }
};

void Sapxep(Sanpham a[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i],a[j]);
}

void Timkiem(Sanpham a[], int n)
{
    string s;
    cout<<"Nhap ten san pham can tim: ";
    cin.ignore();
    getline(cin,s);
    for (int i = 0; i <n; i++)
        if (a[i] == s)
            a[i].XuatSP();
}

void NhapDay(Sanpham a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"\nNhap san pham thu "<<i<<": \n";
        a[i].NhapSP();
    }
}

void XuatDay(Sanpham a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i].XuatSP();
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    Sanpham a[n];
    cout<<"\n__NHAP SAN PHAM__"<<endl;
    NhapDay(a,n);
    cout<<"\n__XUAT SAN PHAM__\n";
    XuatDay(a,n);
    cout<<"\n__TIM KIEM SAN PHAM__\n";
    Timkiem(a,n);
    cout<<"\n__SAP XEP__\n";
    Sapxep(a,n);
    XuatDay(a,n);

}