#include <iostream>

using namespace std;

bool Ktra(long long n){
    if (n < 10)
        return false;
    while (n > 0){
        if (n % 10 != 4 && n % 10 != 7)
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    long long n;
    cin>>n;
    if (Ktra(n))
        cout<<"YES";
    else
        cout<<"NO";
}