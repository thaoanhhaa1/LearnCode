#include <iostream>
#include <vector>

using namespace std;

#define MAX 100000
//char a[100000][100000];

vector<int> Dem(string a[], int m, int n, string Q[], int q){   
    vector<int> kq(n,0);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < q; k++)
                if (a[i][j] == Q[k][0] && kq[k] == 0){
                    int h, M = Q[k].size();
                    if (j+M-1 < n)
                    {
                        for (h = 1; h < M; h++)
                            if (a[i][j+h] != Q[k][h])
                                break;
                        if (h == M)
                            kq[k] = 1;
                    }
                    if (j+M-1 < m && kq[k] == 0)
                    {
                        for (h = 1; h < M; h++)
                            if (a[i+h][j] != Q[k][h])
                                break;      
                        if (h == M)
                            kq[k] = 1;
                    }
                }
    return kq;
}

int main()
{
    int m,n,q;
    cin>>m>>n>>q;
    cin.ignore(1);
    string a[m], Q[q];
    for (int i = 0; i < m; i++)
        getline(cin,a[i]);
    for (int i = 0; i < q; i++)
        getline(cin,Q[i]);
    vector<int> kq = Dem(a,m,n,Q,q);
    for (int i = 0; i < q; i++)
        cout<<kq[i];
}