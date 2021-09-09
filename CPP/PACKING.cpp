#include <iostream>

using namespace std;

void QHD(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, V;
    cin>>n>>V;
    int a[n], DP[n+1][V+1];
    for (int i = 0; i <= n; i++){
        if (i != 0)
            cin>>a[i-1];
        for (int j = 0; j <= V; j++)
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (j >= a[i-1])
                DP[i][j] = max(DP[i-1][j],DP[i-1][j-a[i-1]]+a[i-1]);
            else
                DP[i][j] = DP[i-1][j];
    }
    cout<<DP[n][V];
}

void Try(int a[], int n, int &max, int V, int sum){
    if (n > 0 && V > 0){
        for (int i = 0; i <= 1; i++)
            if (i == 0){
                Try(a,n-1,max,V,sum);
            }
            else if (V >= a[n-1]){
                sum += a[n-1];
                if (sum > max)
                    max = sum;
                Try(a,n-1,max,V-a[n-1],sum);
            }
    }
}

void QuayLui(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, V;
    cin>>n>>V;
    int a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    int kq = 0;
    Try(a,n,kq,V,0);
    cout<<kq;
}

int main(){
    QuayLui();
}