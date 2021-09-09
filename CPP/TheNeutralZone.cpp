#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<long long> kt(30000000,1); //1 T 0 F
int i, j, N, dem;
long long tam;

void Sangnguyento(int n)
{
    N = sqrt(n);
    for (i = 3; i <= N; i += 2)
        if (kt[i] == 1)
        {
            j = i*2;
            while (j <= n)
            {
                kt[j] = 0;
                j += i;
            }
        }
    for (i = 4; i <= n; i += 2)
        kt[i] = 0;
}

int main()
{
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    Sangnguyento(n);
    long long kq = 0;
    for (i = 2; i <= n; i++)
        if (kt[i] != 0)
        {
            tam = i*i;
            kt[i] = a*i*tam + b*tam + c*i + d;
            kq += kt[i];
        }
        else
        {
            tam = i;
            //long long sum = 0;
            for (j = 2; j <= i/2; j++)
                if (kt[j] != 0)
                {
                    dem = 0;
                    while (tam % j == 0)
                    {
                        tam /= j;
                        dem++;
                    }
                    kq += dem*kt[j];
                    if (tam == 1)
                        break;
                }
            //kq += sum;
        }
    cout<<kq;
}