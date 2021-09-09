#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/*bool checkprime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;
    int N = sqrt(n);
    for (int i = 3; i <= N; i += 2)
        if (n % i == 0)
            return false;
    return true;
}*/

int Daonguoc(int n){
    int N = 0;
    while (n > 0){
        N = N*10 + (n%10);
        n /= 10;
    }
    return N;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, N;
    cin>>n;
    N = Daonguoc(n);
    if (__gcd(n,N) == 1)
        cout<<"Yes";
    else
        cout<<"No";
}