#include <iostream>
#include<stdio.h>
using namespace std;

/*
Đ?i 1 s? nguyên sang co s? 2 

*/

// khai báo 1 cái node
struct node
{
	int data;
	struct node *pNext;
};
typedef struct node NODE;
// khai báo c?u trúc c?a 1 cái stack
struct stack
{
	NODE *pTop; // con tr? qu?n lí d?u stack
};
typedef struct stack STACK;

// hàm kh?i t?o stack
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

// hàm kh?i t?o 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // dua d? li?u c?a bi?n x vào trong cái data c?a node p
	p->pNext = NULL;
	return p;
}

/* ================= KI?M TRA STACK R?NG =================*/ 
bool IsEmpty(STACK s)
{
	// n?u stack r?ng
	if (s.pTop == NULL)
	{
		return false;
	}
	return true;
}

/* ================= THÊM PH?N T? VÀO Đ?U STACK =================*/
bool Push(STACK &s, NODE *p)
{
	// node p dang r?ng
	if (p == NULL)
	{
		return false;
	}

	// n?u danh sách r?ng
	if (IsEmpty(s) == false)
	{
		s.pTop = p;// node p cung chính là node pTop <=>chính là node d?u stack
	}
	else
	{
		p->pNext = s.pTop; // B1: cho con tr? c?a node p tr? d?n node pTop
		s.pTop = p;// c?p nh?t l?i node d?u chính là node p
	}
	return true;// thêm thành công
}

/* ================= L?Y PH?N T? Đ?U DANH SÁCH VÀ H?Y NÓ ĐI ================= */
bool Pop(STACK &s, int &x) // x chính là giá tr? c?n l?y ra
{
	// n?u danh sách r?ng
	if (IsEmpty(s) == false)
	{
		return false; // l?y th?t b?i <=> danh sách dang r?ng
	}
	NODE *p = s.pTop; // gán node d?u danh sách vào node p <=> node p chính là node mà tí n?a ta s? xóa nó
	s.pTop = s.pTop->pNext; // c?p nh?t l?i node d?u 
	x = p->data; // l?y giá tr? c?a node d?u ra gán vào bi?n x
	return true; // l?y ph?n t? thành công
}

/* ================= XEM THÔNG TIN C?A NODE Đ?U DANH SÁCH ================= */
bool Top(STACK s, int &x) // x chính là giá tr? c?n xem
{
	// n?u danh sách r?ng

	if (IsEmpty(s) == false)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}

// HÀM Đ?I CO S? 10 SANG CO S? 2 8 16
void Chuyen_So_So(STACK &s, int cosocandoi, int hethapphan)
{
	while (hethapphan != 0)
	{
		int x = hethapphan % cosocandoi;
		NODE *p = KhoiTaoNode(x); // thêm x vào node p
		Push(s, p); // thêm node p vào stack
		hethapphan /= cosocandoi;
	}
}

// xu?t danh sách stack
char xx[] = {'A','B','C','D','E','F'};
void XuatStack(STACK &s)
{
	while (IsEmpty(s) == true)
	{
		int x;
		Pop(s, x);
		if (x < 10)
			cout << x;
		else
            cout<<xx[x%10];
	}
}



int main()
{
	STACK s;
	KhoiTaoStack(s);
	
	int hethapphan;
	cout << "\nNhap gia tri he thap phan(10) can chuyen: ";
	cin >> hethapphan;
	int cosocandoi;
	cout << "\nNhap co so can chuyen(2):  ";
	cin >> cosocandoi;

	Chuyen_So_So(s, cosocandoi, hethapphan);
	cout << "\nKET QUA\n";
	XuatStack(s);
	cout << endl;

	system("pause");
	return 0;
}
