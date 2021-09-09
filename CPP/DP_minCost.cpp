#include <iostream>

using namespace std;

#define R 3
#define C 3

int dequy(int m, int n, int a[R][C])
{
    if (m == 0 && n == 0)
        return a[m][n];
    return a[m][n] + min((m-1) >= 0 ? dequy(m-1,n,a) : INT_MAX,min((n-1) >= 0 ? dequy(m,n-1,a) : INT_MAX,(m - 1 >= 0 && n - 1 >= 0) ? dequy(m-1,n-1,a) : INT_MAX));
}

int dp(int m, int n, int a[R][C])
{
    int L[R][C];
    L[0][0] = a[0][0];
    for (int i = 1; i <= m ;i++)
        L[i][0] = L[i-1][0] + a[i][0];
    for (int j = 1; j <= n; j++)
        L[0][j] = L[0][j-1] + a[0][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            L[i][j] = a[i][j] + min(L[i-1][j],min(L[i][j-1],L[i-1][j-1]));
    return L[m][n];
}

int main()
{
    int m = 3, n = 3;
    int a[R][C] = {{1,2,3},{4,8,2},{1,5,3}};
    cout<<"Ket qua: "<<dp(2,2,a);
    /*
    cout<<"Nhap m: ";
    cin>>m;
    cout<<"Nhap n: ";
    cin>>n;
    */
    /*
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cout<<"a["<<i<<","<<j<<"] = ";
            cin>>a[i][j];
        }
        */
}