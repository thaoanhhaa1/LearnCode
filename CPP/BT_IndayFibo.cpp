#include <iostream>

using namespace std;
//1 1 2 3 5 8 13 21 34 55 ...
int Fibo(int n){
    if (n <= 2) //Trường hợp neo: nếu n <= 2 thì trả về giá trị 1
        return 1;
    return Fibo(n-1) + Fibo(n-2); //Trả về giá trị của số thứ n-1 + n-2 của dãy Fibonacci
}

/*Ví dụ: Nếu n = 5
Vì n > 2 điều kiện sai nên không thực hiện lệnh if và xuống lệnh return Fibo(n-1) + Fibo(n-2);
- Nhánh Fibo(n-1) = Fibo(4) = Fibo(3) + Fino(2) = Fibo(2) + Fibo(1) + 1 (Fibo(2) = 1 vì gặp trường hợp neo)
                                                = 1 + 1 + 1 = 3
- Nhánh Fibo(n-2) = Fibo(3) = Fibo(2) + Fibo(1) = 1 + 1 = 2
=> Fibo(n-1) + Fibo(n-2) = Fibo(4) + Fibo(3) = 5
*/

void IndayFibo(int f1, int f2, int k){
    if (k > 0){ //Nếu k vẫn còn lớn hơn 0 thì vẫn còn số để in nên vẫn thực hiện
        cout<<f1<<" ";
        IndayFibo(f2,f1+f2,k-1);
    }
}

/* Ví dụ: k = 5
f1 = f2 = 1: bởi vì 2 giá trị đầu tiên trong dãy Fibonacci = 1
vì k = 5 > 0 đúng nên
    lệnh cout in giá trị đầu tiên là in 1 ra màn hình
    gọi đệ quy để in số tiếp theo, lúc này f1 của lệnh gọi đệ quy sẽ bằng f2 tức bằng 1, f2 = f1+f2=2, k giảm đi 1 còn 4
    IndayFibo(1,2,4)
        k = 4 đúng
            In 1 ra màn hình
            IndayFibo(2,3,3)
                In 2
                IndayFibo(3,5,2)
                    In 3
                    IndayFibo(5,8,1)
                        In 5
                        IndayFibo(8,13,0)
                            Lúc này k = 0 điều kiện sai nên không thực hiện tiếp
Vậy kết quả in ra màn hình là: 1 1 2 3 5
*/

int main()
{
    int n;
    cout<<"Nhap so phan tu cua day Fibonacci: ";
    cin>>n;
    cout<<"\n_____Su dung de quy_____\n";
    cout<<"\tCach 1: ";
    for (int i = 1; i <= n; i++)
        cout<<Fibo(i)<<" ";
    cout<<endl;
    cout<<"\tCach 2: ";
    IndayFibo(1,1,n);
    cout<<endl;
    cout<<"\n_____In day khong de quy_____\n";
    int f1 = 1, f2 = 1;
    while (n--)
    {
        cout<<f1<<" ";
        f2 += f1;
        f1 = f2 - f1;
    }
    /*Ví dụ: n = 5
    n-- -> n = 4
        In 1 ra màn hình
        f2 = f2 + f1 = 2
        f1 = f2 - f1 = 2 - 1 = 1
    n-- -> n = 3
        In 1 ra màn hình
        f2 = f2 + f1 = 3
        f1 = f2 - f1 = 3 - 1 = 2
    n-- -> n = 2
        In 2 ra màn hình
        f2 = f2 + f1 = 5
        f1 = f2 - f1 = 5 - 2 = 3
    n-- -> n = 1
        In 3 ra màn hình
        f2 = f2 + f1 = 8
        f1 = f2 - f1 = 8 - 3 = 5
    n-- -> n = 0
        In 5 ra màn hình
        f2 = f2 + f1 = 13
        f1 = f2 - f1 = 13 - 5 = 8
    n = 0 -> sai nên không thoát lệnh while
    Vậy kết quả in ra màn hình là: 1 1 2 3 5
    */
}