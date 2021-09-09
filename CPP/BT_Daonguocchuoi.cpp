#include <iostream>

using namespace std;

string Daonguocchuoi(string s, int n)
{
    if (n == 0)
        return "";
    return s[n-1] + Daonguocchuoi(s,n-1);
}

int main()
{
    string s;
    cin>>s;
    cout<<Daonguocchuoi(s,s.length());
}