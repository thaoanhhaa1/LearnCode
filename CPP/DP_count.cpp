#include <iostream>

using namespace std;

int dequy(int S[], int N, int n)
{
    if (N == 0)
        return 1;
    if (N < 0)
        return 0;
    if (n <= 0 && N >= 1)
        return 0;
    return dequy(S,N,n-1) + dequy(S,N - S[n-1],n);
}

void sort(int S[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (S[i] > S[j])
                swap(S[i],S[j]);
}

int dp(int S[], int n, int N)
{
    sort(S,n);
    int L[n+1][N+1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= N; j++)
            if (j == 0)
                L[i][j] = 1;
            else
                if (i == 0)
                    L[i][j] = 0;
                else
                    if (j < S[i-1])
                        L[i][j] = L[i-1][j];
                    else
                        L[i][j] = L[i-1][j] + L[i][j-S[i-1]];
    return L[n][N];
}

int main()
{
    int N = 4;   
    int S[] = {1,2,3};
    int n = sizeof(S)/sizeof(S[0]);
    cout<<"Ket qua de quy: "<<dequy(S,N,n);
    cout<<"\nKet qua DP: "<<dp(S,n,N);
}