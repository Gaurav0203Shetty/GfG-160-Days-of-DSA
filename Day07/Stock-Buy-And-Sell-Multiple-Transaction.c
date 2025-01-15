#include <stdio.h>

int maximumProfit(const int* prices, int n) {
    int res = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) 
            res += prices[i] - prices[i - 1];
    }
    
    return res;
}

int main() {
    int prices[] = { 100, 180, 260, 310, 40, 535, 695 };
    int size = sizeof(prices) / sizeof(prices[0]);
    printf("%d\n", maximumProfit(prices, size));
    return 0;
}
