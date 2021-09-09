#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

typedef struct {
    char ma_phach[6];
    int ky_thi;
    char diem_chu[2];
}SV;
SV ds[500];

//Cau a
void input_one(SV &P){
    do{
        cout<<"Nhap ma phach (5 ki tu): ";
        cin.getline(P.ma_phach,6);
    }while (strlen(P.ma_phach) != 5);
    do{
        cout<<"Nhap ky thi: ";
        cin>>P.ky_thi;
    }while (P.ky_thi != 1 && P.ky_thi != 2);
    cin.ignore();
    do{
        cout<<"Nhap diem chu: ";
        cin>>P.diem_chu;
    }while (P.diem_chu[0] < 'A' || P.diem_chu[0] > 'D' || strlen(P.diem_chu) != 1);
    cin.ignore();
}

//Cau b
void input_list(SV ds[], int &n){
    do{
        cout<<"Nhap n: ";
        cin>>n;
    }while (n <= 0);
    cin.ignore();
    for (int i = 0; i < n; i++)
        input_one(ds[i]);
}

//Cau c
void Write_File(SV ds[], int n){
    ofstream ofs("dssv.txt",ios::binary);
    if (ofs){
        for (int i = 0; i < n; i++)
            ofs.write((char*)&ds[i],sizeof(ds[i]));
        ofs.close();
    }
    else
        cout<<"Khong mo duoc file!";
}
//Cau d
void Read_File(){
    SV sv;
    ifstream ifs("dssv.txt",ios::binary);
    if (ifs){
        while (ifs.read((char*)&sv,sizeof(sv))){
            cout<<"Ma phach: "<<sv.ma_phach<<endl;
            cout<<"Ky thi: "<<sv.ky_thi<<endl;
            cout<<"Diem: "<<sv.diem_chu<<endl;
        }
        ifs.close();
    }
    else
        cout<<"Khong co file!";
}

int main()
{
    int n;
    input_list(ds,n);
    Write_File(ds,n);
    Read_File();
}