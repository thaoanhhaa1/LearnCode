#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    clock_t begin = clock();
    int a = 1e+9,n = 1e+9;
    long long kq = 1, mod = 1e+9 + 7;
    for (int i = 0; i < n/20; i++)
    {
        kq *= a;
        kq %= mod;
    }
    cout<<(kq*20)%mod;
    cout<<"\nTime run: "<<(float)(clock() - begin)/CLOCKS_PER_SEC<<" s";
}