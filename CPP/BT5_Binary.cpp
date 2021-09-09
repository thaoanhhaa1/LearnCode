#include <iostream>
#include <fstream>

using namespace std;

struct SinhVien
{
    char ten[30];
    char diachi[50];
    char email[50];
    float diem;
};

void ReadFile(SinhVien sv[], int &n)
{
    ifstream f("D:/Code/IOFile/Bt55.txt");
    n = 0;
    while (!f.eof())
    {
        f.getline(sv[n].ten,255);
        f.getline(sv[n].diachi,255);
        f.getline(sv[n].email,255);
        f>>sv[n].diem;
        f.ignore(1);
        n++;
    }
}

int main()
{
    SinhVien sv[50];
    int n;
    ReadFile(sv,n);
    ofstream f("D:/Code/IOFile/Bt55_O.txt",ios::binary);
    for (int i = 0; i < n; i++)
        f.write((char*)&sv[i],sizeof(SinhVien))<<endl;
    f.close();
}
