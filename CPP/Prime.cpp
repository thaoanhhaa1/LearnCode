#include <iostream>
#include <math.h>

using namespace std;

bool checkprime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n != 2 && n % 2 == 0)
        return false;
    int N = sqrt(n);
    for (int i = 3; i <= N; i+=2)
        if (n % i == 0)
            return false;
    return true;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    int PriMin, PriMax, i = 0;
    while (!checkprime(a[i]))
        i++;
    PriMin = a[i];
    PriMax = a[i];
    for (; i < n; i++)
        if (checkprime(a[i]))
            if (a[i] > PriMax)
                PriMax = a[i];
            else if (a[i] < PriMin)
                PriMin = a[i];
    cout<<PriMax + PriMin;
}