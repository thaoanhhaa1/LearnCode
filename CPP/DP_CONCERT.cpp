#include <iostream>

using namespace std;

int main()
{
    int n = 7;
    int a[] = {2,4,1,2,2,5,1};
    int kq = 0;
    for (int i = 0; i < n-1; i++)
        if (a[i] > a[i+1])
        {
            kq++;
            for (int j = i+2; j < n; j++)
                if (a[j] <= a[j-1])
                    break;
                else
                    kq++;
        }
        else
        {
            kq++;
            for (int j = i+2; j < n; j++)
                if (a[j] < a[j-1])
                    break;
                else
                    kq++;
        }
    cout<<kq;
}