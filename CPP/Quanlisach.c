#include <stdio.h>

typedef struct Sach
{
    char MaSach[11], TenSach[30], TacGia[30], NhaXB[30];
    int NamXB, SoLuong;
    float GiaBan;
}Sach;

void Nhap1Sach(Sach *a)
{
    fflush(stdin);
    printf("Nhap ma sach: ");
    fgets(a->MaSach,sizeof(a->MaSach),stdin);
    printf("Nhap ten sach: ");
    fgets(a->TenSach,sizeof(a->TenSach),stdin);
    printf("Nhap tac gia: ");
    fgets(a->TacGia,sizeof(a->TacGia),stdin);
    printf("Nhap nam xuat ban: ");
    scanf("%d",&a->NamXB);
    fflush(stdin);
    printf("Nhap nha xuat ban: ");
    fgets(a->NhaXB,sizeof(a->NhaXB),stdin);
    printf("Nhap gia ban: ");
    scanf("%f",&a->GiaBan);
    printf("Nhap so luong: ");
    scanf("%d",&a->SoLuong);
}

void NhapSach(Sach a[], int *n)
{
    printf("Nhap so luong sach: ");
    scanf("%d",&(*n));
    printf("\n___NHAP THONG TIN SACH___\n");
    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap sach thu %d: \n",i);
        Nhap1Sach(&a[i]);
    }
}

void Xuat1Sach(Sach a)
{
    printf("Ma sach: %s",a.MaSach);
    printf("Ten sach: %s",a.TenSach);
    printf("Tac gia: %s",a.TacGia);
    printf("Nam xuat ban: %d\n",a.NamXB);
    printf("Nha xuat ban: %s",a.NhaXB);
    printf("Gia ban: %f\n",a.GiaBan);
    printf("So luong: %d\n",a.SoLuong);
}

void XuatSach(Sach a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nSach thu %d: \n",i);
        Xuat1Sach(a[i]);
    }
}

void TimsachtheoTen(Sach a[], int n)
{
    fflush(stdin);
    char TenSach[30];
    printf("Nhap ten sach can tim: ");
    fgets(TenSach,sizeof(TenSach),stdin);
    printf("\nNhung sach co ten la: %s\n",TenSach);
    for (int i = 0; i < n; i++)
        if (!strcmp(a[i].TenSach,TenSach))
        {
            Xuat1Sach(a[i]);
            printf("\n");
        }
}

void TimsachtheoTacgia(Sach a[], int n)
{
    fflush(stdin);
    char TenSach[30];
    printf("Nhap tac gia can tim: ");
    fgets(TenSach,sizeof(TenSach),stdin);
    printf("\nNhung sach co tac gia la: %s\n",TenSach);
    for (int i = 0; i < n; i++)
        if (!strcmp(a[i].TacGia,TenSach))
        {
            Xuat1Sach(a[i]);
            printf("\n");
        }
}

void TimsachtheoNXB(Sach a[], int n)
{
    fflush(stdin);
    char TenSach[30];
    printf("Nhap nha xuat ban sach can tim: ");
    fgets(TenSach,sizeof(TenSach),stdin);
    printf("\nNhung sach co nha xuat ban la: %s\n",TenSach);
    for (int i = 0; i < n; i++)
        if (!strcmp(a[i].NhaXB,TenSach))
        {
            Xuat1Sach(a[i]);
            printf("\n");
        }
}

int VTGiaMin(Sach a[], int n)
{
    int vt = 0;
    for (int i = 1; i < n; i++)
        if (a[vt].GiaBan > a[i].GiaBan)
            vt = i;
    return vt;
}

void GiaBanMin(Sach a[], int n)
{
    Xuat1Sach(a[VTGiaMin(a,n)]);
}

int SoluongSach(Sach a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        dem += a[i].SoLuong;
    return dem;
}

int main()
{
    Sach a[30];
    int n;
    NhapSach(a,&n);
    printf("\n___XUAT THONG TIN SACH___\n");
    XuatSach(a,n);
    printf("\n___TIM SACH THEO TEN___\n");
    TimsachtheoTen(a,n);
    printf("\n___TIM SACH THEO TAC GIA___\n");
    TimsachtheoTacgia(a,n);
    printf("\n___TIM SACH THEO NXB___\n");
    TimsachtheoNXB(a,n);
    printf("\n___SACH CO GIA THAP NHAT___\n");
    GiaBanMin(a,n);
    printf("\n___TONG SACH___\n");
    printf("Tong so luong sach la: %d\n",SoluongSach(a,n));
}