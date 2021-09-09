#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int DP[n+1][m+1], a, b;
    for (int i = 0; i <= n; i++)
    {
        if (i != 0)
            cin>>a>>b;
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (a > j)
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = max(DP[i-1][j-a] + b,DP[i-1][j]);
    }
    cout<<DP[n][m];
}