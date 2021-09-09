#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;
    int a[n+1], b[n+1], k = 1, max = 0;
    a[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= n; i++){
        b[i] = 0;
        cin>>a[i];
        if (a[i] > b[k-1]){
            b[k] = a[i];
            k++;
        }
        if (max < k)
            max = k;
    }
    cout<<max-1;
}