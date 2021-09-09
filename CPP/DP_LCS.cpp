#include <iostream>

using namespace std;

int dp(string s1, string s2, int n1, int n2)
{
    int L[n1+1][n2+1];
    for (int i = 0; i <= n1; i++)
        for (int j = 0; j <= n2; j++)
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else
                if (s1[i-1] == s2[j-1])
                    L[i][j] = L[i-1][j-1] + 1;
                else
                    L[i][j] = max(L[i-1][j],L[i][j-1]);
    return L[n1][n2];
}

int main()
{
    string s1, s2;
    int n, m;
    cin>>m>>n;
    cin.ignore(1);
    getline(cin,s1);
    getline(cin,s2);
    cout<<dp(s1,s2,m,n);
}