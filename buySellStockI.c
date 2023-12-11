#include <stdio.h>
/*
    Two pointers method:
    1. Constantly update the cheapest price (buy)
    2. If future price (sell) - the current cheapest price > maxProfit => update maxProfit
*/

int maxProfit(int* prices, int pricesSize) {   
    int buy = 0;
    int max_profit = 0;
    if (pricesSize < 2) {return max_profit;}
    for (int sell = 0; sell < pricesSize; sell++) {
        if (prices[sell] < prices[buy]) {
            buy = sell;
        }
        if (prices[sell]- prices[buy] > max_profit) {
            max_profit = prices[sell]- prices[buy];
        }
    }
    return max_profit;
}

int main() {
    int prices[] = {3};
    int pricesSize = 1;
    int res = maxProfit(prices, pricesSize);
    printf("Results: %d", res);
}