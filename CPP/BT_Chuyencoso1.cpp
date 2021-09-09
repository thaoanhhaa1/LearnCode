#include <iostream>

using namespace std;

string aaa[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

string chuyenphanthapphan(double n, int x)
{
    string tam = "";
    int k = 5;
    while (k-- && n != 0)
    {
        tam += aaa[int(n*x)];
        n = n*x - int(n*x);
    }
    return tam;
}

string chuyencoso(int n, int x)
{
    if (n < x) 
        return aaa[n];
    return chuyencoso(n/x,x) + aaa[n%x];
}

int main()
{
    double n;
    int cs;
    cout<<"Nhap so muon chuyen: ";
    cin>>n;
    cout<<"Nhap co so muon chuyen sang: ";
    cin>>cs;
    cout<<chuyencoso(int(n),cs) + ((int(n)*1.0 != n) ? '.' + chuyenphanthapphan(n-int(n),cs) : "");
}