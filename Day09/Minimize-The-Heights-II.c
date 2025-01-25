#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int getMinDiff(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare);

    int res = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] - k < 0)
            continue;

        int minH = (arr[0] + k < arr[i] - k) ? (arr[0] + k) : (arr[i] - k);

        int maxH = (arr[i - 1] + k > arr[n - 1] - k) ? (arr[i - 1] + k) : (arr[n - 1] - k);

        res = (res < maxH - minH) ? res : (maxH - minH);
    }
    return res;
}

int main() {
    int k = 6;
    int arr[] = {12, 6, 4, 15, 17, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = getMinDiff(arr, n, k);
    printf("%d\n", ans);

    return 0;
}
