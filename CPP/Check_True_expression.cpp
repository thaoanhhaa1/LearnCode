#include <iostream>

using namespace std;

int main()
{
    string KQ, tester;
    cin>>KQ;
    cin>>tester;
    int Sumkq = 0, Sumtest = 0;
    for (int i = 1; i <= KQ.size(); i++) {
        Sumkq += (KQ[i-1] == '+') ? i : (-1)*i;
        Sumtest += (tester[i-1] == '+') ? i : (-1)*i;
    }
    cout<<Sumkq<<" "<<Sumtest;
}