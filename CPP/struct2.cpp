#include <iostream>
#include <fstream>

using namespace std;

struct PS{
    int T, M;
};

PS Tong(PS p1, PS p2){
    PS temp;
    temp.T = p1.T*p2.M + p1.T*p2.M;
    temp.M = p1.M*p2.M;
    return temp;
}

void NhapPS(){
    ofstream ofs("PhanSo.bin",ios::binary);
    int n;
    PS temp;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>temp.T>>temp.M;
        ofs.write((char*)&temp,sizeof(temp));
    }
    ofs.close();
}

void Tong(){
    ifstream ifs("PhanSo.bin",ios::binary);
    ofstream ofs("Tong.txt");
    PS ps1, ps2;
    ifs.read((char*)&ps1,sizeof(ps1));
    while (ifs.read((char*)&ps2,sizeof(ps2))){
        PS tong = Tong(ps1,ps2);
        cout<<ps1.T<<"/"<<ps1.M<<" + "<<ps2.T<<"/"<<ps2.M<<" = "<<tong.T<<"/"<<tong.M<<endl;
        ofs<<ps1.T<<"/"<<ps1.M<<" + "<<ps2.T<<"/"<<ps2.M<<" = "<<tong.T<<"/"<<tong.M<<endl;
        ps1 = ps2;
    }
}

int main()
{
    NhapPS();
    Tong();
}