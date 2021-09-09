#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void Cau1(pair<double,double> *a, int &n){
    string s;
    cout<<"Nhap ten file: ";
    cin>>s;
    ifstream ifs(s);
    if (ifs){
        ifs>>n;
        a = new pair<double,double>[n];
        for (int i = 0; i < n; i++)
            ifs>>a[i].first>>a[i].second;
        cout<<"\nXuat danh sach\n";
        for (int i = 0; i < n; i++)
            cout<<a[i].first<<" "<<a[i].second<<endl;
        ifs.close();
    }
    else
        cout<<"Khong mo duoc file!";
}

bool Check(pair<double,double> a, pair<double,double> b, double R){
    return sqrt(a.first*a.first + a.second*a.second) <= R && sqrt(b.first*b.first + b.second*b.second) <= R;
}

void Cau2(pair<double,double> *a, int n){
    double R;
    int dem = 0;
    cout<<"Nhap R: ";
    cin>>R;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (Check(a[i],a[j],R))
                dem++;
    cout<<"Co "<<dem<<" doan thang nam trong duong trong tam O ban kinh "<<R<<endl;

}

double KC(pair<double,double> a, pair<double,double> b) {
    return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
}

double CheckTamGiac(pair<double,double> a, pair<double,double> b, pair<double,double> c){
    double C1 = KC(a,b), C2 = KC(a,c), C3 = KC(b,c), tam;
    if (C1 == 0 || C2 == 0 || C3 == 0)
        return -1;
    if (pow(C1,2)+pow(C2,2) == pow(C3,2))
        return 0.5*pow(C1,2)+pow(C2,2);
    if (pow(C1,2)+pow(C3,2) == pow(C2,2))
        return 0.5*pow(C1,2)+pow(C3,2);
    if (pow(C3,2)+pow(C2,2) == pow(C1,2))
        return 0.5*pow(C3,2)+pow(C2,2);
    return -1;
}

void Cau3(pair<double,double> *a, int n){
    double Smax = -1;
    for (int i = 0; i < n-2; i++)
        for (int j = i+1; j < n-1; j++)
            for (int k = j+1; k < n; k++)
                Smax = max(Smax,CheckTamGiac(a[i],a[j],a[k]));
    if (Smax == -1)
        cout<<"Khong co tam giac vuong";
    else
        cout<<"Dien tich tam giac lon nhat la: "<<Smax;
}

int main(){
    pair<double,double> *a;
    int n;
    Cau1(a,n);
    Cau2(a,n);
    Cau3(a,n);
}