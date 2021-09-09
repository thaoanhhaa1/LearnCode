#include <iostream>
#include <windows.h>
#include <stack>
#include <queue>

using namespace std;

stack<int> luu;
queue<int> luutp;
char aaa[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void chuyencoso(int n, int x)
{
    while (n > 0){
        luu.push(n%x);
        n /= x;
    }
}

void chuyenphanthapphan(double n, int x)
{
    int k = 5;
    while (--k && n != 0)
    {
        luutp.push(int(n*x));
        n = n*x - int(n*x);
    }
}

int main()
{
    double n;
    int cs;
    cout<<"Nhap so muon chuyen: ";
    cin>>n;
    cout<<"Nhap co so muon chuyen sang: ";
    cin>>cs;
    chuyencoso(int(n),cs);
    string kq;
    while (luu.size() != 0)
    {
        kq += aaa[luu.top()];
        luu.pop();
    }
    if (int(n)*1.0 != n)
    {
        chuyenphanthapphan(n - (int)n,cs);
        if (kq.size() == 0)
            kq += '0';
        kq += '.';
        while (luutp.size() != 0)
        {
            kq += aaa[luutp.front()];
            luutp.pop();
        }
    }
    cout<<kq<<endl;
    //system("pause");
}