#include <iostream>
#include <windows.h>

using namespace std;
int n, a[100];
bool kt[100];

void Xuat()
{
    for (int i = 1; i <= n; i++)
        cout<<a[i];
    cout<<endl;
}

void Hoanvi(int k)
{
    for (int i = 1; i <= n; i++)
        if (kt[i])
        {
            a[k] = i;
            kt[i] = false;
            if (k == n)
                Xuat();
            else
            {
                Hoanvi(k+1);
            }
            kt[i] = true;
        }
}

int main()
{
    cout<<"Nhap n: ";
    cin>>n;
    for (int i = 1; i <= n; i++)
        kt[i] = true;
    Hoanvi(1);
    system("pause");
}