#include <iostream>
#include <fstream>

using namespace std;

struct Ngay{
    int d,m,y;
};

struct Gio{
    int h,p;
};

struct VeMayBay{
    char Carrier[10];
    char Name[50];
    char From[30];
    char To[30];
    char Flight[10];
    Ngay Date;
    int Gate;
    Gio Time;
    char Seat[5];
};

void Input(VeMayBay &vmp){
    cout<<"Hang chuyen cho/Carrier: ";
    cin.getline(vmp.Carrier,10);
    cout<<"Ho va ten/Name: ";
    cin.getline(vmp.Name,50);
    cout<<"Noi di/From: ";
    cin.getline(vmp.From,30);
    cout<<"Noi den/To: ";
    cin.getline(vmp.To,30);
    cout<<"Chuyen bay/Flight: ";
    cin.getline(vmp.Flight,10);
    cout<<"Ngay/Date: ";
    cin>>vmp.Date.d>>vmp.Date.m>>vmp.Date.y;
    cout<<"Cua/Gate: ";
    cin>>vmp.Gate;
    cout<<"Gio len may bay/Time: ";
    cin>>vmp.Time.h>>vmp.Time.p;
    cin.ignore(1);
    cout<<"Ghe/Seat: ";
    cin.getline(vmp.Seat,5);
}

void Output(VeMayBay vmp){
    cout<<"Hang chuyen cho/Carrier: "<<vmp.Carrier<<endl;
    cout<<"Ho va ten/Name: "<<vmp.Name<<endl;
    cout<<"Noi di/From: "<<vmp.From<<endl;
    cout<<"Noi den/To: "<<vmp.To<<endl;
    cout<<"Chuyen bay/Flight: "<<vmp.Flight<<endl;
    cout<<"Ngay/Date: "<<vmp.Date.d<<"/"<<vmp.Date.m<<"/"<<vmp.Date.y<<endl;
    cout<<"Cua/Gate: "<<vmp.Gate<<endl;
    cout<<"Gio len may bay/Time: "<<vmp.Time.h<<":"<<vmp.Time.p<<endl;
    cout<<"Ghe/Seat: "<<vmp.Seat<<endl;
}

/*ostream &operator<<(ostream &os, VeMayBay vmp){
    os<<"Hang chuyen cho/Carrier: "<<vmp.Carrier<<endl;
    os<<"Ho va ten/Name: "<<vmp.Name<<endl;
    os<<"Noi di/From: "<<vmp.From<<endl;
    os<<"Noi den/To: "<<vmp.To<<endl;
    os<<"Chuyen bay/Flight: "<<vmp.Flight<<endl;
    os<<"Ngay/Date: "<<vmp.Date.d<<"/"<<vmp.Date.m<<"/"<<vmp.Date.y<<endl;
    os<<"Cua/Gate: "<<vmp.Gate<<endl;
    os<<"Gio len may bay/Time: "<<vmp.Time.h<<":"<<vmp.Time.p<<endl;
    os<<"Ghe/Seat: "<<vmp.Seat<<endl;
    return os;
}*/

void WriteFile() {
    ofstream ofs("FileStruct2.txt",ios::binary);
    if (ofs.is_open()){
        int n;
        cout<<"Nhap so ve: ";
        cin>>n;
        cin.ignore(1);
        VeMayBay vmp;
        for (int i = 0; i < n; i++){
            cout<<"\n_____THONG TIN VE "<<i+1<<"_____\n";
            Input(vmp);
            ofs.write((char*)&vmp,sizeof(VeMayBay));
        }
        ofs.close();
    }
    else
        cout<<"Khong mo duoc file!";
}

void ReadFile(){
    ifstream ifs("FileStruct2.txt",ios::binary);
    if (ifs.is_open()){
        int i = 1;
        VeMayBay vmp;   
        while(ifs.read((char*)&vmp,sizeof(VeMayBay))){
            cout<<"\n_____THONG TIN VE "<<i<<"_____\n";
            Output(vmp);
            i++;
        }
        ifs.close();
    }
    else
        cout<<"Mo file khong thanh cong!";
}

int main()
{
    cout<<"_____NHAP DU LIEU GHI VAO FILE_____\n";
    WriteFile();
    cout<<"\n_____DOC DU LIEU TU FILE_____\n";
    ReadFile();
}