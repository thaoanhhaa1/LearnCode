#include <iostream>

using namespace std;

int main()
{
    int n, v;
    cin>>n>>v;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    int DP[v+1];
    for (int j = 0; j <= v; j++)
    {
        DP[j] = 0;
        for (int i = 0; i < n; i++)
        {
        	if (a[i] == j)
                DP[j] = 1;
            else if (a[i] < j)
                if (DP[j] == 0)
                    DP[j] = (DP[j-a[i]] == 0) ? 0 : DP[j-a[i]] + 1;
                else
                    DP[j] = min(DP[j],(DP[j-a[i]] == 0)?DP[j]: DP[j-a[i]] + 1);
        }
    }
    if (DP[v] != 0)
        cout<<DP[v];
    else
        cout<<-1;
}