#include <iostream>
#include <math.h>

using namespace std;

float Sin(float x, int n){          
    float S = x, Pow = x;           //1
    long GT = 1;                    //2
    for (int i = 1; i <= n; i++){   //3
        Pow *= x*x;                 //4
        GT *= (4*i*i + 2*i);        //5
        S += pow(-1,i)*Pow/GT;      //6
    }
    return S;                       //7
}


float SinVD(float x, int n){
    float S = x, T;
    long M;
    for (int i = 1; i <= n; i++){
        T = 1;
        M = 1;
        for (int j = 1; j <= 2*i+1; j++){
            T *= x;
            //M *= i;
            M *= j;
        }
        S += pow(-1,i)*1.0*T/M;
    }
    return S;
}

int main(){
    int n = 3;
    float x = 2;
    cout<<Sin(x,n)<<"\n"<<SinVD(x,n);
}