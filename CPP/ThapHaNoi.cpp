#include <iostream>

using namespace std;

void chuyen(int n, char a, char b, char c)
{
    if (n == 1)
        cout<<a<<" -> "<<c<<endl; //Nếu chỉ có 1 cột thì chuyển thực tiếp nó qua cột đích
    else //Nếu lớn hơn 1 cột thì: 
    {
        chuyen(n-1,a,c,b); //Chuyển n-1 cột từ cột nguồn sang cột trung gian
        chuyen(1,a,b,c); //Chuyển cột còn lại qua cột đích
        chuyen(n-1,b,a,c); //Chuyển n-1 cột từ cột trung gian qua cột đích
    }
}

int main()
{
    int n;
    cout<<"Nhap so cot: "; //Nhập số cột cần chuyển
    cin>>n; 
    chuyen(n,'A','B','C');
}
