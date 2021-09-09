#include <iostream>

using namespace std;

int count = 0;

void loop()
{
    count++;
    if (count <= 5)
    {
        cout<<"Loop "<<count<<endl;
        loop();
    }
}

int main()
{
    loop();
}