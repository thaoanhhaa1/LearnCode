#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n = 19, s = 36, S = (n*(n+1)/2 - s)/2;
    int DP[S+1];
    memset(DP,0,sizeof(DP));
    DP[0] = 1;
    for (int i = 1; i <= n; i++){
        DP[i] = 1;
        for (int j = S; j >= i; j--)
            if (DP[j] == 0 && DP[j-i] == 1)
                DP[j] = 1;
    }
    for (int i = 0; i <= S; i++)
        cout<<i<<" "<<DP[i]<<endl;
}