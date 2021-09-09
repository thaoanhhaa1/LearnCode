#include <iostream>
#include <string.h>

using namespace std;
#define N 8

void Show(int b[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
}

bool SetOk(int b[][N], int c, int h)
{
    int i, j;
    for (i = 0; i < c; i++)
        if (b[i][h] == 1)
            return false;
    i = c-1, j = h-1;
    while (i >= 0 && j >= 0)
        if (b[i--][j--] == 1)
            return false;
    i = c+1, j = h-1;
    while (i < N && j >= 0)
        if (b[i++][j--] == 1)
            return false;
    return true;
}

bool SetQueen(int b[][N], int h)
{
    if (h >= N)
        return true;
    for (int i = 0; i < N; i++)
        if (SetOk(b,h,i))
        {
            b[h][i] = 1;
            if (SetQueen(b,h+1))
                return true;
            b[h][i] = 0;
        }
    return false;
}

int main()
{
    int b[N][N];
    for (int i = 0; i < N; i++)
        memset(b[i],0,sizeof b[i]);
    if (SetQueen(b,0))
        Show(b);
    else
        cout<<"No solution";
}