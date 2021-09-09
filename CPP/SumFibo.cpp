#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    long long n;
    cin>>n;
    long long f1 = 1, f2 = 2;
    vector<long long> a;
    a.push_back(1);
    while (f2 <= n){
        a.push_back(f2);
        f2 += f1;
        f1 = f2 - f1;
    }
    for (int i = a.size()-1; i >= 0; i--)
        if (n == 0)
            break;
        else if (n >= a[i]){
            cout<<a[i]<<endl;
            n -= a[i];
        }
}