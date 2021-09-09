#include <iostream>
#include <time.h>

using namespace std;

int main(){
    clock_t begin = clock();
    int sum = 0;
    for (int i = 0; i <= 10000; i++)
        for (int j = i+1; j <= 10000; j++)
            sum++;
    cout<<"Run time: "<<(float)(clock() - begin)/CLOCKS_PER_SEC<<" s";
}