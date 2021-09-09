#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int a[] = {5,2,6,2,8};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<accumulate(a,a+n,0);
}