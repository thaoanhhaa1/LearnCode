#include <iostream>
#include <string.h>

using namespace std;

class Student{
    private:
        char id[5], name[30], course[20];
        float mark;
    public:
        void Write1SV(){
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;       
            cout<<"Course: "<<course<<endl;
            cout<<"Mark: "<<mark<<endl;
        }

        char* getName(){
            return name;
        }

        char* getID(){
            return id;
        }

        char* getCourse(){
            return course;
        }

        void Read1SV(){
            cout<<"Nhap ID sinh vien: ";
            cin.getline(id,5);
            cout<<"Nhap ho ten: ";
            cin.getline(name,30);
            cout<<"Nhap course: ";
            cin.getline(course,20);
            cout<<"Nhap diem: ";
            cin>>mark;
            cin.ignore();
        }
};

class StudentList{
    private:
        int n;
        Student sv[100];
    public:

        StudentList(){
            n = 0;
        }

        void WriteList(){
            for (int i = 0; i < n; i++)
                sv[i].Write1SV();
        }

        void AddSV(Student svadd){
            sv[n++] = svadd;
        }

        void AddSV(){
            sv[n++].Read1SV();
        }

        void SearchName(char Name[]){
            for (int i = 0; i < n; i++)
                if (!strcmp(Name,sv[i].getName())){
                    sv[i].Write1SV();
                    break;
                }
                else if (i == n-1)
                    cout<<"Khong co sinh vien ten "<<Name;
        }

        void DelID(char ID[]){
            for (int i = 0; i < n; i++)
                if (!strcmp(ID,sv[i].getID())){
                    for (int j = i+1; j < n; j++)
                        sv[j-1] = sv[j];
                    n--;
                    break;
                }
                else if (i == n-1)
                    cout<<"Khong co sinh vien co ID "<<ID;
        }

        void PrintCourse(){
            char course[20];
            cout<<"Nhap course: ";
            cin.getline(course,20);
            for (int i = 0; i < n; i++)
                if (!strcmp(course,sv[i].getCourse()))
                    sv[i].Write1SV();
        }
};

int main(){
    StudentList SV;
    SV.AddSV();
    SV.AddSV();
    SV.WriteList();
    cout<<"\n_____Search Name_____\n";
    SV.SearchName("Ha Anh Thao");
    cout<<"\n_____Delete ID_____\n";
    SV.DelID("A12");
    SV.WriteList();
    cout<<"\n_____Print Course_____\n";
    SV.PrintCourse();
}