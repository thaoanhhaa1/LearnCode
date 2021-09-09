#include <iostream>

using namespace std;

long long POW(long long a, long long b){
    long long kq = 1; 
    while (b > 1){
        if (b % 2 != 0)
            kq *= a;
        a *= a;
        b /= 2;
    }
    return kq*a;
}

long long POW_MOD(long long a, long long b){
    long long kq = 1;
    int MOD = 1E+9 + 7;
    while (b > 1){
        if (b % 2 != 0)
            kq = (kq*a)%MOD;
        a =  (a*a)%MOD;
        b /= 2;
    }
    return (kq*a)%MOD;
}

int main()
{
    cout<<POW_MOD(2,100)<<endl;
}