#include <stdio.h>

// void printArr(int a[]){
//     printf("Size array: %d\n", sizeof(a));
//     printf("Cac phan tu trong mang: ");

//     for(int i=0;i<5;i++){
//         printf("%d ",a[i]);
//     }
// }

int main(){
    // int arr[]={1, 3, 5, 7, 9};
    // printf("Size array: %d\n", sizeof(arr));
    // printArr(arr);
    int a = 10;
    int* p;
    p = &a;
    printf("%d\n",p);
    printf("%d",*p);
}