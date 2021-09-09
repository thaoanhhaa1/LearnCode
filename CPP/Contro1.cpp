#include <iostream>
//#include <string.h>

using namespace std;

int main()
{
    int a[] = {5,2,6,9,7}, x= 10;
    int*ptr;// = a;
    ptr = &x;
    cout<<&ptr<<" ";
    cout<<ptr<<" ";
    cout<<&x<<" ";
    ptr = &a[0];
    cout<<*ptr<<" ";
    //cout<<ptr<<endl;
    //cout<<(ptr+2)<<endl;
    //cout<<(ptr+3)<<endl;

    cout<<*(ptr+3)<<endl;
    *(ptr+3) = 10;
    cout<<ptr[3]<<endl;
    ptr++;
    cout<<*ptr<<endl;
    cout<<*(ptr-1)<<endl;
    int *p;
    p = ptr;
    cout<<*p<<endl;
    cout<<ptr<<endl;
    cout<<p<<endl;
    cout<<&ptr<<endl;
    cout<<&p<<endl;
    //cout<<(ptr+4);
    /*int val = 10;
    int *ptr = &val; //Tạo biến con trỏ trỏ tới địa chỉ của val
    cout<<val<<endl; //In giá trị của biến val
    cout<<&val<<endl; //In địa chỉ của biến val
    cout<<ptr<<endl; //In địa chỉ của con trỏ
    cout<<*ptr<<endl; //In giá trị của biến con trỏ
    *ptr = 5; //Thay đổi giá trị của con trỏ bằng 5
    cout<<val<<endl;
    cout<<*ptr<<endl;                 
    val = 15; //Thay đổi giá trị của biến val bằng 15
    cout<<val<<endl;
    cout<<*ptr<<endl;*/
}