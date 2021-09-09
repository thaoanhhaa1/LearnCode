#include <iostream>
#include <fstream>

using namespace std;

struct SinhVien{
    string MaSV, TenSV, QueQuan;
    float Diem;
    char Gioitinh; //M Nam F Nu
    int Tuoi;
};

void Read(SinhVien &sv){
    cin.ignore();
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
}

void WriteFile(SinhVien sv[], int n){
    ofstream ofs("FileStruct2.txt",ios::binary);
    if (ofs.is_open()){
        for (int i = 0; i < n; i++){
            cout<<"\n___Nhap thong tin sinh vien thu "<<i+1<<": \n";
            Read(sv[i]);
            ofs.write((char*)&sv[i],sizeof(SinhVien));
        }
        ofs.close();
    }
    else
        cout<<"Khong mo duoc file!";
}

void Write(SinhVien &sv){
    cout<<"Ma sinh vien: "<<sv.MaSV<<endl;
    cout<<"Ho ten: "<<sv.TenSV<<endl;
    cout<<"Tuoi: "<<sv.Tuoi<<endl;
    cout<<"Diem: "<<sv.Diem<<endl;
    cout<<"Que quan: "<<sv.QueQuan<<endl;
    cout<<"Gioi tinh (M: Nam, F: Nu): "<<((sv.Gioitinh == 'M' || sv.Gioitinh == 'm') ? "Nam" : "Nu")<<endl;
}

void ReadFile(SinhVien sv[], int n){
    ifstream ifs("FileStruct2.txt",ios::binary);
    if (ifs.is_open()){
        for (int i = 0; i < n; i++){
            cout<<"\nThong tin sinh vien "<<i+1<<": \n";
            ifs.read((char*)&sv[i],sizeof(SinhVien));
            Write(sv[i]);
        }
        ifs.close();
    }
    else
        cout<<"Khong mo duoc file!";
}

int main(){
    int n;
    cout<<"Nhap so sinh vien: ";
    cin>>n;
    SinhVien sv[n];
    cout<<"_____NHAP VA GHI GIU LIEU VAO FILE_____\n";
    WriteFile(sv,n);
    cout<<"\n_____MO FILE VA DOC DU LIEU_____\n";
    ReadFile(sv,n);
}