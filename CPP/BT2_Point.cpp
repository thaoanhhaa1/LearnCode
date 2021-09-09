#include <iostream>

using namespace std;

int main()  
{
    int a = 10;
    cout<<"Gia tri cua bien a la: "<<a<<endl;
    cout<<"Dia chi cua bien a la: "<<&a<<endl;
    cout<<"Gia tri dia chi cua bien a la: "<<*&a<<endl;
    cout<<"\n========================================\n";
    cout<<"\n_____Khai bao con tro q_____\n";
    int *q = NULL;
    //cout<<"Gia tri cua q la: "<<*q<<endl;
    //cout<<"Dia chi cua q la: "<<q<<endl;
    //cout<<"Dia chi cua q la: "<<&q<<endl; 
    cout<<"\n_____Gan p = &a_____\n";
    q = &a;
    cout<<"Gia tri cua q la: "<<*q<<endl;
    cout<<"Dia chi cua q la: "<<q<<endl;
    cout<<"Dia chi cua q la: "<<&q<<endl;
}