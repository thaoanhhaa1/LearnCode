#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int a[n];
    int DP[n];
    int kq = -1000;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if (i < k)
            DP[i] = a[i];
        else
            DP[i] = -1000;
        for (int j = max(0,i-k); j < i; j++)
            if (DP[j] + a[i] > DP[i])
                DP[i] = DP[j] + a[i];
        if (DP[i] > kq)
            kq = DP[i];
    }
    cout<<kq;
}