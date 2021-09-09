#include <iostream>

using namespace std;

int KQ(int n, int k){
    int a[n], c = 0, l = n-1;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0)
            a[i] = l--;
        else
            a[i] = c++;
        if (a[i] == k)
            return i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<KQ(n,k)<<endl;
    }
}