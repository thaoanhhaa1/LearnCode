#include <iostream>

using namespace std;

int main()
{
    int a[] = {9,7,5,3,1,-1};
    cout<<"Dia chi cua a la: "<<a<<endl;
    cout<<"Dia chi cua a cung la: "<<&a<<endl;
    cout<<"Dia chi cua a cung la: "<<&a[0]<<endl;
    cout<<"Gia tri cua a[0] la: "<<a[0]<<endl;
    cout<<"=================================="<<endl;
    int *q = a;
    cout<<"Dia chi cua q la: "<<&q<<endl;
    cout<<"Dia chi q quan li la: "<<q<<endl;
    cout<<"Gia tri cua bien q la: "<<*q;
}