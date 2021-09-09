#include <iostream>
using namespace std;

bool a[100], b[100], c[100];
int x[100];

void In_Ketqua()
{

}

void TRY(int j, int q){
    for (int i = 0; i < 8; i++){
        if (a[i] && b[i+j] && c[i-j]){
            x[j] = i;
            a[i] = false;
            b[i+j] = false;
            c[i-j] = false;
            if (i < 8){
                TRY(i+1,q);
                if (!q){
                    a[i] = true;
                    b[i+j] = true;
                    c[i-j] = true;
                }
            }
            else In_Ketqua();
        }
    }
}




