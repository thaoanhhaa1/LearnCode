#include<iostream>
#include<string>
#include<fstream>
using namespace std;
// it nhat 4 truong kieu du lieu khac nhau, ghi vao dong file roi ghi ra

typedef struct SinhVien
{
	char MSSV[20];
	char HoTen[50];
	char Gender; // F is Female, M is Male
	int NamSinh;
	char DiaChi[50];
	float DiemTB;
} SV;
void input(SV &a);
void output(SV a);
void outFile(SV a, ofstream &WriteFile);
void inputToFile(SV &temp, ifstream &ReadFile);
void outFileBin(SV &a, ofstream &WriteFileBin);
void inputToFileBin(SV &tam, ifstream &ReadFileBin);
int main()
{
	ofstream WriteFile ("FileSinhVien.txt");
	ofstream WriteFileBin ("FileBinNe.txt", ios::binary);
	SV a;
	input(a);
	outFile(a, WriteFile);
	outFileBin(a, WriteFileBin);
	ifstream ReadFile ("FileSinhVien.txt");
	ifstream ReadFileBin ("FileBinNe.txt", ios::binary);
	SinhVien temp, tam;
    inputToFileBin(tam, ReadFileBin);
	inputToFile(temp, ReadFile);
    output(temp);
	output(tam);
	return 0;
}

void input(SV &a)
{
	cout<<"Nhap vao Ma So Sinh Vien: ";
	gets(a.MSSV);
	cout<<"Nhap vao Ho va ten: ";
	gets(a.HoTen);
	do
	{
		cout<<"Nhap vao gioi tinh (F is Female, M is Male): ";
		cin>>a.Gender;
	} while (a.Gender != 'F' && a.Gender != 'M');
	cout<<"Nhap vap Nam Sinh: ";
	cin>>a.NamSinh;
	cin.ignore();
	cout<<"Nhap vao Dia Chi: ";
	gets(a.DiaChi);
	do
	{
		cout<<"Nhap vao diem trung binh (0 <= diem <= 10): ";
		cin>>a.DiemTB;
	} while (a.DiemTB > 10 || a.DiemTB < 0);
	cin.ignore();
}
void outFile(SV a, ofstream &WriteFile)
{
	WriteFile<<a.MSSV<<endl;
	WriteFile<<a.HoTen<<endl;
	WriteFile<<a.Gender<<endl;
	WriteFile<<a.NamSinh<<endl;
	WriteFile<<a.DiaChi<<endl;
	WriteFile<<a.DiemTB<<endl;
	
	WriteFile.close();
}
void inputToFile(SV &temp, ifstream &ReadFile)
{
	ReadFile.getline(temp.MSSV, 20);
	ReadFile.getline(temp.HoTen, 49);
	ReadFile.get(temp.Gender);
	//ReadFile.ignore(1);
	ReadFile>>temp.NamSinh;
	ReadFile.ignore(1);
	ReadFile.getline(temp.DiaChi, 50);
	ReadFile>>temp.DiemTB;
	ReadFile.ignore(1);
	ReadFile.close();
}
void output(SV a)
{
	cout<<a.MSSV<<endl;
	cout<<a.HoTen<<endl;
	if (a.Gender == 'M')
	{
		cout<<"Nam"<<endl;
	} else
	{
		cout<<"Nu"<<endl;;
	}
	cout<<a.NamSinh<<endl;
	cout<<a.DiaChi<<endl;
	cout<<a.DiemTB<<endl<<endl;
}
void outFileBin(SV &a, ofstream &WriteFileBin)
{
	WriteFileBin.write((char*)&a.MSSV, sizeof(SV));
	WriteFileBin.write((char*)&a.HoTen, sizeof(SV));
	WriteFileBin.write((char*)&a.Gender, sizeof(SV));
	WriteFileBin.write((char*)&a.NamSinh, sizeof(SV));
	WriteFileBin.write((char*)&a.DiaChi, sizeof(SV));
	WriteFileBin.write((char*)&a.DiemTB, sizeof(SV));
	WriteFileBin.close();
}
void inputToFileBin(SV &tam, ifstream &ReadFileBin)
{
	/*while (!ReadFileBin.eof())
	{
		ReadFileBin.read((char*)&tam.MSSV , sizeof(SV));
		ReadFileBin.read((char*)&tam.HoTen , sizeof(SV));
		ReadFileBin.read((char*)&tam.Gender , sizeof(SV));
		ReadFileBin.read((char*)&tam.NamSinh , sizeof(SV));
		ReadFileBin.read((char*)&tam.DiaChi , sizeof(SV));
		ReadFileBin.read((char*)&tam.DiemTB , sizeof(SV));
	}*/
    ReadFileBin.read((char*)&tam,sizeof(SV));
	ReadFileBin.close();
}