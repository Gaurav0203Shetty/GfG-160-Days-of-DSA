#include <stdio.h>
#include <limits.h>

int maxSubarraySum(int arr[], int size) {
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < size; i++) {

        maxEnding = (maxEnding + arr[i] > arr[i]) ? maxEnding + arr[i] : arr[i];
        res = (res > maxEnding) ? res : maxEnding;
      
    }
    return res;
}

int main() {
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%lld\n", maxSubarraySum(arr, size));
    return 0;
}
