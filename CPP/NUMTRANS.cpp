#include <iostream>

using namespace std;

bool operator<(string s1, string s2){
    int n = min(s1.size(),s2.size());
    for (int i = 0; i < n; i++)
        if (s1[i] > s2[i])
            return false;
        else if (s1[i] < s2[i])
            return true;
    if (s1.size() >= s2.size())
        return true;
    return false; 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;
    string a[n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (a[i] < a[j])
                swap(a[i],a[j]);
    for (int i = 0; i < n; i++)
        cout<<a[i];
}