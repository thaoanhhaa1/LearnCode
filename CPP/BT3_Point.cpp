#include <iostream>

using namespace std;

void Change1BienA(int x){
    x *= 2;
}

void Change2BienA(int *x){
    *x *= 2;
}

void Change3BienA(int &x){
    x *= 2;
}

int main()
{
    int a = 10;
    Change1BienA(a);
    cout<<"Gia tri cua bien A: "<<a<<endl;
    Change2BienA(&a);
    cout<<"Gia tri cua bien A: "<<a<<endl;
    Change3BienA(a);
    cout<<"Gia tri cua bien A: "<<a<<endl;
}