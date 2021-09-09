#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int a[n][m], DP[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
            if (i == 0 && j == 0)
                DP[i][j] = a[i][j];
            else if (i == 0)
                DP[i][j] = a[i][j] + DP[i][j-1];
            else if (j == 0)
                DP[i][j] = a[i][j] + DP[i-1][j];
            else
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]) + a[i][j];
        }
    cout<<DP[n-1][m-1];
}