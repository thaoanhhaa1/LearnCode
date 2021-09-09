#include <iostream>
#include <fstream>

using namespace std;

struct Date{
    int d,m,y;
};

struct HocVien{
    string MaHV, HoTen;
    Date NgaySinh;
    int Gioitinh; //0 Nu, 1 Nam
    float Ex, Wo, Pp;
};

//Nhập 1 học viên
void Nhap1HV(HocVien hv){
    cin.ignore();
    cout<<"Nhap ma hoc vien: ";
    getline(cin,hv.MaHV);
    cout<<"Nhap ho ten hoc vien: ";
    getline(cin,hv.HoTen);
    cout<<"Nhap ngay sinh: ";
    cin>>hv.NgaySinh.d>>hv.NgaySinh.m>>hv.NgaySinh.y;
    do{
        cout<<"Nhap gioi tinh (0 Nu, 1 Nam): ";
        cin>>hv.Gioitinh;
    }while (hv.Gioitinh != 0 && hv.Gioitinh != 1);
    cout<<"Nhap diem Work: ";
    cin>>hv.Wo;
    cout<<"Nhap diem Excel: ";
    cin>>hv.Ex;
    cout<<"Nhap diem Power Point: ";
    cin>>hv.Pp;
}

//Xuất 1 học viên
void Xuat1HV(HocVien hv){
    cout<<"Ma hoc vien: "<<hv.MaHV<<endl;
    cout<<"Ho ten: "<<hv.HoTen<<endl;
    cout<<"Ngay sinh: "<<hv.NgaySinh.d<<"/"<<hv.NgaySinh.m<<"/"<<hv.NgaySinh.y<<endl;
    cout<<"Gioi tinh: "<<hv.Gioitinh<<endl;
    cout<<"Diem Work: "<<hv.Wo<<endl;
    cout<<"Diem Excel: "<<hv.Ex<<endl;
    cout<<"Diem Power Point: "<<hv.Pp<<endl;
}


//Lưu thông tin 1 học viên ra file
void Write1HV(HocVien hv, ofstream &ofs){
    ofs<<hv.MaHV<<endl;
    ofs<<hv.HoTen<<endl;
    ofs<<hv.NgaySinh.d<<" "<<hv.NgaySinh.m<<" "<<hv.NgaySinh.y<<endl;
    ofs<<hv.Gioitinh<<endl;
    ofs<<hv.Wo<<endl;
    ofs<<hv.Ex<<endl;
    ofs<<hv.Pp<<endl;
}

//Lưu n học viên ra file
void WriteHV(HocVien hv[], int n){
    string s;
    cin.ignore();
    cout<<"Nhap ten file: ";
    getline(cin.s);
    ofstream ofs(s);
    for (int i = 0; i < n; i++)
        Write1HV(hv[i],ios);
    ofs.close();
}

bool operator==(string s1, string s2){
    int n = s1.size();
    if (n != s2.size())
        return false;
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}

//Xem thông tin học viên theo mã học viên
void ViewHV(HocVien hv[], int n){
    cout<<"Nhap ma hoc vien can xem: ";
    string mhv;
    getline(cin,mhv);
    for (int i = 0; i < n; i++)
        if (mhv == hv[i].MaHV)
            Xuat1HV(hv[i]);
        else if (i == n-1)
            cout<<"Khong co hoc vien voi ma hoc vien "<<mhv<<endl;
}

//Xóa thông tin học viên theo mã học viên
void DeleteHV(HocVien hv[], int n){
    cout<<"Nhap ma hoc vien can xoa: ";
    string mhv;
    getline(cin,mhv);
    for (int i = 0; i < n; i++)
        if (mhv == hv[i].MaHV)
        {
            for (; i < n-1; i++)
                hv[i] = hv[i+1];
            return;
        }
        else if (i == n-1)
            cout<<"Khong co hoc vien voi ma hoc vien "<<mhv<<endl;
}

//Sửa thông tin học viên theo mã học viên
void SuaHV(HocVien hv[], int n){
    cout<<"Nhap ma hoc vien can sua: ";
    string mhv;
    getline(cin,mhv);
    for (int i = 0; i < n; i++)
        if (mhv == hv[i].MaHV)
            Nhap1HV(hv[i]);
        else if (i == n-1)
            cout<<"Khong co hoc vien voi ma hoc vien "<<mhv<<endl;
}

int main(){
    int n;
    cout<<"Nhap so hoc vien: ";
    cin>>n;
    HocVien hv[n];
    for (int i = 0; i < n; i++)
        Nhap1HV(hv[i]);
}