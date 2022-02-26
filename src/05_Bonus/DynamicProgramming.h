
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
 * 120. Triangle
 * Bottom up
 * @param triangle
 * @return
 */
int minimumTotal(std::vector<std::vector<int>> &triangle) {
    // Iterate
    for (int rows = triangle.size() - 2; rows >= 0; rows--) {
        for (int cols = 0; cols < triangle[rows].size(); cols++) {
            triangle[rows][cols] += std::min(triangle[rows + 1][cols], triangle[rows + 1][cols + 1]);
        }
    }

    return triangle[0][0];
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

/**
 * Climbing Stairs
 * Bottom up
 * @param n the number of steps to take.
 * @return the number of options
 */
int climbStairs(int n) {
    int first = 1;
    int second = 1;
    int temp = 0;

    for (int i = 0; i < n - 1; i++) {
        temp = first;
        first = first + second;
        second = temp;
    }

    return first;
}

/**
 * House Robber
 * @param nums
 * @return
 */
int rob(std::vector<int> &nums) {
    int previousRob = 0;
    int currentRob = 0;
    int temp;

    // [2,7,9,3,1]
    // [previousRob, currentRob, n, n+1]
    for (int num: nums) {
        // Figure out max between new num + previousRob or currentRob
        temp = std::max(previousRob + num, currentRob);
        // Shift currentRob to previousRob
        previousRob = currentRob;
        currentRob = temp;
    }

    // Always return latest rob
    return currentRob;
}

/**
 * Finds the contiguous subarray (containing at least one number) which has the largest sum.
 * See Kadane's Algorithm (O(n)). Alternative: Bruteforce (O(n^2))
 * @param nums the dynamic array containing the numbers
 * @return the sum of largest numbers;
 */
int maxSubArray(std::vector<int> &nums) {
    int max = nums[0];
    int current = max;

    // Starting at 1 because first already solved
    for (int i = 1; i < nums.size(); i++) {
        // Check if current sum + new num > new num
        current = std::max(current + nums[i], nums[i]);
        // Check if we have a new max
        max = std::max(current, max);
    }

    return max;
}

#endif //CPPBASICS_DYNAMICPROGRAMMING_H
