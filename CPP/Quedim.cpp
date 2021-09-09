#include <iostream>
#include <time.h>

using namespace std;

int a[] = {6,2,5,5,4,5,6,3,7,6};

void TimMin(int scs, int d, long long kq, int n, long long &Min){
    if (Min == 0)
        for (int i = 0; i <= 9; i++)
            if (!(i == 0 && d == 1)){
                if (d >= scs){
                    if (n == a[i]){
                        Min = kq*10 + i;
                        break;
                    }
                }
                else
                    TimMin(scs,d+1,kq*10 + i,n-a[i],Min);
            }
}

void InMin(int n){
    if (n <= 7)
        for (int i = 1; i <= 9; i++)
            if (a[i] == n){
                cout<<i<<" ";
                return;
            }
    int scs = (n % 7 == 0) ? n/7 : n/7 + 1;
    long long kq = 0;
    TimMin(scs,1,0,n,kq);
    cout<<kq<<" ";
}

void InMax(int n){
    int DIV = n/2;
    if (n % 2 == 0){
        for (int i = 0; i < DIV; i++)
            cout<<1;
        cout<<endl;
    }
    else{
        cout<<7;
        for (int i = 0; i < DIV-1; i++)
            cout<<1;
        cout<<endl;
    }
}

int main()
{
    clock_t begin= clock();
    //int T;
    //cin>>T;
    //while(T--){
        //int i;
        //cin>>i;
    for (int i = 2; i <= 39; i++){ 
        //int i = 9;
        cout<<i<<" ";       
        InMin(i);
        InMax(i);
    }
    //}
    cout<<"\nTime run: "<<(float)(clock() - begin)/CLOCKS_PER_SEC<<" s";
}