    #include <iostream>

    using namespace std;

    long long TongDaySoCong(int n){
        int i = 1;
        n++;
        long long sum = 0;
        while (n--){
            sum += i;
            i += 3;
        }
        return sum;
    }

int MaxK(int a[], int n, int k){
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (a[i] < a[j])
                swap(a[i],a[j]);
    return a[k-1];
}

int main()
{
    int a[] = {6,3,2,7,3,7,3}, n = 7;
    cout<<MaxK(a,n,2);
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}