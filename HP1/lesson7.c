#include <stdio.h>
#include <stdlib.h>  // Thêm thư viện để sử dụng hàm abs

int sum_of_digits(int num) {
    int sum = 0;
    num = abs(num);  // Lấy giá trị tuyệt đối của num

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main() {
    int num;

    printf("Nhap mot so nguyen: ");
    scanf("%d", &num);

    printf("Tong cac chu so cua %d la: %d\n", num, sum_of_digits(num));

    return 0;
}
