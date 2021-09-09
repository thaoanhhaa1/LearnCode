#include <iostream>
#include <fstream>

using namespace std;

void ReadFile()
{
    ifstream f("D:/Code/IOFile/INPUT3.txt");
    if (f.is_open())
    {
        ofstream f1("D:/Code/IOFile/KETQUA31.txt");
        ofstream f2("D:/Code/IOFile/KETQUA32.txt");
        if (!f1.is_open() || !f2.is_open())
        {
            cout<<"Mo file ghi khong thanh cong";
            return;
        }
        while (!f.eof())
        {
            char c;
            f>>c;
            if (c >= '0' && c <= '9')
                f2<<c;
            else
                f1<<c;
        }
        f.close();
        f1.close();
        f2.close();
    }
    else
        cout<<"Mo file doc khong thanh cong";
}

int main()
{
    ReadFile();
}