#include <iostream>

using namespace std;

int main()
{
    int n;  
    //cin>>n;
    int a[] = {0,14,8,11,14,13,9,2,11,11,11,8,15,6,4},  sqt[n+1], vt[n+1];
    n = sizeof(a)/sizeof(a[0]) -1;
    //a[0] = 0;
    sqt[0] = 0;
    //vt[0] = -1;
    int kq = 0;
    for (int i = 1; i <= n; i++)
    {
        //cin>>a[i];
        int j;
        for (j = i-1; j > 0; j--)
            if (a[j] < a[i])
                break;
        sqt[i] = sqt[j] + 1;
        if (sqt[i] > kq)
            kq = sqt[i];
    }
    for (int i = 0; i <= n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for (int i = 0; i <= n; i++)
        cout<<sqt[i]<<" ";
    cout<<endl<<kq; 
}
