#include <iostream>

using namespace std;

void Show1(int a[]){
    for (int i = 0; i < 5; i++)
        cout<<"a["<<i<<"] = "<<a[i]<<endl;
}

void Show2(int *a){
    for (int i = 0; i < 5; i++)
        cout<<"a["<<i<<"] = "<<a[i]<<endl;
}

void Show3(int *a){
    for (int i = 0; i < 5; i++)
        cout<<"a["<<i<<"] = "<<*(a+i)<<endl;
}

void Show4(int *a){
    for (int i = 0; i < 5; i++){
        cout<<"a["<<i<<"] = "<<*a<<endl;
        a++;
    }
}

int main()
{
    int a[] = {11,12,13,14,15};
    cout<<"Dia chi cua mang a la: "<<a<<endl;
    cout<<"Dia chi cua mang a la: "<<&a<<endl;
    cout<<"Dia chi cua a[0] la: "<<&a[0]<<endl;
    cout<<"\n_____Show 1_____\n";
    Show1(a);
    cout<<"\n_____Show 2_____\n";
    Show2(a);
    cout<<"\n_____Show 3_____\n";
    Show3(a);
    cout<<"\n_____Show 4_____\n";
    Show4(a);
}