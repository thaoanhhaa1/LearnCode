#include <iostream>
#include <fstream>
using namespace std;
struct SinhVien{ //Tạo một struct SinhVien để quản lí các thông tin của sinh viên như:
    char MaSV[20], TenSV[30], QueQuan[50]; //MaSV, TenSV, QueQuan của sinh viên
    int NamSinh; // và NamSinh của sinh viên
};

void Read(SinhVien &sv){ //Hàm Read để nhập thông tin của sinh viên từ bàn phím vào biến sv
    cout<<"Nhap ma sinh vien: "; //vì muốn lưu giá trị của biến sv để sử dụng
    cin.getline(sv.MaSV,19); //sau khi kết thúc hàm Read nên em truyền tham chiếu (&)
    cout<<"Nhap ho ten: ";
    cin.getline(sv.TenSV,29);
    cout<<"Nhap nam sinh: ";
    cin>>sv.NamSinh;
    cin.ignore();
    cout<<"Nhap que quan: ";
    cin.getline(sv.QueQuan,49);
}
void WriteFile(){ //Hàm WriteFile để viết thông tin của sinh viên ra file
    ofstream ofs("FileStruct2.txt",ios::binary);
    if (ofs.is_open()){ //Kiểm tra xem file có mở thành công hay không, nếu thành công thực hiện lệnh dưới, nếu không thực hiện phần else
        SinhVien sv;
        Read(sv); //Đọc thông tin sinh viên từ bàn phím
        ofs.write((char*)&sv,sizeof(SinhVien)); //Viết giá trị của biến sv (thông tin sinh viên được nhập từ bàn phím) ra màn hình theo kiểu nhị phân
        ofs.close(); //Đóng file 
    }
    else
        cout<<"Khong mo duoc file!"; //Thông báo ra màn hình file mở không thành công
}

void Write(SinhVien sv){ //Hàm Write thực hiện chức năng xuát thông tin của sinh viên ra màn hình console
    cout<<"Ma sinh vien: "<<sv.MaSV<<endl;
    cout<<"Ho ten: "<<sv.TenSV<<endl;
    cout<<"Nam sinh: "<<sv.NamSinh<<endl;
    cout<<"Que quan: "<<sv.QueQuan<<endl;
}
void ReadFile(){ //Hàm ReadFile dùng để đọc file và xuất thông tin từ file ra màn hình
    ifstream ifs("FileStruct2.txt",ios::binary);
    if (ifs.is_open()){ //Kiểm tra file có mở thành công hay không?
        SinhVien sv;
        ifs.read((char*)&sv,sizeof(SinhVien)); //Đọc thông tin từ file
        Write(sv); //Viết thông tin đọc được ra màn hình
        ifs.close();
    }
    else
        cout<<"Khong mo duoc file!";
}

int main(){
    cout<<"_____NHAP VA GHI GIU LIEU VAO FILE_____\n";
    WriteFile(); //Gọi hàm thực hiện công việc nhập dữ liệu từ bàn phím và xuất ra file
    cout<<"\n_____MO FILE VA DOC DU LIEU_____\n";
    ReadFile(); //Gọi hàm thực hiện công việc đọc thông tin từ file và xuất ra màn hình
    return 0;
}
