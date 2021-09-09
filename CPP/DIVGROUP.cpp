#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n, k;
        cin>>n>>k;
        if (k == 1 || k == n)
            cout<<1<<endl;
        else if (k == n-1)
            cout<<k<<endl;
    }
}