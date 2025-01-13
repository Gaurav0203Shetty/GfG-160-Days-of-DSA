#include <stdio.h>
#include <limits.h>

void findMajority(int arr[], int n, int *res, int *resSize) {

    int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        int ele = arr[i];

        if (ele1 == ele) {
            cnt1++;
        }

        else if (ele2 == ele) {
            cnt2++;
        }

        else if (cnt1 == 0) {
            ele1 = ele;
            cnt1++;
        }

        else if (cnt2 == 0) {
            ele2 = ele;
            cnt2++;
        }

        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++) {
        int ele = arr[i];
        if (ele1 == ele) cnt1++;
        if (ele2 == ele) cnt2++;
    }

    *resSize = 0;
    if (cnt1 > n / 3) res[(*resSize)++] = ele1;
    if (cnt2 > n / 3 && ele1 != ele2) res[(*resSize)++] = ele2;

    if (*resSize == 2 && res[0] > res[1]) {
        int temp = res[0];
        res[0] = res[1];
        res[1] = temp;
    }
}

int main() {
    int arr[] = {2, 2, 3, 1, 3, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res[2]; 
    int resSize;

    findMajority(arr, n, res, &resSize);
    for (int i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
