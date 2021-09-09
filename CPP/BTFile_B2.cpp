#include <iostream>
#include <fstream>

using namespace std;

void ReadFile(double &kq)
{
    ifstream f("D:/Code/IOFile/INPUT2.txt");
    if (f.is_open())
    {
        kq = 0;
        while (!f.eof())
        {
            double tam;
            f>>tam;
            if (tam > kq)
                kq = tam;
        }
        f.close();
    }
    else
        cout<<"Mo file doc khong thanh cong";
}

void WriteFile(double kq)
{
    ofstream f("D:/Code/IOFile/KETQUA2.txt");
    if (f.is_open())
    {
        f<<kq;
        f.close();
    }
    else
        cout<<"Mo file ghi khong thanh cong";
}

int main()
{
    double kq;
    ReadFile(kq);
    WriteFile(kq);
}