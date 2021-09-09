#include <iostream>
#include <math.h>

using namespace std;

struct Point {
    double a,b;
};

double Khoangcach(Point x, Point y){
    return sqrt(pow(x.a - y.a,2) + pow(x.b - y.b,2));
}

void InPoint(Point a[], int n){
    for (int i = 0; i < n; i++)
        cin>>a[i].a>>a[i].b;
}

void InDiemMax(Point a[], int n){
    double kcmax = 0;
    Point s1,s2;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++){
            double kc = Khoangcach(a[i],a[j]);
            if (kc > kcmax){
                kcmax = kc;
                s1 = a[i];
                s2 = a[j];
            }
        }
    cout<<"Toa do cua 2 diem xa nhau nhat la: ("<<s1.a<<";" <<s1.b<<") va ("<<s2.a<<";" <<s2.b<<")";
}

int main()
{
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    Point A[n];
    InPoint(A,n);
    InDiemMax(A,n);
}