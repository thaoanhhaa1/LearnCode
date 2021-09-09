#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int dem = 0, gt = n*n;
    int a[n][n];
    while (gt)
    {
        for (int i = dem; i < n - dem; i++)
        {
            a[dem][i] = gt;
            gt--;
        }
        for (int i = dem + 1; i < n - dem; i++)
        {
            a[i][n - dem - 1] = gt;
            gt--;
        }
        for (int i = n - 2 - dem; i >= dem; i--)
        {
            a[n-dem-1][i] = gt;
            gt--;
        }
        for (int i = n - dem - 2; i >= dem + 1; i--)
        {
            a[i][dem] = gt;
            gt--;
        }
        dem++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    system("pause");
}