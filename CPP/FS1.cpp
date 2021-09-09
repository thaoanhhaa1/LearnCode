#include <iostream>
#include <fstream>

using namespace std;

struct manhinh{
    string manh;
    int dsmh;
};

struct cpu{
    string tencpu;
    int dungluong;
};

struct mainboard{
    string tenmain;
    cpu cpudsd;
};

struct Maytinh{
    manhinh tenmh;
    mainboard ttmain;
};

void NhapFile(Maytinh &a){
    cout<<"Tinh trang man hinh: ";
    getline(cin,a.tenmh.manh);
    cout<<"Do sang man hinh: ";
    cin>>a.tenmh.dsmh;
    cin.ignore();
    cout<<"Ten main: ";
    getline(cin,a.ttmain.tenmain);
    cout<<"Ten CPU duoc su dung: ";
    getline(cin,a.ttmain.cpudsd.tencpu);
    cout<<"Dung luong cache: ";
    cin>>a.ttmain.cpudsd.dungluong;
    cin.ignore();
    ofstream ofs("FileStruct.txt",ios::binary);
    ofs.write((char*)&a,sizeof(Maytinh));
    ofs.close();
}

void XuatFile (){
    Maytinh a;
    ifstream ifs("FileStruct.txt",ios::binary);
    ifs.read((char*)&a,sizeof(Maytinh));
    cout<<"\nMan hinh: \n";
    cout<<"\t- Tinh trang: "<<a.tenmh.manh<<endl;
    cout<<"\t- Do sang: "<<a.tenmh.dsmh<<endl;
    cout<<"\nMainboard: \n";
    cout<<"\t- Ten main: "<<a.ttmain.tenmain<<endl;
    cout<<"\t- CPU duoc su dung: "<<endl;
    cout<<"\t\t+ Ten CPU: "<<a.ttmain.cpudsd.tencpu<<endl;
    cout<<"\t\t+ Dung luong cache: "<<a.ttmain.cpudsd.dungluong<<endl;
    ifs.close();
}

int main()
{
    Maytinh a;
    NhapFile(a);
    XuatFile();
}
