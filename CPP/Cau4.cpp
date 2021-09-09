#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n = 5, a[] = {5,3,4,6,7};
    bool kt[n];
    memset(kt,true,sizeof kt);
    for (int i = 1; i < n-1; i++)
        if (kt[i])
        {
            int ir = i - 1, il = i+1;
            while (!kt[ir])
                ir--;
            while (!kt[il])
                il++;
            if (a[i] < a[ir] && a[i] < a[il])
                kt[i] = false;
        }
    for (int i = 0; i < n; i++)
        if (kt[i])
            cout<<a[i]<<" ";
}