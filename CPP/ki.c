#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include <conio.h>
#define KTM 30
void docFile(int a[], int* n);
void xuatMang(int a[], int n);
int TongMang(int a[], int n);
int Tongle(int a[], int n);
void XuatDuongLe(int a[], int n);
int Find200(int a[], int n);
int Amle(int a[], int n);
void XoaDau(int a[], int n);
int main()
{
		int arr[KTM], spt;
		docFile(arr, &spt);
		printf("\nGia tri cua mang doc tu file la :\n");
		xuatMang(arr, spt);
		printf("\nTong am le: %d\n",Tongle(arr,spt));
		printf("\nCac so duong le boi 3: \n");
		XuatDuongLe(arr,spt);
		if (Find200(arr,spt) == 1)
			printf("\n200 co trong mang\n");
		else
			printf("\n200 khong co trong mang\n");
		if (Amle(arr,spt) == 0)
			printf("Mang co phan tu khac am le");
		else
			printf("Mang toan bo am le");
		printf("\nMang sau khi xoa phan tu dau\n");
		XoaDau(arr,spt--);
		xuatMang(arr,spt);
		_getch();
}

void docFile(int a[], int* n)
{
		FILE* f = fopen("data.txt", "r+");
		if (f == NULL)
		{
			printf("\nLoi doc file");
			return;
		}
		fscanf_s(f,"%d", &(*n));
		for (int i = 0; i < *n; i++)
			fscanf_s(f, "%d", &a[i]);
		fclose(f);
}


void xuatMang(int a[], int n)
	{
		for (int i = 0; i < n; i++)
			printf("%3d", a[i]);
	}
int TongMang(int a[], int n)
	{
		int sum = 0;
		for (int i= 0; i < n; i++)
			sum += a[i];
		return sum;
	}
	
int Tongle(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < 0 && a[i] % 2 != 0)
            sum += a[i];
    return sum;
}

void XuatDuongLe(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] > 0 && a[i] % 2 != 0 && a[i] % 3 == 0)
            printf("%d ",a[i]);
}

int Find200(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] == 200)
            return i;
    return -1;
}

int Amle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (!(a[i] < 0 && a[i] % 2 == 1))
            return 0;
    return 1;
}

void XoaDau(int a[], int n)
{
    for (int i = 1; i < n; i++)
        a[i-1] = a[i];
    n--;
}	