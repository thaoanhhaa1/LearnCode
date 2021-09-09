#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    int v[n], w[n];
    int DP[n+1][m+1];
    for (int i = 0; i <= n; i++){
        if (i != 0)
            cin>>w[i-1]>>v[i-1];
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (j >= w[i-1])
                DP[i][j] = max(DP[i-1][j],DP[i-1][j-w[i-1]]+v[i-1]);
            else
                DP[i][j] = DP[i-1][j];
    }
    cout<<DP[n][m];
}