#include <iostream>

using namespace std;

class Bai1{
    private:
        long long a, b;
    public:
        void Nhap(){
            cin>>a>>b;
        }
        int Sum(){
            return (a+b)%101;
        }
};

int main(){
    Bai1 a;
    a.Nhap();
    cout<<a.Sum();
}