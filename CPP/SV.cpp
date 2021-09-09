#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

typedef struct{
    char ma_sv[12];
    char ten_sv[30];
    char ma_lop[10];
    float D10, D4;
}SinhVien;

void input_one(SinhVien &P){
    cin.ignore();
    cout<<"Nhap ma sinh vien: ";
    cin.getline(P.ma_sv,11);
    cout<<"Nhap ten sinh vien: ";
    cin.getline(P.ten_sv,29);
    do{
        cout<<"Nhap ma lop: ";
        cin.getline(P.ma_lop,9);
    }while (strcmp(P.ma_lop,"01") && strcmp(P.ma_lop,"02") && strcmp(P.ma_lop,"03"));
    do{
        cout<<"Nhap diem: ";
        cin>>P.D10;
    }while (P.D10 < 0 || P.D10 > 10);
}

void input_list(SinhVien A[], int &n){
    cout<<"Nhap so sinh vien: ";
    cin>>n;
    for (int i = 0; i < n; i++){
        input_one(A[i]);
        A[i].D4 = 0.4*A[i].D10;
    }
}

void output_list(SinhVien A[], int n, char ma_lop_hoc[]){
    cout<<"\tBang Diem KTLT - Lop: "<<ma_lop_hoc<<endl;
    int stt = 1;
    cout<<right<<setw(4)<<"STT"<<setw(30)<<"Ho ten"<<setw(13)<<"Ma sinh vien"<<setw(14)<<"Diem thang 4"<<setw(8)<<"Ghi chu"<<endl;
    for (int i = 0; i < n; i++)
        if (!strcmp(A[i].ma_lop,ma_lop_hoc)){
            cout<<setw(4)<<stt<<setw(30)<<A[i].ten_sv<<setw(13)<<A[i].ma_sv<<setw(14)<<A[i].D4;
            if (A[i].D4 < 1.0)
                cout<<setw(7)<<"Hoc lai"<<endl;
            else
                cout<<endl;
            stt++;
        }

}

int main(){
    int n;
    SinhVien A[500];
    input_list(A,n);
    cout<<"Nhap ma lop hoc: ";
    char malop[10];
    cin.ignore();
    cin.getline(malop,9);
    output_list(A,n,malop);
}