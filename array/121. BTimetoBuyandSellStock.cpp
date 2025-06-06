/*
121. Best Time to Buy and Sell Stock
121. Best Time to Buy and Sell Stock
Easy
Topics
premium lock icon
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;  // Initialize with the highest possible value
    int maxProfit = 0;       // Maximum profit starts from 0

    for (int price : prices) {
        // Update minPrice if current price is lower
        if (price < minPrice) {
            minPrice = price;
        }
        // Update maxProfit if current profit is higher
        else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice;
        }
    }

    return maxProfit;
}

int main() {
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};

    cout << "Max Profit (Example 1): " << maxProfit(prices1) << endl;  // Output: 5
    cout << "Max Profit (Example 2): " << maxProfit(prices2) << endl;  // Output: 0

    return 0;
}
