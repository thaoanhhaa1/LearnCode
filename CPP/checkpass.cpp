#include <iostream>

using namespace std;

bool Check_Up(string s, int i, int j)
{
    for (int k = i; k <= j; k++)
        if (s[k] >= 'A' && s[k] <= 'Z')
            return true;
    return false;
}

bool Check_Lower(string s, int i, int j)
{
    for (int k = i; k <= j; k++)
        if (s[k] >= 'a' && s[k] <= 'z')
            return true;
    return false;
}

bool Check_Number(string s, int i, int j)
{
    for (int k = i; k <= j; k++)
        if (s[k] >= '0' && s[k] <= '9')
            return true;
    return false;
}

int  checkpass(string s)
{
    int dem = 0;
    if (s.size() < 6)
        return 0;
    for (int i = 0; i < s.size()-6; i++)
        for (int j = i+5; j < s.size(); j++)
            if (Check_Up(s,i,j) && Check_Lower(s,i,j) && Check_Number(s,i,j))
                dem++;
    return dem;
}

int main()
{
    cout<<checkpass("abc3456789PQ");
}