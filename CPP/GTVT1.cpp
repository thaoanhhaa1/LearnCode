#include <bits/stdc++.h>
using namespace std;

struct VienBi{
    int x;
    char name;
};

void Nhap(FILE *f, VienBi *a, int *n){
    fscanf(f,"%d",n);
    a = (VienBi*)malloc(*n*sizeof(VienBi));
    for (int i = 0; i < *n; i++){
        fscanf(f,"%d %d %c",&(a+i)->x,&(a+i)->name);
        printf("%d %d %c\n",(a+i)->x,(a+i)->name);
    }
}

void Kiemtra(VienBi *a, int n){
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if ((a+i)->x == (a+j)->x){
                printf("Co 2 vien bi nam cung vi tri tren truc toa do\n");
                return;
            }
    printf("Khong co 2 vien bi nao nam cung vi tri tren truc toa do\n");
}

void Sosanh(VienBi *a, int n){
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if ((a+i)->name > (a+j)->name){
                VienBi tg = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tg;
            }
            else if ((a+i)->x > (a+j)->x){
                VienBi tg = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tg;
            }
    
}

int main()
{
    FILE *f = fopen("bi.txt","r");
    VienBi *a;
    int n;
    Nhap(f,a,&n);
}