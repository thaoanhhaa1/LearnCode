#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;
    int a[n+1];
    bool kt[n+1], Kt = false;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        kt[i] = true;
        if (a[i] == n)
            Kt = true;
    }
    if (!Kt){
        cout<<-1;
        return 0;
    }
    int i = 1;
    vector<int> kq;
    while (kt[a[i]]){
        kt[i] = false;
        if (a[i] == n){
            kq.push_back(i);
            kq.push_back(a[i]);
            int N = kq.size();
            for (int j = 0; j < N; j++)
                cout<<kq[j]<<" ";
            return 0;
        }
        kq.push_back(i);
        i = a[i];
    }
    cout<<-1;
}