#include <iostream>

using namespace std;

int main()
{
    int n = 5, k = 2;
    int a[] = {7,3,3,9,10};
    if (k == 1)
    {
        int kq = a[0];
        for (int i = 1; i < n; i++)
            if (kq < a[i])
                kq = a[i];
        cout<<kq;
        return 0;
    }
    int DP[n];
    DP[0] = a[0];
    DP[1] = a[0] + a[1];
    for (int i = 2; i < n; i++)
    {
        if (k > i+1)
        {
            DP[i] = a[i];
            for (int j = 0; i < i; j++) 
                DP[i] += a[j];
        }
        else
        {
            DP[i] = max(DP[i-1],DP[i-2]) + a[i];
        }
    }
    for (int i = 0; i < n; i++)
        cout<<DP[i]<<" ";
}