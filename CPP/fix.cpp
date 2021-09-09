#include<iostream>
using namespace std;
void sapxep(int n , int arr[]){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n ; j++){
            if (arr[j] < arr[i]){
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    for(int i=0 ; i<n ; i++)
    cout<<arr[i];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cout<<"a["<<i<<"]= ";
        cin>>a[i];
    }
    sapxep(n , a);
    return 0;

}