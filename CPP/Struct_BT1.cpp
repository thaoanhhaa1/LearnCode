#include <iostream>
#include <fstream>

using namespace std;

struct SinhVien{
    string Hoten, MaSV, Lop, Sothich, Quequan;
};

void Read_File(SinhVien &a){
    ifstream ifs("D:/Code/IOFile/Struct.txt");
    if (ifs.is_open()){
        getline(ifs,a.Hoten);
        getline(ifs,a.MaSV);
        getline(ifs,a.Lop);
        getline(ifs,a.Sothich);
        getline(ifs,a.Quequan);
    }
    else
        cout<<"Mo file khong thanh cong\n";
}

void Xuat(SinhVien a){
    cout<<"Ho ten: "<<a.Hoten<<endl;
    cout<<"Ma sinh vien: "<<a.MaSV<<endl;
    cout<<"Lop: "<<a.Lop<<endl;
    cout<<"So thich: "<<a.Sothich<<endl;
    cout<<"Que quan: "<<a.Quequan;
}

int main()
{
    SinhVien a;
    Read_File(a);
    Xuat(a);
}