#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int luu[9][9];
int vt[9];
int dem = 0;


void checkHau(int x, int y)
{
    for (int i = 1; i <= 8; i++)
    {
        luu[x][i] = 1;
        luu[i][y] = 1;
    }
    int i = x-1, j = y-1;
    while (i >= 1 && j >= 1)
    {
        luu[i][j] = 1;
        i--;
        j--;
    }
    i = x+1;
    j = y+1;
    while (i <= 8 && j <= 8)
    {
        luu[i][j] = 1;
        i++;
        j++;
    }
    i = x + 1;
    j = y - 1;
    while (i <= 8 && j >= 1)
    {
        luu[i][j] = 1;
        i++;
        j--;
    }
    i = x - 1;
    j = y + 1;
    while (i >= 1 && j <= 8)
    {
        luu[i][j] = 1;
        i--;
        j++;
    }
}

void Inkq()
{
        dem++;
        for (int i = 1; i <= 8; i++)
            cout<<i<<" "<<vt[i]<<endl;
        cout<<endl;
}

void Gan_tam(int tam[][9])
{
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            tam[i][j] = luu[i][j];
}


void Tra_tam(int tam[][9])
{
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            luu[i][j] = tam[i][j];
}

void xuli(int x)
{
    for (int j = 1; j <= 8; j++)
        if (luu[x][j] == 0)
        {
            int tam[9][9];
            Gan_tam(tam);
            vt[x] = j;
            checkHau(x,j);
            if (x < 8)
                xuli(x+1);
            else
                Inkq();
            Tra_tam(tam);
        }

}

void All0()
{
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 8; j++)
            luu[i][j] = 0;
}

int main()
{
    for (int i = 1; i <= 8; i++)
    {
        All0();
        vt[1] = i;
        checkHau(1,i);
        xuli(2);
    }
    cout<<dem;
}
