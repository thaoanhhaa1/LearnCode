#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

long F[10000][10000];

int main()
{
    clock_t begin = clock();
    int x = 100000-1, y = x, mod = 1000000007;
    F[0][0] = 0;
    F[0][1] = F[1][0] = 1;
    int i, Min = min(x,y);
    for (i = 2; i <= Min; i++)
    {
        F[i][0] = (F[i-1][0] + F[i-2][0]) % mod;
        F[0][i] = (F[0][i-1] + F[0][i-2]) % mod;
    }
    while (i <= x)
    {
        F[i][0] = (F[i-1][0] + F[i-2][0]) % mod;
        i++;
    }
    while (i <= y)
    {
        F[0][i] = (F[0][i-1] + F[0][i-2]) % mod;
        i++;
    }
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            F[i][j] = (F[i-1][j] + F[i][j-1]) % mod;
    cout<<F[x][y] % mod;
    cout<<"\nTime run: "<<(float)(clock() - begin)/CLOCKS_PER_SEC<<" s";
}