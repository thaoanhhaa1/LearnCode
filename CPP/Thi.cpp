#include <bits/stdc++.h>

int main(){
    char s[50];
    gets(s); // Đọc chuỗi có khoảng trắng
    puts(s); //In cuỗi
    printf("%s",s);
    FILE *f = fopen("ThongTinSach.txt","r");
    while (fgets(s,49,f))
        printf("%s",s);
    fclose(f);
}