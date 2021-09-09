#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int x,y,z,k,m,n;
    cin>>x>>y>>z;
    cin>>k>>m>>n;
    cout<<k*x + (m-k)*y + (n-m)*z;
}