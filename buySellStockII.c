#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {   
    int max_profit = 0;
    for(int day = 1; day < pricesSize; day++){
        if (prices[day] > prices[day - 1]) {
            max_profit += prices[day] - prices[day-1];
        }
    }
    return max_profit;
}

int main() {
    int prices[] = {7};
    int pricesSize = 1;
    int res = maxProfit(prices, pricesSize);
    printf("Results: %d", res);
}