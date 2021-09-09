#include <iostream>
#include <fstream>

using namespace std;

struct SinhVien{
    string MaSV, TenSV, QueQuan;
    float Diem;
    char Gioitinh; //M Nam F Nu
    int Tuoi;
};

void WriteFile(SinhVien &sv){
    cout<<"Nhap ma sinh vien: ";
    getline(cin,sv.MaSV);
    cout<<"Nhap ho ten: ";
    getline(cin,sv.TenSV);
    cout<<"Nhap tuoi: ";
    cin>>sv.Tuoi;
    cout<<"Nhap diem: ";
    cin>>sv.Diem;
    cin.ignore();
    cout<<"Nhap que quan: ";
    getline(cin,sv.QueQuan);
    do{
    cout<<"Nhap gioi tinh (M: Nam, F: Nu): ";
    cin>>sv.Gioitinh;
    }while (sv.Gioitinh != 'm' && sv.Gioitinh != 'M' && sv.Gioitinh != 'f' && sv.Gioitinh != 'F' );
    ofstream ofs("FileStruct1.txt",ios::binary);
    if (ofs.is_open()){
        ofs.write((char*)&sv,sizeof(SinhVien));
        ofs.close();
    }
    else
        cout<<"Khong mo duoc file!";
}

void ReadFile(SinhVien &sv){
    ifstream ifs("FileStruct1.txt",ios::binary);
    if (ifs.is_open()){
        ifs.read((char*)&sv,sizeof(SinhVien));
        cout<<"Ma sinh vien: "<<sv.MaSV<<endl;
        cout<<"Ho ten: "<<sv.TenSV<<endl;
        cout<<"Tuoi: "<<sv.Tuoi<<endl;
        cout<<"Diem: "<<sv.Diem<<endl;
        cout<<"Que quan: "<<sv.QueQuan<<endl;
        cout<<"Gioi tinh (M: Nam, F: Nu): "<<((sv.Gioitinh == 'M' || sv.Gioitinh == 'm') ? "Nam" : "Nu")<<endl;
        ifs.close();
    }
    else
        cout<<"Khong mo duoc file!";
}

int main(){
    SinhVien sv;
    cout<<"_____NHAP VA GHI GIU LIEU VAO FILE_____\n";
    WriteFile(sv);
    cout<<"\n_____MO FILE VA DOC DU LIEU_____\n";
    ReadFile(sv);
}