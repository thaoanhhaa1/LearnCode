#include <iostream>

using namespace std;

int main()
{
    int n = 4, m = 5;
    int a[n][m] = {{0,3,0,0,0},{1,-1,2,5,0},{1,2,-1,-1,-1},{-1,1,-1,1,0}};
    int DP[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                DP[i][j] = a[i][j];
            else if (a[i][j] != -1)
            {
                int tam = max((i-1 >= 0) ? DP[i-1][j] : -2,(j-1 >= 0) ? DP[i][j-1] : -2);
                DP[i][j] = (tam == -1) ? -1 : tam + a[i][j];
            }
            else
                DP[i][j] = -1;
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout<<DP[i][j]<<" ";
        cout<<endl;
    }
}