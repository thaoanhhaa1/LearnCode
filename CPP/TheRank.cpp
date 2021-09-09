#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a,b,c,d, kq;
    cin>>a>>b>>c>>d;
    vector<int> gt;
    kq = a+b+c+d;
    gt.push_back(a+b+c+d);
    for (int i = 1; i < n; i++)
    {
        cin>>a>>b>>c>>d;
        gt.push_back(a+b+c+d);
    }
    sort(gt.begin(),gt.end(),greater<int>());
    for (int i = 0; i < n; i++)
        if (gt[i] == kq)
        {
            cout<<i+1;
            return 0;
        }
}