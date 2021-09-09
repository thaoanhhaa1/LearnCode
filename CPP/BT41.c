#include <stdio.h>
#include <string.h>

typedef struct{
    char TenMay[30];
    char SoSeri[12];
    float GiaTien;
}MayTinh;

void NhapTT(MayTinh *MT, int n){
    for (int i = 0; i < n; i++){
        fflush(stdin);
        printf("Nhap ten may: ");
        gets((MT+i)->TenMay);
        printf("Nhap so seri: ");
        gets((MT+i)->SoSeri);
        printf("Nhap gia tien: ");
        scanf("%f",&((MT+i)->GiaTien));
    }
}

void XuatTT(MayTinh *MT, int n){
    printf("Ten may         So seri     Giatien     \n");
    for (int i = 0; i < n; i++)
        printf("%-15s %-11s %f\n",(MT+i)->TenMay,(MT+i)->SoSeri,(MT+i)->GiaTien);
}

void ShowGiaTien(MayTinh *MT, int n){
    printf("\nNhung may co gia tien > 10000\n");
    printf("Ten may         So seri     Giatien     \n");
    for (int i = 0; i < n; i++)
        if ((MT+i)->GiaTien > 10000)
            printf("%-15s %-11s %f\n",(MT+i)->TenMay,(MT+i)->SoSeri,(MT+i)->GiaTien);
}

void ShowSeri(MayTinh *MT, int n){
    char Seri[12];
    printf("Nhap so seri can xem: ");
    fflush(stdin);
    gets(Seri);
    printf("Ten may         So seri     Giatien     \n");
    for (int i = 0; i < n; i++)
        if (!strcmp(Seri,(MT+i)->SoSeri))
            printf("%-15s %-11s %f\n",(MT+i)->TenMay,(MT+i)->SoSeri,(MT+i)->GiaTien);
}

void WriteFile(MayTinh *MT, int n){
    FILE *f;
    f = fopen("D:\\data41.txt","w");
    for (int i = 0; i < n; i++)
        if (!strcmp("ACER",(MT+i)->TenMay)){
            fprintf(f,"%s\n%s\n%f\n",(MT+i)->TenMay,(MT+i)->SoSeri,(MT+i)->GiaTien);
        }
    fclose(f);
}

int main(){
    int n;
    printf("Nhap so may tinh: ");
    scanf("%d",&n);
    MayTinh *MT = (MayTinh*)malloc(n*sizeof(MayTinh));
    NhapTT(MT,n);
    //XuatTT(MT,n);
    //ShowSeri(MT,n);
    WriteFile(MT,n);
}