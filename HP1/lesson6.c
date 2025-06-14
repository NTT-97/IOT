#include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap cac phan tu de so sanh:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int maxValue = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > maxValue) {
            maxValue = a[i];
        }
    }
    printf("Phan tu lon nhat trong mang la: %d", maxValue);
    return 0;
}