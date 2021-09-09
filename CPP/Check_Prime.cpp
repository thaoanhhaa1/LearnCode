//Kiểm tra số nguyên tố
#include <iostream>
#include <math.h>

using namespace std;

bool Checkprime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n = 6;
    if (Checkprime(n))
        cout<<n<<" la so nguyen to";
    else
        cout<<n<<" khong la so nguyen to";
}