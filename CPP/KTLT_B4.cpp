#include <iostream>

using namespace std;

void Nhap(float &M1, float &M2, float &S){
    cout<<"Nhap M1: ";
    cin>>M1;
    cout<<"Nhap M2: ";
    cin>>M2;
    cout<<"Nhap S: ";
    cin>>S;
}

void TienDien(float M1, float M2, float S){
    cout<<"So dien nang tieu thu la: "<<S<<" chu"<<endl;
    cout<<"So tien phai tra la: "<<((S > 100) ? 100*M1 + (S-100)*M2 : S*M1)<<endl;
}

int main(){
    while (true){
        float M1, M2, S;
        cout<<"\n CONG VIEC\n";
        cout<<" ---------------------------\n";
        cout<<" So 1: Nhap M1, M2 va S\n";
        cout<<" So 2: Tinh so tien phai tra\n";
        cout<<" SO 0: Thoat\n";
        cout<<" ---------------------------\n";
        int n;
        do{
            cout<<"Moi ban chon cong viec: ";
            cin>>n;
        }while (n < 0 || n > 2);
        if (n == 0)
            break;
        switch(n){
            case 1:
                Nhap(M1,M2,S);
                break;
            default:
                TienDien(M1,M2,S);
        }
    }
}