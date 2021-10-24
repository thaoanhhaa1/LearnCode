#include <iostream>
#include <stack>

using namespace std;

int doUuTien(char x)
{
    if (x == '+' || x == '-')
        return 0;
    if (x == '*' || x == '/')
        return 1;
    if (x == '$')
        return 2;
    return 3;
}

string chuyenSangHauTo(string s, int l, int r)
{
    int num = 0;
    string kq = "";
    stack<char> toanTu;
    for (int i = l; i <= r; i++)
        if (s[i] >= '0' && s[i] <= '9')
            num = num * 10 + (s[i] - '0');
        else if (s[i] == '(')
        {
            int j = i + 1;
            for (; j <= r; j++)
                if (s[j] == ')')
                    break;
            kq += chuyenSangHauTo(s, i + 1, j - 1);
            if (j + 1 <= r)
                toanTu.push(s[j + 1]);
            i = j + 1;
        }
        else
        {
            kq += ' ' + to_string(num);
            num = 0;
            if (toanTu.empty())
                toanTu.push(s[i]);
            else if (doUuTien(toanTu.top()) >= doUuTien(s[i]))
            {
                while (!toanTu.empty() && doUuTien(toanTu.top()) >= doUuTien(s[i]))
                {
                    kq = kq + ' ' + toanTu.top();
                    toanTu.pop();
                }
                toanTu.push(s[i]);
            }
            else
                toanTu.push(s[i]);
        }
    if (s[r] != ')')
        kq += ' ' + to_string(num);
    while (!toanTu.empty())
    {
        kq = kq + ' ' + toanTu.top();
        toanTu.pop();
    }
    return kq;
}

int main()
{
    string s;
    cout << "Nhap bieu thuc: ";
    cin >> s;
    cout <<"Ket qua: "<< chuyenSangHauTo(s, 0, s.size() - 1).substr(1);
}