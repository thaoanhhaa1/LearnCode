#include <bits/stdc++.h>
using namespace std;

struct VDV{
    char HoTen[50];
    float ChieuCao, CanNang;
};



void Thongke(VDV *a, int n){
    int tk[121];
    memset(a,0,sizeof tk);
    for (int i = 0; i < n; i++)
        if ((a+i)->CanNang >= 1 && (a+i)->CanNang <= 120)
            tk[int((a+i)->CanNang)]++;
    for (int i = 1; i <= 120; i++)
        if (tk[i] != 0)
            printf("Co %d van dong vien nang %d kg\n",tk[i],i);
}

void Cau2(VDV *a, int n){
    int max = 0, vt;
    for (int i = 0; i < n; i++)
        if (a[i].ChieuCao > max && a[i].CanNang < 60){
            max = a[i].ChieuCao;
            vt = i;
        }
    printf("%s %d %d",a[vt].HoTen,a[vt].ChieuCao,a[vt].CanNang);
}



int main()
{
    FILE *f = fopen("Bongchuyen.txt","r");
    VDV vdv[10000];
    int n;
    Nhap(f,vdv,n);
    cout<<n<<endl;
    Thongke(vdv,n);
    fclose(f);
}