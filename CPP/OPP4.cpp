#include <iostream>
#include <math.h>

using namespace std;

bool checkprime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    int N = sqrt(n);
    for (int i = 2; i <= N; i++)
        if (n % i == 0)
            return false;
    return true;
}

int a[999999];

class Prime{
    private:
        int n;
    public:
        Prime(){
            cin>>n;
            for (int i = 0; i < n; i++)
                cin>>a[i];
        }

        int getai(int i){
            return a[i];
        }

        void Check(){
            int vtd = 0, vtc;
            for (int i = 0; i < n; i++)
                if (checkprime(getai(i))){
                    if (vtd == 0){
                        vtd = i;
                    }
                    vtc = i;
                }
            if (vtd == 0)
                cout<<-1;
            else
                cout<<a[vtd]<<" "<<a[vtc];
        }
};

int main(){
    Prime a;
    a.Check();
}