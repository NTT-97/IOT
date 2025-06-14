#include <stdio.h>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\t");
} 
/*Bubble Sort (Sắp xếp nổi bọt)
So sánh và hoán đổi các phần tử liền kề cho đến khi mảng được sắp xếp.*/
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void Sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/*
Selection Sort (Sắp xếp chọn)
Tìm phần tử nhỏ nhất từ mảng chưa sắp xếp và hoán đổi nó với phần tử đầu tiên của mảng chưa sắp xếp.*/
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

/*
Insertion Sort (Sắp xếp chèn)
Xây dựng mảng đã sắp xếp từng phần bằng cách chèn từng phần tử từ mảng chưa sắp xếp vào vị trí đúng của nó.*/
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*
Merge Sort (Sắp xếp trộn)
Chia mảng thành hai nửa, sắp xếp đệ quy từng nửa và trộn chúng lại.*/
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/*
QuickSort (Sắp xếp nhanh)
Chọn một phần tử làm chốt (pivot), phân chia mảng xung quanh chốt và sắp xếp đệ quy.*/
int partition(int arr[], int low, int high) {
    
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high; j++) {
        printf("i=%d\t",i);
        printf("j=%d\n",j);
        printArray(arr,high+1);
        if (arr[j] <= pivot){
            i++;
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }     
    }
    printArray(arr,high+1);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("\n");
        quickSort(arr, low, pi - 1);
        printf("\n");
        quickSort(arr, pi + 1, high);
    }
}

/*
Heap Sort (Sắp xếp đống)
Ý tưởng chính:Chuyển đổi mảng thành một cây heap và liên tục loại bỏ phần tử lớn nhất.*/
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
    }
}



int main(){

    int arr[]={10,5,8,12,15,6,3,9,16,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    //bubbleSort(arr,n);
    quickSort(arr, 0, n-1);
    printArray(arr,n);
    return 0;
}
