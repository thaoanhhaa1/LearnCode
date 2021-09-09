#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    int tam;
    set<int> kg;
    for (int i = 0; i < n; i++){
        cin>>tam;
        set<int> Tam;
        for (set<int>::iterator it = kg.begin(); it != kg.end(); ++it)
            Tam.insert(*it + tam);
        kg.insert(tam);
        for (set<int>::iterator it = Tam.begin(); it != Tam.end(); ++it)
            kg.insert(*it);
    }
    string s = "";
    for (int i = 0; i < m; i++){
        cin>>tam;
        if (kg.find(tam) != kg.end())
            s += '1';
        else
            s += '0';
    }
    cout<<s;
}