#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

void Check1(long long n){
    int dem = 0;
    for (long long i = 1; i <= n; i++)
        if (n % i == 0)
            dem++;
    if (dem == 2)
        cout<<n<<" la so nguyen to";
    else 
        cout<<n<<" khong la so nguyen to";
}

bool Check2(long long n){
    for (long long i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

bool Check3(long long n){
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(){
    long long n = 843584353536863;
    clock_t begin = clock();
    Check1(n);
    cout<<"\nTime check 1: "<<(float)(clock()-begin)/CLOCKS_PER_SEC<<" s";
    clock_t begin1 = clock();
    if (Check2(n))
        cout<<"\nDung";
    else
        cout<<"\nSai";
    cout<<"\nTime check 2: "<<(float)(clock()-begin1)/CLOCKS_PER_SEC<<" s";
    clock_t begin2 = clock();
    if (Check3(n))
        cout<<"\nDung";
    else
        cout<<"\nSai";
    cout<<"\nTime check 3: "<<(float)(clock()-begin2)/CLOCKS_PER_SEC<<" s";
}