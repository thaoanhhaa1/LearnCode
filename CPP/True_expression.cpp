#include <iostream>
#include <time.h>

using namespace std;

#define n 95
#define s 3952

string CheckS1 = "", CheckS2 = "";
int S1 = s;

void Tiepcan1(){
    //int n = 76, s = 172;
    //cin>>n>>s;
    int Sum = n*(n+1)/2;
    if (Sum < s || (Sum-s) % 2 != 0){
        cout<<"NO_SOLUTION";
        return;
    }
    string S = "";
    for (int i = 1; i <= n; i++)
        S += '+';
    Sum = (Sum - s)/2;
    if (!Sum){
        cout<<S;
        CheckS1 = S;
        return;
    }
    if (Sum <= n){
        S[Sum-1] = '-';
        cout<<S;
        CheckS1 = S;
        return;
    }
    //cout<<Sum;
    int x = n;
    while (Sum > x){
        S[x-1] = '-';
        Sum -= x--;
    }
    S[Sum-1] = '-';
    cout<<S;
    CheckS1 = S;
}

void Tiepcan3(){
    //int n = 76, s = 172;
    int Sum = n*(n+1)/2;
    if (Sum < s || (Sum-s) % 2 != 0){
        cout<<"NO_SOLUTION";
        return;
    }
    string S = "";
    for (int i = 1; i <= n; i++)
        S += '+';
    int i = 1;
    Sum = (Sum - s)/2; //77
    while (Sum > 0){ //77 76 74 71 67 62 56 49 41 32 22 11 -1
        S[i-1] = '-'; //1 2 3 4 5 6 7 8 9 10 11 12
        Sum -= i++; //76 74 71 67 62 56 49 41 32 22 11 -1
    }               //2 3 4 5 6 7 8 9 10 11 12 13
    if (Sum < 0)
        S[(-1)*Sum - 1] = '+';
    cout<<S;
    CheckS2 = S;
}

int main()
{
    clock_t begin = clock();
    Tiepcan1();
    cout<<"\nTime run 1: "<<(float)(clock() - begin)/CLOCKS_PER_SEC<<" s\n";
    clock_t end = clock();
    Tiepcan3();
    cout<<"\nTime run 3: "<<(float)(clock() - end)/CLOCKS_PER_SEC<<" s";
    if (CheckS1.size() == 0){
        cout<<"\nNo_SOLUTION";
    }
    else{
        int Sumtest = 0;
        for (int i = 1; i <= CheckS1.size(); i++)
            Sumtest += (CheckS1[i-1] == '+') ? i : (-1)*i;
        if (Sumtest == S1)
            cout<<"\nDung";
        else
            cout<<"\nSai";
    }
    if (CheckS2.size() == 0){
        cout<<"\nNo_SOLUTION";
    }
    else{
        int Sumtest = 0;
        for (int i = 1; i <= CheckS2.size(); i++)
            Sumtest += (CheckS2[i-1] == '+') ? i : (-1)*i;
        if (Sumtest == S1)
            cout<<"\nDung";
        else
            cout<<"\nSai";
    }
}