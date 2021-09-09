#include <iostream>

using namespace std;

int dequy(int a[], int l, int r)
{
    if (l == r)
        return 0;
    int min = INT_MAX;
    for (int i = l; i < r; i++)
    {
        int count = dequy(a,l,i) + dequy(a,i+1,r) + a[l-1]*a[i]*a[r];
        if (count < min)
            min = count;
    }
    return min;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 3 }, n = 2;//sizeof(arr) / sizeof(arr[0]);
    cout<<"Ket qua de quy: "<<dequy(arr,1,n-1);
}