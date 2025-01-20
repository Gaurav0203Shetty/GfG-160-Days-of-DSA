#include <stdio.h>

int maxProfit(int prices[], int size) {
    int minSoFar = prices[0];
    int res = 0;
  
    for (int i = 1; i < size; i++) {

        if (prices[i] < minSoFar) {
            minSoFar = prices[i];
        }
               
        if (prices[i] - minSoFar > res)
            res = prices[i] - minSoFar;
    }
    return res;
}

int main() {
    int prices[] = {7, 10, 1, 3, 6, 9, 2};
    int size = sizeof(prices) / sizeof(prices[0]);
    printf("%d\n", maxProfit(prices, size));
    return 0;
}
