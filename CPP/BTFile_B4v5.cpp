#include <iostream>
#include <fstream>

using namespace std;

struct SinhVien
{
    char name[30];
    char address[50];
    char email[30];
    float scores;
};

int main()
{
    SinhVien sv;
    ifstream f("D:/Code/IOFile/INPUT4.txt");
    ofstream f1("D:/Code/IOFile/KETQUA5.txt",ios::binary);
    ofstream f2("D:/Code/IOFile/KETQUA4.txt");
    if (f && f1 && f2)
    {
        while (!f.eof())
        {
            f.getline(sv.name,31);
            f.getline(sv.address,51);
            f.getline(sv.email,31);
            f>>sv.scores;
            if (sv.scores >= 8)
            {
                f1.write((char*)&sv,sizeof(sv));
                f2<<sv.name<<endl;
                f2<<sv.address<<endl;
                f2<<sv.email<<endl;
                f2<<sv.scores<<endl;
            }
            f.ignore(1);
        }
        f.close();
        f1.close();
        f2.close();
    }
    else
        cout<<"Unable to open file";
}
