#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

long giaithua(int n)
{
    if (n == 0)
        return 1;
    else
        return n*giaithua(n-1);
}

int main()
{
    double x, s1 = 0, s2 = 0;
    int n = 0;
    cout<<"Nhap x: ";
    cin>>x;
    x = x*M_PI/180;
    do
    {
        s1 = s2;
        s2 += pow(-1,n)*pow(x,2*n+1)/giaithua(2*n+1);
        n++;
    }
    while (fabs(s2 - s1) > 0.00001);
    cout.precision(3);
    cout<<s2;
}
