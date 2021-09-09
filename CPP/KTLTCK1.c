#include <stdio.h>

int main(){
    int ar[] = {10,15,2,25,3,-4}, *p, i;
    for (i = 0; i < 6; i++)
        printf("&a[%d] = %X\n",i,&ar[i]);
    p = &ar[2];
    printf("\nCho biet gia tri cua cac bieu thuc\n");
    printf("a. (p-1) = %X\n",(p-1));
    printf("b. p[-1] = %d\n",p[-1]);
    printf("c. (ar-p) = %d\n",(ar-p));
    printf("\t ar[4] = %X\n",ar[4]);
    printf("d. ar+ar[4] = %X\n",ar+ar[4]);
    printf("\t ar + 3 = %X\n",ar+1);
}