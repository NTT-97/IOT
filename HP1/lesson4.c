#include <stdio.h>

int main() {
	int n ;
	printf("Nhap vao 1 so: ");
    scanf("%d",&n);
    if (n % 2 == 0){
        printf("n is an even number");
    }
    else {
        printf("n is an odd number");
    }
    
	return 0;
}   