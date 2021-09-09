#include <iostream>

using namespace std;

class NoalNum{
    private:
        string s;
    public:
        NoalNum(){
            getline(cin,s);
        }
        int Dem(){
            int dem = 0;
            for (int i = 0; i < s.size(); i++)
                if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'))
                    dem++;
            return dem;
        }
};

int main()
{
    NoalNum a;
    cout<<a.Dem();
}