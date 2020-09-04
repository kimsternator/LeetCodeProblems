#include "LeetCodeProblems.h"

int maxProfit(vector<int>& prices) {
    int minVal = prices[0], maxVal = prices[0], profit = 0, counter = 0;
    int length = (signed int) prices.size() - 1;

    while(counter < length) {
        while(counter < length && prices[counter] >= prices[counter + 1])
            counter++;

        minVal = prices[counter];

        while(counter < length && prices[counter] <= prices[counter + 1])
            counter++;

        maxVal = prices[counter];
        profit += maxVal - minVal;
    }

    return profit;
}