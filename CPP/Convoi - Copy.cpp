#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    float a,b,c;
    cin>>a>>b>>c;
    if (a == 0){
        if (b == 0 && c == 0)
            cout<<"Phuong trinh co vo so nghiem";
        else
            cout<<"Day khong phai phuong trinh bac 2";
    }
    else{
        float denta = b*b - 4*a*c;
        if (denta == 0){
            cout<<"Phuong trinh co nghiem kep\n";
            cout<<"x = "<<(-b/(2*a));
        }
        else if (denta < 0)
            cout<<"Phuong trinh vo nghiem";
        else{
            cout<<"Phuong trinh co 2 nghiem\n";
            cout<<"x1 = "<<((-b - sqrt(denta))/(2*a))<<endl;
            cout<<"x2 = "<<((-b + sqrt(denta))/(2*a))<<endl;
        }
    }
}