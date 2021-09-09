#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int DP[n+1];
    memset(DP,0,sizeof DP);
    for (int i = 0; i < m; i++)
    {
        int s,e,v,d;
        cin>>s>>e>>v>>d;
        for (int j = s; j <= e; j++)
            DP[j] = max(DP[j],v + (j-s)*d);
    }
    for (int i = 1; i <= n; i++)
        cout<<DP[i]<<endl;
}