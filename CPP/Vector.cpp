#include<iostream>
#include<vector>
using namespace std;
string sum(vector<string> s){
    int max = s[0].size();
    vector<string> w;
    for(int i = 0; i < s.size(); i++)
        if(max < s[i].size())
            max = s[i].size();
    for(int i = 0; i < s.size(); i++)
        if(max == s[i].size())
            return s[i];
}
int main(){
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
    cout << sum(a);
    return 0;
}