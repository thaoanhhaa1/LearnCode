#include <iostream>
#include <string.h>

using namespace std;

char *XoaTrai(char *s, char x, int pos){
    int n = strlen(s);
    for (int i = pos-1; i >= 0; i--)
        if (s[i] == x)
        {
            for (int j = i+1; j < n; j++)
                s[j-1] = s[j];
            n--;
        }
    s[n] = '\0';
    return s;
}

char *XoaPhai(char *s, char x, int pos){
    int n = strlen(s);
    for (int i = n-1; i >= pos; i--)
        if (s[i] == x)
        {
            for (int j = i+1; j < n; j++)
                s[j-1] = s[j];
            n--;
        }
    s[n] = '\0';
    return s;
}

char *XoaHet(char *s, char x){
    int n = strlen(s);
    for (int i = n-1; i >= 0; i--)
        if (s[i] == x)
        {
            for (int j = i+1; j < n; j++)
                s[j-1] = s[j];
            n--;
        }
    s[n] = '\0';
    return s;
}

char *TrichTrai(char *s, int len){
    s[len] = '\0';
    return s;
}

char *TrichPhai(char *s, int len){
    char *p = new char;
    int n = strlen(s), i = n - len, j = 0;
    while (i < n)
        p[j++] = s[i++];
    return p;
}

char *TrichGiua(char *s, int pos, int len){
    char *p = new char;
    int n = strlen(s);
    for (int i = 0; i < len; i++)
        p[i] = s[i+pos];
    p[len] = '\0';
    return p;
}

int main()
{
    char *s;
    gets(s);
    //char *p = TrichGiua(s,2,4);
    cout<<TrichGiua(s,2,4);
    //cout<<endl;
    //delete p;
    delete s;
}