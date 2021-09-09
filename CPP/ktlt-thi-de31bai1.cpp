#include <bits/stdc++.h>

int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);
    fflush(stdin);
    char Hodem[n][50], Ten[n][50], HoTen[n][50];
    for (int i = 0; i < n; i++){
        printf("Nhap ho dem nguoi thu %d: ",i+1);
        gets(Hodem[i]);
    }
    for (int i = 0; i < n; i++){
        printf("Nhap ten nguoi thu %d: ",i+1);
        scanf("%s",&Ten[i]);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < strlen(Hodem[i])+strlen(Ten[i]); j++)
            if (j < strlen(Hodem[i]))
                HoTen[i][j] = Hodem[i][j];
            else{
                if (j == strlen(Hodem[i]))
                    HoTen[i][j] = ' ';
                HoTen[i][j+1] = Ten[i][j-strlen(Hodem[i])];
            }
    printf("Danh sach ho ten: \n");
    int vtmax = 0;
    for (int i = 0; i < n; i++){
        if (strlen(HoTen[i]) > strlen(HoTen[vtmax]))
            vtmax = i;
        printf("%s\n",HoTen[i]);
    }
    printf("Ho ten dai nhat la: %s",HoTen[vtmax]);
}