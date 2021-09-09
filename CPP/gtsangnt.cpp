#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

void sangnguyento(int n, bool a[])
{
    for (int i = 3; i <= sqrt(n); i += 2)
        if (a[i])
            for (int j = i*i; j <= n; j += i)
                a[j] = false;
    for (int i = 4; i <= n; i+= 2)
        a[i] = false;
}

string factorialDecomp(int n)
{
    bool a[n+1] = {true};
    int b[n+1] = {0};
    long long gt = 1;
    sangnguyento(n,a);
    for (int i = n; i >= 2; i--)
    {
        gt *= i;
        for (int j = 2; j <= n; j++)
            if (gt % j == 0 && a[j])
            {
                b[j]++;
                gt /= j;
            }
    }
    string kq = "";
    for (int i = 2; i <= n; i++)
        if (b[i] != 0 && a[i])
            if (b[i] == 1)
                kq += to_string(i) + " * ";
            else
                kq += to_string(i) + "^" + to_string(b[i]) + " * ";
    return kq.substr(0,kq.size()-3);
}

int main()
{
    cout<<factorialDecomp(22);
}
