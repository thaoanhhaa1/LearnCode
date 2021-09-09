#include <iostream>
#include <fstream>

using namespace std;

void ReadFile(int &kq)
{
    ifstream f("D:/Code/IOFile/INPUT1.txt");
    if (f.is_open()){
        int n;
        f>>n;
        kq = 0;
        for (int i = 0; i < n; i++){
            int tam;
            f>>tam;
            if (tam > kq)
                kq = tam;
        }
        f.close();
    }
    else
        cout<<"Mo file doc khong thanh cong";
}

void WriteFile(int kq)
{
    ofstream f("D:/Code/IOFile/KETQUA1.txt");
    if (f.is_open()){
        f<<kq;
        f.close();
    }
    else
        cout<<"Mo file ghi khong thanh cong";
}

int main()
{
    int kq;
    ReadFile(kq);
    WriteFile(kq);
}