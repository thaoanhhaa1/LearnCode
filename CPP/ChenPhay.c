#include <stdio.h>
#include <string.h>

void Xuli(int n){
    if (n < 1000){
        printf("%d",n);
        return;
    }
    Xuli(n/1000);
    printf(",");
    int tam = n%1000;
}

int main(){
    int n;
    char a[15];
    scanf("%s",&a);
    int t = 3;
    for (int i = strlen(a)-1; i >= 0; i--){
        t--;
        if (t == 0 && i != 0){
            for (int j = strlen(a)-1; j >= i; j--)
                a[j+1] = a[j];
            a[i] = ',';
            t = 3;
        }
    }
    a[strlen(a)] = '\0';
    printf("%s",a);
}