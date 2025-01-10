// C Code to left rotate an array using Reversal Algorithm

#include <stdio.h>

void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArr(int* arr, int n, int d) {
    
    d %= n;

    reverse(arr, 0, d - 1);

    reverse(arr, d, n - 1);

    reverse(arr, 0, n - 1);
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
    
    rotateArr(arr, n, d);
  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    return 0;
}
