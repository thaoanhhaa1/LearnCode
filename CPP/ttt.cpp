#include <iostream>
#include <fstream>

using namespace std;

int main(){
    char a;
    ifstream ifs("bi.txt");
    while (ifs>>a)
        cout<<a;
    ifs.close();
}