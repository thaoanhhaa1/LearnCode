#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    vector<int> a = {100,60,60,40,30,30,10};
    set<int> b(a.begin(),a.end());
    cout<<b.size();
}