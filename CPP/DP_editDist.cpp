#include <iostream>
#include <time.h>

using namespace std;

int dequy(int n1, string s1, int n2, string s2)
{
    if (n1 == 0)
        return n2;
    if (n2 == 0)
        return n1;
    if (s1[n1] == s2[n2])
        return dequy(n1-1,s1,n2-1,s2);
    return 1 + min(dequy(n1,s1,n2-1,s2),min(dequy(n1-1,s1,n2,s2),dequy(n1-1,s1,n2-1,s2)));
}

int dp(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();
    int L[n1+1][n2+1];
    for (int i = 0; i <= n1; i++)
        for (int j = 0; j <= n2; j++)
        {
            if (i == 0)
                L[i][j] = j;
            else
                if (j == 0)
                    L[i][j] = i;
                else 
                    if (s1[i-1] == s2[j-1])
                        L[i][j] = L[i-1][j-1];
                    else
                        L[i][j] = min(L[i-1][j-1],min(L[i-1][j],L[i][j-1])) + 1;
        }
    return L[n1][n2];
}

int main()
{
    string s1 = "sunday", s2 = "saturday";
    clock_t begin = clock();
    //cout<<"KQ: "<<dequy(s1.size()-1,s1,s2.size()-1,s2);
    cout<<"KQ: "<<dp(s1,s2);
    cout<<"\nTime run: "<<(float)(clock() - begin)/CLOCKS_PER_SEC<<" s";
}