#include <stdio.h>
#include <limits.h>

int maxProduct(int arr[], int n) {
    int maxProd = LLONG_MIN;

    int leftToRight = 1;

    int rightToLeft = 1;
  
    for (int i = 0; i < n; i++) {
        if (leftToRight == 0)
            leftToRight = 1;
        if (rightToLeft == 0)
            rightToLeft = 1;

        leftToRight *= arr[i];

        int j = n - i - 1;
        rightToLeft *= arr[j];
        maxProd = (leftToRight > maxProd ? leftToRight : maxProd);
        maxProd = (rightToLeft > maxProd ? rightToLeft : maxProd);
    }
    return maxProd;
}

int main() {
    int arr[] = { -2, 6, -3, -10, 0, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%lld\n", maxProduct(arr, n));
    return 0;
}
