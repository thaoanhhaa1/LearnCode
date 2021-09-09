#include <bits/stdc++.h>

struct MatHang{
    char TenHang[50];
    int SoLuong;
};

void XuatFile(){
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    fflush(stdin);
    MatHang a;
    FILE *f = fopen("mathang.dat","w");
    if (f == NULL){
        printf("Mo file loi\n");
        return;
    }
    for (int i = 0; i < n; i++){
        printf("Nhap ten mat hang: ");
        // gets(a.TenHang);
        fgets(a.TenHang,sizeof(a.TenHang),stdin);
        printf("Nhap so luong mat hang %s: ",a.TenHang);
        scanf("%d",&a.SoLuong);
        fflush(stdin);
        fwrite(&a,sizeof(a),1,f);
    }
    fclose(f);
}

void DocFile(){
    FILE *f = fopen("mathang.dat","r");
    MatHang a, b;
    b.SoLuong = 2*1e+9;
    printf("\nDanh Sach Cac Mat Hang Da Nhap: \n");
    while (fread(&a,sizeof(a),1,f)){
        printf("%s %d\n",a.TenHang,a.SoLuong);
        if (a.SoLuong < b.SoLuong)
            b = a;
    }
    printf("\nMat hang co so luong nho nhat: \n");
    printf("%s %d\n",b.TenHang,b.SoLuong);
    fclose(f);
}

int main(){
    XuatFile();
    DocFile();
}