#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Sach {
    char MaSach[11];
    char TenSach[50];
    char TenTG[50];
    char LoaiSach[3];
    int NamSB;
    double GiaTien;
    int SoLuong;
}CuonSach;

CuonSach* NhapSach(int n){
    // printf("Nhap so cuon sach: ");
    // scanf("%d",&(*n));
    // fflush(stdin);
    // for (int i = 0; i < *n; i++){
    //     printf("\nNhap cuon sach thu %d\n",i+1);
    //     printf("Nhap ma sach: ");
    //     scanf("%s",&a[i].MaSach);
    //     fflush(stdin);
    //     printf("Nhap ten sach: ");
    //     gets(a[i].TenSach);
    //     printf("Nhap ten tac gia: ");
    //     gets(a[i].TenTG);
    //     printf("Nhap loai sach: ");
    //     scanf("%s",&a[i].LoaiSach);
    //     printf("Nhap nam xuat ban: ");
    //     scanf("%d",&a[i].NamSB);
    //     printf("Nhap gia tien: ");
    //     scanf("%lf",&a[i].GiaTien);
    //     printf("Nhap so luong: ");
    //     scanf("%d",&a[i].SoLuong);
    //     fflush(stdin);
    // }
}

void Xuat1Sach(CuonSach a){
    printf("Ma sach: %s\n",a.MaSach);
    printf("Ten sach: %s\n",a.TenSach);
    printf("Ten tac gia: %s\n",a.TenTG);
    printf("Loai sach: %s\n",a.LoaiSach);
    printf("Nam xuat ban: %d\n",a.NamSB);
    printf("Gia tien: %lf\n",a.GiaTien);
    printf("So luong: %d\n",a.SoLuong);
}

void XuatSach(CuonSach a[], int n){
    for (int i = 0; i < n; i++){
        printf("\nThong tin cuon sach thu %d: \n",i+1);
        Xuat1Sach(a[i]);
    }
}

void XuatFileB(CuonSach a[], int n){
    FILE *f;
    if ((f = fopen("CuonSach.bin","wb")) == NULL){
       printf("Error! opening file");
       return;
    }
    for (int i = 0; i < n; i++)
        fwrite(&a[i], sizeof(CuonSach), 1, f); 
    fclose(f);
}

void NhapFileB(CuonSach a[], int *n){
    FILE *f;
    if ((f = fopen("CuonSach.bin","rb")) == NULL){
       printf("Error!");
       return;
    }
    *n = 0;
    while (fread(&a[*n], sizeof(CuonSach), 1, f))
        *n += 1;
    fclose(f);
}

void TongTien(CuonSach a[], int n){
    double Sum = 0;
    for (int i = 0; i < n; i++)
        Sum += a[i].GiaTien*a[i].SoLuong;
    printf("Tong tien la: %lf",Sum);
}

void Sort(CuonSach a[], int n){
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (strcmp(a[i].MaSach,a[j].MaSach) > 0){
                CuonSach TG = a[i];
                a[i] = a[j];
                a[j] = TG;
            }
}

void FindSach(CuonSach a[], int *n){
    char X[11];
    printf("Nhap ma sach can tim: ");
    scanf("%s",&X);
    for (int i = 0; i < *n; i++)
        if (!strcmp(a[i].MaSach,X)){
            for (int j = i; j < *n-1; j++)
                a[j] = a[j+1];
            *n--;
            return;
        }
    printf("Khong co cuon sach co ma sach la %s\n");
}

void XuatSachTN(CuonSach a[], int n){
    for (int i = 0; i < n; i++)
        if (!strcmp(a[i].LoaiSach,"TN"))
            Xuat1Sach(a[i]);
}

int main(){
    int n = 10;
    CuonSach a[] = {
        {"2011040111","Mang may tinh","Le Duy Anh","TN",2000,5.4,3},
        {"2011063222","Van hoc the gioi","Kieu Ngoc My Nhan","XH",2001,6.8,4},
        {"2011210555","Khoa hoc thoi nay","Nguyen Thanh Trung","TN",2002,8.1,7},
        {"2011140777","Lap trinh Python","Do Tuan Hung","TN",2002,5.9,1},
        {"2011062121","Lap trinh Huong doi tuong","Nguyen Duy Cuong","TN",2001,7.2,8},
        {"2011043999","Thien Van Hoc","Vu Thi Kim Chi","TN",2001,7.2,8},
        {"2011064888","Vat ly hoc hien dai","Tran Kien Cuong","TN",2002,7.7,2},
        {"2011062666","Cau truc du lieu","Ly Tieu Long","TN",2002,4.7,4},
        {"2011062333","Hoa hoc 12","Do Thanh Hieu","TN",2001,8.3,3},
        {"2011065000","Vu khi sinh hoc","Ho Thi Dung","XH",2000,6.5,6}
    };
    while(1){
        printf("1. Nhap thong tin cac cuon sach\n");
        printf("2. Xuat thong tin cac cuon sach\n");
        printf("3. Ghi thong tin cac cuon sach ra file nhi phan\n");
        printf("4. Doc thong tin cac cuon sach tu file nhi phan\n");
        printf("5. Tinh tong tien cac cuon sach\n");
        printf("6. Sap xep theo 'Ma Sach' tang dan\n");
        printf("7. Tim sach va xoa theo ma sach\n");
        printf("8. Xuat sach loai 'Tu nhien'\n");
        printf("0. Ket thuc\n");
        int x;
        printf("Moi nhap lua chon: ");
        scanf("%d",&x);
        fflush(stdin);
        switch (x)
        {
        case 1:
            
            break;
        
        case 2:
            XuatSach(a,n);
            break;

        case 3:
            XuatFileB(a,n);
            break;

        case 4:
            NhapFileB(a,&n);
            break;

        case 5:
            TongTien(a,n);
            break;

        case 6:
            Sort(a,n);
            break;

        case 7:
            FindSach(a,&n);
            break;

        case 8:
            XuatSachTN(a,n);
            break;

        default:
            break;
        }
    }
}