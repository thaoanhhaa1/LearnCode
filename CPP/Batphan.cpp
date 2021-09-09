#include <iostream>
#include <string.h>

using namespace std;

void DeQuy(long long a){
    if (a < 8){
        cout<<a;
        return;
    }
    DeQuy(a/8);
    cout<<a%8;
}

void KoDeQuy(long long a){
    string s = "";
    while (a >= 8){
        s = char(int(a%8) + '0') + s;
        a /= 8;
    }
    s = char(int(a%8) + '0') + s;
    cout<<s;
}

char* XoaGiua(char *s, int pos, int len) {
    int j = 0, dem = 0;
    char *kq;
    for (int i = 0; i < strlen(s); i++)
        if (i >= pos+j && i < pos+len){
            j++;
            continue;
        }
        else{
            kq[dem] = s[i];
            dem++;
        }
    return kq;
}

int main()
{
    char *s;
    gets(s);
    cout<<XoaGiua(s,3,3);
}