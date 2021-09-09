#include <iostream>
#include <stdio.h>

using namespace std;

void Reverse()
{
    char s;
    scanf("%c",&s);
    if (s != '\n')
    {
        Reverse();
        cout<<s;
    }
}

int main()
{
    Reverse();
}