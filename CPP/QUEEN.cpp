#include <iostream>

using namespace std;

char a[1000][1000];
int m,n;

int Dem(int x, int y)
{
    int i = y-1, dem = 0, j;
    while (i >= 0 && a[x][i] != '#')
    {
        dem++;
        i--;
    }
    i = y+1;
    while (i < n && a[x][i] != '#')
    {
        dem++;
        i++;
    }
    i = x-1;
    while (i >= 0 && a[i][y] != '#')
    {
        dem++;
        i--;
    }
    i = x+1;
    while (i < m && a[i][y] != '#')
    {
        dem++;
        i++;
    }
    i = x-1;
    j = y-1;
    while (i >= 0 && j >= 0 && a[i][j] != '#')
    {
        dem++;
        i--;
        j--;
    }
    i = x+1;
    j = y+1;
    while (i < m && j < n && a[i][j] != '#')
    {
        dem++;
        i++;
        j++;
    }
    i = x-1;
    j = y+1;
    while (i >= 0 && j < n && a[i][j] != '#')
    {
        dem++;
        i--;
        j++;
    }
    i = x+1;
    j = y-1;
    while (i < m && j >= 0 && a[i][j] != '#')
    {
        dem++;
        i++;
        j--;
    }
    return dem+1;
}

int main()
{
    cin>>m>>n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin>>a[i][j];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][j] == '#')
                cout<<0<<" ";
            else
                cout<<Dem(i,j)<<" ";
        cout<<endl;
    }
}