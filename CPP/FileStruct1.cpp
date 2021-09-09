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
    char Seat[3];
    string Name, Carrier, From, To, Flight;
    Ngay Date;
    Gio Time;
    int Gate;
};

void Input(VeMayBay &vmp){
    cout<<"Hang chuyen cho/Carrier: ";
    getline(cin,vmp.Carrier);
    cout<<"Ho va ten/Name: ";
    getline(cin,vmp.Name);
    cout<<"Noi di/From: ";
    getline(cin,vmp.From);
    cout<<"Noi den/To: ";
    getline(cin,vmp.To);
    cout<<"Chuyen bay/Flight: ";
    getline(cin,vmp.Flight);
    cout<<"Ngay/Date: ";
    cin>>vmp.Date.d>>vmp.Date.m>>vmp.Date.y;
    cout<<"Cua/Gate: ";
    cin>>vmp.Gate;
    cout<<"Gio len may bay/Time: ";
    cin>>vmp.Time.h>>vmp.Time.p;
    cin.ignore();
    cout<<"Ghe/Seat: ";
    cin.getline(vmp.Seat,3);
}

void WriteFile() {
    VeMayBay vmp;
    ofstream ofs("FileStruct1.txt",ios::binary);
    if (ofs.is_open()){
        Input(vmp);
        ofs.write((char*)&vmp,sizeof(VeMayBay));
        ofs.close();
    }
    else
        cout<<"Khong mo duoc file!";
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

void ReadFile(){
    VeMayBay vmp;
    ifstream ifs("FileStruct1.txt",ios::binary);
    if (ifs.is_open()){
        ifs.read((char*)&vmp,sizeof(VeMayBay));
        Output(vmp);
        ifs.close();
    }
    else
        cout<<"Mo file khong thanh cong!";
}

int main()
{
    VeMayBay VMB;
    cout<<"_____NHAP DU LIEU GHI VAO FILE_____\n";
    //WriteFile();
    cout<<"\n_____DOC DU LIEU TU FILE_____\n";
    ReadFile();
}

