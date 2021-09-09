#include <iostream>

using namespace std;

string DecToBin(int n)
{
    if (n == 0)
        return "";
    return DecToBin(n/2) + to_string(n%2);
}

int main()
{
    int n;
    cin>>n;
    cout<<DecToBin(n);
}