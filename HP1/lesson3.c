#include <stdio.h>
#include <stdlib.h>

int main(){

    int num1, num2;
    printf("Xin chao!");
    printf("Ban hay nhap cac gia tri.\n");

    printf("Nhap gia tri thu nhat: ");
    scanf("%d", &num1);
    printf("\nNhap gia tri thu hai: ");
    scanf("%d", &num2);

    printf("So vua nhap: %d va %d",num1, num2);

    printf("\nKet qua cac phep tinh.");
    printf("\n----------");
    printf("\nCong: %d",num1+num2);
    printf("\nTru: %d",num1-num2);
    printf("\nNhan: %d",num1*num2);
    printf("\nChia: %f",num1/num2);
    printf("\n----------");
    
    system("PAUSE");

    return 0;
}