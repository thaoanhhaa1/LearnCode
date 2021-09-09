#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct SV{
    char HT[30], Truong[30];
    double Diem;
};

void Cau1(SV sv[], int n){
    double A, B, C;
    for (int i = 0; i < n; i++)
        if (!strcmp(sv[i].Truong,"A"))
            A += sv[i].Diem;
        else if (!strcmp(sv[i].Truong,"B"))
            B += sv[i].Diem;
        else
            C += sv[i].Diem;
    if (A <= B  && A <= C)
        printf("Truong A co tong diem thap nhat");
    else if (B <= A && B <= C)
        printf("Truong B co tong diem thap nhat");
    else
        printf("Truong C co tong diem thap nhat");
}

void Cau2(SV sv[], int n){
    double Diem = sv[0].Diem;
    for (int i = 1; i < n; i++)
        if (sv[i].Diem > Diem)
            Diem = sv[i].Diem;
    FILE *f;
    f = fopen("cao nhat.txt","w");
    for (int i = 0; i < n; i++)
        if (sv[i].Diem == Diem){
            fprintf(f,"%s\n",sv[i].HT);
            fprintf(f,"%s\n",sv[i].Truong);
        }
}

void Cau3(SV sv[], int n){
    char s[10];
    double diem = 0;
    int dem = 0;
    printf("Nhap ho: ");
    gets(s);
    for (int i = 0; i < n; i++)
        if (!strncmp(sv[i].HT,s,strlen(s))){
            diem += sv[i].Diem;
            dem++;
        }
    printf("Diem trung binh cua ho %s la: %f",s,diem/dem);
}

int main()
{
    int n;
    SV sv[n];
    cout<<("Ha" == "Ha");
}