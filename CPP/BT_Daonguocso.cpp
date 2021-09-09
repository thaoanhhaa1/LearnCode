#include <iostream>

using namespace std;

string Daonguocso(long long n)
{
    if (n < 10)
        return to_string(n);
    return to_string(n%10) + Daonguocso(n/10);
}

int main()
{
    long long n;
    cout<<"Nhap n: ";
    cin>>n;
    cout<<Daonguocso(n);
}