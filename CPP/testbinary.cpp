#include <iostream>
#include <fstream>

using namespace std;

struct SinhVien
{
    char ten[30];
    char diachi[50];
    char email[30];
    float diem;
};

int main()
{
    SinhVien sv;
    ifstream f("D:/Code/IOFile/KETQUA5.txt",ios::binary);   
    if (f)
    {
        while (f.read((char*)&sv,sizeof(sv)))
        {
            //f.read((char*)&sv,sizeof(sv));
            cout<<sv.ten<<endl;
            cout<<sv.diachi<<endl;
            cout<<sv.email<<endl;
            cout<<sv.diem<<endl;
        }
        f.close();        
    }
    else
        cout<<"Mo file khong thanh cong";
    cout<<"Test Binary";
}