#include <iostream>

using namespace std;

float avg(int *a, int n){
    int sum = 0, dem = 0;
    for (int i = 0; i < n; i++)
        if (*(a+i) > 0){
            sum += *(a+i);
            dem++;
        }
    return float(sum)/dem;
}

int main()
{
    int n;
    cin>>n;
    int *a;
    for (int i = 0; i < n; i++)
        cin>>*(a+i);
    cout<<avg(a,n);
}