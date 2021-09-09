#include <iostream>

using namespace std;

void Nhaparr(int *a, int n){
    for (int i = 0; i < n; i++)
        cin>>*(a+i);
}

void Xuatarr(int *a, int n){
    for (int i = 0; i < n; i++)
        cout<<*(a+i)<<" ";
}

void Sort(int *a, int n){
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n; j++)
            if (*(a+i) % 2 == 0 && *(a+j) % 2 == 0 && *(a+i) > *(a+j))  
                swap(*(a+i),*(a+j));
}

int main(){
    int n;
    cin>>n;
    int *a = new int[n];
    Nhaparr(a,n);
    Xuatarr(a,n);
    Sort(a,n);
    Xuatarr(a,n);
}