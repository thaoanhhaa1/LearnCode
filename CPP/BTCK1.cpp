#include <iostream>

using namespace std;

long long Fibo(long long n){
    if (n == 0) //Trường hợp neo: nếu n <= 2 thì trả về giá trị 1
        return 0;
    return Fibo(n-1) + Fibo(n-2); //Trả về giá trị của số thứ n-1 + n-2 của dãy Fibonacci
}

int main()
{
    cout<<"in";
    int n = 12;
    cout<<Fibo(n);
}