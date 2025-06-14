#include <stdio.h>

// n! = n(n-1)(n-2)...1

int gt(int n){
    printf("%d\n",n);
    if (n==0){
        return 1; // trả về giá trị của giai thừa của 0!
    }
    else{
        return n*gt(n-1); // gọi hàm gt với n-1 
    }
}
int main() {
    
    printf("Giai thua cua 5: %d", gt(5));
    return 0;
}