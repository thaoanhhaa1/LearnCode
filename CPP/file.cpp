#include <iostream>
#include <fstream>

using namespace std;

struct Sinhvien
{
    string name;
    int rall;
    char male;
};

int main()
{
    Sinhvien SV;
    SV.name = "Ha Anh Thao";
    SV.rall = 9;
    SV.male = 'Y';
    ofstream f1("D:/output.txt",ios::binary);
    f1.write((char*)&SV,sizeof(Sinhvien));
    f1.close();
}
