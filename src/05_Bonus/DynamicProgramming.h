
#ifndef CPPBASICS_DYNAMICPROGRAMMING_H
#define CPPBASICS_DYNAMICPROGRAMMING_H

#include <vector>

/**
 * 121. Best Time to Buy and Sell Stock
 * @param prices a list of prices where each index represents the price on the i-th day.
 * @return the maximum profit possible.
 */
int maxProfit(std::vector<int> &prices) {
    int maxPro = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++) {
        minPrice = std::min(minPrice, prices[i]);
        maxPro = std::max(maxPro, prices[i] - minPrice);
    }

    return maxPro;
}

/**
 * 118. Pascal's Triangle
 * Using dynamic programming, memoization
 * @param numRows
 * @return
 */
std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < numRows; i++) {
        // Generate empty vector
        std::vector<int> row(i + 1, 1);

        // Starting at 1 because access to index 0 needed
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }

        triangle.push_back(row);
    }

    return triangle;
}

#endif //CPPBASICS_DYNAMICPROGRAMMING_H
