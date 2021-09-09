#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n], vt2 = -1, vt1 = -1, dem = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if (a[i] == 2 && vt2 == -1)
            vt2 = i;
       	if (a[i] == 1)
            vt1 = i;
    }
    for (int i = vt2; i < vt1; i++)
        if (a[i] == 2)
            dem++;
   	cout<<dem;
}