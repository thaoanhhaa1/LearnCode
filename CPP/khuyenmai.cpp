#include <iostream>

using namespace std;

int Khuyenmai(int m, int n, int t)
{
    if (m > n)
        return n*t;
    if (n % (m+1) == 0)
        return (n/(m+1))*t*m;
    return ((n/(m+1))*m + 1)*t;
}

int main()
{
    int m = 3, n = 2, t = 100;
    cout<<((n/(m+1))*m + (n - (n/(m+1))*(m+1)))*t<<endl;
    cout<<Khuyenmai(m,n,t)<<endl;
}