#include <iostream>

using namespace std;

int C(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    return C(n-1,k-1) + C(n-1,k);
}

int C_dp(int n, int k)
{
    if (k > n)
        return 0;
    int L[n+1][k+1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            if (j == 0 || i == j)
                L[i][j] = 1;
            else
                L[i][j] = L[i-1][j-1] + L[i-1][j];
    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i,k); j++)
            cout<<L[i][j]<<" ";
        cout<<endl;
    }*/
    return L[n][k];
}

int main()
{
    int n = 5, k = 2;
    cout<<"Ket qua: "<<C(n,k)<<endl;
    cout<<"Ket qua DP: "<<C_dp(n,k);
}