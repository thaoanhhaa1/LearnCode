#include <stdio.h>
#include <string.h>

typedef struct Date
{
    int d, m, y;
}Date;

typedef struct Nhanvien
{
    char maso[11], HoTen[30], Noisinh[50], Diachi[50];
    float Luong;
    Date Ngaysinh, Ngaycongtac;
}Nhanvien;

void Xuat1Nhanvien(Nhanvien a)
{
    printf("Ma nhan vien: %s",a.maso);
    printf("Ho ten: %s",a.HoTen);
    printf("Ngay sinh: %d/%d/%d\n",a.Ngaysinh.d,a.Ngaysinh.m,a.Ngaysinh.y);
    printf("Noi sinh: %s",a.Noisinh);
    printf("Dia chi: %s",a.Diachi);
    printf("Ngay cong tac: %d/%d/%d\n",a.Ngaycongtac.d,a.Ngaycongtac.m,a.Ngaycongtac.y);
    printf("Luong: %f\n",a.Luong);
}

void NhapdanhsachNhanvien(Nhanvien a[], int *n)
{
    printf("Nhap so nhan vien: ");
    scanf("%d",&(*n));
    printf("\n___NHAP THONG TIN___\n");
    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap nhan vien thu %d: \n",i);
        fflush(stdin);
        int kt;
        do
        {
            kt = 0;
            printf("Nhap ma nhan vien: ");
            fgets(a[i].maso,sizeof(a[i].maso),stdin);
            for (int j = 0; j < i; j++)
                if (!strcmp(a[i].maso,a[j].maso))
                {
                    kt = 1;
                    break;
                }
        } while (kt == 1);
        printf("Nhap ho ten: ");
        fgets(a[i].HoTen,sizeof(a[i].HoTen),stdin);
        printf("Nhap ngay sinh: ");
        scanf("%d%d%d",&a[i].Ngaysinh.d,&a[i].Ngaysinh.m,&a[i].Ngaysinh.y);
        fflush(stdin);
        printf("Nhap noi sinh: ");
        fgets(a[i].Noisinh,sizeof(a[i].Noisinh),stdin);
        printf("Nhap dia chi: ");
        fgets(a[i].Diachi,sizeof(a[i].Diachi),stdin);
        printf("Ngay cong tac: ");
        scanf("%d%d%d",&a[i].Ngaycongtac.d,&a[i].Ngaycongtac.m,&a[i].Ngaycongtac.y);
        printf("Nhap luong: ");
        scanf("%f",&a[i].Luong);
        fflush(stdin);
    }
}

void XuatdanhsachNhanvien(Nhanvien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhan vien thu %d: \n",i);
        Xuat1Nhanvien(a[i]);
    }
}

void Timnhanvien(Nhanvien a[], int n)
{
    char Maso[11];
    printf("Nhap ma so nhan vien can tim: ");
    fgets(Maso,sizeof(Maso),stdin);
    printf("\nThong tin nhan vien can tim la: \n");
    for (int i = 0; i < n; i++)
        if (!strcmp(Maso,a[i].maso))
        {
            Xuat1Nhanvien(a[i]);
            return;
        }
}

void SapxepLuong(Nhanvien a[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (a[i].Luong < a[j].Luong)
            {
                Nhanvien tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
}

void Xoa1Nhanvien(Nhanvien a[], int n)
{
    char Maso[11];
    printf("Nhap ma so nhan vien can xoa: ");
    fgets(Maso,sizeof(Maso),stdin);
    int i = 0;
    while (i < n && strcmp(Maso,a[i].maso) != 0)
        i++;
    for (; i < n; i++)
        a[i] = a[i+1];
}

int main()
{
    Nhanvien a[30];
    int n;
    NhapdanhsachNhanvien(a,&n);
    printf("\n___XUAT THONG TIN___\n");
    XuatdanhsachNhanvien(a,n);
    printf("\n\n___TIM NHAN VIEN___\n");
    Timnhanvien(a,n);
    printf("\n\n___SAP XEP LUONG GIAM___");
    SapxepLuong(a,n);
    XuatdanhsachNhanvien(a,n);
    printf("\n\n___XOA NHAN VIEN___\n");
    Xoa1Nhanvien(a,n--);
    XuatdanhsachNhanvien(a,n);
}
