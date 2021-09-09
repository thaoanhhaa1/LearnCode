#include <iostream>

using namespace std;
 
void Try(int a[], int n, int b[], int &m){
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (a[i] == b[j])
                break;
        if (j == m){
            b[m++] = a[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    int b[n], m = 0;
    Try(a,n,b,m);
    for (int i = 0 ; i < m; i++)
        cout<<b[i]<<" ";
}