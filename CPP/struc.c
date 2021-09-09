#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

typedef	struct sanpham {
	char masp[11];
	char tensp[30];
	char dvt[30];
	float giaban;
	int soluong;
}sanpham;
void NhapSanPham(sanpham *x);
void XuatSanPham(sanpham x);
void NhapDsSanPham(sanpham a[], int *n);
void XuatDsSanPham(sanpham a[], int n);
float GiaBanMax(sanpham a[], int n);
void SanPhamMax(sanpham a[], int n);
int TongSoLuong(sanpham a[], int n);
int SanPhamTren30000(sanpham a[], int n);
void InSanPhamCai(sanpham a[], int n);
//void TimSanPhamSua(sanpham a[], int n);
int main()
{
	sanpham dssp[30];
	int sosp;
	NhapDsSanPham(dssp, &sosp);
	XuatDsSanPham(dssp, sosp);
	printf("\nGia ban cao nhat %f", GiaBanMax(dssp, sosp));
	SanPhamMax(dssp, sosp);
	printf("\nTong So luong cac san pham la %d ", TongSoLuong(dssp, sosp));
	printf("\nSan pham co gia tren 30000 la %d ", SanPhamTren30000(dssp, sosp));
	printf("\nSan pham co dvt la cai ");
	InSanPhamCai(dssp, sosp);
	printf("\nSan pham sua la ");
	//TimSanPhamSua(dssp, sosp);
}
void NhapSanPham(sanpham *x)
{
	printf("Nhap ma san pham: ");
	fflush(stdin);
    //fgets(x.masp);
    fgets(x->masp, sizeof(x->masp), stdin);
	printf("Nhap ten san pham: ");
	//gets_s(x.tensp);
	fgets(x->tensp, sizeof(x->tensp), stdin);
	printf("Nhap dvt san pham: ");
	//gets_s(x.dvt);
	fgets(x->dvt, sizeof(x->dvt), stdin);
	printf("Nhap gia ban: ");
	scanf("%f", &x->giaban);
	printf("\nNhap so luong: ");
	scanf("%d", &x->soluong);
}
void XuatSanPham(sanpham x)
{
	printf("\n%s\t%s\t%s\t%f\t%d", x.masp, x.tensp, x.dvt, x.giaban, x.soluong);
}
void NhapDsSanPham(sanpham a[], int *n)
{
	do {
		printf("Nhap so luong san pham: ");
		scanf("%d", &(*n));
	} while (n <= 0);
	fflush(stdin);
	for (int i = 0; i < *n; i++)
	{
		printf("\nSan pham thu %d: \n", i);
		NhapSanPham(&a[i]);
	}
}
void XuatDsSanPham(sanpham a[], int n)
{
	for (int i = 0; i < n; i++)
		XuatSanPham(a[i]);
}
float GiaBanMax(sanpham a[], int n)
{
	float max = a[0].giaban;
	for (int i = 0; i < n; i++)
		if (max < a[i].giaban)
			max = a[i].giaban;
	return max;
}
void SanPhamMax(sanpham a[], int n)
{
	float max1 = GiaBanMax(a, n);
	for (int i = 0; i < n; i++)
		if (a[i].giaban == max1)
			XuatSanPham(a[i]);
}
int TongSoLuong(sanpham a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i].soluong;
	return sum;
}
int SanPhamTren30000(sanpham a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i].giaban >= 30000)
			dem++;
	return dem;
}
void InSanPhamCai(sanpham a[], int n)
{
	for (int i = 0; i < n; i++)
		if (strcmp(a[i].dvt, "cai"))
			XuatSanPham(a[i]);
}
/*void TimSanPhamSua(sanpham a[], int n)
{
	for (int i = 0; i < n; i++)
		if (strchr(a[i].tensp,)  != NULL)
			XuatSanPham(a[i]);
}*/