#include <bits/stdc++.h>

using namespace std;

#define W 50

int knapSack(int wt[], int val[], int n)
{
    int DP[n+1][W+1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= W; j++)
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else
                if (j < wt[i-1])
                    DP[i][j] = DP[i-1][j];
                else
                    DP[i][j] = max(val[i-1] + DP[i-1][j-wt[i-1]],DP[i-1][j]);
    return DP[n][W];
}

int dequy(int w, int wt[], int val[], int n, int dp[][W+1])
{
    if (n <= 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    return max((w >= wt[n-1]) ? val[n-1] + dequy(w - wt[n-1],wt,val,n-1,dp) : 0,dequy(w,wt,val,n-1,dp));
}

int knapSackRec(int wt[], int val[], int n)
{
    int dp[n+1][W+1];
    memset(dp,-1,sizeof dp);
    int w = W;
    return dequy(w,wt,val,n,dp);
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    //int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    clock_t begin = clock();
    cout <<"Ket qua DP: "<<knapSack(wt, val, n);
    cout<<"\nTime run: "<<(float)(clock() - begin)/CLOCKS_PER_SEC<<" s";
    clock_t end = clock();
    cout<<"\nKet qua DQ: "<<knapSackRec(wt,val,n);
    cout<<"\nTime run: "<<(float)(clock() - end)/CLOCKS_PER_SEC<<" s";
    return 0;
}