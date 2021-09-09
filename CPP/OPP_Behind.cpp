#include <iostream>

using namespace std;

class Behind{
    private:
        char ch;
        int n;
    public:
        Behind(){
            cin>>ch>>n;
        }
        void Output(){
            if (ch + n <= 'Z')
                cout<<char(ch+n);
            else{
                n -= ('Z' - ch);
                cout<<char('A'+n-1);
            }
        }
};

int main(){
    Behind a;
    a.Output();
}