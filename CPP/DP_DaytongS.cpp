#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n, W;
    cin>>n>>W;
    int a[n], DP[W+1];
    memset(DP,0,sizeof DP);
    DP[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if (DP[a[i]] == 0)
        {
        	DP[a[i]] = 1;
        	for (int j = W; j >= a[i]; j--)
            	if (DP[j] == 0 && DP[j-a[i]] == 1 && j-a[i] != a[i])
                	DP[j] = 1;
        }
        else
        {
            //DP[a[i]] = 1;
        	for (int j = W; j >= a[i]; j--)
            	if (DP[j] == 0 && DP[j-a[i]] == 1)// && j-a[i] != a[i])
                	DP[j] = 1;
        }
    }   
    for (int i = 0; i <= W; i++)
        cout<<DP[i];
    cout<<endl;
    cout<<(DP[W] == 0) ? -1 : DP[W];
}