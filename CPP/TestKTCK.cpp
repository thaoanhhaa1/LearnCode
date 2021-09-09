#include <iostream>
#include <fstream>

using namespace std;

void Test1(){
    int n = 0;
    ifstream ifs("D:/Code/IOFile/TestKTCK.txt");
    ifs>>n;
    int a[n];
    for (int i = 0; i < n; i++)
        ifs>>a[i];
    cout<<n<<endl;
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    ifs.close();
}

void Test2(){
    int n = 0;
    ifstream ifs("D:\\Code\\IOFile\\TestKTCK.txt");
    ifs>>n;
    int a[n];
    for (int i = 0; i < n; i++)
        ifs>>a[i];
    cout<<n<<endl;
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    ifs.close();
}

int main(){
    Test1();
    Test2();
}