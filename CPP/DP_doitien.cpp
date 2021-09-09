#include <bits/stdc++.h>

using namespace std;

long getWays(int n, vector<long> c) {
    long m = c.size(), DP[m+1][n+1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            if (j == 0)
                DP[i][j] = 1;
            else if (i == 0)
                DP[i][j] = 0;
            else if (c[i-1] < j)
                DP[i][j] = DP[i-1][j];
            else
                DP[i][j] = DP[i-1][j] + DP[i][j-c[i-1]];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            cout<<DP[i][j]<<" ";
        cout<<endl;
    }
    return DP[m][n];
}

int main()
{
    vector<long> a = {2,5,3,6};
    cout<<getWays(10,a);
}