#include <iostream>

using namespace std;

void Pointer(){
    int *p = NULL;
    cout<<"\n_____*p = NULL_____\n";
    cout<<"Dia chi bien p quan li la: "<<p<<endl;
    cout<<"Dia chi cua con tro p la: "<<&p<<endl;
    p = new int;
    cout<<"\n_____p sau khi cap phat_____\n";
    cout<<"Dia chi bien p quan li la: "<<p<<endl;
    cout<<"Dia chi cua con tro p la: "<<&p<<endl;
    cout<<"Gia tri cua *p la: "<<*p<<endl;
}

void Pointer_Val(){
    int n = 10;
    int *p = &n;
    cout<<"\n_____Pointer and Val_____\n";
    cout<<"Gia tri cua bien n la: "<<n<<endl;
    cout<<"Dia chi cua bien n la: "<<&n<<endl;
    cout<<"Dia chi cua con tro p la: "<<&p<<endl;
    cout<<"Gia tri cua con tro p la: "<<*p<<endl;
    cout<<"Dia chi con tro p quan li la: "<<p<<endl;
    cout<<"\n_____Thay doi gia tri *p_____\n";
    *p = 5;
    cout<<"Gia tri cua bien n la: "<<n<<endl;
    cout<<"Gia tri cua *p la: "<<*p<<endl;
    cout<<"\n_____Thay doi gia tri n_____\n";
    *p = 15;
    cout<<"Gia tri cua bien n la: "<<n<<endl;
    cout<<"Gia tri cua *p la: "<<*p<<endl;
}

void Pointer_Array(){
    int a[] = {1,2,3,4,5};
    cout<<"\n_____Pointer and Array_____\n";
    cout<<"\tArray\n";
    cout<<"\t\tDia chi cua mang a la: "<<&a<<endl;
    cout<<"\t\tGia tri cua mang a la: "<<a<<endl;
    cout<<"\t\tDia chi cua a[0] la: "<<&a[0]<<endl;
    cout<<"\t\tGia tri cua a[0] la: "<<a[0]<<endl;
    int *p = a;
    cout<<"\tPointer\n";
    cout<<"\t\tDia chi bien p quan li la: "<<p<<endl;
    cout<<"\t\tDia chi cua con tro p la: "<<&p<<endl;
    cout<<"\t\tGia tri cua *p la: "<<*p<<endl;
    cout<<"\tToan tu tang giam\n";
    p += 2;
    cout<<"\t\tDia chi bien p quan li la: "<<p<<endl;
    cout<<"\t\tGia tri cua *p la: "<<*p<<endl;
    p--;
    cout<<"\t\tDia chi bien p quan li la: "<<p<<endl;
    cout<<"\t\tGia tri cua *p la: "<<*p<<endl;
    (*p) += 3;
    cout<<"\t\tDia chi bien p quan li la: "<<p<<endl;
    cout<<"\t\tGia tri cua *p la: "<<*p<<endl;
    cout<<"\tGia tri cua mang: ";
    for (int i = 0; i < 5; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void Pointer_Struct(){
    cout<<"\n_____Pointer and Struct_____\n";
    struct SinhVien{
        string Name = "Nguyen";
        int Age = 19;
    };
    SinhVien a;
    SinhVien *p = &a;
    cout<<"\tDia chi cua struct a: "<<&a<<endl;
    cout<<"\tDia chi cua p: "<<&p<<endl;
    cout<<"\tDia chi p quan li: "<<p<<endl;
    cout<<"\n\ta.Name: "<<a.Name<<endl;
    cout<<"\t(*p).Name: "<<(*p).Name<<endl;
    cout<<"\tp->Name: "<<p->Name<<endl;
    cout<<"\t&a.Name: "<<&a.Name<<endl;
    cout<<"\t&(*p).Name: "<<&(*p).Name<<endl;
    cout<<"\t&(p->Name): "<<&(p->Name)<<endl;
    cout<<"\n\ta.Age: "<<a.Age<<endl;
    cout<<"\t(*p).Age: "<<(*p).Age<<endl;
    cout<<"\tp->Age: "<<p->Age<<endl;
    cout<<"\t&a.Age: "<<&a.Age<<endl; 
    cout<<"\t&(*p).Age: "<<&(*p).Age<<endl;
    cout<<"\t&(p->Age): "<<&(p->Age)<<endl;  
}

int main()
{
    //Pointer();
    //Pointer_Val();
    //Pointer_Array();
    //Pointer_Struct();
}