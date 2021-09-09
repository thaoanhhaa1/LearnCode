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
    ifstream f("input.inp");
    n = -1;
    while (!f.eof())
    {
        n++;
        f.getline(sv[n].ten,255);
        f.getline(sv[n].diachi,255);
        f.getline(sv[n].email,255);
        f>>sv[n].diem;
        f.ignore(1);
    }
}

void Write(SinhVien sv[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<sv[i].ten<<endl;
        cout<<sv[i].diachi<<endl;
        cout<<sv[i].email<<endl;
        cout<<sv[i].diem<<endl;
    }
}

int main()
{
    SinhVien sv[50];
    int n;
    ReadFile(sv,n);
    ofstream f("D:/NMLT/IO_FILE/OUT.inp",ios::binary & ios::out);
    for (int i = 0; i < n; i++)
    {
        f.write((char*)&sv[i],sizeof(SinhVien));
        f<<endl;
    }
    f.close();
}
